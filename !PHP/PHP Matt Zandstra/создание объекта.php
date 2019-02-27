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
    $book1 = new Book(200, 'good', 'poor');
    echo $book1->getInfo('pages'),' страниц. <br>';
    $book1->setInfo('pages', 100);
    echo $book1->getInfo('pages'),' страниц. <br>';
     ?>
