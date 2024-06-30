
#include "Games.hpp"
#include "MenuSIGMA.hpp"


#if defined(max)
#undef max
#endif

// ВСЕ СДЕЛАНО!

//Создание переменных!

// Корабельная ячейка под номерами 1 - 4 первого человека
char ship_cellOneFirstHuman = '1';
char ship_cellTwoFirstHuman = '2';
char ship_cellThreeFirstHuman = '3';
char ship_cellFourFirstHuman = '4';
// Установка кораблей первого человека по углам X и Y
int ship_cellOneCornerX_FirstHuman;
int ship_cellOneCornerY_FirstHuman;
int ship_cellTwoCornerX_FirstHuman;
int ship_cellTwoCornerY_FirstHuman;
int ship_cellThreeCornerX_FirstHuman;
int ship_cellThreeCornerY_FirstHuman;
int ship_cellFourCornerX_FirstHuman;
int ship_cellFourCornerY_FirstHuman;

// Корабельная ячейка под номерами 1 - 4 второго человека
char ship_cellOneSecondHuman = '1';
char ship_cellTwoSecondHuman = '2';
char ship_cellThreeSecondHuman = '3';
char ship_cellFourSecondHuman = '4';
// Установка кораблей второго человека по углам X и Y
int ship_cellOneCornerX_SecondHuman;
int ship_cellOneCornerY_SecondHuman;
int ship_cellTwoCornerX_SecondHuman;
int ship_cellTwoCornerY_SecondHuman;
int ship_cellThreeCornerX_SecondHuman;
int ship_cellThreeCornerY_SecondHuman;
int ship_cellFourCornerX_SecondHuman;
int ship_cellFourCornerY_SecondHuman;

const int field_sizeByX = 10;// Граница поля по углу X
const int field_sizeByY = 10;// Граница поля по углу Y
const char empty_cell = '.';// Установка точки на пустые строки при выводе поля


int tempInput; // Защита от ввода букв и символов


// Вывод поля первого человека
void printFieldFirstHuman(char fieldFirstHuman[field_sizeByX][field_sizeByY])
{
    std::cout << "  ";
    for (int i = 0; i < field_sizeByX; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < field_sizeByY; ++i)
    {
        std::cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < field_sizeByX; ++j)
        {
            std::cout << fieldFirstHuman[i][j] << " ";
        }
        std::cout << "\n";
    }
}
//Работает

void printFieldSecondHuman(char fieldSecondHuman[field_sizeByX][field_sizeByY])
{
    std::cout << "  ";
    for (int i = 0; i < field_sizeByX; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < field_sizeByY; ++i)
    {
        std::cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < field_sizeByX; ++j)
        {
            std::cout << fieldSecondHuman[i][j] << " ";
        }
        std::cout << "\n";
    }
}
//Работает
// Карта
void FieldShipsFirstHuman()
{
    char fieldFirstHuman[field_sizeByX][field_sizeByY];

    for (int i = 0; i < field_sizeByX; ++i)
    {
        for (int j = 0; j < field_sizeByX; ++j)
        {
            fieldFirstHuman[i][j] = empty_cell;
        }
    }
    printFieldFirstHuman(fieldFirstHuman);



}
//  Работает 
void FieldShipsSecondHuman()
{
    char fieldSecondHuman[field_sizeByX][field_sizeByY];

    for (int i = 0; i < field_sizeByX; ++i)
    {
        for (int j = 0; j < field_sizeByX; ++j)
        {
            fieldSecondHuman[i][j] = empty_cell;
        }
    }
    printFieldSecondHuman(fieldSecondHuman);



}


