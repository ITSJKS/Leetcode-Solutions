SELECT ACTOR_ID, DIRECTOR_ID
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) > 2