#include <iostream>
#include <string>
#include <limits>

class Program {
public:
    // Variáveis estáticas para armazenar informações dos candidatos
    static std::string str_cand_aux;
    static int n_teobaldo, n_astrogildo;
    static bool check_int, check_length, n_ok;

    // Função para verificar a validade do número do eleitor
    static int CheckNumEleit(std::string str_cand) {
        // Verifica se é numérico, diferente de "00" e "0"
        check_int = IsNumeric(str_cand) && str_cand != "00" && str_cand != "0";
        // Verifica se o comprimento é de dois dígitos
        check_length = (str_cand.length() == 2);
        // Verifica se as condições são atendidas e se o número é diferente do anterior
        n_ok = check_int && check_length && str_cand != str_cand_aux;

        // Loop para solicitar um número válido
        while (!n_ok) {
            if (!check_int) {
                std::cout << "Por favor, insira um valor que seja numérico: ";
            } else if (!check_length) {
                std::cout << "Por favor, insira um número que tenha dois algarismos: ";
            } else {
                std::cout << "Tente novamente. Insira um NÚMERO que tenha APENAS DOIS algarismos e que seja DIFERENTE do número anterior: ";
            }
            std::cin >> str_cand;
            check_int = IsNumeric(str_cand) && str_cand != "00" && str_cand != "0";
            check_length = (str_cand.length() == 2);
            n_ok = check_int && check_length && str_cand != str_cand_aux;
        }

        // Atualiza o número anterior e retorna o número convertido para inteiro
        str_cand_aux = str_cand;
        return std::stoi(str_cand);
    }

    // Função para verificar se uma string é numérica
    static bool IsNumeric(const std::string& str) {
        for (char c : str) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    // Função principal do programa
    static void Main() {
        int n_eleitores, v_teobaldo = 0, v_astrogildo = 0, v_br = 0, v_nulo = 0;
        std::string str_teobaldo, str_astrogildo, voto;

        // Solicita o número de eleitores
        std::cout << "Digite o número de eleitores dessa votação (necessário número ser maior ou igual a 10): ";

        // Verifica se o número de eleitores é válido
        while (!(std::cin >> n_eleitores) || n_eleitores < 10) {
            std::cout << "Por favor, digite um número válido para o número de eleitores (maior ou igual a 10): ";
            std::cin.clear(); // Limpa o estado de erro do cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consumir a quebra de linha pendente

        // Solicita o número do candidato Teobaldo
        std::cout << "Insira o número do candidato Teobaldo (O número deve conter apenas dois dígitos e deve ser diferente de '00' e de '0'): ";
        std::cin >> str_teobaldo;
        n_teobaldo = CheckNumEleit(str_teobaldo);

        // Solicita o número do candidato Astrogildo
        std::cout << "Insira agora o número do candidato Astrogildo (Novamente, apenas dois dígitos diferente de '00', '0' e do número do candidato anterior '" << n_teobaldo << "'): ";
        std::cin >> str_astrogildo;
        n_astrogildo = CheckNumEleit(str_astrogildo);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consumir a quebra de linha pendente

        // Loop para receber os votos
        for (int i = 0; i < n_eleitores; i++) {
            std::cout << "Por favor, insira o " << i + 1 << "° voto: ";
            std::getline(std::cin, voto);

            // Contabiliza os votos
            if (voto == std::to_string(n_teobaldo)) {
                v_teobaldo++;
            } else if (voto == std::to_string(n_astrogildo)) {
                v_astrogildo++;
            } else if (voto == "00" || voto == "0") {
                v_br++;
            } else {
                v_nulo++;
            }
        }

        // Exibe os resultados da eleição
        std::cout << "O resultado das eleições foram:" << std::endl;
        std::cout << "O candidato Teobaldo recebeu " << v_teobaldo << " votos!" << std::endl;
        std::cout << "O candidato Astrogildo recebeu " << v_astrogildo << " votos!" << std::endl;
        std::cout << "Houve " << v_br << " votos brancos e " << v_nulo << " votos nulos." << std::endl;

        // Verifica o vencedor
        if (v_teobaldo > v_astrogildo) {
            std::cout << "O candidato Teobaldo venceu as eleições para prefeito!" << std::endl;
        } else if (v_astrogildo > v_teobaldo) {
            std::cout << "O candidato Astrogildo venceu as eleições para prefeito!" << std::endl;
        } else {
            std::cout << "A eleição deu empate!" << std::endl;
        }
    }
};

// Inicializa as variáveis estáticas
std::string Program::str_cand_aux = "";
int Program::n_teobaldo = 0;
int Program::n_astrogildo = 0;
bool Program::check_int = false;
bool Program::check_length = false;
bool Program::n_ok = false;

int main() {
    // Chama a função principal do programa
    Program::Main();
    return 0;
}