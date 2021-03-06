<?php

use diversen\cli\common;
function reload_site ($options) {
    common::needRoot();
    $command ="./coscli.sh db --load-db-file";
    common::execCommand($command, $options);
    
    $command ="./coscli.sh backup --public-restore";
    common::execCommand($command, $options);
}
    
self::setCommand('reload', array(
    'description' => "Wrapper command used for reloading site with latest public files and sql backup ",
));

self::setOption('reload_site', array(
    'long_name'   => '--reload',
    'description' => 'Command for reloading site files',
    'action'      => 'StoreTrue'
));