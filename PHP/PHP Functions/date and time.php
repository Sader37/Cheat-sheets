<?php
// Dates
$regDate = "2017-12-23 12:33:00";
$regDate_dump = strtotime($registerDate);
$diff = time() - $regDate_dump;
echo "С регистрации прошло " .  floor($diff / 86400) . " дней.<br>";
 ?>
