DROP TABLE IF EXISTS shops;
DROP TABLE IF EXISTS items;
DROP TABLE IF EXISTS employees;
DROP TABLE IF EXISTS sales;

-- 店舗情報を登録するテーブル
CREATE TABLE shops (
    id         integer PRIMARY KEY AUTOINCREMENT, -- 店舗ID
    name       varchar NOT NULL,                  -- 店舗名
    prefecture varchar NOT NULL,                  -- 都道府県
    city       varchar NOT NULL,                  -- 市区町村
    restroom   boolean NOT NULL                   -- トイレの有無 (1: あり, 0: なし) ※これ以外の値は取らない
);

-- 商品情報を格納するテーブル
CREATE TABLE items (
    id       integer PRIMARY KEY AUTOINCREMENT, -- 商品ID
    name     varchar            NOT NULL,       -- 商品名
    category integer            NOT NULL,       -- 商品カテゴリ (0: 食品, 1: 文房具, 2: 日用品, 3: たばこ, 4: その他) ※これ以外の値は取らない
    price    integer            NOT NULL,       -- 商品の税抜価格 (円)
    tax_rate float DEFAULT 0.10 NOT NULL        -- 税率 (0.08 or 0.10) ※これ以外の値は取らない
);

-- 従業員情報を格納するテーブル
CREATE TABLE employees (
 id      integer PRIMARY KEY AUTOINCREMENT, -- 従業員ID
    name    varchar NOT NULL,                  -- 氏名
    age     integer NOT NULL,                  -- 年齢
    shop_id integer NOT NULL                   -- 所属店舗のID
);

-- 売上情報を格納するテーブル
CREATE TABLE sales (
    id      integer PRIMARY KEY AUTOINCREMENT, -- 売上ID
    item_id integer NOT NULL,                  -- 購入された商品のID
    shop_id integer NOT NULL                   -- その買い物が行われた店舗のID
);

SELECT * FROM shops WHERE restroom = 1;

INSERT INTO items (name, category, price, tax_rate) VALUES ('りんご', 0, 100, 0.08);

-- id = 0以外の商品の税率を0.10に変更する
UPDATE items SET tax_rate = 0.10 WHERE id != 0;

-- 1000円以上の食品を削除する
DELETE FROM items WHERE category = 0 AND price >= 1000;

-- 関東の店舗一覧を取得する
SELECT * FROM shops WHERE prefecture = '東京都' OR prefecture = '神奈川県' OR prefecture = '千葉県' OR prefecture = '埼玉県';

-- 食品を安い順に20件取得する
SELECT * FROM items WHERE category = 0 ORDER BY price ASC LIMIT 20;

-- カテゴリごとに商品数を集計する
SELECT category, COUNT(*) FROM items GROUP BY category;

-- 店舗が5つ以上ある都道府県を取得する
SELECT prefecture FROM shops GROUP BY prefecture HAVING COUNT(*) >= 5;
