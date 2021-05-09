SELECT COUNT(DISTINCT NAME)
FROM ANIMAL_INS;

-- 중복 제거하고 집계하려면 DISTINCT
-- 중복을 먼저 제거한 후 COUNT  ->  COUNT(DISTINCT A)

-- NULL 인 값도 같이 행으로서 COUNT 집계함수로 셀려면 
  -- NULL 인 값은 모두 0 으로 치환하고나서 세자.
    -- COUNT(CASE WHEN A IS NULL THEN 0 ELSE A END)
      -- COUNT(IFNULL(column, 1))