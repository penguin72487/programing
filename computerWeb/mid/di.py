import pandas as pd
import os

# 檢查當前工作目錄
print("當前工作目錄:", os.getcwd())

# 文件路徑
file_path = 'C:\gitproject\programing\computerWeb\mid\\trade0.csv'  # 請替換為你的文件路徑

# 檢查文件是否存在
if os.path.exists(file_path):
    trade_df = pd.read_csv(file_path)

    # 修改第一列的值
    trade_df.iloc[:, 0] = 1
    # 保存修改後的文件
    trade_df.to_csv('C:\gitproject\programing\computerWeb\mid\\trade0.csv', index=False)
else:
    print("無法找到文件:", file_path)
