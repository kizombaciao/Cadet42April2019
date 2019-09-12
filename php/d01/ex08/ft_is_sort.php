#!/usr/bin/php
<?php
    function ft_is_sort($arr)
    {
        $tmp = $arr;
        sort($tmp);
        if (array_diff_assoc($tmp, $arr) == null)
            return true;
        return false;
    }
?>