<?php

/**
 * @file
 * Documents Block reference's hooks for api reference.
 */

/**
 * Alter the potential references.
 *
 * DEPRECATED in favor of hook_blockreference_potential_references2_alter().
 *
 * @param $references
 *  The references array to be modified.
 * @param $field
 *  Array containing field data.
 * @param $return_full_blocks
 *  Whether to return full blocks.
 * @param $string
 *  Filter string to match blocks.
 * @param $exact_string
 *  Strictly match string like for validation.
 */
function hook_blockreference_potential_references_alter(&$references, $field, $current_bids = array()) {
  // no example code
}

/**
 * Alter the potential references.
 *
 * @param $blocks
 *  List of referenceable blocks. Always keyed by bid. Might
 *  contain full block objects or only block titles, depending
 *  on `$context['return_full_blocks']`.
 * @param $context
 *  Assoc array containing:
 *  - field: Array: Array containing field data from field_info_field().
 *  - current_bids: Array: current field values.
 *  - return_full_blocks: Bool: Whether to return full blocks.
 *  - string: String: Filter string to match blocks.
 *  - exact_string: Bool: Strictly match string like for validation.
 */
function hook_blockreference_potential_references2_alter(&$blocks, $context) {
  $secret_bid = db_query('SELECT bid FROM {block} WHERE module = ? AND delta = ?', array('foo', 'bar'))->fetchField();
  unset($blocks[$secret_bid]);
}
