# import cs50
import cs50
import math
# get cost from user
amount = cs50.get_float()
if (amount >= 1):
    amount *= 100
    numOfDollarsDecimal = amount / 100
    numOfDollarsPure = math.floor(numOfDollarsDecimal)
    dollars = numOfDollarsPure * 100
    amount -= dollars
else:
    amount *= 100
amount = math.floor(amount)
# initialize counter
numOfCoins = 0
# while amount > 0, create series of conditions starting from greatest
while (amount > 0):
    if (amount / 25 >= 1):
        print('true for q')
        numOfCoins += 1
        amount -= 25
        continue
    if (amount / 10 >= 1):
        print('true for d')
        numOfCoins += 1
        amount -= 10
        continue
    if (amount / 5  >= 1):
        print('true for n')
        numOfCoins += 1
        amount -= 5
        continue
    if (amount / 1 >= 1):
        print('true for p')
        numOfCoins += 1
        amount -= 1
print(numOfCoins)
