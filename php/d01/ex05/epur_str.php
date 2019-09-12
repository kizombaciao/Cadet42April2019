#!/bin/usr/php
<?php
    if ($argc == 2)
    {
        $words = array_filter(explode(' ', $argv[1]));
        $res = "";
        foreach($words as $w)
            $res .= $w." ";
        echo trim($res)."\n";
    }
/*
//append a string:  .=
https://www.tutorialrepublic.com/faq/how-to-append-a-string-in-php.php
*/
/*
if ($argc > 1)
{
	$trimmed = trim($argv[1]);
	while ((strpos($trimmed, "  ")) == TRUE)
		$trimmed = str_replace("  ", " ", $trimmed);
	echo("$trimmed\n");
}
*/
?>
