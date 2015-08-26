<?php

/**
 * @file
 * Utility functions for the UMKCdora module.
 */

/**
 * Utility function that builds up the required objects for the UMKCdora module.
 *
 * @see hook_islandora_required_objects()
 *
 * @return array
 *   An array containing all of the required objects for the UMKCdora module.
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
 * other places. Any additional content models should be added here. The
 * structure is that of content model pid => array of values. The values array
 * contains:
 *   -label: A string that will be when constructing the content model object.
 *   -mappings: An array defining what the origin content models can be for
 *   this particular UMKC content model.
 *   -form: An array defining the form for the UMKC content model laid out in
 *   the structure expected by hook_islandora_xml_form_builder_forms().
 *   -association: An array defining the form association for the UMKC content
 *   model laid out in the structure expected by
 *   hook_islandora_xml_form_builder_form_associations().
 *
 * @return array
 *   The mapped array of UMKC content models to Islandora content models.
 */
function umkcdora_retrieve_content_model_mappings() {
  $module_path = drupal_get_path('module', 'umkcdora');
  $content_models = array(
    'umkc:bookCModel' => array(
      'label' => t('UMKC Book Content Model'),
      'mappings' => array('islandora:bookCModel' => 'islandora:bookCModel'),
      'form' => array(
        'UMKC Book Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_book_association' => array(
          'content_model' => 'umkc:bookCModel',
          'form_name' => 'UMKC Book Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:graphicsCModel' => array(
      'label' => t('UMKC Graphics Content Model'),
      'mappings' => array('islandora:sp_large_image_cmodel' => 'islandora:sp_large_image_cmodel'),
      'form' => array(
        'UMKC Graphics Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_graphics_association' => array(
          'content_model' => 'umkc:graphicsCModel',
          'form_name' => 'UMKC Graphics Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:manuscriptsCModel' => array(
      'label' => t('UMKC Manuscripts Content Model'),
      'mappings' => array(
        'islandora:sp_large_image_cmodel' => 'islandora:sp_large_image_cmodel',
        'islandora:bookCModel' => 'islandora:bookCModel',
      ),
      'form' => array(
        'UMKC Manuscripts Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_manuscripts_association' => array(
          'content_model' => 'umkc:manuscriptsCModel',
          'form_name' => 'UMKC Manuscripts Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:mapsandatlasesCModel' => array(
      'label' => t('UMKC Maps and Atlases Content Model'),
      'mappings' => array(
        'islandora:sp_large_image_cmodel' => 'islandora:sp_large_image_cmodel',
        'islandora:bookCModel' => 'islandora:bookCModel',
      ),
      'form' => array(
        'UMKC Maps and Atlases Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_maps_and_atlases_association' => array(
          'content_model' => 'umkc:mapsandatlasesCModel',
          'form_name' => 'UMKC Maps and Atlases Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:newslettersCModel' => array(
      'label' => t('UMKC Newsletters Content Model'),
      'mappings' => array('islandora:newspaperCModel' => 'islandora:newspaperCModel'),
      'form' => array(
        'UMKC Newsletters Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_newsletters_association' => array(
          'content_model' => 'umkc:newslettersCModel',
          'form_name' => 'UMKC Newsletters Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:newspapersCModel' => array(
      'label' => t('UMKC Newspapers Content Model'),
      'mappings' => array('islandora:newspaperCModel' => 'islandora:newspaperCModel'),
      'form' => array(
        'UMKC Newspapers Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_newspapers_association' => array(
          'content_model' => 'umkc:newspapersCModel',
          'form_name' => 'UMKC Newspapers Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:pamphletsCModel' => array(
      'label' => t('UMKC Pamphlets Content Model'),
      'mappings' => array('islandora:bookCModel' => 'islandora:bookCModel'),
      'form' => array(
        'UMKC Pamphlets Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_pamphlets_association' => array(
          'content_model' => 'umkc:pamphletsCModel',
          'form_name' => 'UMKC Pamphlets Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:photographsCModel' => array(
      'label' => t('UMKC Photographs Content Model'),
      'mappings' => array('islandora:sp_large_image_cmodel' => 'islandora:sp_large_image_cmodel'),
      'form' => array(
        'UMKC Photographs Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_photographs_association' => array(
          'content_model' => 'umkc:photographsCModel',
          'form_name' => 'UMKC Photographs Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:postersCModel' => array(
      'label' => t('UMKC Posters Content Model'),
      'mappings' => array('islandora:sp_large_image_cmodel' => 'islandora:sp_large_image_cmodel'),
      'form' => array(
        'UMKC Posters Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_posters_association' => array(
          'content_model' => 'umkc:postersCModel',
          'form_name' => 'UMKC Posters Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:scrapbooksCModel' => array(
      'label' => t('UMKC Scrapbooks Content Model'),
      'mappings' => array('islandora:bookCModel' => 'islandora:bookCModel'),
      'form' => array(
        'UMKC Scrapbooks Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_scrapbooks_association' => array(
          'content_model' => 'umkc:scrapbooksCModel',
          'form_name' => 'UMKC Scrapbooks Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:sheetmusicCModel' => array(
      'label' => t('UMKC Sheet Music Content Model'),
      'mappings' => array('islandora:bookCModel' => 'islandora:bookCModel'),
      'form' => array(
        'UMKC Sheet Music Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_sheet_music_association' => array(
          'content_model' => 'umkc:sheetmusicCModel',
          'form_name' => 'UMKC Sheet Music Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:soundCModel' => array(
      'label' => t('UMKC Sound Recordings Content Model'),
      'mappings' => array('islandora:sp-audioCModel' => 'islandora:sp-audioCModel'),
      'form' => array(
        'UMKC Sound Recordings Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_sound_recordings_association' => array(
          'content_model' => 'umkc:soundCModel',
          'form_name' => 'UMKC Sound Recordings Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:videoCModel' => array(
      'label' => t('UMKC Video Recordings Content Model'),
      'mappings' => array('islandora:sp_videoCModel' => 'islandora:sp_videoCModel'),
      'form' => array(
        'UMKC Video Recordings Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_video_recordings_association' => array(
          'content_model' => 'umkc:videoCModel',
          'form_name' => 'UMKC Video Recordings Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
    'umkc:yearbooksCModel' => array(
      'label' => t('UMKC Yearbooks Content Model'),
      'mappings' => array('islandora:bookCModel' => 'islandora:bookCModel'),
      'form' => array(
        'UMKC Yearbooks Form' => array(
          'form_file' => "$module_path/xml/placeholder_form.xml",
        ),
      ),
      'association' => array(
        'umkc_yearbooks_association' => array(
          'content_model' => 'umkc:yearbooksCModel',
          'form_name' => 'UMKC Yearbooks Form',
          'dsid' => 'MODS',
          'title_field' => array('titleInfo', 'title'),
          'transform' => 'mods_to_dc.xsl',
          'self_transform' => 'cleanup_mods.xsl',
          'template' => FALSE,
        ),
      ),
    ),
  );
  return $content_models;
}

/**
 * Retrieves all the XML form builder for UMKC's custom content model.
 */
function umkcdora_retrieve_xml_form_builder_forms() {
  $content_models = umkcdora_retrieve_content_model_mappings();
  $xml_forms = array();
  foreach ($content_models as $content_model) {
    $key = key($content_model['form']);
    $xml_forms[$key] = $content_model['form'][$key];
  }
  return $xml_forms;
}

/**
 * Retrieves all the form associations for UMKC's custom content model.
 */
function umkcdora_retrieve_xml_form_builder_form_associations() {
  $content_models = umkcdora_retrieve_content_model_mappings();
  $form_associations = array();
  foreach ($content_models as $content_model) {
    $key = key($content_model['association']);
    $form_associations[$key] = $content_model['association'][$key];
  }
  return $form_associations;
}

/**
 * Parses the object from the current URL and returns a content model array.
 *
 * @return array
 *   The content model array, minus the FedoraObject content model.
 */
function umkcdora_get_models_from_url() {
  // Get the PID.
  if (arg(0) == 'umkc') {
    $pid = arg(3);
  }
  else {
    $pid = arg(2);
  }
  // Query for the models. Otherwise, we would need to load the object, which
  // we can't, since we may be unauthorized by the time we get here.
  $query = <<<QUERY
SELECT ?model
FROM <#ri>
WHERE {
  <info:fedora/$pid> <fedora-model:hasModel> ?model
}
QUERY;
  $connection = islandora_get_tuque_connection();
  $results = $connection->repository->ri->sparqlQuery($query);
  // Populate an array with the model PIDs.
  $models = array();
  foreach ($results as $result) {
    if ($result['model']['value'] !== "fedora-system:FedoraObject-3.0") {
      $models[] = $result['model']['value'];
    }
  }
  return $models;
}

/**
 * Returns an appropriate message per-content-model when access is restricted.
 *
 * @param array $models
 *   The array of content models for the object.
 *
 * @return string
 *   The appropriate t()-vetted string to display.
 */
function umkcdora_get_access_denied_message(array $models) {
  // Content model mappings.
  $text_image = array(
    'umkc:graphicsCModel',
    'umkc:manuscriptsCModel',
    'umkc:photographsCModel',
    'umkc:postersCModel',
    'umkc:bookCModel',
    'umkc:mapsandatlasesCModel',
    'umkc:newslettersCModel',
    'umkc:newspapersCModel',
    'umkc:pamhletsCModel',
    'umkc:scrapbooksCModel',
    'umkc:yearbooksCModel',
  );
  $audiovisual = array(
    'umkc:soundCModel',
    'umkc:videoCModel',
  );

  // Image message.
  if (array_intersect($models, $text_image)) {
    return t("This material is restricted due to copyright and is unavailable for viewing online. If you would like a copy for personal research and study, please visit <a href='@href'>@href</a>.", array(
      '@href' => "http://library.umkc.edu/spec-col-about/services",
    ));
  }
  // Audiovisual content message.
  elseif (array_intersect($models, $audiovisual)) {
    return t("This material is restricted due to copyright and is unavailable for listening or viewing online. If you would like a copy for personal research and study, please visit <a href='@href'>@href</a>.", array(
      '@href' => "http://library.umkc.edu/marr-services",
    ));
  }
  // Otherwise, return a generic message.
  else {
    return t("You are not authorized to view this page.");
  }
}

/**
 * Helper function to map objects to their values to be used in templates.
 *
 * @see islandora_objects_object_mapper().
 */
function umkcdora_objects_object_mapper($object_id) {
  $o = islandora_object_load($object_id);
  $module_path = drupal_get_path('module', 'islandora');
  $url = "islandora/object/{$object_id}";
  $img = array(
    '#theme' => 'image',
    '#path' => ($o && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $o['TN']) ?
      "$url/datastream/TN/view" :
      "$module_path/images/folder.png"),
    '#attributes' => array(),
  );
  $img = drupal_render($img);
  if ($o) {
    $link_options = array('html' => TRUE, 'attributes' => array('title' => $o->label));
    $description = NULL;
    if (isset($o['DC']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $o['DC'])) {
      $dc = DublinCore::importFromXMLString($o['DC']->content);
      if ($dc) {
        $dc = $dc->asArray();
        $description = $dc['dc:description']['value'];
      }
    }
    return array(
      'label' => $o->label,
      'class' => drupal_strtolower(preg_replace('/[^A-Za-z0-9]/', '-', $o->id)),
      'link' => l($o->label, $url, $link_options),
      'thumb' => l($img, $url, $link_options),
      'description' => $description,
    );
  }
  else {
    $link_options = array('html' => TRUE, 'attributes' => array('title' => t('(Copyright-Restricted Material)')));
    return array(
      'label' => t('(Copyright-Restricted Material)'),
      'class' => drupal_strtolower(preg_replace('/[^A-Za-z0-9]/', '-', $object_id)),
      'link' => l(t('(Copyright-Restricted Material)'), $url, $link_options),
      'thumb' => '',
      'description' => '',
    );
  }
}
