import checkNumEleit
import verifNum

v_teobaldo = 0
v_astrogildo = 0 
v_br = 0 
v_nulo = 0
str_cand_aux = ''

# Verifica o número através da função e armazena na variável n_eleitores
n_eleitores = verifNum.verifNum(input("Digite o número de eleitores dessa votação (necessário número ser maior ou " +
    "igual a 10) :"))

# Enquanto "n_eleitores" for < 10, pede ao usuário que insira um valor > 10
while (n_eleitores < 10):
    n_eleitores = int(input("Por favor, digite um número de eleitores maior ou igual a 10: "))

str_teobaldo = str(input("Insira o número do candidato Teobaldo (O número deve conter apenas dois dígitos "+
"e deve ser diferente de '00' e de '0'): "))

n_teobaldo = checkNumEleit.checkNumEleit(str_teobaldo)
str_cand_aux = str_teobaldo

str_astrogildo = str(input("Insira agora o número do candidato Astrogildo (Novamente, apenas dois dígitos "+
f"diferente de '00', '0' e do número do candidato anterior '{n_teobaldo}'): "))

n_astrogildo = checkNumEleit.checkNumEleit(str_astrogildo)

# Para cada valor de "i" menor que "n_eleitores", executa o bloco abaixo e incrementa o valor de "i"
for eleitor in range(0, n_eleitores):
    voto = str(input(f"Por favor, insira o {eleitor + 1}° voto: "))

    # Se "voto" for igual a "str_teobaldo", adiciona um voto para Teobaldo em "v_teobaldo"
    if (voto == str_teobaldo):
        v_teobaldo += 1

    # Se não, se "voto" for igual a "str_astrogildo", adiciona um voto para Astrogildo em "v_astrogildo"
    elif (voto == str_astrogildo):
        v_astrogildo += 1

    # Se não, se "voto" for igual a "00" OU "0", adiciona um voto em branco  em "v_br"
    elif (voto == "00" or voto == "0"):
        v_br += 1

    # Se não for nenhuma das opções acima, adiciona um voto nulo  em "v_nulo"
    else:
        v_nulo += 1

print("O resultado das eleições foram: \n")
print(f"O candidato Teobaldo recebeu {v_teobaldo} votos! \n")
print(f"O candidato Astrogildo recebeu {v_astrogildo} votos! \n")
print(f"Houve {v_br} votos brancos e {v_nulo} votos nulos. \n")

# Se os votos em Teobaldo forem maiores que em Astrogildo, declara vitória para Teobaldo
if (v_teobaldo > v_astrogildo):
    print("O candidato Teobaldo venceu as eleições para prefeito!")

# Se não, se os votos em Astrogildo forem maiores que em Teobaldo, declara vitória para Astrogildo
elif (v_astrogildo > v_teobaldo):
    print("O cadidato Astrogildo venceu as eleições para prefeito!")

# Se não, se os votos em Teobaldo forem iguais aos em Astrogildo, declara empate
elif (v_teobaldo == v_astrogildo):
    print("A eleição deu empate!")
    