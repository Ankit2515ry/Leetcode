# Write your MySQL query statement below
-- SELECT a.machine_id, 
--        ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
-- FROM Activity a, 
--      Activity b
-- WHERE 
--     a.machine_id = b.machine_id
-- AND 
--     a.process_id = b.process_id
-- AND 
--     a.activity_type = 'start'
-- AND 
--     b.activity_type = 'end'
-- GROUP BY machine_id

-- select x.machine_id,round(avg(y.timestamp-x.timestamp),3) as processing_time
-- from Activity as x, Activity as y
-- where x.machine_id=y.machine_id
-- and x.process_id=y.process_id
-- and x.activity_type='start'
-- and y.activity_type='end'
-- group by x.machine_id;

select x.machine_id,round(avg(y.timestamp-x.timestamp),3) as processing_time
from Activity as x
join Activity as y
on x.machine_id=y.machine_id
and x.process_id=y.process_id
and x.activity_type='start'
and y.activity_type='end'
group by x.machine_id;

-- SELECT 
--     machine_id,
--     ROUND(
--         AVG(CASE 
--             WHEN activity_type = 'end' THEN timestamp 
--             ELSE -timestamp 
--         END) * 2, 
--         3
--     ) AS processing_time
-- FROM Activity
-- GROUP BY machine_id;