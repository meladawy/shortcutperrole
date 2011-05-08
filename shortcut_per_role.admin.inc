<?php
function shortcut_per_role_admin_form() {
$form['#tree'] = TRUE;
$roles=db_query( 'SELECT rid,name FROM {role}' )->fetchAllKeyed();
$sets = db_query ('SELECT * FROM {shortcut_set}')->fetchAllKeyed();
foreach ($roles as $rid => $role) {
 $role=  str_replace(' ', '_',$role);
  $form[$role]['title'] = array(
  
    '#markup' => '<h3 class="title">' . t('Assign Shortcuts for ' . $role . ' Role') . '</h3>');

  $form[$role]['shortcut_set'] = array(
  '#type' => 'select',
  '#default_value' => variable_get('shorcut_per_role_' . $role . '_set', $default='shortcut-set-1'),
  '#options' => $sets );}
$form['create_new_ss'] = array(
 '#markup' => '<h3 class="title">' . l(t('Add a shortcut set'), 'admin/config/user-interface/shortcut/add-set') . '</h3>');
  


  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Your configration'),
  );
  return $form;
}
/**
 * Submit handler for shortcut_per_role_admin().
 */
function shortcut_per_role_admin_form_submit($form, &$form_state) {
$roles=db_query( 'SELECT rid,name FROM {role}' )->fetchAllKeyed();
foreach ($roles as $rid => $role) {
$role=  str_replace(' ', '_',$role);
variable_set('shorcut_per_role_' . $role . '_set', $form_state['values'][$role]['shortcut_set']);
}
  drupal_set_message(t('Your Configration has been saved'));
}
