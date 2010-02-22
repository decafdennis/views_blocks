<?php
// Developed by Dennis Stevense, naquah.net

function views_blocks_settings() {
  $options = array();
  for ($i = 0; $i < 50; $i++) {
    $options[$i] = $i;
  }
  
  $form = array();
  $blocks = views_blocks_list();
  foreach ($blocks as $delta => $block) {
    $form[$block['count_key']] = array(
      '#type' => 'select',
      '#title' => t('Number of blocks for %title', array('%title' => $block['view']->name . ': ' . $block['display']->display_title)),
      '#options' => $options,
      '#default_value' => variable_get($block['count_key'], 0),
    );
  }
  return system_settings_form($form);
}
