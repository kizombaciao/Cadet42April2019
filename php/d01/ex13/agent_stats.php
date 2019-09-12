#!/usr/bin/php
<?php
    if ($argc != 2)
        exit();

    //echo $argc."\n";

    $line = array();
    $user = array();

    foreach ($user as $w)
        echo $w."\n";
    
    $stdin = fopen('php://stdin', 'r');
    fgets($stdin);
    // ???
    while ($stdin && !feof($stdin))
    {
        $tmp = explode(";", fgets($stdin));
        if (count($tmp) == 4)
        {
            $line[] = $tmp;

            //foreach ($line as $w)
            //    echo $w[3]."\n";
        
            //$fff = array_key_exists($tmp[0], $user);
            //echo $fff."\n";

            // initialize statistics table
            if (!array_key_exists($tmp[0], $user))
            {
                $user[$tmp[0]] = null;
                $user[$tmp[0]]['sum'] = 0;
                $user[$tmp[0]]['count'] = 0;
                $user[$tmp[0]]['moulinette'] = 0;
            }
        }        
    }

    //foreach ($line as $w)
    //    echo $w[0]."\n";
    //foreach ($user as $w)
    //    echo $w['david_a']['sum']."\n";

    ksort($user);

    if ($argv[1] == "average")
    {
        $sum = 0;
        $count = 0;
        foreach ($line as $d)
        {
            if ($d[2] != 'moulinette' && $d[1] != '')
            {
                $count++;
                $sum += $d[1];
            }
        }
        echo ($sum / $count)."\n";
    }
    else if ($argv[1] == "average_user" || $argv[1] == "moulinette_variance")
    {
        foreach ($line as $d)
        {
            if ($d[1] != '' && $d[2] != "moulinette")
            {
                $user[$d[0]]['count']++;
                $user[$d[0]]['sum'] += $d[1];
                //echo $d[0]." ".$user[$d[0]]['sum']."\n";
            }
            else if ($d[2] == "moulinette")
            {
                $user[$d[0]]['moulinette'] += $d[1]; // ???
            }
        }        
        if ($argv[1] == "average_user")
        {
            foreach ($user as $k => $d)
            {
                echo $k.":".($d['sum']/$d['count'])."\n";
            }
        } 
        else 
        {
            foreach ($user as $k => $v)
            {
                echo $k.":".(($d['sum'] / $d['count']) - $d['moulinette'])."\n";
                //echo $k.":".(($d['sum'] / $d['count']) - $d['moulinette'])."\n";
            }
        }
    }






// how did you skip reading the header for the colum fields ???
// each user is graded my moulinette only once ???

/*
https://www.w3schools.com/php/func_array_key_exists.asp
The array_key_exists() function checks an array 
for a specified key, 
and returns true if the key exists and false 
if the key does not exist.
*/
/*
https://www.w3schools.com/php/func_array_ksort.asp
The ksort() function sorts an associative array 
in ascending order, according to the key.
*/

?>
