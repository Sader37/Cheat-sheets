<?php
     class NewClass {
         public $number;
         public $text;
         public function __construct($number, $text="Hello world!") {
             $this->number = $number;
             $this->text = $text;
         }
     }
     function writeInfo(NewClass $newClass) {
             $text = "$newClass->number — номер. <br>";
             $text .= " $newClass->text — текст.";
             echo $text;
         }
     $newClassVar = new NewClass(10);
     writeInfo($newClassVar);

      ?>
