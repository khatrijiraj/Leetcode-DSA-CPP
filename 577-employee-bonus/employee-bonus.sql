# Write your MySQL query statement below
SELECT name, bonus
FROM Employee as e
LEFT JOIN Bonus as b
on e.empId = b.empID
WHERE b.bonus < 1000 OR b.bonus IS NULL