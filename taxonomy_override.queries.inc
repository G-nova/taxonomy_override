<?php

function _taxonomy_override_get_association_by_vid($vid) {
  $callback = &drupal_static(__FUNCTION__);
  if (!isset($callback)) {
    $query = db_query("SELECT tao.taoid, tao.vid, tao.callback_function
     FROM {taxonomy_override} tao
     WHERE tao.vid = '%s'
     LIMIT 1", array($vid));
    $callback = db_fetch_array($query);
  }
  return $callback;
}

/**
 *
 * Adds an association machine_name <=> callback in the database.
 *
 * @param $vid
 * @param $callback
 */
function _taxonomy_override_add_association($vid, $callback) {
  $toid = db_query("INSERT INTO {taxonomy_override} (vid, callback_function) VALUES ('%d', '%s')", array($vid, $callback));
  return $toid;
}

/**
 *
 * Updates an association by machine_name.
 *
 * @param $machine_name
 * @param $callback
 */
function _taxonomy_override_update_association($vid, $callback) {
  $updated = db_query("UPDATE {taxonomy_override} SET callback_function = '%s' WHERE vid = '%s'", array($callback, $vid));

  return $updated;
}

function _taxonomy_overide_delete_association_by_vid($vid) {
  $deleted = db_query("DELETE FROM {taxonomy_override} WHERE vid = '%s'", array($vid));
  return $deleted;
}
