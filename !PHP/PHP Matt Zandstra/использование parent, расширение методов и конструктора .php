<?php
     class Book {
     private $pages;
     private $printingQuality;
     private $content;
     public function __construct($pages, $printingQuality, $content) {
         $this->pages = $pages;
         $this->printingQuality = $printingQuality;
         $this->content = $content;
     }
     public function getInfo($arg) {
         if ($arg == 'pages') {
             return $this->pages;
         }
         if ($arg == 'printingQuality') {
             return $this->printingQuality;
         }
         if ($arg == 'content') {
             return $this->content;
         }
     }
     public function setInfo($property, $value) {
         if ($property == 'pages') {
             if (is_numeric($value)) {
                 $this->pages = $value;
             }
         }
         if ($property == 'printingQuality') {
             $this->printingQuality = $value;
         }
         if ($property == 'content') {
             $this->content = $value;
         }
     }
     }
     class Magazine extends Book {
         private $weight;
          function __construct($pages, $printingQuality, $content, $weight) {
              // не приходится писать огромное количество переменных сверху, а стоит лишь добавить новые(как $weight).
            parent::__construct($pages, $printingQuality, $content);
            $this->weight = $weight;
          }
          function getInfo($arg) {
            if ($arg == 'weight') {
                  return $this->weight;
              }
            return parent::getInfo($arg);
          }
     }
     $magazine = new Magazine(100,4,3, '400g');
     echo $magazine->getInfo('pages');
 ?>
