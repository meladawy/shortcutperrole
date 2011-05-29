<?php

/**
 * @file
 * Admin page callbacks for the Shortcut per Role module.
 */
 
/**
 * Process callback for the admin page
 *
 * @return form
 */
function shortcut_per_role_admin_form() {
  $roles = db_query( 'SELECT rid,name FROM {role}' )->fetchAllKeyed();
  $sets = db_query('SELECT set_name, title FROM {shortcut_set}')->fetchAllKeyed();
  
  $form['title'] = array(
      '#markup' => '<h3 class="title">' . t('Assign Shortcuts for  Role:') . '</h3>',
    );

  foreach ($roles as $rid => $role) {
  $role= str_replace(' ', '_', $role);
    $form['shorcut_per_role_' . $role . '_set'] = array(
      '#type' => 'select',
      '#default_value' => variable_get('shorcut_per_role_' . $role . '_set', $default = 'shortcut-set-1'),
      '#options' => $sets,
      '#prefix' => '<b>'. $role . '</b>' ,
    );
  }
  
  $form['create_new_ss'] = array(
    '#markup' => '<h3 class="title">' . l(t('Add a shortcut set'), 'admin/config/user-interface/shortcut/add-set') . '</h3>',
  );
 
 return system_settings_form($form);
}
