import requests
import pandas as pd
import matplotlib.pyplot as plt

def fetch_price_data(symbol):
    """
    Fetch the real-time price data for a given symbol from Pyth Network.
    Replace 'your_api_url' with the actual API endpoint provided by Pyth Network.
    """
    api_url = f"https://api.pyth.network/{symbol}"
    response = requests.get(api_url)
    data = response.json()
    return data['price']

def main():
    # Symbols for AFSUI and SUI on Pyth Network
    afsui_symbol = 'symbol_for_afsui'
    sui_symbol = 'symbol_for_sui'
    
    # Fetching price data
    afsui_price = fetch_price_data(afsui_symbol)
    sui_price = fetch_price_data(sui_symbol)
    
    # Calculate the ratio
    ratio = afsui_price / sui_price
    
    # Prepare the dataframe for plotting
    data = {'AFSUI Price': [afsui_price], 'SUI Price': [sui_price], 'Ratio': [ratio]}
    df = pd.DataFrame(data)
    
    # Plotting
    df.plot(kind='bar', y='Ratio', title='AFSUI/SUI Price Ratio')
    plt.ylabel('Price Ratio')
    plt.show()

if __name__ == "__main__":
    main()
