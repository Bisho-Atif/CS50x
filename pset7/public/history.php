<?php

    //Configuration 
    require("../includes/config.php");

    $user_history = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    render("history_table.php",["history" => $user_history]);
?>

