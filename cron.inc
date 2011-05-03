<?php


function reload_site_cron (){
    $latest = _get_latest();
    if (!$latest){
        cos_cli_abort("Cron failed in module reload_site: No sql file found in backup/sql");
        return 1;
    }
    $latest = "backup/sql/" . $latest . ".sql";
    $file = $latest;

    $db = get_db_info();
    $options = array();
    $options['silence'] = 1;

    $command =
        "mysql -u" . register::$vars['coscms_main']['username'] .
        " -p" . register::$vars['coscms_main']['password'] . " $db[name] < $file";
    return $ret = cos_exec($command, $options);
}
