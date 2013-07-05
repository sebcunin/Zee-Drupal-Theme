<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?><!doctype html>
<html lang="<?php print $language->language; ?>" class="no-js <?php print $classes; ?>">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php $theme_path = path_to_theme(); ?>
  <!-- TEMP MERCI DRUPAL ! -->
  <link rel="stylesheet" href="/<?php print $theme_path; ?>/css/screen.css?<?php print uniqid(); ?>" media="all"/>
  <link rel="stylesheet" href="/<?php print $theme_path; ?>/css/print.css?<?php print uniqid(); ?>" media="print"/>

  <script src="/<?php print $theme_path; ?>/js/libs/respond.min.js?<?php print uniqid(); ?>"></script>
  <script src="/<?php print $theme_path; ?>/js/libs/raisingthebar.js?<?php print uniqid(); ?>"></script>
  <?php print $scripts; ?>

  <script type="text/javascript">
  /* Fonts.com */
  var MTIProjectId='f7891e64-234d-415a-bddc-0e4676ac24e0';
   (function() {
          var mtiTracking = document.createElement('script');
          mtiTracking.type='text/javascript';
          mtiTracking.async='true';
          mtiTracking.src=('https:'==document.location.protocol?'https:':'http:')+'//fast.fonts.com/t/trackingCode.js';
          (document.getElementsByTagName('head')[0]||document.getElementsByTagName('body')[0]).appendChild( mtiTracking );
     })();
  </script>
</head>
<body class="" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
 
  <script src="/<?php print $theme_path; ?>/js/libs/require.min.js?<?php print uniqid(); ?>"></script>
  <script>
  (function() {
    var config = {
      baseUrl: '/<?php print $theme_path; ?>/js/',
      urlArgs: 'bust=' +  (new Date()).getTime()
    };
    define('config', config);
    require.config(config);
    require(['main']);
  })();

  </script>
</body>
</html>