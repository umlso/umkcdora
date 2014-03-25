<?php

/**
 * @file
 * Admin/config form and friends.
 */

/**
 * Form building function.
 *
 * system_settings_form(), huzzah!
 */
function umkcdora_admin_form($form, &$form_state) {
  $form['umkcdora_date_metadata_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Date Metadata Field'),
    '#description' => t('The Solr field used to populate the "Date" field, in Islandora object displays.'),
    '#default_value' => variable_get('umkcdora_date_metadata_field', 'dc.date'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
