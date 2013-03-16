<?php

function reload_site ($options) {
    cos_needs_root();
    $command ="./coscli.sh db --load-db-file";
    cos_exec($command, $options);
    
    $command ="./coscli.sh backup --public-restore";
    cos_exec($command, $options);
}
    
mainCli::setCommand('reload', array(
    'description' => "Reload site with latest files and sql backup ",
));

mainCli::setOption('reload_site', array(
    'long_name'   => '--reload',
    'description' => 'Command for reloading site files',
    'action'      => 'StoreTrue'
));