// Растановка кораблей первого человека на поле
void placeShipsFirstHuman(char fieldFirstHuman[field_sizeByX][field_sizeByY])
{
    system("cls");
    std::cout << "Пусть ";
    std::cout << NameFirstHuman;
    std::cout << " заполнит поле кораблями: \n";

    // Первый корабль
    FieldShipsFirstHuman();
    std::cout << "\nВыбери цифрой расположение для 1 корабля по вертикали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellOneCornerY_FirstHuman = tempInput;

    std::cout << "\nВыбери цифрой расположение для 1 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellOneCornerX_FirstHuman = tempInput;
    fieldFirstHuman[ship_cellOneCornerY_FirstHuman - 1][ship_cellOneCornerX_FirstHuman] = ship_cellOneFirstHuman;

    // Проверка координат для первого корабля
    if (ship_cellOneCornerY_FirstHuman > field_sizeByY || ship_cellOneCornerX_FirstHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }


    // Второй корабль
    std::cout << "\nВыбери цифрой расположение для 2 корабля по вертикали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellTwoCornerY_FirstHuman = tempInput;

    std::cout << "\nВыбери цифрой расположение для 2 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellTwoCornerX_FirstHuman = tempInput;
    fieldFirstHuman[ship_cellTwoCornerY_FirstHuman - 1][ship_cellTwoCornerX_FirstHuman] = ship_cellTwoFirstHuman;
    // Проверка координат для второго корабля
    if (ship_cellTwoCornerY_FirstHuman > field_sizeByY || ship_cellTwoCornerX_FirstHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    // Если второй корабль равен координатам первого корабля
    if (ship_cellTwoCornerY_FirstHuman == ship_cellOneCornerY_FirstHuman && ship_cellTwoCornerX_FirstHuman == ship_cellOneCornerX_FirstHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    // Третий корабль
    std::cout << "\nВыбери цифрой расположение для 3 корабля по вертикали: ";
    fieldFirstHuman[ship_cellThreeCornerY_FirstHuman - 1][ship_cellThreeCornerX_FirstHuman] = ship_cellThreeFirstHuman;
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellThreeCornerY_FirstHuman = tempInput;

    std::cout << "\nВыбери цифрой расположение для 3 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellThreeCornerX_FirstHuman = tempInput;
    fieldFirstHuman[ship_cellThreeCornerY_FirstHuman - 1][ship_cellThreeCornerX_FirstHuman] = ship_cellThreeFirstHuman;
    if (ship_cellThreeCornerY_FirstHuman > field_sizeByY || ship_cellThreeCornerX_FirstHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    if (ship_cellThreeCornerX_FirstHuman == ship_cellTwoCornerX_FirstHuman && ship_cellThreeCornerY_FirstHuman == ship_cellTwoCornerY_FirstHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    else if (ship_cellThreeCornerY_FirstHuman == ship_cellOneCornerY_FirstHuman && ship_cellThreeCornerX_FirstHuman == ship_cellOneCornerX_FirstHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }

    // Четвертый корабль
    std::cout << "\nВыбери цифрой расположение для 4 корабля по вертикали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellFourCornerY_FirstHuman = tempInput;

    std::cout << "\nВыбери цифрой расположение для 4 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellFourCornerX_FirstHuman = tempInput;
    fieldFirstHuman[ship_cellFourCornerY_FirstHuman - 1][ship_cellFourCornerX_FirstHuman] = ship_cellFourFirstHuman;
    if (ship_cellFourCornerY_FirstHuman > field_sizeByY || ship_cellFourCornerX_FirstHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции

    }


    if (ship_cellFourCornerY_FirstHuman == ship_cellOneCornerY_FirstHuman && ship_cellFourCornerX_FirstHuman == ship_cellOneCornerX_FirstHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    else if (ship_cellFourCornerY_FirstHuman == ship_cellTwoCornerY_FirstHuman && ship_cellFourCornerX_FirstHuman == ship_cellTwoCornerX_FirstHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    else if (ship_cellFourCornerY_FirstHuman == ship_cellThreeCornerY_FirstHuman && ship_cellFourCornerX_FirstHuman == ship_cellThreeCornerX_FirstHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
}
//Работает


// Растановка кораблей второго человека на поле
void placeShipsSecondHuman(char fieldSecondHuman[field_sizeByX][field_sizeByY])
{
    system("cls");
    // Первый корабль  
    std::cout << "Пусть ";
    std::cout << NameSecondHuman;
    std::cout << " заполнит поле кораблями: \n";
    FieldShipsSecondHuman();
    std::cout << "\nВыбери цифрой расположение для 1 корабля по вертикали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellOneCornerY_SecondHuman = tempInput;
    std::cout << "\nВыбери цифрой расположение для 1 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellOneCornerX_SecondHuman = tempInput;
    fieldSecondHuman[ship_cellOneCornerY_SecondHuman - 1][ship_cellOneCornerX_SecondHuman] = ship_cellOneSecondHuman;
    // Проверка координат для первого корабля
    if (ship_cellOneCornerY_SecondHuman > field_sizeByY || ship_cellOneCornerX_SecondHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }

    // Второй корабль
    std::cout << "\nВыбери цифрой расположение для 2 корабля по вертикали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellTwoCornerY_SecondHuman = tempInput;
    std::cout << "\nВыбери цифрой расположение для 2 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellTwoCornerX_SecondHuman = tempInput;
    fieldSecondHuman[ship_cellTwoCornerY_SecondHuman - 1][ship_cellTwoCornerX_SecondHuman] = ship_cellTwoSecondHuman;
    // Проверка координат для второго корабля
    if (ship_cellTwoCornerY_SecondHuman > field_sizeByY || ship_cellTwoCornerX_SecondHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }


    if (ship_cellTwoCornerY_SecondHuman == ship_cellOneCornerY_SecondHuman && ship_cellTwoCornerX_SecondHuman == ship_cellOneCornerX_SecondHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }

    // Третий корабль
    std::cout << "\nВыбери цифрой расположение для 3 корабля по вертикали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellThreeCornerY_SecondHuman = tempInput;
    std::cout << "\nВыбери цифрой расположение для 3 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellThreeCornerX_SecondHuman = tempInput;
    fieldSecondHuman[ship_cellThreeCornerY_SecondHuman - 1][ship_cellThreeCornerX_SecondHuman] = ship_cellThreeSecondHuman;
    if (ship_cellThreeCornerY_SecondHuman > field_sizeByY || ship_cellThreeCornerX_SecondHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }

    if (ship_cellThreeCornerX_SecondHuman == ship_cellTwoCornerX_SecondHuman && ship_cellThreeCornerY_SecondHuman == ship_cellTwoCornerY_SecondHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    else if (ship_cellThreeCornerY_SecondHuman == ship_cellOneCornerY_SecondHuman && ship_cellThreeCornerX_SecondHuman == ship_cellOneCornerX_SecondHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    // Четвертый корабль
    std::cout << "\nВыбери цифрой расположение для 4 корабля по вертикали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellFourCornerY_SecondHuman = tempInput;
    std::cout << "\nВыбери цифрой расположение для 4 корабля по горизонтали: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "Ошибка! Нужно вводить только цифры.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellFourCornerX_SecondHuman = tempInput;
    fieldSecondHuman[ship_cellFourCornerY_SecondHuman - 1][ship_cellFourCornerX_SecondHuman] = ship_cellFourSecondHuman;
    if (ship_cellFourCornerY_SecondHuman > field_sizeByY || ship_cellFourCornerX_SecondHuman >= field_sizeByX)
    {
        std::cout << "Вы выбрали не правильные координаты поля!\nПопробуйте еще раз!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }

    if (ship_cellFourCornerY_SecondHuman == ship_cellOneCornerY_SecondHuman && ship_cellFourCornerX_SecondHuman == ship_cellOneCornerX_SecondHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }
    else if (ship_cellFourCornerX_SecondHuman == ship_cellThreeCornerX_SecondHuman && ship_cellFourCornerY_SecondHuman == ship_cellThreeCornerY_SecondHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции
    }

    else if (ship_cellFourCornerY_SecondHuman == ship_cellTwoCornerY_SecondHuman && ship_cellFourCornerX_SecondHuman == ship_cellTwoCornerX_SecondHuman)
    {
        std::cout << "Вы выбрали одинаковые поля!\nВыберите другое поле!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // Добавлен return для предотвращения повторного вызова функции

    }

    system("cls");
}
//Работает


// Функция для проверки попадания и обновления поля
bool checkHitAndUpdateField(char field[][field_sizeByX], int y, int x, char shipSymbol)
{
    if (field[y][x] == shipSymbol)
    {
        field[y][x] = 'X'; // Пометить попадание
        return true;
    }
    else if (field[y][x] == empty_cell)
    {
        field[y][x] = '*'; // Пометить промах
    }
    return false;
}
//Работает

void updateAndPrintFieldFirstHuman(char field[field_sizeByX][field_sizeByY], int y, int x, bool hit)
{
    // Обновляем поле в зависимости от результата атаки
    field[y][x] = hit ? 'X' : '*';

    // Выводим обновленное поле без показа кораблей
    std::cout << "  ";
    for (int i = 0; i < field_sizeByX; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < field_sizeByY; ++i)
    {
        std::cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < field_sizeByX; ++j)
        {
            // Показываем только попадания 'X', промахи '*' и пустые ячейки '.'
            if (field[i][j] == 'X' || field[i][j] == '*' || field[i][j] == empty_cell)
            {
                std::cout << field[i][j] << " ";
            }
            else
            {
                std::cout << empty_cell << " "; // Заменяем символы кораблей на пустые ячейки
            }
        }
        std::cout << "\n";
    }
}
void updateAndPrintFieldSecondHuman(char fieldSecondHuman[field_sizeByX][field_sizeByY], int y, int x, bool hit)
{
    // Обновляем поле в зависимости от результата атаки
    fieldSecondHuman[y][x] = hit ? 'X' : '*';

    // Выводим обновленное поле без показа кораблей
    std::cout << "  ";
    for (int i = 0; i < field_sizeByX; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < field_sizeByY; ++i)
    {
        std::cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < field_sizeByX; ++j)
        {
            // Показываем только попадания 'X', промахи '*' и пустые ячейки '.'
            if (fieldSecondHuman[i][j] == 'X' || fieldSecondHuman[i][j] == '*' || fieldSecondHuman[i][j] == empty_cell)
            {
                std::cout << fieldSecondHuman[i][j] << " ";
            }
            else
            {
                std::cout << empty_cell << " "; // Заменяем символы кораблей на пустые ячейки
            }
        }
        std::cout << "\n";
    }
}
// Работает 

// Атака на противника
void AttackPlayer(char fieldFirstHuman[field_sizeByX][field_sizeByY], char fieldSecondHuman[field_sizeByX][field_sizeByY])
{
    int rounds = 5;
    int AttackByAngleX, AttackByAngleY;
    int shipsSunkFirstHuman = 0;
    int shipsSunkSecondHuman = 0;


    std::cout << "Помните:\n 1 - Попадание отмечается символом X, промах отмечается символом *\n 2 - Если кто-то потопил корабль противника, то он еще раз атакует противника \n 3 - У вас есть 5 раундов";
    std::cout << "\n 4 - Выигрывает тот кто больше всего потопил кораблей\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("pause");
    system("cls");
    for (int round = 1; round <= rounds; ++round)
    {
        std::cout << "\n" << round << " Раунд!\n\n";
        std::cout << "==========================================\n";
        std::cout << NameFirstHuman;
        std::cout << " атакует ";
        std::cout << NameSecondHuman;
        std::cout << "\n";
        std::cout << "Выберите расположение атаки по вертикали: ";
        while (!(std::cin >> AttackByAngleY) || AttackByAngleY <= 0 || AttackByAngleY > field_sizeByY)
        {
            std::cout << "Ошибка! Введите число от 1 до " << field_sizeByY << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Выберите расположение атаки по горизонтали: ";
        while (!(std::cin >> AttackByAngleX) || AttackByAngleX < 0 || AttackByAngleX >= field_sizeByX)
        {
            std::cout << "Ошибка! Введите число от 0 до " << field_sizeByX - 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        system("pause");
        system("cls");

        // Проверка на выход за пределы поля и на попадание
        if (AttackByAngleY > 0 && AttackByAngleY <= field_sizeByY && AttackByAngleX >= 0 && AttackByAngleX < field_sizeByX)
        {
            if (checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellOneSecondHuman) ||
                checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellTwoSecondHuman) ||
                checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellThreeSecondHuman) ||
                checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellFourSecondHuman))
            {
                std::cout << "Попадание!\n\n";
                updateAndPrintFieldFirstHuman(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, true);
                shipsSunkSecondHuman++;

                continue; // Первый человек атакует снова
            }
            else
            {
                std::cout << "Промах.\n\n";
                updateAndPrintFieldFirstHuman(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, false);
            }
        }
        else
        {
            std::cout << "Вы вышли за пределы поля!\n\n";
        }

        // Второй человек атакует первого человека
        std::cout << "\n";
        std::cout << NameSecondHuman;
        std::cout << " атакует ";
        std::cout << NameFirstHuman;
        std::cout << "\n";
        std::cout << "Выберите расположение атаки по вертикали: ";
        while (!(std::cin >> AttackByAngleY) || AttackByAngleY <= 0 || AttackByAngleY > field_sizeByY)
        {
            std::cout << "Ошибка! Введите число от 1 до " << field_sizeByY << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Выберите расположение атаки по горизонтали: ";
        while (!(std::cin >> AttackByAngleX) || AttackByAngleX < 0 || AttackByAngleX >= field_sizeByX)
        {
            std::cout << "Ошибка! Введите число от 0 до " << field_sizeByX - 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        system("pause");
        system("cls");

        // Проверка на выход за пределы поля и на попадание
        if (AttackByAngleY > 0 && AttackByAngleY <= field_sizeByY && AttackByAngleX >= 0 && AttackByAngleX < field_sizeByX)
        {
            if (checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellOneFirstHuman) ||
                checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellTwoFirstHuman) ||
                checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellThreeFirstHuman) ||
                checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellFourFirstHuman))
            {
                std::cout << "Попадание!\n\n";
                updateAndPrintFieldSecondHuman(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, true);
                continue; // Второй человек атакует снова

            }
            else
            {
                std::cout << "Промах.\n\n";
                updateAndPrintFieldSecondHuman(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, false);
            }
        }
        else
        {
            std::cout << "Вы вышли за пределы поля!\n\n";
        }


    }
    if (shipsSunkSecondHuman > shipsSunkFirstHuman)
    {
        std::cout << "Первый человек победил, потопив больше кораблей!\nБой окончен!\n";
    }
    else if (shipsSunkFirstHuman > shipsSunkSecondHuman)
    {
        std::cout << "Второй человек победил, потопив больше кораблей!\nБой окончен!\n";
    }
    else
    {
        std::cout << "Ничья! Оба игрока потопили одинаковое количество кораблей или не попали не разу.\nБой окончен!\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("pause");
    system("cls");

}
//Работает
// Функция для обновления и вывода поля после атаки



void Games()
{

    std::cout << "\n\nПравила игры:\n1 - Вам даются ровно по 4 корабля\n2 - Выигрывает то кто больше всего потопил кораблей у противника!\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "ПОПЫТАЙСЯ ВЫЖИТЬ В СМЕРТЕЛЬНОМ СРАЖЕНИЕ!\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("pause");

    char fieldFirstHuman[field_sizeByX][field_sizeByY];
    char fieldSecondHuman[field_sizeByX][field_sizeByY];

    placeShipsFirstHuman(fieldFirstHuman);
    placeShipsSecondHuman(fieldSecondHuman);
    // Вывод поля человека после заполнения кораблей


    std::cout << "======================================\n";
    std::cout << "Вы расставили все корабли на поле боя!\n";
    std::cout << "Теперь время атаковать противника!\n";
    std::cout << "======================================\n";
    AttackPlayer(fieldSecondHuman, fieldFirstHuman);




}
//Работает



//GAME OVER 





