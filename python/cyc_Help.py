def sum_One_of_n(n):
    i_Sum = 0
    for i in range(2 - (n & 1), n + 1, 2):
        i_Sum += (1 / i)
    return i_Sum


for i in range(100):
    print(sum_One_of_n(i))
