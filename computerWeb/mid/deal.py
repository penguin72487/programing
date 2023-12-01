import pandas as pd

def process_summary_data(summary_file_path):
    summary_df = pd.read_csv(summary_file_path)
    strategy_id = 1  # Placeholder value for strategy_id
    summary_df = pd.read_csv(summary_file_path)

    # 打印出文件的前幾行以檢查數據結構
    # print(summary_df.head())

    # Ensure all necessary fields are present
    required_fields = ['淨利', '毛利', '最大交易虧損', '最大交易獲利', '夏普比率', '盈利因子', '勝率', '所有已平倉交易']
    for field in required_fields:
        if field not in summary_df.iloc[:, 0].values:
            raise ValueError(f"Field '{field}' not found in the summary file.")

    # Extracting necessary fields
    def get_value(row_name, col_name):
        row = summary_df[summary_df.iloc[:, 0] == row_name]
        return row.iloc[0][col_name] if not row.empty else None

    net_profit = get_value('淨利', '全部 USDT')
    gross_profit = get_value('毛利', '全部 USDT')
    roi = (net_profit / gross_profit) * 100 if gross_profit != 0 else 0
    total_profit = net_profit
    max_drawdown = get_value('最大交易虧損', '全部 USDT')
    max_drawdown_percent = get_value('最大交易虧損', '全部 %')
    max_runup = get_value('最大交易獲利', '全部 USDT')
    max_runup_percent = get_value('最大交易獲利', '全部 %')
    sharpe_ratio = get_value('夏普比率', '全部 USDT')
    profit_factor = get_value('盈利因子', '全部 USDT')
    win_rate = get_value('勝率', '全部 USDT')
    total_closed_trade = int(get_value('所有已平倉交易', '全部 USDT'))

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

    if '' not in review_df.columns:
        review_df.insert(0, '', '')  # Insert an empty column if not already present

    return review_df

def process_trades_data(trades_file_path):
    # Reading the trades file
    trades_df = pd.read_csv(trades_file_path)

    # Placeholder value for review_id
    review_id = 1  # This should ideally link to the corresponding review record

    # Extracting and converting trade data
    # Splitting the '日期/時間' column into date and time, and adding '00' as seconds for MySQL compatibility
    split_datetime = trades_df['日期/時間'].str.split(' ', n=1, expand=True)
    trades_df['entry_Date'] = split_datetime[0].str.replace('-', '/')
    trades_df['entry_Time'] = split_datetime[1] + ':00'  # Adding seconds
    trades_df['exit_Date'] = split_datetime[0]  # Assuming exit date is the same as entry date
    trades_df['exit_Time'] = split_datetime[1] + ':00'  # Adding seconds, adjust if actual exit time is different
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
    trades_df = trades_df[['review_Id', 'trade_Order', 'entry_Date', 'entry_Time', 
                           'exit_Date', 'exit_Time', 'entry_Price', 'exit_Price', 'trade_Amount']]
    trades_df.insert(0, '', '')
    return trades_df

# The rest of the script remains the same


# File paths for the summary and trades files
# Processing the files
for i in range(0, 1):  # 假設你有0到8這些文件
    summary_file_path = f'C:\gitproject\programing\computerWeb\mid\PerformanceSummary{i}.csv'
    trades_file_path = f'C:\gitproject\programing\computerWeb\mid\ListofTrades{i}.csv'

    # 處理文件
    review_df = process_summary_data(summary_file_path)
    trades_df = process_trades_data(trades_file_path)

    # Saving the processed data to new CSV files
    review_df.to_csv(f'C:\gitproject\programing\computerWeb\mid\\review{i}.csv', index=False, header=False)
    trades_df.to_csv(f'C:\gitproject\programing\computerWeb\mid\\trade{i}.csv', index=False, header=False)
