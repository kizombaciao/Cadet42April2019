#!/usr/bin/php
<?php
    if ($argc != 2) 
    {
        echo "Incorrect Number of Parameters.\n";
        exit();
    }
    $tmp = str_replace(" ", "", $argv[1]);
    $n1 = intval($tmp);
    $op = substr(substr($tmp, strlen((string)$n1)), 0, 1);
    $n2 = substr(substr($tmp, strlen((string)$n1)), 1);
    if (!is_numeric($n1) || !is_numeric($n2))
    {
        echo "Syntax Error\n";
        exit();
    }
    switch ($op)
    {
        case ("+") :
            echo $n1 + $n2;
            break;
        case ("-") :
            echo $n1 - $n2;
            break;
        case ("*") :
            echo $n1 * $n2;
            break;
        case ("/") :
            echo $n1 / $n2;
            break;
        case ("%") :
            echo $n1 % $n2;
            break;
        default:
            echo "Syntax Error\n";
            exit();
    }
    echo "\n";
/*
trim() set to remove spaces and tabs.
*/
/*
https://www.w3schools.com/php/func_string_str_replace.asp
*/
/*
substr(string_name, start_pos, length_to_cut) 
The substr() function used to cut a part of a string from a string, 
starting at a specified position.
*/
?>
