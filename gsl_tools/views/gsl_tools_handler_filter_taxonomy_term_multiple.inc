<?php

/**
 * @file
 * Definition of views_handler_filter_term_node_tid_depth.
 */

/**
 * Filter handler for taxonomy terms with depth.
 *
 * This handler is actually part of the node table and has some restrictions,
 * because it uses a subquery to find nodes with.
 *
 * @ingroup views_filter_handlers
 */
class gsl_tools_handler_filter_taxonomy_term_multiple extends views_handler_filter_term_node_tid_depth_join {
	
  // Stores the exposed input for this filter.
  var $validated_exposed_input = NULL;

  function option_definition() {
    $options = parent::option_definition();

    $options['type'] = array('default' => 'select');
    $options['limit'] = array('default' => TRUE, 'bool' => TRUE);
    $options['vocabulary'] = array('default' => array());
    $options['hierarchy'] = array('default' => 0);
    $options['error_message'] = array('default' => TRUE, 'bool' => TRUE);

    return $options;
  }
  
  function extra_options_form(&$form, &$form_state) {
    $vocabularies = taxonomy_get_vocabularies();
    $options = array();
    foreach ($vocabularies as $voc) {
      $options[$voc->machine_name] = check_plain($voc->name);
    }

    if ($this->options['limit']) {
      // We only do this when the form is displayed.

      if (empty($this->definition['vocabulary'])) {
        $form['vocabulary'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Vocabulary'),
          '#options' => $options,
          '#description' => t('Select which vocabulary to show terms for in the regular options.'),
          '#default_value' => $this->options['vocabulary'],
        );
      }
    }

    $form['type'] = array(
      '#type' => 'hidden',
      '#default_value' => $this->options['type'],
    );

    $form['hierarchy'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show hierarchy in dropdown'),
      '#default_value' => !empty($this->options['hierarchy']),
      '#dependency' => array('radio:options[type]' => array('select')),
    );
        
  }
    
  function value_form(&$form, &$form_state) {
  	// get vocabulary for each selected option
  	$selected_vocabulary = array_filter(array_values($this->options['vocabulary'])); 
  	
  	$vocabulary = array();
  	foreach($selected_vocabulary as $v) {
  		$vocabulary[$v] = taxonomy_vocabulary_machine_name_load($v); 
  	}
  	
  	if (empty($vocabulary) && $this->options['limit']) {
  		$form['markup'] = array(
  				'#markup' => '<div class="form-item">' . t('An invalid vocabulary is selected. Please change it in the options.') . '</div>',
  		);
  		return;
  	}
  
  	if (!empty($this->options['hierarchy']) && $this->options['limit']) {
  		$options = array();
  		foreach($vocabulary as $v_key => $v_value){
  			$tree = taxonomy_get_tree($v_value->vid, 0, NULL, TRUE);
  			if ($tree) {
  				// Translation system needs full entity objects, so we have access to label.
  				foreach ($tree as $term) {
  					$choice = new stdClass();
  					$choice->option = array($term->tid => str_repeat('-', $term->depth) . entity_label('taxonomy_term', $term));
  					$options[] = $choice;
  				}
  			}
  		}
  	}
  	else {
  		$options = array();
  		$query = db_select('taxonomy_term_data', 'td');
  		$query->innerJoin('taxonomy_vocabulary', 'tv', 'td.vid = tv.vid');
  		$query->fields('td');
  		$query->orderby('tv.weight');
  		$query->orderby('tv.name');
  		$query->orderby('td.weight');
  		$query->orderby('td.name');
  		$query->addTag('term_access');
  		if ($this->options['limit']) {
  			//$query->condition('tv.machine_name', $vocabulary->machine_name);
  			$query->condition('tv.machine_name', $selected_vocabulary,'IN');
  		}
  		$result = $query->execute();
  
  		$tids = array();
  		foreach ($result as $term) {
  			$tids[] = $term->tid;
  		}
  		$entities = taxonomy_term_load_multiple($tids);
  		foreach ($entities as $entity_term) {
  			$options[$entity_term->tid] = entity_label('taxonomy_term', $entity_term);
  		}
  	}
  
  	$default_value = (array) $this->value;
  
  	if (!empty($form_state['exposed'])) {
  		$identifier = $this->options['expose']['identifier'];
    	if (!empty($this->options['expose']['reduce'])) {
  			$options = $this->reduce_value_options($options);
  
  			if (!empty($this->options['expose']['multiple']) && empty($this->options['expose']['required'])) {
  				$default_value = array();
  			}
  		}
  
  		if (empty($this->options['expose']['multiple'])) {
  			if (empty($this->options['expose']['required']) && (empty($default_value) || !empty($this->options['expose']['reduce']))) {
  				$default_value = 'All';
  			}
  			elseif (empty($default_value)) {
  				$keys = array_keys($options);
  				$default_value = array_shift($keys);
  			}
  			// Due to #1464174 there is a chance that array('') was saved in the admin ui.
  			// Let's choose a safe default value.
  			elseif ($default_value == array('')) {
  				$default_value = 'All';
  			}
  			else {
  				$copy = $default_value;
  				$default_value = array_shift($copy);
  			}
  		}
  	}
  	$form['value'] = array(
  			'#type' => 'select',
  			'#title' => $this->options['limit'] ? t('Select terms from vocabularies') : t('Select terms'),
  			'#multiple' => TRUE,
  			'#options' => $options,
  			'#size' => min(9, count($options)),
  			'#default_value' => $default_value,
  	);
  
  	if (!empty($form_state['exposed']) && isset($identifier) && !isset($form_state['input'][$identifier])) {
  		$form_state['input'][$identifier] = $default_value;
  	}
    
  	if (empty($form_state['exposed'])) {
  		// Retain the helper option
  		$this->helper->options_form($form, $form_state);
  
  		// Show help text if not exposed to end users.
  		$form['value']['#description'] = t('Leave blank for all. Otherwise, the first selected term will be the default instead of "Any".');
  	}
  }
   
}
	