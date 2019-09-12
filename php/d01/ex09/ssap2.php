#!/usr/bin/php
<?php

function concat_args($argv, $argc)
{
    $s = "";
    for ($i = 1; $i < $argc; $i++)
        $s .= " ".$argv[$i]." ";
    return $s;
}

// replace this with array_filter and explode ???
// are there some characters we don't want the above to remove ???
function clean_string($s)
{
    $tmp = trim($s);
    while ((strpos($tmp, "  ")) == true)
        $tmp = str_replace("  ", " ", $tmp);
    return $tmp;
}

function usort2($a, $b)
{
    $la = strtolower($a);
    $lb = strtolower($b);

    $idx = "abcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~";

    for ($i = 0; $i < strlen($a) || $i < strlen($b); $i++)
    {
        $posa = strpos($idx, $la[$i]);
        $posb = strpos($idx, $lb[$i]);
        if ($posa < $posb)
            return -1;
        else if ($posa > $posb)
            return 1;
    }
}
if ($argc >= 2)
{
    //echo $argc."\n";
    $s = concat_args($argv, $argc);
    //echo $s."\n";
    $s = clean_string($s);
    $s2 = explode(" ", $s);
    usort($s2, 'usort2');
    foreach ($s2 as $w)
        echo "$w\n";
}

/*
https://www.w3schools.com/php/func_string_strpos.asp
https://www.geeksforgeeks.org/php-strpos-stripos-functions/
// The strpos() function finds 
the position number of the first occurrence 
of a string inside another string.
*/
/*
https://www.w3schools.com/php/func_string_str_replace.asp
https://www.geeksforgeeks.org/php-str_replace-function/
// Replace the characters "world" in the string "Hello world!" with "Peter":
str_replace("world","Peter","Hello world!");

*/

?>
