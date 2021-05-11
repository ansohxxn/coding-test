SELECT P.CART_ID 
FROM CART_PRODUCTS P JOIN (SELECT CART_ID FROM CART_PRODUCTS WHERE NAME="Yogurt") YO 
    ON P.CART_ID=YO.CART_ID 
WHERE NAME="Milk" 
ORDER BY P.CART_ID