SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) AS count
FROM ANIMAL_INS
WHERE ANIMAL_TYPE IN ('Cat', 'Dog')
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE 

-- 실행 순서
  -- FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY

-- 같은 값을 가지는 행들끼리 그룹화 한다. 

-- WHERE : 집계함수 사용 불가. (전체 테이블 대상)
-- HAVING : 집계함수 사용 가능 (그룹 대상으로 진행)

-- SELECT 열, 집계함수(열)    -> 무조건 GROUP BY 사용해야 함 
