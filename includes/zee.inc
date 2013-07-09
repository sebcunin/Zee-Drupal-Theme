<?php
/**
 * A wrapper function for theme_get_settings().
 *
 * @param $name
 *   The name of the setting that you want to retrieve.
 * @param $default (optional)
 *   The name (key) of the theme that you want to fetch the
 *   setting for. Defaults to NULL.
 * @param $theme (optional)
 *   The key (machin-readable name) of a theme. Defaults to the key of the
 *   current theme if not defined.
 *
 * @see
 *   theme_get_setting().
 *
 * @see
 * 	  alpha_theme_get_setting
 */
function zee_theme_get_setting($name, $default = NULL, $theme = NULL) {
  $setting = theme_get_setting($name, $theme);

  return isset($setting) ? $setting : $default;
}