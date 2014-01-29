<?php
/**
 * @file
 * Houses the ingest step functionality for the UMKCdora module.
 */

/**
 * Adds UMKC's additional content model to the object being ingested.
 *
 * @param array $form_state
 *   An array containing the Drupal form state.
 */
function umkcdora_add_content_model(&$form_state) {
  if (isset($form_state['umkc']['selected'])) {
    $model = $form_state['umkc']['selected'];
  }
  else {
    $model = reset($form_state['umkc']['mappings']);
  }
  $form_state['umkc']['added_content_model'] = $model;
  // Go add the new model to all the objects.
  $objects = &islandora_ingest_form_get_objects($form_state);
  $shared_storage = &islandora_ingest_form_get_shared_storage($form_state);
  $shared_storage['models'][] = $model;
  foreach ($objects as $object) {
    $object_models = $object->models;
    $object_models[] = $model;
    $object->models = $object_models;
  }
}

/**
 * Removes UMKC's additional content model from the object being ingested.
 *
 * @param array $form_state
 *   An array representing the Drupal form state.
 */
function umkcdora_remove_content_model(&$form_state) {
  $objects = &islandora_ingest_form_get_objects($form_state);
  foreach ($objects as $object) {
    $object->relationships->remove(FEDORA_MODEL_URI, 'hasModel', $form_state['umkc']['added_content_model']);
  }
  $shared_storage = &islandora_ingest_form_get_shared_storage($form_state);
  $current_models = array_flip($shared_storage['models']);
  unset($current_models[$form_state['umkc']['added_content_model']]);
  $shared_storage['models'] = array_flip($current_models);
  unset($form_state['umkc']['added_content_model']);
}

/**
 * Select a content model form if there is more than one mapping for the object.
 *
 * @param array $form
 *   An array representing a form within Drupal.
 * @param array $form_state
 *   An array containing the Drupal form state.
 *
 * @return array
 *   An array containing the renderable form.
 */
function umkcdora_select_additional_content_model_form($form, $form_state) {
  $form = array();
  $options = array();
  foreach ($form_state['umkc']['mappings'] as $model) {
    $object = islandora_object_load($model);
    $options[$model] = $object->label;
  }
  $model = isset($form_state['umkc']['selected']) ? $form_state['umkc']['selected'] : key($options);
  $form['models'] = array(
    '#type' => 'select',
    '#title' => t('What type of Islandora content model is the object?'),
    '#options' => $options,
    '#default_value' => $model,
  );
  return $form;
}

/**
 * Submit handler for the content model selection form.
 *
 * @param array $form
 *   An array representing a form within Drupal.
 * @param array $form_state
 *   An array containing the Drupal form state.
 */
function umkcdora_select_additional_content_model_form_submit($form, &$form_state) {
  $form_state['umkc']['selected'] = $form_state['values']['models'];
}
