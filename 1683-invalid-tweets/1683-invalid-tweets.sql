SELECT t.tweet_id
FROM Tweets as t
WHERE length(t.content)>15