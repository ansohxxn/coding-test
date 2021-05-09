--아픈 동물1의 아이디와 이름을 조회

SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE INTAKE_CONDITION = 'Sick'
ORDER BY ANIMAL_ID;

-- SQL 에서 = 은 할당이 아닌 == 비교 연산자나 다름 없다.
