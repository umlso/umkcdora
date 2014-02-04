<?php

/**
 * @file
 * Misc implementations of theme hooks.
 */

/**
 * Prepares variables for umkcdora_collection_info templates.
 *
 * Default template: umkcdora-collection-info.tpl.php
 *
 * @param array $variables
 *   An associative array containing:
 *   - islandora_object: The AbstractObject for which to render collection
 *     info.
 */
function template_preprocess_umkcdora_collection_info(array &$variables) {
  module_load_include('inc', 'islandora', 'includes/utilities');
  $variables['parent_collections'] = islandora_get_parents_from_rels_ext($variables['islandora_object']);
}
