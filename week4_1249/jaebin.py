import heapq

def dijk_method(h, n, field, d_field):
    m = [0,1,2,3]
    while h:
        d, x, y = heapq.heappop(h)
        for i in m:
            if i == 0:
                m_x = x + 1
                m_y = y
            elif i== 1:
                m_x = x -1
                m_y = y
            elif i == 2:
                m_x = x
                m_y = y + 1
            else:
                m_x = x
                m_y = y -1
                
            if 0<=m_x<n and 0<= m_y<n:
                new_d = d + field[m_x][m_y]
                
                if d_field[m_x][m_y] > new_d:
                    d_field[m_x][m_y] = new_d
                    heapq.heappush(h, (new_d, m_x, m_y))
                    if m_x == n-1 and m_y == n-1:
                        return d_field
T = int(input())

for test_case in range(1, T + 1):
    h = []
    n = int(input())
    field = [list(map(int, list(input()))) for _ in range(n)]
    d_field = [[ 99999999 for _ in range(n)] for _ in range(n)]
    d_field[0][0] = 0
    heapq.heappush(h, (0,0,0))
    d_result = dijk_method(h, n, field, d_field)
    
    print("#{} {}".format(test_case, d_field[-1][-1]))
    