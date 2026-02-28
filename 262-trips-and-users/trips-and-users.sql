SELECT 
    Request_at AS Day, 
    ROUND(
        SUM(IF(Status != 'completed', 1, 0)) / COUNT(*), 
        2
    ) AS 'Cancellation Rate'
FROM Trips
WHERE 
    -- Filter out banned clients
    Client_Id IN (SELECT Users_Id FROM Users WHERE Banned = 'No') 
    AND 
    -- Filter out banned drivers
    Driver_Id IN (SELECT Users_Id FROM Users WHERE Banned = 'No')
    AND 
    -- Date range constraint
    Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at;