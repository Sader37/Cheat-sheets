show tables;
-- all datatypes:
INT -- Whole Numbers
DECIMAL(M,N) -- Decimal Numbers - Exact Value
VARCHAR(length) -- String of text of length 'length'
BLOB    -- Binary large Object which stores large data
DATE    -- 'YYYY-MM-DD'
TIMESTAMP   -- 'YYYY-MM-DD HH:MM:SS'
-- create table:
CREATE TABLE table_name ();
-- specify table params:
student_id INT PRIMARY KEY, --PRIMARY KEY includes UNIQUE notion
name VARCHAR(15) NOT NULL, -- makes DB never set NULL on here
major VARCHAR(20) UNIQUE, -- makes DB never set the same values on here
birthdate DATE DEFAULT '1970-01-01', -- sets statement after DEFAULT keyword as default unless birthdate wasn't specified earlier
p_id INT PRIMARY KEY AUTO_INCREMENT --automaticly increases id per every INSERT INTO
name ON DELETE SET NULL -- sets NULL for name whenever name is deleted
p_id ON DELETE CASCADE -- deletes the entire row whenever id is deleted
-- delete table:
DROP TABLE table_name;
-- describe table:
DESCRIBE student;
-- ALTER TABLE is to add, delete and modify
ALTER TABLE table_name ADD column_name datatype);
ALTER TABLE table_name DROP COLUMN column_name;
ALTER TABLE table_name MODIFY COLUMN column_name datatype;
-- edit attribute
ALTER TABLE table_name DROP COLUMN p_id;
ALTER TABLE table_name ADD COLUMN p_id INT(11) AUTO_INCREMENT PRIMARY KEY;
-- put the information into DB's table:
INSERT INTO student(p_id, name, major) VALUES(1, 'Kate', 'Sociology');
--
WHERE row IN (); -- selects ids' where name IN .. range
-- UPDATE DB:
UPDATE table_name
SET major = 'Bio'
WHERE major = 'Biology';
-- DELETE row(s) from DB:
DELETE FROM table_name
WHERE id = 4;
-- ORDER QUERY BY:
ORDER BY attribute (ASC);
ORDER BY name, surname, id; -- orders, priority is name>surname>id
-- LIMITING:
LIMIT <int> -- returns specific amount of values;
-- Case
CASE case_value
    WHEN when_value THEN statement_list
    [WHEN when_value THEN statement_list] ...
    [ELSE statement_list]
END
-- functions
COUNT()
SUM()
AVG()
ROUND()
CEIL()
FLOOR()
MAX()
MIN()
LOWER()
LENGTH()
SUBSTR(str, pos, len)
-- Grouping:
SELECT COUNT(id), attribute
FROM student
GROUP BY attribute;
-- Similar to regex
% — any # characters, _ — one character
SELECT * FROM student
WHERE client_name LIKE '%pieceOfName';
SELECT * FROM student
WHERE birthdate LIKE '____-10%'; -- selects every student who was born in October
-- DELETE from table:
DELETE FROM student
WHERE id = 2;
-- UNIONS
SELECT name FROM student
UNION
SELECT name FROM student1
UNION
-- ...//// even more SELECT queries can be written inside of here
-- JOIN ON
SELECT student.p_id FROM student
JOIN student1
ON student.p_id = student1.p_id;
-- Nesting queries
SELECT student.p_id FROM student
WHERE student.p_id IN (
    SELECT student1.p_id
    FROM student1
);
-- Avoiding duplicating:
SELECT DISTINCT
-- Deleting trigger:
DROP TRIGGER my_trigger;
-- Creating trigger:
DELIMITER $$
CREATE
    TRIGGER my_trigger BEFORE(AFTER) INSERT
    ON employee
    FOR EACH ROW BEGIN
    IF NEW.sex = 'M' THEN
            INSERT INTO trigger_test VALUES('added male student');
        ELSEIF NEW.sex = 'F' THEN
            INSERT INTO trigger_test VALUES('added female student');
        ELSE
            INSERT INTO trigger_test VALUES('added other student');
        END IF;
    END$$
DELIMITER ;
