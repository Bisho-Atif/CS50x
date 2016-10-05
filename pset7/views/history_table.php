<div>
    <table class="table table-striped">
        <thead>
            <tr>
                <th>Type</th>
                <th>Symobl</th>
                <th>Shares</th>
                <th>Price</th>
                <th>Total</th>
                <th>Date</th>
            </tr>
        </thead>

        <?php foreach($history as $num => $element){?>
            <tr>
            <th><?=$history[$num]["type"]?></th>
            <th><?=$history[$num]["symbol"]?></th>
            <th><?=$history[$num]["shares"]?></th>
            <th>$<?=$history[$num]["price"]?></th>
            <th>$<?=$history[$num]["shares"] * $history[$num]["price"]?></th>
            <th><?=$history[$num]["date"]?></th>
            </tr>
        <?php } ?>
    </table>
</div>
