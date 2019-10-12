# Write your MySQL query statement below
select w1.Id from Weather w1, Weather w2
where w1.Temperature>w2.Temperature and
    DATEDIFF(w1.RecordDate, w2.RecordDate)=1