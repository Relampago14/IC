using System;

class Funcs{   
    public static int verifNum(string str_num){

        // Pega a string recebida e somente irá liberar caso a mesma possa ser convertida para inteiro

        int int_num;

        while (!(int.TryParse(str_num, out int_num))){

            Console.WriteLine("Por favor, digite um número: ");
            str_num = Console.ReadLine();

        }

        return int_num;

    }
}
