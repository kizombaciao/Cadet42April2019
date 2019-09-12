#!/usr/bin/php
<?php
    function ft_split($s)
    {
        $w = array_values(array_filter(explode(" ", trim($s))));
        sort($w);
        if (!count($w) || !$w[0])
            return NULL;
        return $w;
    }
// PROBLEM WITH SORTING BY ABC, SORT IS NOT CASE INSENSITIVE!!!
/*
//array_filter() to remove extra spaces between words as well
//better than trim() which only removes on sides.
//by not providing a callback function, spaces are treated as false
*/
// trim() needed ? needed, see ttt1.php for why
/*
https://www.geeksforgeeks.org/php-explode-function/
// explode() is a built in function in PHP 
used to split a string in different strings
by using a delimiter.
*/
/*
https://www.w3schools.com/php/func_array_filter.asp
https://www.geeksforgeeks.org/php-array_filter-function/
//This built-in function in PHP is used to filter 
the elements of an array using a user-defined function 
which is also called a callback function.
//This way the keys of the array gets preserved, 
i.e. the key of element in the original array 
and output array are same.
*/
/*
https://www.geeksforgeeks.org/php-array_values-function/
The function creates another array 
where it stores all the values 
and by default assigns numerical keys to the values.
*/
?>
