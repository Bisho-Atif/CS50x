<?php
    // configuration
    require("../includes/config.php"); 
    
    $row = CS50::query("SELECT shares,symbol FROM stocks WHERE user_id = ?", $_SESSION["id"]);
   
    if ($_SERVER["REQUEST_METHOD"]  == "GET" )
    {
        render("sell_form.php",["title" => "Sell", "symbols" => $row]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock_name = $_POST["stockname"];
        $stock_sold = (int)$_POST["sold"];
        $stock = lookup($stock_name);
        if ($row == FALSE) 
        {
            apologize("It seems that you haven't a stock with such a name");
        }
        if ((int)$row[0]["shares"] < $stock_sold)
        {
            apologize("You haven't the number of stocks to be sold");
        }    
        else if ((int)$row[0]["shares"] == $stock_sold)
        {
            CS50::query("DELETE FROM stocks WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $stock_name);
        }
        else
        {
            CS50::query("UPDATE stocks SET shares = shares - ? WHERE user_id = ? AND symbol = ?", $stock_sold, $_SESSION["id"], $stock_name);
        }
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", ($stock_sold * $stock["price"]), $_SESSION["id"]);
        CS50::query("INSERT INTO history (user_id, type, symbol, shares, price ) VALUES (?, 'Sell', ?, ?, ?)", $_SESSION["id"], $stock["symbol"], $stock_sold, $stock["price"]);
        
    }
    redirect("/");
    // render portfolio
    //render("portfolio.php", ["title" => "Portfolio" , "positions" => $positions]);

?>
