
def split_number(number__):
    split_list = list()
    number = number__
    while True:
        if number == 0:
            break
        num = number%10
        number = number//10
        split_list.append(num)

    return split_list 

def change_value(n_list__, index_1, index_2):
    n_list = n_list__
    temp = n_list[index_1]
    n_list[index_1] = n_list[index_2]
    n_list[index_2] = temp
    return n_list 

def change_number(number_list__, change_num__):
    number_list = number_list__
    change_num = change_num__
    number_len = len(number_list)
    change_list = [0]*number_len 
    total_set = set(number_list)
    for change in range(1,change_num+1):
        for i in range(1, number_len):
            temp_set = set(number_list[:-i])
            if number_list[-i] < max(temp_set):
                temp_index = number_list.index(max(temp_set))
                number_list = change_value(number_list, temp_index, -i)
                
                if change_list[temp_index] == 0 and change_list[-i]==0:
                    change_list[temp_index] = -change
                    change_list[-i] = change

                else:
                    change_list = change_value(change_list,-i,temp_index)
                
                if change>1 and change_num<number_len:
                    index_ch_p_u = change_list.index(change-1)
                    index_ch_c_u = change_list.index(change)
                    index_ch_p_d = change_list.index(-(change-1))
                    index_ch_c_d = change_list.index(-(change))
                    if number_list[index_ch_c_u] == number_list[index_ch_p_u] and index_ch_c_d>index_ch_p_d and number_list[index_ch_c_d]<number_list[index_ch_p_d]:
                        change_list = change_value(change_list,index_ch_c_d,index_ch_p_d)
                        number_list = change_value(number_list,index_ch_c_d,index_ch_p_d)

                break 

            if i == number_len-1:
                if number_len == len(set(number_list)):
                    number_list = change_value(number_list, 0, 1)
                    break
    
    max_number = list_to_number(number_list, number_len)
    return max_number 

def list_to_number(num_list, list_len):
    i = 0
    number = 0
    for val in num_list:
        number += val*(10**i)
        i += 1
    
    return number 



T = int(input())
for test_case in range(1,T+1):
    number, n_change = map(int,input().split())

    n_list = split_number(number)
    max_number = change_number(n_list, n_change)

    print("#{} {}".format(test_case,max_number))
