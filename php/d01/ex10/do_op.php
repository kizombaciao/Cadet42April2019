#!/usr/bin/php
<?php
    if ($argc != 4) 
    {
        echo "Incorrect Number of Parameters.\n";
        exit();
    }
    switch (trim($argv[2], " \t"))
    {
        case ("+") :
        echo trim($argv[1], " \t") + trim($argv[3], " \t");
        break;
        case ("-") :
        echo trim($argv[1], " \t") - trim($argv[3], " \t");
        break;
        case ("*") :
        echo trim($argv[1], " \t") * trim($argv[3], " \t");
        break;
        case ("/") :
        echo trim($argv[1], " \t") / trim($argv[3], " \t");
        break;
        case ("%") :
        echo trim($argv[1], " \t") % trim($argv[3], " \t");
        break;
    }
    echo "\n";
/*
trim() set to remove spaces and tabs.
*/
?>
