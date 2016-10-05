<?php 
    
    //Configuration
    require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("password_form.php", ["title" => "Reset password"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["old"]) || empty($_POST["new"]) || empty($_POST["confirm"]))
        {
            apologize("You have a required field empty");
        }
        if($_POST["new"] != $_POST["confirm"])
        {
            apologize("Password and password confirmation doesn't match");
        }
        $old_password = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        
        if(password_verify($_POST["old"], $old_password[0]["hash"]))
        {
        $new_password = password_hash($_POST["new"], PASSWORD_DEFAULT);
        CS50::query("UPDATE users SET hash = ? WHERE id = ?", $new_password, $_SESSION["id"]);
        render("password_success.php", ["title" => "Password Change"]);
        }
        else
        {
            apologize("Your old password is wrong ");
        }
    }

?>