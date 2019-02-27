<?php
     $newArray = array(1, 2, 4, 10, 'dog');
     function printArray($array) {
         echo "hello world!";
         if (!is_array($array)) {
             die("<br>Неверный тип данных!");
         }
         echo "goodbye world!";
         }
     printArray(123);
      ?>
