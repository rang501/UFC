<?php

/**
 * Implements hook_views_default_views().
 */
function statistics_views_default_views() {
  $views = array();

  $files = file_scan_directory(drupal_get_path('module', 'statistics'). '/views', '/.*\.view$/');

  foreach ($files as $filepath => $file) {
    require_once $filepath;

    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }

  return $views;
}
