import math  

def make_dict(mc_list, n_m):
    m_list = sorted(mc_list[0:n_m])
    m_dict = {}
    for i in range(n_m):
        m_dict[mc_list[i]] = mc_list[n_m + i]

    return m_list, m_dict 

def GoldenSectionSearch(n_m, m_list, m_dict, error = 1e-12):
#    P = 0.381966
    P = (3-2.23606797749979)/2
    x_list = []
    for seg in range(n_m-1):
        max_x = m_list[seg]  #b0
        min_x = m_list[seg+1]#a0
        temp = None
        flag = None 
        min_val = 999999
        count_minval = 0
        while True:
            P_len = max_x - min_x
            test_x1 = max_x - P*P_len    # b1
            test_x2 = min_x + P*P_len    # a1
            if flag == 1 and temp is not None:
                test_x1_F = temp 
                test_x2_F = force_calcul(test_x2, m_list, m_dict)
            elif flag == 2 and temp is not None:
                test_x1_F = force_calcul(test_x1, m_list, m_dict)
                test_x2_F = temp 
            else:
                test_x1_F = force_calcul(test_x1, m_list, m_dict) #f(b1)
                test_x2_F = force_calcul(test_x2, m_list, m_dict) #f(a1)
            
            if test_x1_F > test_x2_F:   #f(b1) > f(a1)
                if test_x2_F < error and P_len < 1e-14:
                    x_list.append(test_x2)
                    break
                else:
                    max_x = test_x1  
                    temp = test_x2_F  
                    flag = 1
            else:                       # f(b1) < f(a1)
                if test_x1_F < error and P_len < 1e-14:
                    x_list.append(test_x1)
                    break
                else:
                    min_x = test_x2  
                    temp = test_x1_F 
                    flag = 2
            if min_val == min(test_x1_F,test_x2_F):
                count_minval += 1
                if count_minval == 100:
                    if min_val < 1e-10:
                        x_list.append(test_x1) 
                    break 
            else:
                min_val = min(test_x1_F,test_x2_F)
                count_minval = 0
    
    return floor_10(sorted(list(set(x_list))))

def floor_10(x_list):
    result = list()
    for n in x_list:   
        result.append(format(n,".10f")) 
    return result


def force_calcul(x, m_list, m_dict):
    left_F = 0
    right_F = 0
    for i in m_list:
        if i < x:
            left_F += (m_dict[i] / (i - x)**2)
        elif i > x:
            right_F += (m_dict[i] / (i - x)**2)
    total_F = abs(left_F - right_F)

    return total_F 

T = int(input())

for test_case in range(1, T+1):
    n_m = int(input())
    mc_list = list(map(int, input().split()))
    m_list, m_dict = make_dict(mc_list, n_m)
    result = "#"+str(test_case) 

    x = GoldenSectionSearch(n_m, m_list, m_dict, error = 1e-13)
    for i in x:
        result += " "+str(i)
    print(result)
