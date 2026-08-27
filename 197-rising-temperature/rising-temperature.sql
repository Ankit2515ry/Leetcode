# Write your MySQL query statement below
-- self join and datediff 
select w1.id 
from Weather as w1
join Weather as w2
on DATEDIFF(w1.recordDate,w2.recordDate)=1
where w1.temperature>w2.temperature;

-- lag
-- WITH RankedWeather AS (
--     SELECT 
--         id,
--         recordDate,
--         temperature,
--         LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp,
--         LAG(recordDate) OVER (ORDER BY recordDate) AS prev_date
--     FROM Weather
-- )
-- SELECT id
-- FROM RankedWeather
-- WHERE temperature > prev_temp
--   AND DATEDIFF(recordDate, prev_date) = 1;