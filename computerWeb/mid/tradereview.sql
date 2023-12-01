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

    ROI DOUBLE,--
    totle_Profit DOUBLE,
    max_Drawdown DOUBLE,
    max_Drawdown_Percent DOUBLE,
    max_Runup DOUBLE,
    max_Runup_Percent DOUBLE,
    sharpe_Ratio DOUBLE,
    profit_Factor DOUBLE,
    win_Rate DOUBLE,
    totle_closed_Trade INT,
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

CREATE TABLE trade(
    trade_Id INT AUTO_INCREMENT,
    review_Id INT,
    trade_Order INT,
    entry_Date DATE,
    entry_Time TIME,
    exit_Date DATE,
    exit_Time TIME,
    entry_Price DOUBLE,
    exit_Price DOUBLE,
    profit DOUBLE,
    trade_Amount DOUBLE,
    PRIMARY KEY (trade_Id),
    FOREIGN KEY (review_Id) REFERENCES review(review_Id)
);
