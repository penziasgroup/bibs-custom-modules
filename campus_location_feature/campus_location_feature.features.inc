<?php
/**
 * @file
 * campus_location_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function campus_location_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function campus_location_feature_node_info() {
  $items = array(
    'campus_location' => array(
      'name' => t('Campus Location'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
