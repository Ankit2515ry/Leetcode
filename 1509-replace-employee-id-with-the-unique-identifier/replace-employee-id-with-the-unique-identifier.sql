# Write your MySQL query statement below
-- select ei.unique_id,e.name 
-- from Employees as e 
-- left join EmployeeUNI as ei 
-- on e.id=ei.id; -- on fill runs before the outer join logic completes, right table column with null if not exit(condition not matched) in right table


-- Look up the unique_id directly inside the SELECT list for each employee. If no match is found, SQL automatically returns NULL
select (
    select ei.unique_id from EmployeeUNI as ei
    where ei.id=e.id 
) as unique_id,e.name from
Employees as e;