-- 코드를 입력하세요
SELECT ANIMAL_ID, 
       NAME,
       CASE 
            WHEN SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%'
            THEN 'O'
            ELSE 'X'
            END AS '중성화'
FROM ANIMAL_INS


-- CASE : IF 문 시작
  -- WHEN : 조건문 
    -- THEN : 참이면
    -- ELSE : 거짓이면  
-- END : IF 문 종료

-- CASE + 변수열
  -- WHEN 1 THEN
  -- WHEN 2 THEN 
--이렇게쓰기도!