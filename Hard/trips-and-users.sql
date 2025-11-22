SELECT DATE(request_at) as Day,
ROUND(AVG(CASE WHEN status = 'completed' THEN 0 ELSE 1 END), 2) as "Cancellation Rate"
FROM TRIPS T
JOIN Users U1
ON T.client_id = U1.users_id
AND U1.banned = 'No'
AND U1.role = 'client'
JOIN Users U2
ON T.driver_id = U2.users_id
AND U2.banned = 'No'
AND U2.role = 'driver'
WHERE DATE(request_at) BETWEEN '2013-10-01' and '2013-10-03'
GROUP BY 1