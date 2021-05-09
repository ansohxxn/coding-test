SET @HOUR = -1;
SELECT @HOUR := @HOUR + 1,
       (SELECT COUNT(*)
        FROM ANIMAL_OUTS
        WHERE HOUR(DATETIME) = @HOUR)
FROM ANIMAL_OUTS
WHERE @HOUR < 23


-- 변수 선언 
  -- SET @변수이름 = 값;
-- 변수 대입
  -- SET @변수이름 := 값

-- 변수도 SELECT 로 열 이름으로서 출력 가능. 말그대로 변수임 변수!