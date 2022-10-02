

# def sortInsertion(unsortedList):
   
#     for i in range(1, len(unsortedList)):
#         key = unsortedList[i]
#         j = i-1
#         while j >= 0 and int(unsortedList[j]) > int(key):
#             unsortedList[j+1] = unsortedList[j]
#             j = j - 1
#         unsortedList[j+1] = key
#     # return

def solve():


    n = int(input())
    # print("n: ", n)
   
    damageFire = []
    damageFrost = []
    
    # damageFire.clear()
    # damageFrost.clear()



    # get input the skill
    skill = input()
    skill = skill.split(" ")
    

    # Get input the damage cost
    # dmg = input()
    dmg = [*map(int, input().split())] # here * is used to unpack the positionsal arguement
    # Tutorial link:  https://www.geeksforgeeks.org/python-star-or-asterisk-operator/

    for i in range(0, n):
        if skill[i] == "0":
            damageFrost.append(dmg[i])
        else:
            damageFire.append(dmg[i])
    

    # # printing the damage cost of Frost
    # print("Unsorted Damage of Frost: ", end="")
    # for x in damageFrost:
    #     print(x, end=" ")
    # print()

    # print("Unsorted Damage of Fire: ", end="")
    # for x in damageFire:
    #     print(x, end=" ")
    # print()

    # sortInsertion(damageFire)
    # sortInsertion(damageFrost)

    damageFire.sort()
    damageFrost.sort()

    # # printing the damage cost of Frost
    # print("Sorted Damage of Frost: ", end="")
    # for x in damageFrost:
    #     print(x, end=" ")
    # print()

    # print("Sorted Damage of Fire: ", end="")
    # for x in damageFire:
    #     print(x, end=" ")
    # print()

    totalCost = 0

    numberOfOne = len(damageFire)
    numberOfZero = len(damageFrost)

    if numberOfOne > numberOfZero :
        while numberOfZero:
            totalCost  = totalCost + (2*int(damageFire[numberOfOne-1])) + (2*int(damageFrost[numberOfZero-1]))
            numberOfOne = numberOfOne -1
            numberOfZero = numberOfZero - 1
        
        while(numberOfOne):
            totalCost  = totalCost + int(damageFire[numberOfOne-1])
            numberOfOne = numberOfOne - 1
        
    elif numberOfZero > numberOfOne:
        while numberOfOne:
            totalCost  = totalCost + (2*int(damageFire[numberOfOne-1])) + (2*int(damageFrost[numberOfZero-1]))
            numberOfZero = numberOfZero - 1
            numberOfOne = numberOfOne - 1
        
        while(numberOfZero):
            totalCost  = totalCost + int(damageFrost[numberOfZero-1])
            numberOfZero = numberOfZero - 1

    else: # numberOfOne == numberOfZero
        if int(damageFire[0]) < int(damageFrost[0]):
            while numberOfOne:
                totalCost  = totalCost + (2*int(damageFire[numberOfOne-1])) + (2*int(damageFrost[numberOfZero-1]))
                numberOfZero = numberOfZero - 1
                numberOfOne = numberOfOne - 1
            
            totalCost  = totalCost - damageFire[0]

        else:
            while numberOfZero:
                totalCost = totalCost + (2*int(damageFire[numberOfOne-1])) + (2*int(damageFrost[numberOfZero-1]))
                numberOfZero = numberOfZero - 1
                numberOfOne = numberOfOne - 1

            totalCost = totalCost - int(damageFrost[0])
    
    
    # print("Total Cost: ", end=" ")
    print(totalCost)
    # print("\n")


if __name__ == '__main__':

    # print("Testcase: ", testCase)
    for _ in range(int(input())):
        solve()



