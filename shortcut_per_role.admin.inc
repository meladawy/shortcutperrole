<?php
function shortcut_per_role_admin($form, &$form_state) {
$roles=db_query( 'SELECT name FROM {role}' )->fetchCol();
$sets = shortcut_sets();
foreach ($sets as $name => $set) {
    $options[$name] = $set;
  }

return $form;
}
