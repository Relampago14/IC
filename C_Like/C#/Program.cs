using System;

class Program{

    static string str_cand_aux;
    static int n_teobaldo, n_astrogildo;
    static bool check_int = false, check_length = false, n_ok = false;

    public static int CheckNumEleit(string str_cand){

        int n_cand;
        
        // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
        check_int = int.TryParse(str_cand, out n_cand) && str_cand != "00" && str_cand != "0";

        // Checa se "str_cand" possui dois dígitos
        check_length = (str_cand.Length == 2);

        // Se "check_int" E "check_lenght" forem verdadeiros E "str_cand" for diferente de "str_cand_aux",
        // "n_ok" é verdadeiro também
        n_ok = check_int && check_length && str_cand != str_cand_aux;

        // Enquanto "n_ok" for falso, executa o bloco abaixo
        while (!(n_ok)){

            // Se "check_int" for falso, pede ao usuário que digite um valor numérico
            if (!(check_int)){
                Console.Write("Por favor, insira um valor que seja númerico: ");
                str_cand = Console.ReadLine();
                // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
                check_int = int.TryParse(str_cand, out n_cand) && str_cand != "00" && str_cand != "0";
                // Checa se "str_cand" possui dois dígitos
                check_length = (str_cand.Length == 2);
            }

            // Se não, se "check_length" for falso, pede ao usuário que digite um valor com dois dígito
            else if (!(check_length)){
                Console.Write("Por favor, insira um número que tenha dois algarismos, não podendo ser '00': ");
                str_cand = Console.ReadLine();
                // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
                check_int = int.TryParse(str_cand, out n_cand) && str_cand != "00" && str_cand != "0";
                // Checa se "str_cand" possui dois dígitos
                check_length = (str_cand.Length == 2);
            }

            else{
                Console.Write("Tente novamente. Insira um NÚMERO que tenha APENAS DOIS algarismos "+
                "e que seja DIFERENTE do número anterior: ");
                str_cand = Console.ReadLine();
                // Checa se "str_cand" pode ser convertido para o tipo de dado "int" E se é diferente de "00" e "0"
                check_int = int.TryParse(str_cand, out n_cand) && str_cand != "00" && str_cand != "0";
                // Checa se "str_cand" possui dois dígitos
                check_length = (str_cand.Length == 2);
            }

            // Revalida a variável "n_ok"
            n_ok = check_int && check_length && str_cand != str_cand_aux;

        }

        str_cand_aux = str_cand;
        return n_cand;

    }

    public static void Main(){

        int n_eleitores, n_teobaldo, n_astrogildo, v_teobaldo = 0, v_astrogildo = 0, v_br = 0, v_nulo = 0;
        string str_teobaldo, str_astrogildo, voto;

        Console.Write("Digite o número de eleitores dessa votação (necessário número ser maior ou " +
        "igual a 10) : ");
        n_eleitores = (Funcs.verifNum(Console.ReadLine()));
        
        // Enquanto "n_eleitores" for < 10, pede ao usuário que insira um valor > 10
        while (n_eleitores < 10){

            Console.Write("Por favor, digite um número de eleitores maior ou igual a 10: ");
            n_eleitores = Convert.ToInt32(Console.ReadLine());

        }

        Console.Write("Insira o número do candidato Teobaldo (O número deve conter apenas dois dígitos "+
        "e deve ser diferente de '00' e de '0'): ");
        str_teobaldo = Console.ReadLine();

        n_teobaldo = CheckNumEleit(str_teobaldo);

        Console.Write("Insira agora o número do candidato Astrogildo (Novamente, apenas dois dígitos "+
        $"diferente de '00', '0' e do número do candidato anterior '{n_teobaldo}'): ");
        str_astrogildo = Console.ReadLine();

        n_astrogildo = CheckNumEleit(str_astrogildo);

        // Para cada valor de "i" menor que "n_eleitores", executa o bloco abaixo e incrementa o valor de "i"
        for (int i = 0; i < n_eleitores; i++){

            Console.Write($"Por favor, insira o {i+1}° voto: ");
            voto = Console.ReadLine();

            // Se "voto" for igual a "str_teobaldo", adiciona um voto para Teobaldo em "v_teobaldo"
            if (Convert.ToInt32(voto) == n_teobaldo){
                v_teobaldo++;
            }

            // Se não, se "voto" for igual a "str_astrogildo", adiciona um voto para Astrogildo em "v_astrogildo"
            else if (Convert.ToInt32(voto) == n_astrogildo){
                v_astrogildo++;
            }

            // Se não, se "voto" for igual a "00" OU "0", adiciona um voto em branco  em "v_br"
            else if (voto == "00" || voto == "0"){
                v_br++;
            }

            // Se não for nenhuma das opções acima, adiciona um voto nulo  em "v_nulo"
            else{
                v_nulo++;
            }

        }

        Console.WriteLine("O resultado das eleições foram:");
        Console.WriteLine($"O candidato Teobaldo recebeu {v_teobaldo} votos!");
        Console.WriteLine($"O candidato Astrogildo recebeu {v_astrogildo} votos!");
        Console.WriteLine($"Houve {v_br} votos brancos e {v_nulo} votos nulos.");

        // Se os votos em Teobaldo forem maiores que em Astrogildo, declara vitória para Teobaldo
        if (v_teobaldo > v_astrogildo){
            Console.Write("O candidato Teobaldo venceu as eleições para prefeito!");
        }

        // Se não, se os votos em Astrogildo forem maiores que em Teobaldo, declara vitória para Astrogildo
        else if (v_astrogildo > v_teobaldo){
            Console.Write("O cadidato Astrogildo venceu as eleições para prefeito!");
        }

        // Se não, se os votos em Teobaldo forem iguais aos em Astrogildo, declara empate
        else if (v_teobaldo == v_astrogildo){
            Console.Write("A eleição deu empate!");
        }

    }

}