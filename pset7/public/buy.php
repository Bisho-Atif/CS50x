<?php
    //Configuration
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy_form.php",["title" => "Buy"]);
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $user = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $stock = lookup($_POST["stockname"]);
        if (preg_match("/^\d+$/", $_POST["number"]) == FALSE)
        {
            apologize("You have entered a fractional number to buy");
        }
        $number = $_POST["number"];
        if  ($stock == FALSE)
        {
            apologize("This stock doesn't exist");
        }
        else if ($user[0]["cash"] < ($number * $stock["price"]))
        {
            apologize("You haven't enough cash to make this deal !!");
        }
        else
        {
            CS50::query("UPDATE users SET cash = cash - ? * ? WHERE id = ?", $number, $stock["price"], $_SESSION["id"]);
            CS50::query("INSERT INTO stocks (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], $stock["symbol"], $number, $number);
            CS50::query("INSERT INTO history (user_id, type, symbol, shares, price ) VALUES (?, 'Buy', ?, ?, ?)", $_SESSION["id"], $stock["symbol"], $number, $stock["price"]);

            redirect("/");
        }
    }
?>