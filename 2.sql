SELECT
    dept_name AS 'Department',
    emp_name AS 'Employee',
    emp_salary AS 'Salary'
FROM
    Employee
        JOIN
    Department ON Employee.dept_id = Department.dept_id
WHERE
    (Employee.dept_id , emp_salary) IN
    (   SELECT
            dept_id, MAX(emp_salary)
        FROM
            Employee
        GROUP BY dept_id
    )
Order By Department ASC
;
