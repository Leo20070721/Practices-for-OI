# 输入多个数字并转换为整数列表
numbers = list(map(int, input().split()))
N=numbers[0]
M=numbers[1]
numbers = list(map(int, input().split()))
price=[]
for i in range(N):
    price.append(numbers[i])

ans=0

def dfs(dep,cost):
    global ans
    if(dep == N+1):
        ans+=1
        return
    dfs(dep+1,cost)
    if(cost+price[dep-1]<=M):        
        dfs(dep+1,cost+price[dep-1])
    return



dfs(1,0)
print(ans)