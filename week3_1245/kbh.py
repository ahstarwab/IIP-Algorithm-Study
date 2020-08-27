eps = 1e-16

def getForce(pos,mass,target):
    t_f = 0
    for i in range(len(pos)):
        # right
        if pos[i] > target :
            t_f=t_f + mass[i]/(pos[i]-target+eps)**2
        # left
        else :
            t_f=t_f - mass[i]/(target-pos[i]+eps)**2
    return t_f

# the num of iteration to converge
iter = 100
tc = int(input())
for i in range(tc):
    print("#{:d}".format(i+1), end =" ")
    n = int(input())
    x=[]
    m=[]
    p=[]
    in_list = list(map(int,input().split()))
    for j in range(n):
        x.append(in_list[j])
    for j in range(n,2*n):
        m.append(in_list[j])
    for j in range(n-1):
        left = x[j]
        right = x[j+1]
        val = 0
        #print("between " + str(left) + " and " + str(right))
        for k in range(iter):
            mid = (left + right) /2
            val = getForce(x,m,mid)
            #print("F : "+str(val)+ ' l :'+str(left)+" r : "+str(right)+" m : "+str(mid))
            # need to go right
            if(val < 0) :
                #print("go right" + str(left)+" -> "+str(mid) )
                left = mid
            # need to go left
            elif(val > 0 ):
                #print("go left" + str(right)+" -> "+str(mid) )
                right = mid
            else : 
                break
        print("{:.10f}".format(mid), end =" ")
    print('')




    
