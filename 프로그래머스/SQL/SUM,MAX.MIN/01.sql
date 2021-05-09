SELECT MAX(DATETIME) AS '시간'
FROM ANIMAL_INS;

-- 집계함수(열 이름) -> 집계한 결과 하나만 출력함
-- 모든 집계함수는 NULL 을 제외하고 집계한다. 
-- 집계함수는 WHERE 문에선 사용할 수 없다.
-- 행의 개수를 세는 일이다.
