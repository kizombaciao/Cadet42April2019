#!/usr/bin/php
<?php
    while (1)
    {
        echo "Enter a number:  ";
        $line = trim(fgets(stdin));
        //if (!$line)
        //    break;

        //??? why need below test
        if (feof(stdin))
        {
            echo "\n";
            exit();
        }
        if (is_numeric($line))
        {
            if ($line % 2 == 0)
                echo "The number ".$line." is even.\n";
            else
                echo "The number ".$line." is odd.\n";
        }
        else
            echo "'".$line."'"." is not a number.\n";
    }
/*
The feof() function checks 
if the "end-of-file" (EOF) has been reached for an open file.
https://www.w3schools.com/php/func_filesystem_feof.asp
//feof(STDIN) is needed to ensure that Ctrl+d works
*/
/*
trim() removes white spaces and '\n' 
from both sides of the strings 
https://www.w3schools.com/php/func_string_trim.asp  
*/
?>