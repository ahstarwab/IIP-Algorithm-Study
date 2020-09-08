T = int(input())
for test_case in range(1, T+1):
    k = int(input())
    sentence = input()
    s_list = []
    s_len = len(sentence)

    if k <= s_len:

        for i in range(s_len):
            s_list.append(sentence[i:])
        s_list = sorted(s_list)
        result = s_list[k-1]
    else:
        result = None
    print("#{} {}".format(test_case, result))


