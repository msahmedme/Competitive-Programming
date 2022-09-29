n = int(input())


for i in range(1, n+1,1):
    str = input()

    length = len(str)
    if(length<=10):
        print(str)
    else:
        print(str[0], end="")
        print(length-2, end="")
        print(str[length-1])
        
