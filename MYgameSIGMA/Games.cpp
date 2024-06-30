
#include "Games.hpp"
#include "MenuSIGMA.hpp"


#if defined(max)
#undef max
#endif

// ��� �������!

//�������� ����������!

// ����������� ������ ��� �������� 1 - 4 ������� ��������
char ship_cellOneFirstHuman = '1';
char ship_cellTwoFirstHuman = '2';
char ship_cellThreeFirstHuman = '3';
char ship_cellFourFirstHuman = '4';
// ��������� �������� ������� �������� �� ����� X � Y
int ship_cellOneCornerX_FirstHuman;
int ship_cellOneCornerY_FirstHuman;
int ship_cellTwoCornerX_FirstHuman;
int ship_cellTwoCornerY_FirstHuman;
int ship_cellThreeCornerX_FirstHuman;
int ship_cellThreeCornerY_FirstHuman;
int ship_cellFourCornerX_FirstHuman;
int ship_cellFourCornerY_FirstHuman;

// ����������� ������ ��� �������� 1 - 4 ������� ��������
char ship_cellOneSecondHuman = '1';
char ship_cellTwoSecondHuman = '2';
char ship_cellThreeSecondHuman = '3';
char ship_cellFourSecondHuman = '4';
// ��������� �������� ������� �������� �� ����� X � Y
int ship_cellOneCornerX_SecondHuman;
int ship_cellOneCornerY_SecondHuman;
int ship_cellTwoCornerX_SecondHuman;
int ship_cellTwoCornerY_SecondHuman;
int ship_cellThreeCornerX_SecondHuman;
int ship_cellThreeCornerY_SecondHuman;
int ship_cellFourCornerX_SecondHuman;
int ship_cellFourCornerY_SecondHuman;

const int field_sizeByX = 10;// ������� ���� �� ���� X
const int field_sizeByY = 10;// ������� ���� �� ���� Y
const char empty_cell = '.';// ��������� ����� �� ������ ������ ��� ������ ����


int tempInput; // ������ �� ����� ���� � ��������


// ����� ���� ������� ��������
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
//��������

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
//��������
// �����
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
//  �������� 
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


