import sys
import os

def main():
    # 調整最大位數限制，設定為 20000000（可以根據需要調整）
    sys.set_int_max_str_digits(20000000)

    # Read number A from bumA.txt
    with open('C:\\gitproject\\programing\\penguinLibrary\\FFTmut\\bumA.txt', 'r') as infile:
        num_str = infile.readline().strip()
        A = int(num_str)

    # Calculate A * A
    result = A * A

    # Check if output.txt exists and read number B
    output_path = 'C:\\gitproject\\programing\\penguinLibrary\\FFTmut\\output.txt'
    if os.path.exists(output_path) and os.path.getsize(output_path) > 0:
        with open(output_path, 'r') as infile:
            num_str = infile.readline().strip()
            B = int(num_str)
        
        # Compare the result
        if result == B:
            print("Answer is correct")
        else:
            print("Answer is wrong")
            with open(output_path, 'w') as outfile:
                outfile.write(str(result))
            print("Updated output.txt with the correct result.")
    else:
        # If output.txt does not exist or is empty, write the result
        with open(output_path, 'w') as outfile:
            outfile.write(str(result))
        print("output.txt was empty or missing. Written the calculated result to output.txt.")

if __name__ == "__main__":
    main()
