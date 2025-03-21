#include <iomanip>
#include <iostream>

struct menu
{

    int choice_menu()
    {
        int ch = 0;
        bool flag = true;
        do
        {
            std::cout << "Введите ваш выбор:\n"
                << "1) Ручной ввод\n"
                << "2) Автоматический ввод\n"
                << "0) Выход\n--> ";
            std::cin >> ch;
            switch (ch)
            {
            case 1:
            {
                std::cout << "Вы выбрали 'Ручной ввод'!\n\n";
                flag = false;
                break;
            }
            case 2:
            {
                std::cout << "Вы выбрали 'Автоматический ввод'!\n\n";
                flag = false;
                break;
            }
            case 0:
            {
                flag = false;
                std::cout << "Выход из программы!\n\n";
                break;
            }
            default:
            {
                system("cls");
                std::cout << "Некорректный ввод. Повторите попытку!\n\n";
                break;
            }
            }
        } while (flag);

        return ch;
    }
};