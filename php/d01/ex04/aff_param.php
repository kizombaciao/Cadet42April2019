#!/usr/bin/php
<?php
    $i = 1;
    while ($i < $argc)
    {
        echo $argv[$i]."\n";
        $i++;
    }
/*
    for ($i = 1; $i < $argc; i++)
    {
        echo $argv[$i]."\n";        
    }
*/
?>