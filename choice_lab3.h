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
            std::cout << "������� ��� �����:\n"
                << "1) ������ ����\n"
                << "2) �������������� ����\n"
                << "0) �����\n--> ";
            std::cin >> ch;
            switch (ch)
            {
            case 1:
            {
                std::cout << "�� ������� '������ ����'!\n\n";
                flag = false;
                break;
            }
            case 2:
            {
                std::cout << "�� ������� '�������������� ����'!\n\n";
                flag = false;
                break;
            }
            case 0:
            {
                flag = false;
                std::cout << "����� �� ���������!\n\n";
                break;
            }
            default:
            {
                system("cls");
                std::cout << "������������ ����. ��������� �������!\n\n";
                break;
            }
            }
        } while (flag);

        return ch;
    }
};