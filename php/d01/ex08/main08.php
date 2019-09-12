<?PHP
    include("ft_is_sort.php");
    $tab = array("!/@#;^", "42", "Hello World", "hi", "zZzZzZz");
    foreach($tab as $w)
        echo $w."\n";
    if (ft_is_sort($tab))
        echo "The array is sorted\n";
    else
        echo "The array is not sorted\n";


    echo "\n\n";    
    $tab[] = "What are we doing now ?";
    foreach($tab as $w)
        echo $w."\n";

    echo "\n\n";    

    foreach($tab as $w)
        echo $w."\n";
     
 
    if (ft_is_sort($tab))
        echo "The array is sorted\n";
    else
        echo "The array is not sorted\n";

    sort($tab);
    foreach($tab as $w)
    echo $w."\n";

?>

// above text is not included in submission !!!