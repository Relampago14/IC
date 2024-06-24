#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checknumEleit(char str_cand[20]){

  int n_cand;
  char str_cand_aux[20];

  // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
  int check_int = atoi(str_cand) != 0 && strcmp(str_cand, "00") != 0;

  // Checa se "str_cand" possui dois dígitos
  int check_length = (strlen(str_cand) == 3);

  // Se "check_int" E "check_lenght" forem verdadeiros E "str_cand" for diferente de "str_cand_aux",
  // "n_ok" é verdadeiro também
  int n_ok = check_int && check_length && str_cand != str_cand_aux;

  // Enquanto "n_ok" for falso, executa o bloco abaixo
  while (!(n_ok)){

      // Se "check_int" for falso, pede ao usuário que digite um valor numérico
      if (!(check_int)){
          printf("Por favor, insira um valor que seja númerico: ");
          fgets(str_cand, 20, stdin);
          
          // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
          check_int = atoi(str_cand) != 0 && strcmp(str_cand, "00") != 0;
          // Checa se "str_cand" possui dois dígitos
          check_length = (strlen(str_cand) == 3);
      }

      // Se não, se "check_length" for falso, pede ao usuário que digite um valor com dois dígito
      else if (!(check_length)){
          printf("Por favor, insira um número que tenha dois algarismos, não podendo ser '00': ");
          fgets(str_cand, 20, stdin);
          // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
          check_int = atoi(str_cand) != 0 && strcmp(str_cand, "00") != 0;
          // Checa se "str_cand" possui dois dígitos
          check_length = (strlen(str_cand) == 3);
      }

      else{
          printf("Tente novamente. Insira um NÚMERO que tenha APENAS DOIS algarismos e que seja DIFERENTE do número anterior: ");
          fgets(str_cand, 20, stdin);
          // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
          check_int = atoi(str_cand) != 0 && strcmp(str_cand, "00") != 0;
          // Checa se "str_cand" possui dois dígitos
          check_length = (strlen(str_cand) == 3);
      }

      // Revalida a variável "n_ok"
      n_ok = check_int && check_length && str_cand != str_cand_aux;

  }
  n_cand = atoi(str_cand);
  return n_cand;
}