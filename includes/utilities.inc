<?php

/**
 * @file
 * Utility functions for the UMKCdora module.
 */
function umkcdora_construct_required_objects() {
  $connection = islandora_get_tuque_connection();
  $content_models = umkcdora_retrieve_content_model_mappings();
  $required_objects = array();
  foreach ($content_models as $pid => $values) {
    $content_model_object = $connection->repository->constructObject($pid);
    $content_model_object->owner = 'fedoraAdmin';
    $content_model_object->label = $values['label'];
    $content_model_object->models = 'fedora-system:ContentModel-3.0';
    $required_objects[] = $content_model_object;
  }
  return $required_objects;
}

/**
 * Retrieves the UMKC to Islandora content model mappings.
 *
 * This is used in constructing the required objects, as well as for use in
 * other places. Any additional content models should be added here.
 *
 * @return array
 *   The mapped array of UMKC content models to Islandora content models.
 */
function umkcdora_retrieve_content_model_mappings() {
  $content_models = array(
    'umkc:bookCModel' => array(
      'label' => t('UMKC Book Content Model'),
      'mappings' => array('islandora:bookCModel'),
    ),
    'umkc:graphicsCModel' => array(
      'label' => t('UMKC Graphics Content Model'),
      'mappings' => array('islandora:sp_large_image_cmodel'),
    ),
    'umkc:manuscripts' => array(
      'label' => t('UMKC Manuscripts Content Model'),
      'mappings' => array(
        'islandora:sp_large_image_cmodel',
        'islandora:bookCModel',
      ),
    ),
    'umkc:mapsandatlasesCModel' => array(
      'label' => t('UMKC Maps and Atlases Content Model'),
      'mappings' => array(
        'islandora:sp_large_image_cmodel',
        'islandora:bookCModel',
      ),
    ),
    'umkc:newslettersCModel' => array(
      'label' => t('UMKC Newsletters Content Model'),
      'mappings' => array('islandora:newspaperCModel'),
    ),
    'umkc:newspapersCModel' => array(
      'label' => t('UMKC Newspapers Content Model'),
      'mappings' => array('islandora:newspaperCModel'),
    ),
    'umkc:pamphletsCModel' => array(
      'label' => t('UMKC Pamphlets Content Model'),
      'mappings' => array('islandora:bookCModel'),
    ),
    'umkc:photographsCModel' => array(
      'label' => t('UMKC Photographs Content Model'),
      'mappings' => array('islandora:sp_large_image_cmodel'),
    ),
    'umkc:postersCModel' => array(
      'label' => t('UMKC Posters Content Model'),
      'mappings' => array('islandora:sp_large_image_cmodel'),
    ),
    'umkc:scrapbooksCModel' => array(
      'label' => t('UMKC Scrapbooks Content Model'),
      'mappings' => array('islandora:bookCModel'),
    ),
    'umkc:sheetmusicCModel' => array(
      'label' => t('UMKC Sheet Music Content Model'),
      'mappings' => array('islandora:bookCModel'),
    ),
    'umkc:soundCModel' => array(
      'label' => t('UMKC Sound Recordings Content Model'),
      'mappings' => array('islandora:sp-audioCModel'),
    ),
    'umkc:videoCModel' => array(
      'label' => t('UMKC Video Recordings Content Model'),
      'mappings' => array('islandora:sp_videoCModel'),
    ),
    'umkc:yearbooksCModel' => array(
      'label' => t('UMKC Yearbooks Content Model'),
      'mappings' => array('islandora:bookCModel'),
    ),
  );
  return $content_models;
}

/**
 * Retrieves all the XML form builder for UMKC's custom content model.
 */
function umckdora_retrieve_xml_form_builder_forms() {
  $module_path = drupal_get_path('module', 'umkcdora');
}

/**
 * Retrieves all the form associations for UMKC's custom content model.
 */
function umkcdora_retrieve_xml_form_builder_form_associations() {

}
