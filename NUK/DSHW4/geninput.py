import subprocess
import colorama

# Initialize colorama to handle ANSI sequences in Windows Command Prompt
colorama.init(autoreset=True, convert=True)
import sys

sys.set_int_max_str_digits(10000000)

def read_numbers_from_file(file_path):
    # Read two large numbers from the specified file
    numbers = []
    with open(file_path, 'r') as file:
        for line in file:
            stripped_line = line.strip()
            if stripped_line.isdigit():  # Ensure the line is a number
                numbers.append(stripped_line)
            if len(numbers) == 2:  # We need only two numbers
                break
    if len(numbers) != 2:
        raise ValueError("The input file must contain exactly two lines with numbers.")
    return numbers[0], numbers[1]

def run_executable(input_file, executable_name):
    # Run the executable with the provided input file
    try:
        subprocess.run([executable_name], timeout=30000000)  # Adjust timeout as necessary
    except subprocess.TimeoutExpired:
        print("The process timed out")

def read_output(output_file):
    # Read the output from out.txt
    with open(output_file, 'r') as file:
        return file.read().strip()

def highlight_differences(expected, actual):
    result = []
    # Compare each character and apply red color if they differ
    for exp_char, act_char in zip(expected, actual):
        if exp_char == act_char:
            result.append(exp_char)
        else:
            result.append(colorama.Fore.RED + act_char + colorama.Style.RESET_ALL)
    return ''.join(result)

def main():
    input_file_path = 'ex-in.txt'
    output_file_path = 'ex-out.txt'
    executable_name = 'main.exe'

    # Read two large numbers
    A, B = read_numbers_from_file(input_file_path)
    
    # Calculate the expected sum in Python for verification
    expected_result = str(int(A) + int(B))
    
    # Run the BigBCD executable
    run_executable(input_file_path, executable_name)
    
    # Read and verify the output
    actual_output = read_output(output_file_path)
    if actual_output == expected_result:
        print(True)
    else:
        print(False)
        print("Expected:", expected_result)
        print("Actual:  ", highlight_differences(expected_result, actual_output))

if __name__ == "__main__":
    main()
