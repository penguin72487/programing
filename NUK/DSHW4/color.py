import colorama

# Initialize colorama to handle ANSI sequences in terminals
colorama.init()

def test_colorama():
    print(colorama.Fore.RED + "This should be red")
    print(colorama.Fore.GREEN + "This should be green")
    print(colorama.Fore.BLUE + "This should be blue")
    print(colorama.Fore.YELLOW + "This should be yellow")
    print(colorama.Style.RESET_ALL + "This should be in the default terminal color")

if __name__ == "__main__":
    test_colorama()
