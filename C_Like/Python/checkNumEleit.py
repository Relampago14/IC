str_cand_aux = []

def checkNumEleit(str_cand):

    n_ok = False

    # Enquanto "n_ok" for falso, executa o bloco abaixo
    while (not (n_ok)):

        try:
            n_cand = int(str_cand)
            n_int = True

        except ValueError:
            n_int = False

        # Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
        check_int = n_int and str_cand != "00" and str_cand != "0"

        # Checa se "str_cand" possui dois dígitos
        check_length = (len(str_cand) == 2)

        # Se "check_int" E "check_lenght" forem verdadeiros E "str_cand" for diferente de "str_cand_aux",
        # "n_ok" é verdadeiro também
        n_ok = check_int and check_length and str_cand not in str_cand_aux

        # Se "check_int" for falso, pede ao usuário que digite um valor numérico
        if (not(check_int)):
            str_cand = str(input("Por favor, insira um valor que seja númerico: "))

        # Se não, se "check_length" for falso, pede ao usuário que digite um valor com dois dígitos
        elif (not(check_length)):
            str_cand = str(input("Por favor, insira um número que tenha dois algarismos, não podendo ser '00': "))
        
        elif (not(n_ok)):
            str_cand = str(input("Tente novamente. Insira um NÚMERO que tenha APENAS DOIS algarismos "+
            "e que seja DIFERENTE do número anterior: "))

    n_cand = int(str_cand)
    str_cand_aux.append(str(n_cand))

    return n_cand
