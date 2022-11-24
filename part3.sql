CREATE TABLE product(
    NameOf varchar(255),
    Category varchar(255),
    WhenAdded DATETIME,
    WhoAdded varchar(255)
);
CREATE TABLE productPrice(
    Price INT,
    Discount INT DEFAULT 0,
    WhenUpdated DATETIME,
    WhoUpdated varchar(255)
);
CREATE TABLE productPriceChangeLog(
    OldPrice INT,
    NewPrice varchar(255),
    WhenUpdated DATETIME,
    WhoUpdated varchar(255)
);

SELECT product.NameOf, product.Category
FROM product
SELECT productPrice.Price, productPrice.WhenUpdated, productPrice.WhoUpdated
FROM productPrice
JOIN productPrice ON product;
