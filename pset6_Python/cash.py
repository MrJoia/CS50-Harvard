from cs50 import get_float

# Atribui os valores às variáveis moedas
cents25 = 25
cents10 = 10
cents05 = 5
cents01 = 1
moedas = 0

# Obtém o valor do troco do usuário e valida se é um valor não negativo
while True:
    troco = get_float("Digite o valor do troco: ")
    if troco < 0:
        troco = get_float("Digite o valor do troco: ")
    else:
        break
    
troco = troco * 100    

# Obtém o número de moedas necessárias para o troco
while troco >= cents01:
    # Obtém quantidade de moedas de 25 centavos
    if troco >= cents25:
        troco = troco - cents25
        moedas += 1
    # Obtém quantidade de moedas de 10 centavos
    elif troco >= cents10:
        troco = troco - cents10
        moedas += 1
    # Obtém quantidade de moedas de 05 centavos    
    elif troco >= cents05:
        troco = troco - cents05
        moedas += 1
    # Obtém quantidade de moedas de 01 centavo
    else:
        troco = troco - cents01
        moedas += 1

# Imprime a quantidade de moedas necessárias para o troco
print(f"{moedas}")
