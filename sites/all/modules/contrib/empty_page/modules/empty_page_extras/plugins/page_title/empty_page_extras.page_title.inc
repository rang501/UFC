<?php

/**
 * Implementats hook_page_title_pattern_alter().
 */
function empty_page_extras_page_title_pattern_alter(&$pattern, &$types) {
  $menu_item = menu_get_item();
  // Check that we're on an empty callback page.
  $callbacks = empty_page_get_callbacks();
  foreach ($callbacks as $cid => $callback) {
    if ($menu_item['path'] == $callback->path) {
      $pattern = variable_get('page_title_empty_page_' . $cid, '');
      break;
    }
  }
}

/**
 * Implements hook_page_title_settings().
 */
function empty_page_extras_page_title_settings() {
  $settings = array();

  // Add each empty page callback to the "Page Title" settings form.
  $callbacks = empty_page_get_callbacks();
  foreach ($callbacks as $cid => $callback) {
     $label_args = empty($callback->page_title) ? '[no title]' : $callback->page_title;
     $settings['page_title_empty_page_' . $cid] = array(
      'label'                 => 'Empty Page Callback - %title',
      'label arguments'       => array('%title' => $label_args),
      'description'           => 'This pattern will be used for /%path',
      'description arguments' => array('%path' => $callback->path),
      'scopes'                => array('global'),
    );
  }

  return $settings;
}

