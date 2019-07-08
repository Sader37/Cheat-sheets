<?php
$url = "http://php.net/manual/ru/ref.strings.php";
addslashes($string); // экранирует некоторые символы с помощью слешей(не дает забагать интерпретатору)
chunk_split($body, $chunklen, $end); //Разбивает строку на фрагменты, http://php.net/manual/ru/function.chunk-split.php
explode("divider", $string); //Разбивает строку на фрагменты по divider
implode($separator, $array);//Объединяет элементы массива в строку
lcfirst($string); // Преобразует первый символ строки в нижний регистр
nl2br("foo - это вам не\n bar");//Вставляет HTML-код разрыва строки
number_format ($number , $decimals = 0/*количество символов после плавающей точки*/ , string $dec_point = "."/*,*/ , string $thousands_sep = ","/*.*/ ); // Переводит в формат
|$str = "first=value&arr[]=foo+bar&arr[]=baz";
|parse_str($str, $output); echo $output['first'];  // value
printf('There is a difference between %s and %s', 'good', 'evil');
quotemeta($str);//Экранирует специальные символы: перед каждым символом из следующего списка: . \ + * ? [ ^ ] ( $ ) вставлен обратный слеш (\).
similar_text($str1, $str2, $percentage);//Вычисляет степень похожести двух строк
trim($str)// Удаляет пробелы из начала и конца строки
preg_split(string $regex, string $string, $limit, $flag);//Разбивает строку по регулярному выражению. $limit = -1 || = 0 — отсутствие ограничения
 ?>
