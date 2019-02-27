<?php
dirname($var); // Возвращает имя родительского каталога. Передача __DIR__ опустит на 1 уровень ниже
json_encode($array); // Возвращает данные json, в случае невозможности кодировки возвращает false
json_decode($JSONVariable, $bool);// Возвращает строковое представление данных json, в случае неудачи возвращает null $bool может быть true(вернет object) или false(вернет array)
// ———————————————————————— Математические функции: ——————————————————————————————
abs(); // Модуль числа
base_convert(string $number, int $from, int $to);//Преобразование числа между произвольными системами счисления
fmod($f, $s); //Возвращает дробное  остаток от деления
round($var, $int);// Округляет $var с точностью до $int символов после плавающей точки
is_finite();
is_infinite();
is_nan();//Проверяет, является ли значение не числом
pow($num, $base); // позводит $num в степень $base
rand($min, $max); // Рандом(плохой)
sqrt(); // Корень квадратный
 ?>
