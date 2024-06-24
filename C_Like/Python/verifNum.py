def verifNum(str_n):

    while True:
        try:
            n = int(str_n)
            break
        except:
            str_n = str(input("Por favor, digite um número: "))

    return n
