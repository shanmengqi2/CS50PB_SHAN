from cs50 import get_int


def main():
    cardID = str(get_int("Number: "))

    checkCard(cardID)


def checkCard(cardID):
    if (len(cardID) < 13):
        print("INVALID")

    if (validateCard(cardID) == 0):
        print("INVALID")
    else:
        cardType = checkCardType(cardID)
        print(cardType)


def validateCard(cardID):
    sum1 = 0
    substracted = 0
    for i in range((len(cardID)-1), -1, -1):
        if (substracted % 2 == 0):
            sum1 = sum1 + int(cardID[i])
        else:
            temp = int(cardID[i]) * 2
            if temp < 10:
                sum1 = sum1 + temp
            else:
                sum1 = sum1 + (temp % 10) + (temp // 10)
        substracted += 1

    if sum1 % 10 == 0:
        print("validateCard pass")
        return 1

    return 0


def checkCardType(cardID):
    length = len(cardID)
    if length == 15:
        if cardID[0] == '3' and (cardID[1] == '4' or cardID[1] == '7'):
            return "AMEX"
    elif length == 16:
        if cardID[0] == '5' and (cardID[1] in ['1', '2', '3', '4', '5']):
            return "MASTERCARD"
        elif cardID[0] == '4':
            return "VISA"
    elif length == 13 and cardID[0] == '4':
        return "VISA"

    return "INVALID"


main()
