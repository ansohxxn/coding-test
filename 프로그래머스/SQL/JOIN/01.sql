SELECT O.ANIMAL_ID, O.NAME
FROM ANIMAL_INS I RIGHT JOIN ANIMAL_OUTS O
    ON I.ANIMAL_ID = O.ANIMAL_ID
WHERE I.ANIMAL_ID IS NULL
ORDER BY O.ANIMAL_ID

-- 오른쪽 외부 조인 
  -- 오른쪽 테이블은 무조건 조회하기. 왼쪽 테이블에도 조건 맞는게 있다면 같이 보여줌
  -- A테이블 RIGHT JOIN B테이블 ON A열 = B열

-- 동등 조인 -> 교집합
-- 왼쪽, 오른쪽 외부 조인 -> 그냥 A, B
-- 전체 외부 조인 -> 합집합