-- Determines the number of movies with rating 10.0
SELECT COUNT(movie_id)
FROM ratings
WHERE rating = 10.0
