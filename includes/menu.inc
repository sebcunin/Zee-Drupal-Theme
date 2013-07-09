<?php
/**
 * Returns HTML for primary and secondary local tasks.
 */
function zee_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<ul class="drupal-tasks drupal-tasks--primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<ul class="drupal-tasks drupal-tasks--secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Bootstrap theme wrapper function for the primary menu links
 */
function zee_menu_tree__primary(&$variables) {
  // No <ul>
  return $variables['tree'];
}

function zee_menu_tree(&$variables) {
  return '<ul class="">' . $variables['tree'] . '</ul>';
}

function zee_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Ad our own wrapper
    unset($element['#below']['#theme_wrappers']);
    /* ADPI CUSTOM * /
    $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
    /**/
    $sub_menu = '<ul class="sub-menu">' . drupal_render($element['#below']) . '</ul>';
    /* ADPI CUSTOM * /
    $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
    $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    /**/

    // Check if this element is nested within another
    if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
      // Generate as dropdown submenu
      /* ADPI CUSTOM * /
      $element['#attributes']['class'][] = 'dropdown-submenu';
      /**/
    }
    else {
      // Generate as standard dropdown
      /* ADPI CUSTOM * /
      $element['#attributes']['class'][] = 'dropdown';
      /**/
      $element['#localized_options']['html'] = TRUE;
      $element['#title'] .= '<span class="caret"></span>';
    }

    // Set dropdown trigger element to # to prevent inadvertant page loading with submenu click
    $element['#localized_options']['attributes']['data-target'] = '#';
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}