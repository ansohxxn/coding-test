SELECT HOUR(DATETIME), COUNT(*)
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >= 9 AND HOUR(DATETIME) <= 19
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME)

-- GROUP BY 와 ORDER BY 에도 집계함수 쓸 수 있음
-- 집계함수는 결과이기 때문에.

-- 값이 같은 행들끼리 묶어준다 ! ! !