-- 이름에 El 이 들어가는 이름 찾기
-- LIKE : 검색 패턴!!! 
-- _ : 한자리
--  % : 자리에 상관 없는 모든 값
-- 이름에 El 이 들어가면 %El% 로하면 됨

SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME LIKE '%El%' AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME

-- LIKE 작은따옴표 잊지 말기