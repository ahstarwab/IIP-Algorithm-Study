T = int(input())
from itertools import combinations
for test_case in range(1, T + 1):
    s_len = int(input())
    X = list(input())
    Y = list(input())
    result = 0
    for i in range(s_len, -1, -1):
        X_set = set(combinations(X, i))
        Y_set = set(combinations(Y, i))
        inter_set = X_set.intersection(Y_set)
        if len(inter_set) != 0:
            result = i
            break
        
    result = round(result*100 / s_len,2)
    print("#{} {}".format(test_case, result))

