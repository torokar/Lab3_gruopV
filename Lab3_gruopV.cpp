//Группа В
#include "class_matrix_lab3.h"
#include "choice_lab3.h"

int main()
{
    setlocale(LC_ALL, "ru");

    int choice;
    int ch;
    std::cout << "\t\t\t**Строки: должны быть больше 1 и меньше 10**\n"
        << "\t\t\t**Столбцы: должны быть больше 1 и меньше 10**\n\n";

    bool flag = true;
    do
    {
        std::cout << "0) выход из программы!\n1) Запустить\n--> ";
        std::cin >> ch;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(1000, '\n'); 
            std::cout << "Некорректный ввод. Повторите попытку!\n\n";
            continue; 
        }

        switch (ch)
        {
        case 1:
        {
            MatrixAmAn matrix;
            menu user_input;
            choice = user_input.choice_menu();
            matrix.push_matrix(choice);
            matrix.searc_max_el();
            matrix.how_many_zero();
            matrix.sort_arr();
            matrix.print();
            flag = false;
            break;
        }
        case 0:
        {
            std::cout << "До скорой встречи<3";
            flag = false;
            return 0;
            break;
        }
        default:
        {
            std::cout << "Некорректный ввод. Повторите попытку!\n\n";
            break;
        }
        }
    } while (flag);

    return 0;
}