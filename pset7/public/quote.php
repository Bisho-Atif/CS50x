<?php
    //Configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("quote_submit.php");
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        if ($stock == FALSE) 
        {
            apologize("The symbol entered isn't vailed");
        }
        else
        {
            render("quote_view.php", $stock);
        }
    }
?>