// ���������� �������� ������� �������� �� ����
void placeShipsFirstHuman(char fieldFirstHuman[field_sizeByX][field_sizeByY])
{
    system("cls");
    std::cout << "����� ";
    std::cout << NameFirstHuman;
    std::cout << " �������� ���� ���������: \n";

    // ������ �������
    FieldShipsFirstHuman();
    std::cout << "\n������ ������ ������������ ��� 1 ������� �� ���������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellOneCornerY_FirstHuman = tempInput;

    std::cout << "\n������ ������ ������������ ��� 1 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellOneCornerX_FirstHuman = tempInput;
    fieldFirstHuman[ship_cellOneCornerY_FirstHuman - 1][ship_cellOneCornerX_FirstHuman] = ship_cellOneFirstHuman;

    // �������� ��������� ��� ������� �������
    if (ship_cellOneCornerY_FirstHuman > field_sizeByY || ship_cellOneCornerX_FirstHuman >= field_sizeByX)
    {
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }


    // ������ �������
    std::cout << "\n������ ������ ������������ ��� 2 ������� �� ���������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellTwoCornerY_FirstHuman = tempInput;

    std::cout << "\n������ ������ ������������ ��� 2 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellTwoCornerX_FirstHuman = tempInput;
    fieldFirstHuman[ship_cellTwoCornerY_FirstHuman - 1][ship_cellTwoCornerX_FirstHuman] = ship_cellTwoFirstHuman;
    // �������� ��������� ��� ������� �������
    if (ship_cellTwoCornerY_FirstHuman > field_sizeByY || ship_cellTwoCornerX_FirstHuman >= field_sizeByX)
    {
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    // ���� ������ ������� ����� ����������� ������� �������
    if (ship_cellTwoCornerY_FirstHuman == ship_cellOneCornerY_FirstHuman && ship_cellTwoCornerX_FirstHuman == ship_cellOneCornerX_FirstHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    // ������ �������
    std::cout << "\n������ ������ ������������ ��� 3 ������� �� ���������: ";
    fieldFirstHuman[ship_cellThreeCornerY_FirstHuman - 1][ship_cellThreeCornerX_FirstHuman] = ship_cellThreeFirstHuman;
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellThreeCornerY_FirstHuman = tempInput;

    std::cout << "\n������ ������ ������������ ��� 3 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
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
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    if (ship_cellThreeCornerX_FirstHuman == ship_cellTwoCornerX_FirstHuman && ship_cellThreeCornerY_FirstHuman == ship_cellTwoCornerY_FirstHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    else if (ship_cellThreeCornerY_FirstHuman == ship_cellOneCornerY_FirstHuman && ship_cellThreeCornerX_FirstHuman == ship_cellOneCornerX_FirstHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }

    // ��������� �������
    std::cout << "\n������ ������ ������������ ��� 4 ������� �� ���������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsFirstHuman(fieldFirstHuman);
        return;
    }
    ship_cellFourCornerY_FirstHuman = tempInput;

    std::cout << "\n������ ������ ������������ ��� 4 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
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
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������

    }


    if (ship_cellFourCornerY_FirstHuman == ship_cellOneCornerY_FirstHuman && ship_cellFourCornerX_FirstHuman == ship_cellOneCornerX_FirstHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    else if (ship_cellFourCornerY_FirstHuman == ship_cellTwoCornerY_FirstHuman && ship_cellFourCornerX_FirstHuman == ship_cellTwoCornerX_FirstHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    else if (ship_cellFourCornerY_FirstHuman == ship_cellThreeCornerY_FirstHuman && ship_cellFourCornerX_FirstHuman == ship_cellThreeCornerX_FirstHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsFirstHuman(fieldFirstHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
}
//��������


// ���������� �������� ������� �������� �� ����
void placeShipsSecondHuman(char fieldSecondHuman[field_sizeByX][field_sizeByY])
{
    system("cls");
    // ������ �������  
    std::cout << "����� ";
    std::cout << NameSecondHuman;
    std::cout << " �������� ���� ���������: \n";
    FieldShipsSecondHuman();
    std::cout << "\n������ ������ ������������ ��� 1 ������� �� ���������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellOneCornerY_SecondHuman = tempInput;
    std::cout << "\n������ ������ ������������ ��� 1 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellOneCornerX_SecondHuman = tempInput;
    fieldSecondHuman[ship_cellOneCornerY_SecondHuman - 1][ship_cellOneCornerX_SecondHuman] = ship_cellOneSecondHuman;
    // �������� ��������� ��� ������� �������
    if (ship_cellOneCornerY_SecondHuman > field_sizeByY || ship_cellOneCornerX_SecondHuman >= field_sizeByX)
    {
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }

    // ������ �������
    std::cout << "\n������ ������ ������������ ��� 2 ������� �� ���������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellTwoCornerY_SecondHuman = tempInput;
    std::cout << "\n������ ������ ������������ ��� 2 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellTwoCornerX_SecondHuman = tempInput;
    fieldSecondHuman[ship_cellTwoCornerY_SecondHuman - 1][ship_cellTwoCornerX_SecondHuman] = ship_cellTwoSecondHuman;
    // �������� ��������� ��� ������� �������
    if (ship_cellTwoCornerY_SecondHuman > field_sizeByY || ship_cellTwoCornerX_SecondHuman >= field_sizeByX)
    {
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }


    if (ship_cellTwoCornerY_SecondHuman == ship_cellOneCornerY_SecondHuman && ship_cellTwoCornerX_SecondHuman == ship_cellOneCornerX_SecondHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }

    // ������ �������
    std::cout << "\n������ ������ ������������ ��� 3 ������� �� ���������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellThreeCornerY_SecondHuman = tempInput;
    std::cout << "\n������ ������ ������������ ��� 3 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
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
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }

    if (ship_cellThreeCornerX_SecondHuman == ship_cellTwoCornerX_SecondHuman && ship_cellThreeCornerY_SecondHuman == ship_cellTwoCornerY_SecondHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    else if (ship_cellThreeCornerY_SecondHuman == ship_cellOneCornerY_SecondHuman && ship_cellThreeCornerX_SecondHuman == ship_cellOneCornerX_SecondHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    // ��������� �������
    std::cout << "\n������ ������ ������������ ��� 4 ������� �� ���������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        placeShipsSecondHuman(fieldSecondHuman);
        return;
    }
    ship_cellFourCornerY_SecondHuman = tempInput;
    std::cout << "\n������ ������ ������������ ��� 4 ������� �� �����������: ";
    if (!(std::cin >> tempInput))
    {
        std::cout << "������! ����� ������� ������ �����.\n";
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
        std::cout << "�� ������� �� ���������� ���������� ����!\n���������� ��� ���!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }

    if (ship_cellFourCornerY_SecondHuman == ship_cellOneCornerY_SecondHuman && ship_cellFourCornerX_SecondHuman == ship_cellOneCornerX_SecondHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }
    else if (ship_cellFourCornerX_SecondHuman == ship_cellThreeCornerX_SecondHuman && ship_cellFourCornerY_SecondHuman == ship_cellThreeCornerY_SecondHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������
    }

    else if (ship_cellFourCornerY_SecondHuman == ship_cellTwoCornerY_SecondHuman && ship_cellFourCornerX_SecondHuman == ship_cellTwoCornerX_SecondHuman)
    {
        std::cout << "�� ������� ���������� ����!\n�������� ������ ����!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("pause");
        placeShipsSecondHuman(fieldSecondHuman);
        return; // �������� return ��� �������������� ���������� ������ �������

    }

    system("cls");
}
//��������


// ������� ��� �������� ��������� � ���������� ����
bool checkHitAndUpdateField(char field[][field_sizeByX], int y, int x, char shipSymbol)
{
    if (field[y][x] == shipSymbol)
    {
        field[y][x] = 'X'; // �������� ���������
        return true;
    }
    else if (field[y][x] == empty_cell)
    {
        field[y][x] = '*'; // �������� ������
    }
    return false;
}
//��������

void updateAndPrintFieldFirstHuman(char field[field_sizeByX][field_sizeByY], int y, int x, bool hit)
{
    // ��������� ���� � ����������� �� ���������� �����
    field[y][x] = hit ? 'X' : '*';

    // ������� ����������� ���� ��� ������ ��������
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
            // ���������� ������ ��������� 'X', ������� '*' � ������ ������ '.'
            if (field[i][j] == 'X' || field[i][j] == '*' || field[i][j] == empty_cell)
            {
                std::cout << field[i][j] << " ";
            }
            else
            {
                std::cout << empty_cell << " "; // �������� ������� �������� �� ������ ������
            }
        }
        std::cout << "\n";
    }
}
void updateAndPrintFieldSecondHuman(char fieldSecondHuman[field_sizeByX][field_sizeByY], int y, int x, bool hit)
{
    // ��������� ���� � ����������� �� ���������� �����
    fieldSecondHuman[y][x] = hit ? 'X' : '*';

    // ������� ����������� ���� ��� ������ ��������
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
            // ���������� ������ ��������� 'X', ������� '*' � ������ ������ '.'
            if (fieldSecondHuman[i][j] == 'X' || fieldSecondHuman[i][j] == '*' || fieldSecondHuman[i][j] == empty_cell)
            {
                std::cout << fieldSecondHuman[i][j] << " ";
            }
            else
            {
                std::cout << empty_cell << " "; // �������� ������� �������� �� ������ ������
            }
        }
        std::cout << "\n";
    }
}
// �������� 

// ����� �� ����������
void AttackPlayer(char fieldFirstHuman[field_sizeByX][field_sizeByY], char fieldSecondHuman[field_sizeByX][field_sizeByY])
{
    int rounds = 5;
    int AttackByAngleX, AttackByAngleY;
    int shipsSunkFirstHuman = 0;
    int shipsSunkSecondHuman = 0;


    std::cout << "�������:\n 1 - ��������� ���������� �������� X, ������ ���������� �������� *\n 2 - ���� ���-�� ������� ������� ����������, �� �� ��� ��� ������� ���������� \n 3 - � ��� ���� 5 �������";
    std::cout << "\n 4 - ���������� ��� ��� ������ ����� ������� ��������\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("pause");
    system("cls");
    for (int round = 1; round <= rounds; ++round)
    {
        std::cout << "\n" << round << " �����!\n\n";
        std::cout << "==========================================\n";
        std::cout << NameFirstHuman;
        std::cout << " ������� ";
        std::cout << NameSecondHuman;
        std::cout << "\n";
        std::cout << "�������� ������������ ����� �� ���������: ";
        while (!(std::cin >> AttackByAngleY) || AttackByAngleY <= 0 || AttackByAngleY > field_sizeByY)
        {
            std::cout << "������! ������� ����� �� 1 �� " << field_sizeByY << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "�������� ������������ ����� �� �����������: ";
        while (!(std::cin >> AttackByAngleX) || AttackByAngleX < 0 || AttackByAngleX >= field_sizeByX)
        {
            std::cout << "������! ������� ����� �� 0 �� " << field_sizeByX - 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        system("pause");
        system("cls");

        // �������� �� ����� �� ������� ���� � �� ���������
        if (AttackByAngleY > 0 && AttackByAngleY <= field_sizeByY && AttackByAngleX >= 0 && AttackByAngleX < field_sizeByX)
        {
            if (checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellOneSecondHuman) ||
                checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellTwoSecondHuman) ||
                checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellThreeSecondHuman) ||
                checkHitAndUpdateField(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellFourSecondHuman))
            {
                std::cout << "���������!\n\n";
                updateAndPrintFieldFirstHuman(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, true);
                shipsSunkSecondHuman++;

                continue; // ������ ������� ������� �����
            }
            else
            {
                std::cout << "������.\n\n";
                updateAndPrintFieldFirstHuman(fieldSecondHuman, AttackByAngleY - 1, AttackByAngleX, false);
            }
        }
        else
        {
            std::cout << "�� ����� �� ������� ����!\n\n";
        }

        // ������ ������� ������� ������� ��������
        std::cout << "\n";
        std::cout << NameSecondHuman;
        std::cout << " ������� ";
        std::cout << NameFirstHuman;
        std::cout << "\n";
        std::cout << "�������� ������������ ����� �� ���������: ";
        while (!(std::cin >> AttackByAngleY) || AttackByAngleY <= 0 || AttackByAngleY > field_sizeByY)
        {
            std::cout << "������! ������� ����� �� 1 �� " << field_sizeByY << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "�������� ������������ ����� �� �����������: ";
        while (!(std::cin >> AttackByAngleX) || AttackByAngleX < 0 || AttackByAngleX >= field_sizeByX)
        {
            std::cout << "������! ������� ����� �� 0 �� " << field_sizeByX - 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        system("pause");
        system("cls");

        // �������� �� ����� �� ������� ���� � �� ���������
        if (AttackByAngleY > 0 && AttackByAngleY <= field_sizeByY && AttackByAngleX >= 0 && AttackByAngleX < field_sizeByX)
        {
            if (checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellOneFirstHuman) ||
                checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellTwoFirstHuman) ||
                checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellThreeFirstHuman) ||
                checkHitAndUpdateField(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, ship_cellFourFirstHuman))
            {
                std::cout << "���������!\n\n";
                updateAndPrintFieldSecondHuman(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, true);
                continue; // ������ ������� ������� �����

            }
            else
            {
                std::cout << "������.\n\n";
                updateAndPrintFieldSecondHuman(fieldFirstHuman, AttackByAngleY - 1, AttackByAngleX, false);
            }
        }
        else
        {
            std::cout << "�� ����� �� ������� ����!\n\n";
        }


    }
    if (shipsSunkSecondHuman > shipsSunkFirstHuman)
    {
        std::cout << "������ ������� �������, ������� ������ ��������!\n��� �������!\n";
    }
    else if (shipsSunkFirstHuman > shipsSunkSecondHuman)
    {
        std::cout << "������ ������� �������, ������� ������ ��������!\n��� �������!\n";
    }
    else
    {
        std::cout << "�����! ��� ������ �������� ���������� ���������� �������� ��� �� ������ �� ����.\n��� �������!\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("pause");
    system("cls");

}
//��������
// ������� ��� ���������� � ������ ���� ����� �����



void Games()
{

    std::cout << "\n\n������� ����:\n1 - ��� ������ ����� �� 4 �������\n2 - ���������� �� ��� ������ ����� ������� �������� � ����������!\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "��������� ������ � ����������� ��������!\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("pause");

    char fieldFirstHuman[field_sizeByX][field_sizeByY];
    char fieldSecondHuman[field_sizeByX][field_sizeByY];

    placeShipsFirstHuman(fieldFirstHuman);
    placeShipsSecondHuman(fieldSecondHuman);
    // ����� ���� �������� ����� ���������� ��������


    std::cout << "======================================\n";
    std::cout << "�� ���������� ��� ������� �� ���� ���!\n";
    std::cout << "������ ����� ��������� ����������!\n";
    std::cout << "======================================\n";
    AttackPlayer(fieldSecondHuman, fieldFirstHuman);




}
//��������



//GAME OVER 





