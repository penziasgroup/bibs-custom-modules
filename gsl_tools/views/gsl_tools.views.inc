<?php 
/**
 * Implements hook_views_data_alter().
 */
function gsl_tools_views_data_alter(&$data) {

	$data['node']['taxonomy_term_multiple'] = array(
			'help' => t('Display content if it has the selected taxonomy terms, or children of the selected terms. Due to additional complexity, this has fewer options than the versions without depth. This version allows selecting terms from multiple vocabularies'),
			'real field' => 'nid',
			'filter' => array(
					'title' => t('multiple taxonomy terms with depth (using joins)'),
					'handler' => 'gsl_tools_handler_filter_taxonomy_term_multiple',
			),
	);
		
}