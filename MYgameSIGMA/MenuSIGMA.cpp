
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
		std::cout << "Пусть первый игрок введет имя: ";
		std::getline(std::cin, NameFirstHuman);
		std::cout << "\nПусть второй игрок введет имя: ";
		std::getline(std::cin, NameSecondHuman);

		if (NameFirstHuman.empty() || NameSecondHuman.empty())
		{
			std::cout << "Вы не заполнили оба поля. Пожалуйста, повторите ввод.\n";
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
	std::cout << "\nМЕНЮ ИГРЫ:" << "\n\n";
	std::cout << "|_________________________________|" << "\n";
	std::cout << " | 1.  Играть                    |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |-------------------------------|" << "\n";
	std::cout << " | 2.  Справка                   |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |_______________________________|" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " | 3.  Выйти из игры             |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << "|---------------------------------|" << "\n\n\n";
	std::cout << "Выберите необходимый пункт соответствующей цифры: ";
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
		std::cout << "\n\nДовстречи " << NameFirstHuman << ", " << NameSecondHuman;
	}
	else if (play > 3)
	{
		std::cout << "Вы выбрали неправильное число!\nПожалуйста Выберите число из списка!\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("pause");
		system("cls");
		Back();

	}
}
// Работает!

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
	std::cout << "\nМЕНЮ ИГРЫ:" << "\n\n";
	std::cout << "|_________________________________|" << "\n";
	std::cout << " | 1.  Играть                    |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |-------------------------------|" << "\n";
	std::cout << " | 2.  Справка                   |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " |_______________________________|" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << " | 3.  Выйти из игры             |" << "\n";
	std::cout << " |                               |" << "\n";
	std::cout << "|---------------------------------|" << "\n\n\n";
	std::cout << "Выберите необходимый пункт соответствующей цифры: ";
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
		std::cout << "\n\nДовстречи " << NameFirstHuman << ", " << NameSecondHuman;
	}
	else if (play > 3)
	{
		std::cout << "Вы выбрали неправильное число!\nПожалуйста Выберите число из списка!\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("pause");
		system("cls");
		Back();

	}
}

