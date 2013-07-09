<?php
/**
 * Upgrade jQuery
 */
function adpi_bootstrap_js_alter(&$js) {
  /**/
  $path = drupal_get_path('theme', 'adpi_bootstrap') . '/js/libs/jquery.min.js';

  // Copy the current jQuery file settings and change
  $js[$path] = $js['misc/jquery.js'];

  // Update necessary settings
  $js[$path]['version'] = 1.9;
  $js[$path]['data'] = $path;

  // Finally remove the original jQuery
  unset($js['misc/jquery.js']);
  /**/
}
/**/