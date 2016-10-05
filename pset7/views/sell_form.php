<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="stockname">
                <option disabled selected value="">Symbol</option>
                <?php foreach($symbols as $symbol => $var){?>
                <option><?=$symbols[$symbol]["symbol"]?></option>
                <?php } ?>
        </div>
        <div class="form-group">
            <input class="form-control" name="sold" placeholder="Number of stocks" type="text"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Sell
            </button>
        </div>
    </fieldset>
</form>

