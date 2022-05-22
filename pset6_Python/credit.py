import sys
def main():
    
    # Obtém o número do cartão do usuário
    while True:
        card = input("Number: ")
        
        # Calcula o número de dígitos do cartão
        cardLength = len(card)
        if cardLength > 0 and int(card):
            break
        
    # Valida se o cartão é válido (possui entre 13 e 16 dígitos)
    validateCard(card, cardLength)
def validateCard(card, cardLength):
    if cardLength < 13 or cardLength > 16:
        print("INVALID")
        sys.exit(0)
    evenSum = 0
    oddSum = 0
    cardCopy = card

# Calculate checksum
    for i in range(0, cardLength, 2):
        oddNum = int(cardCopy) % 100 // 10
        oddNum *= 2
        while oddNum >= 10:
            oddSum += oddNum % 10
            oddNum //= 10
            oddSum += oddNum
            evenSum += int(cardCopy) % 10
            cardCopy = int(cardCopy) // 100
        
# Add oddSum (numbers multiplied by 2) to evenSum (numbers not multiplied 2)
    checksum = (oddSum + evenSum) % 10
    
# If valid checksum, print results
    if checksum == 0:
        firstDigit = int(card[0])
        secondDigit = int(card[1])
        if cardLength == 15 and firstDigit == 3 and (secondDigit == 4 or secondDigit == 7):
            print("AMEX")
        elif cardLength == 16 and firstDigit == 5 and 1 <= secondDigit <= 5:
            print("MASTERCARD")
        elif (cardLength == 13 or cardLength == 16) and firstDigit == 4:
            print("VISA")
    else:
        print("INVALID")
if __name__ == "__main__":
    main()
