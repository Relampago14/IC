#include <stdio.h>
#include "checknumEleit.h"

int main(void) {
  int n_eleitores, n_teobaldo, n_astrogildo, v_teobaldo = 0, v_astrogildo = 0, v_br = 0, v_nulo = 0;
  char str_n_eleitores[20], str_teobaldo[20], str_astrogildo[20], voto[20];

  printf("Digite o número de eleitores dessa votação (necessário número ser maior ou igual a 10) : ");
  fgets(str_n_eleitores, 20, stdin);
  n_eleitores = atoi(str_n_eleitores);

  // Enquanto "n_eleitores" for < 10, pede ao usuário que insira um valor > 10
  while (n_eleitores < 10){

      printf("Por favor, digite um número de eleitores maior ou igual a 10: ");
      fgets(str_n_eleitores, 20, stdin);
      n_eleitores = atoi(str_n_eleitores);

  }

  printf("Insira o número do candidato Teobaldo (O número deve conter apenas dois dígitos e deve ser diferente de '00' e de '0'): ");
  fgets(str_teobaldo, 20, stdin);

  n_teobaldo = checknumEleit(str_teobaldo);

  printf("Insira agora o número do candidato Astrogildo (Novamente, apenas dois dígitos diferente de '00', '0' e do número do candidato anterior:%d):", n_astrogildo);
  fgets(str_astrogildo, 20, stdin);

  n_astrogildo = checknumEleit(str_astrogildo);

  // Para cada valor de "i" menor que "n_eleitores", executa o bloco abaixo e incrementa o valor de "i"
  for (int i = 0; i < n_eleitores; i++){

      printf("Por favor, insira o %d° voto: ", i+1);
      fgets(voto, 20, stdin);

      // Se "voto" for igual a "str_teobaldo", adiciona um voto para Teobaldo em "v_teobaldo"
      if (atoi(voto) == n_teobaldo){
          v_teobaldo++;
      }

      // Se não, se "voto" for igual a "str_astrogildo", adiciona um voto para Astrogildo em "v_astrogildo"
      else if (atoi(voto) == n_astrogildo){
          v_astrogildo++;
      }

      // Se não, se "voto" for igual a "00" OU "0", adiciona um voto em branco  em "v_br"
      else if (strcmp(voto, "00") == 0){
          v_br++;
      }

      // Se não for nenhuma das opções acima, adiciona um voto nulo  em "v_nulo"
      else{
          v_nulo++;
      }

  }

  printf("\nO resultado das eleições foram:");
  printf("\nO candidato Teobaldo recebeu %d votos!", v_teobaldo);
  printf("\nO candidato Astrogildo recebeu %d votos!", v_astrogildo);
  printf("\nHouve %d votos brancos e %d votos nulos.", v_br, v_nulo);

  // Se os votos em Teobaldo forem maiores que em Astrogildo, declara vitória para Teobaldo
  if (v_teobaldo > v_astrogildo){
      printf("\nO candidato Teobaldo venceu as eleições para prefeito!");
  }

  // Se não, se os votos em Astrogildo forem maiores que em Teobaldo, declara vitória para Astrogildo
  else if (v_astrogildo > v_teobaldo){
      printf("O cadidato Astrogildo venceu as eleições para prefeito!");
  }

  // Se não, se os votos em Teobaldo forem iguais aos em Astrogildo, declara empate
  else if (v_teobaldo == v_astrogildo){
      printf("A eleição deu empate!");
  }

}