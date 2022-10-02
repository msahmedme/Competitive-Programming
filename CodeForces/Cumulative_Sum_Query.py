

n = int(input())


arr = [*map(int, input().split())]

for i in range(1, n):
    # print(i, end=" ")
    arr[i] = arr[i] + arr[i-1]
# print()

for _ in range(int(input())):
    x = [*map(int, input().split())]
    # print("X[0]: ", x[0], end=" ")
    # print("X[1]: ", x[1])
    if(x[0] == 0):
        print(arr[n-1])
    else:
        print(arr[x[1]]-arr[x[0]-1])
    
