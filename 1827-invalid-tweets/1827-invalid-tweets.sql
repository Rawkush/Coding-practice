# Write your MySQL query statement below


select tweet_id from 
  (select tweet_id,
        CHAR_LENGTH(content) as cl
  from Tweets) as tmp
where  cl > 15