CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare temp int;
  set temp=N-1;
  RETURN (
      # Write your MySQL query statement below.
        select ifnull(
            (select salary from Employee
            group by salary
            order by salary desc
            LIMIT 1 OFFSET temp
            ),null
        )
  );
END