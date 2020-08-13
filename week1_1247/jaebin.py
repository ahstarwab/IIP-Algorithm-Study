class calculrator():
    def __init__(self, n_case, coordinates, case_list):
        self.n_case = n_case -2
        self.calcul_matrix = [[None]*n_case for _ in range(n_case)]
        self.coordinates = coordinates
        self.case_list = case_list 
        self.visited = list()
        
    def calcul_distance(self, current_state, next_state):
        if self.calcul_matrix[current_state][next_state] is None:
            current_x, current_y = self.state_to_coordinate(current_state)
            next_x, next_y = self.state_to_coordinate(next_state)
            distance = abs(current_x-next_x)+abs(current_y-next_y)
            
            self.calcul_matrix[current_state][next_state] = distance
            self.calcul_matrix[next_state][current_state] = distance
            
            return distance

        else:
            return self.calcul_matrix[current_state][next_state]

    def state_to_coordinate(self,state):
        return self.coordinates[2*state], self.coordinates[2*state+1]
    
    def calcul_path(self):
        current_state = 0
        min_distance = self.calcul_state(current_state)
        return min_distance

    def calcul_state(self, current_state):
        if len(self.visited) == self.n_case :
            return self.calcul_distance(current_state, 1)
        else:
            distance = list()
            for next_state in self.case_list:
                if next_state not in self.visited:
                    self.visited.append(next_state)
                    path_distance = self.calcul_distance(current_state, next_state) + self.calcul_state(next_state)
                    self.visited.remove(next_state)
                    distance.append(path_distance)
            return min(distance)

                



T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    n_case = int(input()) + 2
    case_list = [ i for i in range(n_case)]
    case_list.remove(1)
    case_list.remove(0)
    coordinates = list(map(int, input().split()))
    case_calcul = calculrator(n_case, coordinates, case_list)
    min_distance = case_calcul.calcul_path()
    
    print("#{} {}".format(test_case, min_distance))
