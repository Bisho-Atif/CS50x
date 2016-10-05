<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    $place = explode(",", $_GET["geo"]);
    if (count($place) == 1)
    {
        $inf = CS50::query("SELECT * FROM places WHERE place_name LIKE ? OR postal_code LIKE ?",$place[0] . "%", $place[0] . "%");
    }
    else
    {
        $inf = CS50::query("SELECT * FROM places WHERE place_name LIKE ? AND admin_name1 LIKE ?",$place[0] . "%", $place[1] . "%");
    }
    
    foreach ($inf as $num => $element )
    {
    	$places[] = $inf[$num];
    } 

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>