<?php

// Dates
$regDate = "2017-12-23 12:33:00";
$regDate_dump = strtotime($registerDate);
$diff = time() - $regDate_dump;
echo "С регистрации прошло " .  floor($diff / 86400) . " дней.<br>";

// Other functions
dirname($var); // Возвращает имя родительского каталога. Передача __DIR__ опустит на 1 уровень ниже
json_encode($array); // Возвращает данные json, в случае невозможности кодировки возвращает false
json_decode($JSONVariable, $bool);// Возвращает строковое представление данных json, в случае неудачи возвращает null $bool может быть true(вернет object) или false(вернет array)

// Mathematic functions
abs(); // Модуль числа
base_convert(string $number, int $from, int $to); //Преобразование числа между произвольными системами счисления
fmod($f, $s); //Возвращает дробный остаток от деления
round($var, $int);// Округляет $var с точностью до $int символов после плавающей точки
is_finite();
is_infinite();
is_nan();//Проверяет, является ли значение не числом
pow($num, $base); // позводит $num в степень $base
rand($min, $max); // Рандом
sqrt(); // Корень квадратный

// String functions
$url = "http://php.net/manual/ru/ref.strings.php";
addslashes($string); // экранирует некоторые символы с помощью слешей(не дает забагать интерпретатору)
chunk_split($body, $chunklen, $end); //Разбивает строку на фрагменты, http://php.net/manual/ru/function.chunk-split.php
explode("divider", $string); //Разбивает строку на фрагменты по divider
implode($separator, $array);//Объединяет элементы массива в строку
lcfirst($string); // Преобразует первый символ строки в нижний регистр
nl2br("foo - это вам не\n bar");//Вставляет HTML-код разрыва строки
number_format($number , $decimals = 0/*количество символов после плавающей точки*/ , string $dec_point = "."/*,*/ , string $thousands_sep = ","/*.*/ ); // Переводит в формат
|$str = "first=value&arr[]=foo+bar&arr[]=baz";
|parse_str($str, $output); echo $output['first'];  // парсит строку
printf('There is a difference between %s and %s', 'good', 'evil');
quotemeta($str);//Экранирует специальные символы: перед каждым символом из следующего списка: . \ + * ? [ ^ ] ( $ ) вставлен обратный слеш (\).
similar_text($str1, $str2, $percentage);//Вычисляет степень похожести двух строк
trim($str);// Удаляет пробелы из начала и конца строки
preg_split(string $regex, string $string, $limit, $flag);//Разбивает строку по регулярному выражению. $limit = -1 || = 0 — отсутствие ограничения

// Variable functions
$url = "http://php.net/manual/ru/ref.var.php";
=& // use the same data for both variables
empty($var); // Проверяет, пуста ли переменная: null = true, "" = true;
get_defined_vars(); // Возвращает список всех переменных в текущей области видимости
get_resource_type();// Возвращает тип ресурса(ответ с БД)
gettype(); // Возвращает тип переменной;
floatval($var); // Возвращает значение переменной в виде числа с плавающей точкой
is_array($var);
is_bool($var);
is_callable($var); // Проверяет, может ли значение переменной быть вызвано в качестве функции.
is_float($var); // число ли с плавающей точкой
is_int($var); // целочисленное ли число
is_iterable($var); // Проверяет, является ли переменная итерируемой arr(1,2,3) - true
is_null($var);
is_numeric($var); // Является ли $var числом или строкой, содержащей число
is_object($var); // Является ли переменная объектом
is_resource($var); // Является ли переменная ресурсов(e.g. ответом со стороны БД)
is_string($var);
isset($var); // Проверяет, были ли установлена $var значением, отличным от NULL
print_r($var); // Выводит удобочитаемую информацию о переменной
serialize($var); // Генерирует пригодное для хранения представление переменной
settype($var, string $type); //Присваивает переменной новый тип $type = тип данных
strval($var); //Переводит переменную в строку
unset($var);//удаляет переменную $var;
var_dump($var); // Выводит информацию о переменной
var_export($var); // Выводит или возвращает интерпретируемое строковое представление переменной. Аналогично var_dump за исключением того, что является PHP кодом.


?>
