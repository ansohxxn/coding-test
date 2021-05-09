-- 우유와 요거트를 동시에 구입한 장바구니의 아이디를 조회하는 SQL 문을 작성해주세요. 
-- 이때 결과는 장바구니의 아이디 순으로 나와야 합니다.

SELECT P.CART_ID 
FROM CART_PRODUCTS P JOIN (SELECT CART_ID FROM CART_PRODUCTS WHERE NAME="Yogurt") YO 
    ON P.CART_ID=YO.CART_ID 
WHERE NAME="Milk" 
ORDER BY P.CART_ID