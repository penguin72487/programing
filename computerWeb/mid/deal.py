import pandas as pd

def process_summary_data(summary_file_path):
    # Reading the summary file
    summary_df = pd.read_csv(summary_file_path)

    # Placeholder value for strategy_id
    strategy_id = 1

    # Extracting necessary fields from summary data
    net_profit_row = summary_df[summary_df.iloc[:, 0] == '淨利']
    gross_profit_row = summary_df[summary_df.iloc[:, 0] == '毛利']
    max_drawdown_row = summary_df[summary_df.iloc[:, 0] == '最大交易虧損']
    max_runup_row = summary_df[summary_df.iloc[:, 0] == '最大交易獲利']
    sharpe_Ratio_row = summary_df[summary_df.iloc[:, 0] == '夏普比率']
    profit_Factor_row = summary_df[summary_df.iloc[:, 0] == '盈利因子']
    win_Rate_row = summary_df[summary_df.iloc[:, 0] == '勝率']
    total_Closed_Trade_row = summary_df[summary_df.iloc[:, 0] == '所有已平倉交易']
    
    net_profit = net_profit_row.iloc[0]['全部 USDT']
    gross_profit = gross_profit_row.iloc[0]['全部 USDT']
    roi = (net_profit / gross_profit) * 100 if gross_profit != 0 else 0
    total_profit = net_profit
    max_drawdown = max_drawdown_row.iloc[0]['全部 USDT']
    max_drawdown_percent = max_drawdown_row.iloc[0]['全部 %']
    max_runup = max_runup_row.iloc[0]['全部 USDT']
    max_runup_percent = max_runup_row.iloc[0]['全部 %']

    # Placeholder values for unavailable fields
    sharpe_ratio = sharpe_Ratio_row.iloc[0]['全部 USDT']
    profit_factor = profit_Factor_row.iloc[0]['全部 USDT']
    win_rate = win_Rate_row.iloc[0]['全部 USDT']
    total_closed_trade = int(total_Closed_Trade_row.iloc[0]['全部 USDT'])

    # Creating a DataFrame for review table
    review_df = pd.DataFrame([{
        'strategy_Id': strategy_id,
        'ROI': roi,
        'total_Profit': total_profit,
        'max_Drawdown': max_drawdown,
        'max_Drawdown_Percent': max_drawdown_percent,
        'max_Runup': max_runup,
        'max_Runup_Percent': max_runup_percent,
        'sharpe_Ratio': sharpe_ratio,
        'profit_Factor': profit_factor,
        'win_Rate': win_rate,
        'total_closed_Trade': total_closed_trade
    }])

    return review_df
def process_trades_data(trades_file_path):
    # Reading the trades file
    trades_df = pd.read_csv(trades_file_path)

    # Placeholder value for review_id
    review_id = 1  # This should ideally link to the corresponding review record

    # Extracting and converting trade data
    split_datetime = trades_df['日期/時間'].str.split(' ', n=1, expand=True)
    trades_df['entry_Date'] = split_datetime[0]
    trades_df['entry_Time'] = split_datetime[1]
    trades_df['exit_Date'] = split_datetime[0]  # Assuming exit date is the same as entry date
    trades_df['exit_Time'] = split_datetime[1]  # Placeholder, adjust if actual exit time is different
    trades_df['trade_Order'] = trades_df['交易 #']

    # Selecting and renaming the necessary columns
    trades_df = trades_df[['trade_Order', 'entry_Date', 'entry_Time', 'exit_Date', 'exit_Time', 
                           '價格 USDT', '獲利 USDT', '合約']]

    trades_df.columns = ['trade_Order', 'entry_Date', 'entry_Time', 'exit_Date', 'exit_Time', 
                         'entry_Price', 'profit', 'trade_Amount']

    # Calculating 'exit_Price' from 'entry_Price' and 'profit'
    trades_df['exit_Price'] = trades_df['entry_Price'] + trades_df['profit']

    # Adding the review_id and strategy_id columns
    trades_df['review_Id'] = review_id
    trades_df['strategy_Id'] = 1  # Placeholder value

    # Reordering columns to match the database structure
    trades_df = trades_df[['review_Id', 'trade_Order', 'strategy_Id', 'entry_Date', 'entry_Time', 
                           'exit_Date', 'exit_Time', 'entry_Price', 'exit_Price', 'trade_Amount']]

    return trades_df

# The rest of the script remains the same


# File paths for the summary and trades files
# Processing the files
for i in range(0, 1):  # 假設你有0到8這些文件
    summary_file_path = f'PerformanceSummary{i}.csv'
    trades_file_path = f'ListofTrades{i}.csv'

    # 處理文件
    review_df = process_summary_data(summary_file_path)
    trades_df = process_trades_data(trades_file_path)

    # Saving the processed data to new CSV files
    review_df.to_csv(f'review{i}.csv', index=False, header=False)
    trades_df.to_csv(f'trade{i}.csv', index=False, header=False)
