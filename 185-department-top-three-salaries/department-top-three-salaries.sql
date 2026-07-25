# Write your MySQL query statement below
with ranked as (
    SELECT d.name as Department,e.name as Employee, e.salary as Salary,
    DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY salary DESC) as rnk FROM Employee e
    JOIN Department d ON e.departmentId=d.id
)
SELECT Department,Employee,Salary FROM ranked where rnk<=3;