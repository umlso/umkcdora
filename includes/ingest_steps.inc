<?php
/**
 * @file
 * Houses the ingest step functionality for the UMKCdora module.
 */

/**
 * Adds UMKC's additional content model to the object being ingested.
 *
 * @param array $form_state
 *   An array representing the Drupal form state.
 */
function umkcdora_add_content_model(&$form_state) {
  dsm('add content model');
  dsm($form_state);
}

/**
 * Removes UMKC's additional content model from the object being ingested.
 *
 * @param array $form_state
 *   An array representing the Drupal form state.
 */
function umkcdora_remove_content_model(&$form_state) {

}

function umkcdora_select_additional_content_model_form($form, $form_state) {
  $form = array();
  $options = array();
  foreach ($form_state['umkc']['mappings'] as $model) {
    $object = islandora_object_load($model);
    $options[$model] = $object->label;
  }
  dsm($form_state);
  dsm($form_state['umkc']['selected'], 'selected');
  $model = isset($form_state['umkc']['selected']) ? $form_state['umkc']['selected'] : key($options);
  $form['models'] = array(
    '#type' => 'select',
    '#title' => t('Select a Content Model to Ingest'),
    '#options' => $options,
    '#default_value' => $model,
  );
  return $form;
}

function umkcdora_select_additional_content_model_form_submit($form, &$form_state) {
  $form_state['umkc']['selected'] = $form_state['values']['models'];
}