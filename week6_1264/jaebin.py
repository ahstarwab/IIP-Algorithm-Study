T = int(input())
for test_case in range(1, T + 1):
    s_len = int(input())
    X = list(input())
    Y = list(input())
    LCS_table = [[0 for _ in range(s_len+1)] for _ in range(s_len+1)]
    for i in range(1,s_len+1):
        for j in range(1, s_len+1):
            if X[i-1] == Y[j-1]:
                LCS_table[i][j] = LCS_table[i-1][j-1] + 1
            else:
                LCS_table[i][j] = max(LCS_table[i-1][j], LCS_table[i][j-1])

    result = LCS_table[s_len][s_len]
    result = result*100 / s_len
    print(result)
    print("#{} {:.2f}".format(test_case, result))

