import os
import pandas as pd
from io import StringIO

folder_path = 'C:\coding project\programing\computerWeb'

for filename in os.listdir(folder_path):
    if filename.endswith('.csv'):
        file_path = os.path.join(folder_path, filename)
        
        # 讀取文件內容，並嘗試使用big5編碼解碼
        with open(file_path, 'rb') as f:
            content = f.read().decode('big5', errors='ignore')
        
        # 使用StringIO將字符串作為文件對象傳遞給pandas
        df = pd.read_csv(StringIO(content))
        
        # 保存為UTF-8編碼的csv文件
        df.to_csv(file_path, encoding='utf-8', index=False)
