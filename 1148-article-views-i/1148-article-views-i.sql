SELECT distinct(v.author_id) as id
FROM VIEWS as v
where v.author_id=v.viewer_id
ORDER BY v.author_id ASC