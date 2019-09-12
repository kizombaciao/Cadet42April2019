#!/usr/bin/php
<?php
    if ($argc > 1)
    {
        $arr = array_values(array_filter(explode(' ', $argv[1])));
        $arr[count($arr)] = $arr[0];
        unset($arr[0]);
        $res = "";
        foreach($arr as $w)
            $res .= $w." ";
        echo trim($res)."\n";
    }
/*
array_values() simply removes the keys if any and reindexes using 0, 1, .. 
array_filter() removes any 0 or false elements in the string.
trim() is needed to remove the space after the last word
*/
?>