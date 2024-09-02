
#include "Games.hpp"
#include "SIGMAINFO.hpp"
#include "MenuSIGMA.hpp"

std::string NameFirstHuman = " ";
std::string NameSecondHuman = " ";
void Back();
void Menu()
{
	int play;

	do
	{
		std::cout << "����� ������ ����� ������ ���: ";
		std::getline(std::cin, NameFirstHuman);
		std::cout << "\n����� ������ ����� ������ ���: ";
		std::getline(std::cin, NameSecondHuman);

		if (NameFirstHuman.empty() || NameSecondHuman.empty())
		{
			std::cout << "�� �� ��������� ��� ����. ����������, ��������� ����.\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system("pause");
			system("cls");
		}
	} while (NameFirstHuman.empty() || NameSecondHuman.empty());
	system("cls");
	std::cout << " ____      ____    __   __       ___ " << "\n";
	std::cout << "|      |  |       |  | | |      /  |" << "\n";
	std::cout << " |     |  |       |  |_| |     /   |" << "\n";
	std::cout << "  |    |  |  --|  |      |    /    |" << "\n";
	std::cout << "   |   |  |    |  |      |   /-----|" << "\n";
	std::cout << "____|  |  |____|  |      |  /      |" << "\n";
	std::cout << "\n���� ����:" << "\n\n";
	std::cout << "|_________________________________|" << "\n";
	std::cout << " | 1.  ������                    |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |-------------------------------|" << "\n";
	std::cout << " | 2.  �������                   |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |_______________________________|" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " | 3.  ����� �� ����             |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << "|---------------------------------|" << "\n\n\n";
	std::cout << "�������� ����������� ����� ��������������� �����: ";
	std::cin >> play;
	system("cls");

	if (play == 1)
	{

		Games();
		Back();
	}
	else if (play == 2)
	{
		SIGMAINFO();
		Back();
	}
	else if (play == 3)
	{
		std::cout << "\n\n��������� " << NameFirstHuman << ", " << NameSecondHuman;
	}
	else if (play > 3)
	{
		std::cout << "�� ������� ������������ �����!\n���������� �������� ����� �� ������!\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("pause");
		system("cls");
		Back();

	}
}
// ��������!

void Back()
{

	int play;
	std::cout << "\n\n";
	std::cout << " ____      ____    __   __       ___ " << "\n";
	std::cout << "|      |  |       |  | | |      /  |" << "\n";
	std::cout << " |     |  |       |  |_| |     /   |" << "\n";
	std::cout << "  |    |  |  --|  |      |    /    |" << "\n";
	std::cout << "   |   |  |    |  |      |   /-----|" << "\n";
	std::cout << "____|  |  |____|  |      |  /      |" << "\n";
	std::cout << "\n���� ����:" << "\n\n";
	std::cout << "|_________________________________|" << "\n";
	std::cout << " | 1.  ������                    |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |-------------------------------|" << "\n";
	std::cout << " | 2.  �������                   |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |_______________________________|" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " | 3.  ����� �� ����             |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << "|---------------------------------|" << "\n\n\n";
	std::cout << "�������� ����������� ����� ��������������� �����: ";
	std::cin >> play;
	system("cls");

	if (play == 1)
	{

		Games();
		Back();
	}
	else if (play == 2)
	{
		SIGMAINFO();
		Back();
	}
	else if (play == 3)
	{
		std::cout << "\n\n��������� " << NameFirstHuman << ", " << NameSecondHuman;
	}
	else if (play > 3)
	{
		std::cout << "�� ������� ������������ �����!\n���������� �������� ����� �� ������!\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("pause");
		system("cls");
		Back();

	}
}

