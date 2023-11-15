CREATE DATABASE tradereview;


CREATE TABLE trader(
    trader_Id INT AUTO_INCREMENT,
    trader_Name VARCHAR(255),
    PRIMARY KEY (trader_Id)
);

CREATE TABLE strategy(
    strategy_Id INT AUTO_INCREMENT,
    trader_Id INT,
    strategy_Name VARCHAR(255),
    code LONGTEXT,

    FOREIGN KEY (trader_Id) REFERENCES trader(trader_Id),
    PRIMARY KEY (strategy_Id)
);
CREATE TABLE review(
    review_Id INT AUTO_INCREMENT,
    strategy_Id INT,

    ROI DOUBLE,//
    totle_Profit DOUBLE,//淨利 全部%
    max_Drawdown DOUBLE,//最大虧損交易 全部USDT
    max_Drawdown_Percent DOUBLE,//最大虧損交易 全部%
    max_Runup DOUBLE,//最大盈利交易 全部USDT
    max_Runup_Percent DOUBLE,//最大盈利交易 全部%
    sharpe_Ratio DOUBLE,//夏普比率 全部USDT
    profit_Factor DOUBLE,//盈利因子 全部USDT
    win_Rate DOUBLE,//勝率 全部%
    totle_closed_Trade INT,// 所有已平倉交易 全部USDT
    PRIMARY KEY (review_Id),
    FOREIGN KEY (strategy_Id) REFERENCES strategy(strategy_Id)
);
INSERT INTO review (strategy_Id, ROI, totle_Profit, max_Drawdown, max_Drawdown_Percent, max_Runup, max_Runup_Percent, sharpe_Ratio, profit_Factor, win_Rate, totle_closed_Trade) VALUES (1,-6.7453683460318405,-1499730.51,22273846.13,817.25,22640595.72,581906.95,0.109,0.937,83.98,337);

CREATE TABLE trade_parameter(
    parameter_Id INT AUTO_INCREMENT,
    review_Id INT,
    init_Fund DOUBLE,
    trade_Fee DOUBLE,
    PRIMARY KEY (parameter_Id),
    FOREIGN KEY (review_Id) REFERENCES review(review_Id)
);
INSERT INTO trade_parameter (review_Id, init_Fund, trade_Fee) VALUES (2,100.0,0.05);
CREATE TABLE trade(
    trade_Id INT AUTO_INCREMENT,
    review_Id INT,
    trade_Order INT,
    strategy_Id INT,
    entry_Date DATE,
    entry_Time TIME,
    exit_Date DATE,
    exit_Time TIME,
    entry_Price DOUBLE,
    exit_Price DOUBLE,
    profit DOUBLE,
    trade_Amount DOUBLE,
    PRIMARY KEY (trade_Id),
    FOREIGN KEY (strategy_Id) REFERENCES strategy(strategy_Id),
    FOREIGN KEY (review_Id) REFERENCES review(review_Id)
);
