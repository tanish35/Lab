--Q1
DECLARE emp_number NUMBER := 101;
BEGIN
UPDATE
    Employee
SET
    commission = 300
WHERE
    emp_id = emp_number
    and salary < 2000;

END;

--Q2
SELECT
    e.emp_name,
    d.dept_name,
    e.salary
FROM
    Employee e,
    Department d
WHERE
    e.dept_id = d.dept_id
ORDER BY
    e.salary DESC
FETCH FIRST
    4 ROWS ONLY

--Q3
SELECT
    e.emp_name,
    d.dept_name,
    e.salary,
    e.dept_id
FROM
    Employee e,
    Department d
WHERE
    d.dept_id = e.dept_id
    AND e.salary = (
        SELECT
            MIN(e2.salary)
        FROM
            Employee e2
        WHERE
            e2.dept_id = e.dept_id
        GROUP BY
            e2.dept_id
        );

--Q4
SELECT
    AVG(e.salary) as Average_Salary,
    d.dept_name
FROM
    Employee e,
    Department d
WHERE
    e.dept_id = d.dept_id
GROUP BY
    d.dept_name

--Q5
 
