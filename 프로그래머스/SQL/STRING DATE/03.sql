SELECT ANIMAL_ID, 
       NAME,
       CASE 
            WHEN SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%'
            THEN 'O'
            ELSE 'X'
            END AS '중성화'
FROM ANIMAL_INS