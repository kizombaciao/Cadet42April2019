#!/usr/bin/php
<?php
    $array = array();
    unset($argv[0]);
    foreach($argv as $s)
    {
        $w = array_filter(explode(' ', $s));
        foreach ($w as $s2)
        {
            $array[] = $s2;
        }
    }
    sort($array);
    foreach ($array as $s)
        echo $s."\n";
/*
// unset
https://www.geeksforgeeks.org/how-to-delete-an-array-element-based-on-key-in-php/
*/
?>
