<?php
/**
 *  implement of template_propress_page()
 * * /
function zee_preprocess_page(&$variables){
  if(isset($variables['node']) && $variables['node']->type=='page') {
    
    switch ($variables['node']->field_template['und'][0]['value']) {
    
    }
  }
}
/**/

/**
 * implements of template_preprocess_region()
 *
 * @see region.tpl.php
 */
function zee_preprocess_region(&$variables, $hook) {
  global $theme;
  $regions = system_region_list($theme);
  $variables['attributes_array']['data-region'] = $regions[$variables['region']];

  if ($variables['region'] == 'content') {
    $variables['theme_hook_suggestions'][] = 'region__no_wrapper';
  }

  if ($variables['region'] == "sidebar_first") {
    $variables['classes_array'][] = '';
  }

  // $variables['attributes'] = drupal_attributes($variables['attributes_array']);
}
/**/

/**
 * implements of template_preprocess_node()
 * /
function zee_preprocess_node(&$variables){
  $node = $variables['node'];
  // on cible les nodes de types 'push'
  if($node->type == 'page') {
    $variables['test'] = 'test';
  }
}
/**/

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function zen_process_block(&$variables, $hook) {
  // Drupal 7 should use a $title variable instead of $block->subject.
  $variables['title'] = $variables['block']->subject;
}
