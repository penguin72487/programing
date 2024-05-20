import subprocess
import colorama

colorama.init(autoreset=True)

def read_operations(file_path):
    operations = []
    with open(file_path, 'r') as file:
        content = file.read()
    blocks = content.split("=")
    for block in blocks:
        if block.strip():
            operations.append(block.strip())
    return operations

def compute_expected_results(operations):
    expected_results = []
    for block in operations:
        lines = block.split("\n")
        current_result = 0
        for line in lines:
            line = line.strip()
            if not line:  # Skip empty lines
                continue
            # Handle addition
            if '+' in line:
                parts = line.split('+')
                if len(parts) > 1 and parts[1].strip():  # Ensure there is a number to add
                    number = int(parts[1].strip())
                    current_result += number
            # Handle subtraction
            elif '-' in line:
                parts = line.split('-')
                if len(parts) > 1 and parts[1].strip():  # Ensure there is a number to subtract
                    number = int(parts[1].strip())
                    current_result -= number
        expected_results.append(str(current_result))
    return expected_results


def run_executable(executable_name):
    try:
        subprocess.run([executable_name], timeout=300)  # Adjust timeout as necessary
    except subprocess.TimeoutExpired:
        print("The process timed out")

def read_actual_results(output_file):
    with open(output_file, 'r') as file:
        return [line.strip() for line in file]

def highlight_differences(expected, actual):
    results = []
    for exp, act in zip(expected, actual):
        if exp == act:
            results.append(exp)
        else:
            diff = []
            for e_char, a_char in zip(exp, act):
                if e_char == a_char:
                    diff.append(e_char)
                else:
                    diff.append(colorama.Fore.RED + a_char)
            results.append(''.join(diff))
    return results

def main():
    input_file_path = 'in.txt'
    output_file_path = 'out.txt'
    executable_name = 'BigBCD.exe'
    
    operations = read_operations(input_file_path)
    expected_results = compute_expected_results(operations)
    run_executable(executable_name)
    actual_results = read_actual_results(output_file_path)
    
    if expected_results == actual_results:
        print("Results are correct.")
    else:
        print("Results differ:")
        highlighted_results = highlight_differences(expected_results, actual_results)
        for result in highlighted_results:
            print(result)

if __name__ == "__main__":
    main()
