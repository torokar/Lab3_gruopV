#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>

class MatrixAmAn
{
private:
	int row;
	int col;
	int couter = 0;
	double** arr;
	double** sort_a;
	double* max_el_row;
	bool flag = true;
public:

	MatrixAmAn()
	{

		do
		{
			std::cout << "������� ���������� ����� �������:\n--> ";
			std::cin >> row;
			std::cout << "������� ���������� �������� �������\n--> ";
			std::cin >> col;
			while (row < 1 || row > 10 || col > 10 || col < 1 || std::cin.fail())
			{
				std::cout << "������������ ����! ���������� ��� ���!\n";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "������:\n--> ";
				std::cin >> row;
				std::cout << "�������:\n--> ";
				std::cin >> col;
			}
			flag = false;
		} while (flag);


		arr = new double* [row];

		for (int i = 0; i < row; i++)
		{
			arr[i] = new double[col];
		}

		max_el_row = new double[row];
		sort_a = new double* [row];
		for (int i = 0; i < row; i++)
		{
			sort_a[i] = new double[col];
		}
	}

	void push_matrix(int ch)
	{
		int num;
		if (ch == 1)
		{
			std::cout << "������� �������� �������:\n";
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					std::cout << "������ " << i + 1 << " ������� " << j + 1 << "\n--> ";
					std::cin >> num;
					while (std::cin.fail())
					{
						std::cout << "������������ ���� ��������!\n--> ";
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cin >> num;
					}
					arr[i][j] = num;
				}
			}
		}
		else if (ch == 2)
		{
			srand(time(NULL));
			std::cout << "�������������� ���������� �������\n";
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					arr[i][j] = rand() % 100001 - 20000;
				}
			}
		}
	}

	void how_many_zero()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == 0)
				{
					couter++;
				}
			}
		}
	}

	void searc_max_el()
	{
		double max_el = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (max_el < arr[i][j])
				{
					max_el = arr[i][j];
				}
			}
			max_el_row[i] = max_el;
			max_el = 0;
		}
	}


	//�������� ���������� ����� ��������� �� ������ ������, �� ������ ������� ����� ���������� �������� ����� ���� ����� � ��� ����� �� ��������
	void sort_arr()
	{

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				sort_a[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < row - 1; i++)
		{
			for (int j = i + 1; j < row; j++)
			{
				if (max_el_row[i] < max_el_row[j])
				{
					for (int k = 0; k < col; k++)
					{
						double temp = arr[i][k];
						arr[i][k] = arr[j][k];
						arr[j][k] = temp;
					}
					double temp_max = max_el_row[i];
					max_el_row[i] = max_el_row[j];
					max_el_row[j] = temp_max;
				}
			}
		}

	}


	void print()
	{
		//����� ������� 
		std::string str = "-";
		system("cls");
		std::cout << "\n ������� " << row << "X" << col << std::endl;
		for (int i = 0; i < row; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < col; j++)
			{
				std::cout << std::setw(6) << sort_a[i][j] << " | ";
			}
			std::cout << std::endl << " ";
		}

		//������������ �������� �� ��������
		for (int i = 0; i < row; i++)
		{
			std::cout << "\n���������� ����� � ������� " << i + 1 << ") " << max_el_row[i] << std::endl;
		}

		//���������� 0 � �������
		std::cout << "\n���������� 0 � ������� = " << couter << std::endl;

		std::cout << "\n��������������� ������:\n";
		for (int i = 0; i < row; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < col; j++)
			{
				std::cout << std::setw(6) << arr[i][j] << " | ";
			}
			std::cout << std::endl << " ";
		}

	}

	~MatrixAmAn()
	{
		for (int i = 0; i < row; i++)
		{
			delete[] arr[i];
		}
		for (int i = 0; i < row; i++)
		{
			delete[] sort_a[i];
		}

		delete[] sort_a;
		delete[] arr;
		delete[] max_el_row;
	}

};