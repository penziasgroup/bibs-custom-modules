<?php
/**
 * @file
 * campus_location_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function campus_location_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'campus_locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campus Locations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campus Locations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_cl_image']['id'] = 'field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['table'] = 'field_data_field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['field'] = 'field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cl_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_cl_address']['id'] = 'field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['table'] = 'field_data_field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['field'] = 'field_cl_address';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_cl_address_1']['id'] = 'field_cl_address_1';
  $handler->display->display_options['fields']['field_cl_address_1']['table'] = 'field_data_field_cl_address';
  $handler->display->display_options['fields']['field_cl_address_1']['field'] = 'field_cl_address';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_cl_location']['id'] = 'field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['table'] = 'field_data_field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['field'] = 'field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['click_sort_column'] = 'lat';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campus_location' => 'campus_location',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'campus-locations';

  /* Display: Campus Locations Block */
  $handler = $view->new_display('block', 'Campus Locations Block', 'block_campus_locations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="#" data-nid="[nid]" class="show-location-info-link">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_cl_image']['id'] = 'field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['table'] = 'field_data_field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['field'] = 'field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cl_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cl_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_cl_address']['id'] = 'field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['table'] = 'field_data_field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['field'] = 'field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['exclude'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_cl_location']['id'] = 'field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['table'] = 'field_data_field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['field'] = 'field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cl_location']['click_sort_column'] = 'lat';
  $handler->display->display_options['block_description'] = 'Campus Locations Block';

  /* Display: Campus Locations Data */
  $handler = $view->new_display('page', 'Campus Locations Data', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 1;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_cl_image']['id'] = 'field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['table'] = 'field_data_field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['field'] = 'field_cl_image';
  $handler->display->display_options['fields']['field_cl_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_cl_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cl_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_cl_location']['id'] = 'field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['table'] = 'field_data_field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['field'] = 'field_cl_location';
  $handler->display->display_options['fields']['field_cl_location']['label'] = 'latitude';
  $handler->display->display_options['fields']['field_cl_location']['click_sort_column'] = 'lat';
  $handler->display->display_options['fields']['field_cl_location']['type'] = 'geolocation_latitude';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_cl_location_1']['id'] = 'field_cl_location_1';
  $handler->display->display_options['fields']['field_cl_location_1']['table'] = 'field_data_field_cl_location';
  $handler->display->display_options['fields']['field_cl_location_1']['field'] = 'field_cl_location';
  $handler->display->display_options['fields']['field_cl_location_1']['label'] = 'longitude';
  $handler->display->display_options['fields']['field_cl_location_1']['click_sort_column'] = 'lat';
  $handler->display->display_options['fields']['field_cl_location_1']['type'] = 'geolocation_longitude';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_cl_address']['id'] = 'field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['table'] = 'field_data_field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['field'] = 'field_cl_address';
  $handler->display->display_options['fields']['field_cl_address']['label'] = 'address';
  $handler->display->display_options['path'] = 'campus-locations-data';
  $export['campus_locations'] = $view;

  return $export;
}
