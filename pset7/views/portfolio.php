<div>
    <table class="table table-striped">
        <thead>
            <tr>
                <th>Symobl</th>
                <th>Name</th>
                <th>Shares</th>
                <th>Price</th>
                <th>Total</th>
            </tr>
        </thead>
        <tr>
            <th>cash</th><th></th><th></th><th></th><th>$<?=$cash?></th>
        </tr>
            
        <?php foreach($positions as $position){?>
            <tr>
            <th><?=$position["symbol"]?></th>
            <th><?=$position["name"]?></th>
            <th><?=$position["shares"]?></th>
            <th>$<?=$position["price"]?></th>
            <th>$<?=$position["price"] * $position["shares"]?></th>
            </tr>
        <?php } ?>
    </table>
</div>
