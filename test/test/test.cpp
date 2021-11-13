#include <iostream>
#include <random>
#include <Windows.h>
using namespace std;

class test {

public:
	int n, m, i, j;
	HANDLE hConsole;
	int value;
	void test::getVeryEasyGame(int);
	void test::getEasyGame(int);
	void test::getMediumGame(int);
	void test::getHardGame(int);
	void test::startGame();
	void test::processing(char(*)[9]);
	boolean test::isDone(char(*)[9]);
	void test::printMatrix(char(*)[9]);
	void getEasyGame();

};
/*
void test::printMatrix(char(*m)[9]) {
	int row, column;

	cout << "Inside printMatrix" << endl;
	for (row = 0; row < 9; row++)
		for (column = 0; column< 9; column++) {
			cout << "|" << m[row][column];
			if (column == 8)
				cout << "|" << endl;
		}
}*/
void test::printMatrix(char(*m)[9]) {
	int row, column;
	CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	SetCurrentConsoleFontEx(outcon, false, &font);
	system("CLS");
	cout << "             --- Sudoku ---\n\n" << endl;
	SetConsoleTextAttribute(outcon, 0x07);
	cout << " \311\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\273 " << endl;
	SetConsoleTextAttribute(outcon, 0x0c);
	for (row = 0; row < 9; row++)
		for (column = 0; column< 9; column++) {
			if (column == 0 && row != 0) {
				SetConsoleTextAttribute(outcon, 0x07);
				cout << " \314\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\271 " << endl;
				SetConsoleTextAttribute(outcon, 0x0c);
			}
			SetConsoleTextAttribute(outcon, 0x07);
			cout << " \272 ";
			SetConsoleTextAttribute(outcon, 0x0c);
			cout << m[row][column];
			SetConsoleTextAttribute(outcon, 0x07);
			if (column == 8)
				cout << " \272" << endl;
		}
	cout << " \310\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\274 " << endl;
	SetConsoleTextAttribute(outcon, 0x0c);
}


boolean test::isDone(char(*m)[9]) {
	char spmace = ' ';
	char temp = 'Z';
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j< 9; j++) {
			cout << m[i][j] << ' ';
			temp = m[i][j];
			if (m[i][j] == spmace) {
				cout << m[i][j] << ' ';
				return false;
			}
			cout << endl;
		}
	return true;
}

void test::processing(char(*m)[9]) {
	char ch, numb;
	int row, column;
	cout << "In processing method" << endl;
	printMatrix(m);

	while (!(isDone(m))) {

		cout << "Give me the number to enter: ";
		cin >> numb;
		cout << endl << "Give me row number to enter: ";
		cin >> row;
		cout << endl << "Give me the column number: ";
		cin >> column;
		m[row][column] = numb;
		cout << endl;
		cout << "After insertion" << endl;
		printMatrix(m);

	}
}

void test::getHardGame(int num) {
	char spm = ' ';
	cout << "Number given to getHardGame is = " << num << endl;


	char hard_sudo1[9][9] = {
		{ '3', spm, spm, spm, '6', spm, spm, spm, '9' },
		{ spm, '5', spm, '9', spm, '3', spm, '6', spm },
		{ spm, spm, '9', spm, '7', spm, '8', spm, spm },
		{ spm, '2', spm, '1', spm, '6', spm, '3', spm },
		{ '7', spm, '6', spm, spm, spm, '2', spm, '1' },
		{ spm, '1', spm, '7', spm, '8', spm, '5', spm },
		{ spm, spm, '7', spm, '3', spm, '9', spm, spm },
		{ spm, '9', spm, '4', spm, '7', spm, '8', spm },
		{ '1', spm, spm, spm, '8', spm, spm, spm, '4' }
	};

	char hard_sudo2[9][9] = {
		{ '7', spm, '1', spm, spm, spm, '2', spm, '4' },
		{ spm, '8', spm, spm, '1', spm, spm, '9', spm },
		{ '4', spm, spm, '9', spm, '2', spm, spm, '7' },
		{ spm, spm, '6', spm, '7', spm, '3', spm, spm },
		{ spm, '3', spm, '5', spm, '6', spm, '1', spm },
		{ spm, spm, '7', spm, '8', spm, '4', spm, spm, },
		{ '5', spm, spm, '1', spm, '9', spm, spm, '3' },
		{ spm, '4', spm, spm, '2', spm, spm, '7', spm },
		{ '2', spm, '9', spm, spm, spm, '8', spm, '5' }
	};
	char hard_sudo3[9][9] = {
		{ spm, spm, '9', '8', spm, '5', '4', spm, spm },
		{ spm, '1', spm, spm, spm, spm, spm, '8', spm },
		{ '8', spm, '3', spm, '2', spm, '5', spm, '7' },
		{ '9', spm, spm, '6', spm, '7', spm, spm, '3' },
		{ spm, spm, '6', spm, '5', spm, '7', spm, spm },
		{ '2', spm, spm, '1', spm, '9', spm, spm, '5' },
		{ '3', spm, '2', spm, '4', spm, '8', spm, '9' },
		{ spm, '9', spm, spm, spm, spm, spm, '7', spm },
		{ spm, spm, '8', '5', spm, '3', '2', spm, spm }
	};

	char hard_sudo4[9][9] = {
		{ '5', spm, '8', spm, spm, spm, '3', spm, '6' },
		{ spm, spm, spm, '9', spm, '1', spm, spm, spm },
		{ '3', spm, spm, spm, spm, spm, spm, spm, '7' },
		{ spm, '8', spm, '7', spm, '3', spm, '9', spm },
		{ spm, spm, spm, spm, '2', spm, spm, spm, spm },
		{ spm, '7', spm, '5', spm, '9', spm, '6', spm },
		{ '7', spm, spm, spm, spm, spm, spm, spm, '4' },
		{ spm, spm, spm, '1', spm, '7', spm, spm, spm },
		{ '2', spm, '4', spm, spm, spm, '8', spm, '3' }
	};

	char hard_sudo5[9][9] = {
		{ '5', spm, '3', '6', spm, '9', '7', spm, '2' },
		{ spm, '8', spm, spm, '4', spm, spm, '5', spm },
		{ '6', spm, spm, spm, '1', spm, spm, spm, '8' },
		{ '8', spm, spm, '9', spm, '5', spm, spm, '4' },
		{ spm, '9', '6', spm, '3', spm, '5', '2', spm },
		{ '3', spm, spm, '1', spm, '7', spm, spm, '9' },
		{ '1', spm, spm, spm, '9', spm, spm, spm, '5' },
		{ spm, '6', spm, spm, '7', spm, spm, '9', spm },
		{ '4', spm, '9', '2', spm, '6', '8', spm, '7' }
	};

	char hard_sudo6[9][9] = {
		{ '6', '9', '5', spm, spm, spm, '2', '7', '4' },
		{ '3', spm, spm, '6', spm, '5', spm, spm, '1' },
		{ '8', spm, spm, spm, '7', spm, spm, spm, '3' },
		{ spm, '7', spm, spm, '6', spm, spm, '1', spm },
		{ spm, spm, '8', '3', '4', '9', '5', spm, spm },
		{ spm, '5', spm, spm, '8', spm, spm, '3', spm },
		{ '5', spm, spm, spm, '1', spm, spm, spm, '8' },
		{ '9', spm, spm, '4', spm, '7', spm, spm, '2' },
		{ '7', '2', '6', spm, spm, spm, '1', '4', '5' }
	};

	char hard_sudo7[9][9] = {
		{ '1', spm, spm, spm, '3', spm, spm, spm, '2' },
		{ spm, spm, '2', spm, '7', spm, '1', spm, spm },
		{ spm, '6', spm, '1', spm, '8', spm, '7', spm },
		{ spm, spm, '9', spm, '6', spm, '8', spm, spm },
		{ '3', '5', spm, '2', spm, '7', spm, '1', '6' },
		{ spm, spm, '7', spm, '1', spm, '2', spm, spm },
		{ spm, '9', spm, '6', spm, '2', spm, '5', spm },
		{ spm, spm, '1', spm, '9', spm, '4', spm, spm },
		{ '8', spm, spm, spm, '5', spm, spm, spm, '9' }
	};

	char hard_sudo8[9][9] = {
		{ spm, '4', spm, spm, spm, spm, spm, '9', spm },
		{ '3', spm, '7', spm, '1', spm, '2', spm, '8' },
		{ spm, '9', spm, '3', spm, '5', spm, '7', spm },
		{ spm, spm, '1', '5', spm, '6', '7', spm, spm },
		{ spm, '7', spm, spm, '3', spm, spm, '6', spm },
		{ spm, spm, '8', '9', spm, '1', '5', spm, spm },
		{ spm, '2', spm, '8', spm, '3', spm, '1', spm },
		{ '7', spm, '4', spm, '5', spm, '6', spm, '9' },
		{ spm, '1', spm, spm, spm, spm, spm, '5', spm }
	};

	char hard_sudo9[9][9] = {
		{ spm, '6', '5', spm, '2', spm, '8', '7', spm },
		{ '1', spm, spm, spm, '6', spm, spm, spm, '4' },
		{ '7', spm, spm, '8', spm, '3', spm, spm, '1' },
		{ spm, spm, '7', spm, spm, spm, '4', spm, spm },
		{ '6', '3', spm, spm, '5', spm, spm, '9', '2' },
		{ spm, spm, '1', spm, spm, spm, '5', spm, spm },
		{ '3', spm, spm, '5', spm, '4', spm, spm, '7' },
		{ '8', spm, spm, spm, '3', spm, spm, spm, '5' },
		{ spm, '1', '2', spm, '7', spm, '3', '4', spm }
	};

	char hard_sudo10[9][9] = {
		{ '7', spm, spm, spm, '6', spm, spm, spm, '5' },
		{ spm, spm, '5', '2', spm, '3', '1', spm, spm },
		{ spm, '4', spm, '8', spm, '5', spm, '6', spm },
		{ spm, '1', '4', spm, '2', spm, '7', '3', spm },
		{ '8', spm, spm, '1', spm, '4', spm, spm, '6' },
		{ spm, '6', '2', spm, '5', spm, '4', '1', spm },
		{ spm, '9', spm, '6', spm, '2', spm, '8', spm },
		{ spm, spm, '8', '3', spm, '9', '6', spm, spm },
		{ '1', spm, spm, spm, '8', spm, spm, spm, '4' }
	};

	switch (num) {
	case 0:
		processing(hard_sudo1);
		break;
	case 1:
		processing(hard_sudo2);
		break;
	case 2:
		processing(hard_sudo3);
		break;
	case 3:
		processing(hard_sudo4);
		break;
	case 4:
		processing(hard_sudo5);
		break;
	case 5:
		processing(hard_sudo6);
		break;
	case 6:
		processing(hard_sudo7);
		break;
	case 7:
		processing(hard_sudo8);
		break;
	case 8:
		processing(hard_sudo9);
		break;
	case 9:
		processing(hard_sudo10);
		break;
	}

}

void test::getMediumGame(int num) {
	char spm = ' ';
	cout << "Number given to getMediumGame is" << num << endl;


	char medium_sudo1[9][9] = {
		{'2', spm, '3', spm, spm, spm, '6', '7', '8'},
		{'9', spm, '6', '8', '7', '2', spm, spm, spm},
		{'8', spm, '7', '6', spm, '3', '9', '2', '5'},
		{spm, '2', spm, spm, '3', spm, spm, '8', '6'},
		{spm, '9', spm, '2', spm, '6', spm, '1', spm},
		{spm, '6', spm, spm, '4', spm, '2', '5', spm},
		{'1', spm, '9', spm, spm, spm, '4', spm, '2'},
		{spm, spm, spm, '3', '6', '1', spm, spm, spm},
		{spm, spm, '5', spm, spm, spm, '8', spm, spm}
	};

	char medium_sudo2[9][9] = {
		{ '2', spm, '6', spm, spm, '5', '8', '1', '3'},
		{spm, spm, spm, '1', spm, '8', spm, spm, spm},
		{ '8', spm, '1', '3', spm, '6', spm, spm, '5'},
		{spm, '1', '2', '8', '3', '9', '6', '4', spm},
		{ spm, spm, spm, '2', '6', '7', spm, spm, spm},
		{ '6', '7', '8', '4', '5', '1', '9', '3', '2'},
		{ '3', spm, spm, '5', spm, '4', spm, spm, '9'},
		{spm, spm, spm, '6', spm, '2', spm, spm, spm},
		{9, spm, '4', spm, spm, spm, '2', spm, '8'}
	};
	char medium_sudo3[9][9] = {
		{ spm, '5', '6', spm, spm, spm, '1', '3', spm },
		{ '7', spm, spm, '4', '3', '8', spm, spm, '5' },
		{ '2', spm, spm, spm, '1', spm, spm, spm, '9' },
		{ spm, '7', spm, spm, spm, spm, spm, '8', spm },
		{ spm, '2', '3', spm, '7', spm, '5', '6', spm },
		{ spm, '8', spm, spm, spm, spm, spm, '9', spm },
		{ '8', spm, spm, spm, '6', spm, spm, spm, '3' },
		{ '9', spm, spm, '7', '4', '3', spm, spm, '2' },
		{ spm, '1', '7', spm, spm, spm, '9', '4', spm }
	};

	char medium_sudo4[9][9] = {
		{ '6', spm, '5', spm, spm, spm, '3', spm, '7' },
		{ spm, spm, spm, '6', '2', '8', spm, spm, spm },
		{ '2', spm, spm, spm, spm, spm, spm, spm, '9' },
		{ spm, '6', spm, spm, '3', spm, spm, '1', spm },
		{ spm, '5', spm, '9', spm, '1', spm, '6', spm },
		{ spm, '2', spm, spm, '7', spm, spm, '9', spm },
		{ '1', spm, spm, spm, spm, spm, spm, spm, '2' },
		{ spm, spm, spm, '1', '4', '7', spm, spm, spm },
		{ '7', spm, '6', spm, spm, spm, '1', spm, '4' }
	};

	char medium_sudo5[9][9] = {
		{ spm, '8', spm, spm, spm, spm, spm, '1', spm },
		{ '3', spm, '6', '2', spm, '9', '8', spm, '5' },
		{ spm, '1', spm, spm, '7', spm, spm, '6', spm },
		{ spm, '3', spm, spm, '6', spm, spm, '2', spm },
		{ spm, spm, '7', '3', spm, '1', '9', spm, spm },
		{ spm, '9', spm, spm, '2', spm, spm, '5', spm },
		{ spm, '2', spm, spm, '9', spm, spm, '8', spm },
		{ '1', spm, '5', '8', spm, '3', '7', spm, '2' },
		{ spm, '7', spm, spm, spm, spm, spm, '3', spm }
	};

	char medium_sudo6[9][9] = {
		{ spm, spm, '3', spm, spm, spm, '4', spm, spm },
		{ spm, spm, spm, '3', '8', '4', spm, spm, spm },
		{ '5', spm, '4', spm, '2', spm, '1', spm, '3' },
		{ spm, '4', spm, spm, '7', spm, spm, '6', spm },
		{ spm, '7', '8', '2', spm, '5', '3', '9', spm },
		{ spm, '3', spm, spm, '4', spm, spm, '8', spm },
		{ '8', spm, '7', spm, '5', spm, '6', spm, '9' },
		{ spm, spm, spm, '6', '3', '8', spm, spm, spm },
		{ spm, spm, '2', spm, spm, spm, '8', spm, spm }
	};

	char medium_sudo7[9][9] = {
		{ '4', spm, '5', spm, '9', spm, '8', spm, '1' },
		{ spm, spm, spm, '8', spm, '3', spm, spm, spm },
		{ '7', spm, spm, spm, '1', spm, spm, spm, '2' },
		{ spm, '1', spm, '6', spm, '9', spm, '7', spm },
		{ '6', spm, '3', spm, spm, spm, '1', spm, '9' },
		{ spm, '8', spm, '7', spm, '1', spm, '2', spm },
		{ '8', spm, spm, spm, '2', spm, spm, spm, '3' },
		{ spm, spm, spm, '1', spm, '8', spm, spm, spm },
		{ '1', spm, '9', spm, '6', spm, '4', spm, '7' }
	};

	char medium_sudo8[9][9] = {
		{ '4', spm, '8', spm, spm, spm, '7', spm, '2' },
		{ spm, '7', spm, spm, '8', spm, spm, '5', spm },
		{ '3', spm, '6', spm, '9', spm, '1', spm, '4' },
		{ spm, spm, spm, '4', spm, '7', spm, spm, spm },
		{ spm, '6', '3', spm, '1', spm, '2', '4', spm },
		{ spm, spm, spm, '6', spm, '2', spm, spm, spm },
		{ '6', spm, '4', spm, '7', spm, '8', spm, '9' },
		{ spm, '9', spm, spm, '2', spm, spm, '6', spm },
		{ '2', spm, '1', spm, spm, spm, '3', spm, '5' }
	};

	char medium_sudo9[9][9] = {
		{ spm, spm, '9', spm, spm, spm, '6', spm, spm },
		{ spm, spm, '6', spm, '4', spm, '3', spm, spm },
		{ '8', '5', spm, '7', spm, '6', spm, '9', '2' },
		{ spm, spm, '2', spm, '8', spm, '5', spm, spm },
		{ spm, '9', spm, '1', spm, '4', spm, '8', spm },
		{ spm, spm, '4', spm, '9', spm, '2', spm, spm },
		{ '6', '3', spm, '9', spm, '2', spm, '5', '4' },
		{ spm, spm, '7', spm, '5', spm, '9', spm, spm },
		{ spm, spm, '5', spm, spm, spm, '8', spm, spm }
	};

	char medium_sudo10[9][9] = {
		{ spm, spm, '6', spm, spm, spm, '5', spm, spm },
		{ spm, spm, spm, '2', spm, '6', spm, spm, spm },
		{ '9', spm, '4', spm, '8', spm, '1', spm, '7' },
		{ spm, '5', spm, '9', spm, '2', spm, '7', spm },
		{ spm, spm, '9', spm, spm, spm, '4', spm, spm },
		{ spm, '6', spm, '4', spm, '5', spm, '8', spm },
		{ '5', spm, '1', spm, '7', spm, '9', spm, '2' },
		{ spm, spm, spm, '1', spm, '8', spm, spm, spm },
		{ spm, spm, '2', spm, spm, spm, '6', spm, spm }
	};

	switch (num) {
	case 0:
		processing(medium_sudo1);
		break;
	case 1:
		processing(medium_sudo2);
		break;
	case 2:
		processing(medium_sudo3);
		break;
	case 3:
		processing(medium_sudo4);
		break;
	case 4:
		processing(medium_sudo5);
		break;
	case 5:
		processing(medium_sudo6);
		break;
	case 6:
		processing(medium_sudo7);
		break;
	case 7:
		processing(medium_sudo8);
		break;
	case 8:
		processing(medium_sudo9);
		break;
	case 9:
		processing(medium_sudo10);
		break;
	}

}

void test::getVeryEasyGame(int num) {
	char spm = ' ';
	cout << "Number given to getVeryEasyGame is = " << num << endl;


	char veryEasy_sudo1[9][9] = {
		{ spm, '7', '4', '1', '9', '6', '3', '8', '2' },
		{ '3', '1', '9', '8', spm, '4', '7', '5', '6' },
		{ '6', '2', '8', '3', '5', '7', '9', '4', '1' },
		{ '7', '3', '1', '2', '8', '9', spm, '6', '4' },
		{ '4', spm, '5', '6', '7', '3', '2', '1', '9' },
		{ '2', '9', '6', '5', '4', '1', '8', '7', '3' },
		{ '1', '5', '7', spm, '3', '2', '6', spm, '8' },
		{ '8', '4', '2', '9', '6', '5', '1', '3', '7' },
		{ '9', '6', '3', '7', '1', spm, '4', '2', '5' }
	};
	char veryEasy_sudo2[9][9] = {
		{ '8', spm, '7', '6', '1', '3', '2', '4', '9' },
		{ '4', '2', '6', '5', '8', '9', '3', spm, '1' },
		{ '3', '9', '1', spm, '2', '4', '6', '8', '5' },
		{ '7', '4', '9', '2', '3', '5', '8', '1', '6' },
		{ '5', '6', '8', '1', '4', '7', '9', '2', '3' },
		{ '1', '3', '2', '8', '9', spm, spm, '5', '4' },
		{ '9', '1', '5', '3', '7', '8', '4', '6', '2' },
		{ '2', spm, '3', '4', '6', '1', '5', spm, '7' },
		{ '6', '7', '4', '9', spm, '2', '1', '3', '8' }
	};
	char veryEasy_sudo3[9][9] = {
		{ spm, '9', '8', spm, '1', '2', '4', spm, '6' },
		{ '4', '6', '1', '7', '3', '9', '8', '5', '2' },
		{ '5', '2', '3', '6', '4', spm, '1', '9', '7' },
		{ '8', spm, '4', '9', '6', '3', '2', '1', '5' },
		{ '9', '1', '2', '4', '5', '7', '3', '6', '8' },
		{ '3', '5', '6', '2', '8', '1', '7', spm, '9' },
		{ '6', '8', '5', spm, '7', spm, '9', '2', '1' },
		{ '1', '4', '9', '8', '2', '5', '6', '7', '3' },
		{ spm, '3', '7', '1', '9', '6', '5', '8', '4' }
	};
	char veryEasy_sudo4[9][9] = {
		{ '6', '1', '2', spm, '9', '5', '8', '4', '3' },
		{ spm, '8', '7', '3', '4', '6', '9', spm, '2' },
		{ '9', '3', '4', '2', '8', spm, '5', '6', '7' },
		{ '3', '7', spm, '1', '2', '9', '4', '5', '6' },
		{ '1', '4', '9', '6', '5', '7', '3', '2', '8' },
		{ '2', '5', '6', spm, '3', '8', '7', '9', spm },
		{ '7', '6', '5', '9', '1', '3', '2', '8', '4' },
		{ '4', spm, '1', '8', '7', '2', spm, '3', '5' },
		{ '8', '2', '3', '5', '6', '4', '1', '7', '9' }
	};
	char veryEasy_sudo5[9][9] = {
		{ '6', '5', '3', '2', '7', '1', '8', spm, '9' },
		{ '9', '4', spm, '3', '8', spm, '2', '5', '7' },
		{ '7', '8', '2', '4', '9', '5', '1', '6', '3' },
		{ '5', '1', '9', spm, '2', '8', '7', spm, '4' },
		{ '3', spm, '8', '5', '4', '9', '6', '2', '1' },
		{ '2', '6', '4', '7', '1', '3', '9', '8', '5' },
		{ '8', '2', '5', '9', '3', '7', spm, '1', '6' },
		{ '4', '3', '7', '1', '6', '2', '5', '9', spm },
		{ '1', '9', '6', spm, '5', '4', '3', '7', '2' }
	};
	char veryEasy_sudo6[9][9] = {
		{ spm, '9', '4', '8', '1', '2', '3', spm, '6' },
		{ '3', '1', '2', '7', '5', '6', '9', '8', '4' },
		{ '8', '6', '5', '9', '3', spm, '2', '7', '1' },
		{ '5', spm, '9', spm, '7', '8', '6', '1', '2' },
		{ '2', '7', '6', '5', '9', '1', '4', spm, '8' },
		{ spm, '4', '8', '6', '2', '3', '7', '9', '5' },
		{ '9', '2', spm, '3', '6', '5', spm, '4', '7' },
		{ '4', '5', '7', '2', '8', '9', '1', '6', '3' },
		{ '6', '8', '3', '1', '4', spm, '5', '2', '9' }
	};
	char veryEasy_sudo7[9][9] = {
		{ '5', '1', '6', '2', '3', '4', '8', '9', '7' },
		{ '8', spm, '4', '1', '7', '9', '6', spm, '5' },
		{ '3', '9', '7', spm, spm, '5', '1', '4', '2' },
		{ '1', '8', '3', '4', '2', '6', '5', spm, '9' },
		{ '4', spm, '2', '9', '5', '1', '3', '6', '8' },
		{ '9', '6', '5', '7', '8', '3', '2', '1', '4' },
		{ '7', '4', '8', spm, '1', '2', '9', '5', '6' },
		{ '6', spm, '9', '5', '4', '8', '7', '2', spm },
		{ '2', '5', '1', '6', '9', spm, '4', '8', '3' }
	};
	char veryEasy_sudo8[9][9] = {
		{ '6', spm, '2', spm, '5', '7', '4', '3', '8' },
		{ '4', '5', '7', '6', '3', '8', spm, '2', '9' },
		{ '3', '1', '8', '4', spm, '2', '6', spm, '7' },
		{ '5', '4', '1', '8', '7', '3', '2', '9', '6' },
		{ '9', spm, '3', '5', '4', '6', spm, '8', '1' },
		{ '8', '7', '6', '9', '2', '1', '5', '4', '3' },
		{ '7', '8', spm, '2', '6', '9', '3', '1', '4' },
		{ spm, '3', '9', '7', '1', '4', '8', spm, '5' },
		{ '1', '6', '4', spm, '8', spm, '9', '7', '2' }
	};
	char veryEasy_sudo9[9][9] = {
		{ '5', spm, '4', '2', spm, '8', '3', '1', '7' },
		{ '1', '7', '8', '3', '5', '4', '9', '6', '2' },
		{ spm, '3', spm, '7', '1', '9', spm, '4', '5' },
		{ '2', '6', '7', '9', '3', '1', '5', '8', '4' },
		{ '3', '5', '9', '4', '8', '6', '2', '7', spm },
		{ spm, '8', '1', '5', spm, '7', '6', spm, '9' },
		{ '9', '1', '6', '8', '7', '5', '4', '2', '3' },
		{ '8', spm, '5', '1', '4', '3', spm, '9', '6' },
		{ '7', '4', '3', '6', '9', spm, '1', '5', '8' }
	};
	char veryEasy_sudo10[9][9] = {
		{ '5', '8', spm, spm, '3', '9', spm, '7', '4' },
		{ '9', '4', '6', '7', spm, '5', '3', '2', '1' },
		{ '7', '3', '2', spm, '4', '1', '9', '5', '8' },
		{ '1', '5', '3', '9', '6', '8', '2', '4', '7' },
		{ '6', spm, '8', '3', '2', '4', spm, '1', '9' },
		{ '4', '2', '9', '1', '5', '7', '8', '6', '3' },
		{ '8', '6', '7', spm, '1', spm, '4', '9', '2' },
		{ spm, '9', '5', '4', '7', '2', '1', '8', '6' },
		{ '2', '1', spm, '8', '9', '6', '7', '3', '5' }
	};

	switch (num) {
	case 0:
		processing(veryEasy_sudo1);
		break;
	case 1:
		processing(veryEasy_sudo2);
		break;
	case 2:
		processing(veryEasy_sudo3);
		break;
	case 3:
		processing(veryEasy_sudo4);
		break;
	case 4:
		processing(veryEasy_sudo5);
		break;
	case 5:
		processing(veryEasy_sudo6);
		break;
	case 6:
		processing(veryEasy_sudo7);
		break;
	case 7:
		processing(veryEasy_sudo8);
		break;
	case 8:
		processing(veryEasy_sudo9);
		break;
	case 9:
		processing(veryEasy_sudo10);
		break;
	}
}

void test::getEasyGame(int num) {
	char spm = ' ';
	cout << "Number given to getVeryEasyGame is = " << num << endl;


	char easy_sudo1[9][9] = {
		{ spm, '7', spm, '1', '9', '6', spm, '8', '2' },
		{ '3', '1', '9', '8', spm, '4', '7', '5', '6' },
		{ '6', spm, '8', spm, '5', '7', '9', '4', spm },
		{ spm, '3', '1', '2', '8', '9', spm, '6', '4' },
		{ '4', spm, '5', '6', spm, '3', '2', '1', spm },
		{ spm, '9', '6', spm, '4', '1', '8', '7', '3' },
		{ '1', '5', '7', spm, '3', '2', '6', spm, '8' },
		{ '8', spm, '2', '9', '6', '5', spm, '3', '7' },
		{ '9', '6', spm, '7', '1', spm, '4', '2', '5' },
	};
	char easy_sudo2[9][9] = {
		{ '8', spm, '7', '6', '1', spm, '2', spm, '9' },
		{ '4', '2', '6', '5', '8', '9', '3', spm, '1' },
		{ '3', '9', '1', spm, '2', '4', '6', '8', spm },
		{ spm, '4', '9', '2', '3', spm, '8', spm, '6' },
		{ '5', spm, '8', spm, '4', '7', '9', '2', '3' },
		{ '1', spm, '2', '8', '9', spm, spm, '5', '4' },
		{ '9', '1', spm, '3', spm, '8', '4', spm, '2' },
		{ spm, spm, '3', '4', '6', '1', '5', spm, '7' },
		{ '6', spm, '4', spm, spm, '2', spm, '3', '8' },
	};
	char easy_sudo3[9][9] = {
		{ spm, '9', '8', spm, '1', spm, '4', spm, '6' },
		{ '4', '6', '1', '7', spm, '9', '8', '5', '2' },
		{ '5', '2', '3', '6', '4', spm, '1', spm, '7' },
		{ '8', spm, '4', spm, spm, '3', '2', '1', spm },
		{ spm, '1', spm, '4', '5', spm, '3', spm, '8' },
		{ '3', '5', spm, '2', '8', '1', '7', spm, '9' },
		{ '6', spm, '5', spm, '7', spm, '9', spm, '1' },
		{ '1', spm, '9', spm, '2', spm, '6', '7', '3' },
		{ spm, '3', '7', spm, '9', '6', spm, '8', '4' },
	};
	char easy_sudo4[9][9] = {
		{ '6', spm, '2', spm, '9', '5', spm, '4', '3' },
		{ spm, '8', spm, '3', '4', '6', '9', spm, '2' },
		{ '9', '3', spm, '2', '8', spm, '5', spm, '7' },
		{ '3', spm, spm, '1', spm, '9', spm, '5', '6' },
		{ '1', '4', '9', '6', '5', spm, '3', '2', spm },
		{ '2', spm, '6', spm, '3', '8', '7', '9', spm },
		{ '7', '6', '5', '9', '1', spm, '2', '8', '4' },
		{ '4', spm, '1', spm, '7', '2', spm, '3', '5' },
		{ spm, '2', spm, '5', spm, '4', '1', '7', spm },
	};
	char easy_sudo5[9][9] = {
		{ spm, spm, '3', '2', spm, '1', '8', spm, spm },
		{ '9', '4', spm, '3', spm, spm, '2', '5', '7' },
		{ spm, '8', '2', spm, '9', '5', spm, '6', '3' },
		{ '5', '1', '9', spm, '2', spm, '7', spm, '4' },
		{ spm,spm,'8','5','4','9','6','2','1'},
		{'2', '6', '4', spm, '1', '3', '9', '8', '5'},
		{ '8', spm, '5', '9', spm, '7', spm, '1', '6' },
		{ spm, '3', spm, '1', spm, spm, '5', '9', spm },
		{ '1', spm, '6', spm, '5', spm, '3', '7', '2' },
	};
	char easy_sudo6[9][9] = {
		{ spm, '9', spm, '8', spm, '2', '3', spm, '6' },
		{ '3', '1', '2', spm, '5', spm, '9', '8', spm },
		{ '8', spm, '5', spm, '3', spm, '2', spm, '1' },
		{ '5', spm, '9', spm, '7', '8', '6', spm, '2' },
		{ spm, '7', '6', spm, '9', spm, '4', spm, '8' },
		{ spm, '4', spm, '6', '2', '3', '7', spm, '5' },
		{ '9', '2', spm, '3', spm, '5', spm, '4', '7' },
		{ '4', '5', '7', '2', '8', '9', '1', spm, '3' },
		{ spm, spm, spm, '1', spm, spm, '5', spm, '9' },
	};
	char easy_sudo7[9][9] = {
		{ '5', '1', spm, '2', '3', spm, '8', '9', '7' },
		{ '8', spm, '4', '1', spm, '9', '6', spm, '5' },
		{ spm, '9', '7', spm, spm, spm, '1', '4', '2' },
		{ '1', '8', '3', spm, '2', '6', '5', spm, '9' },
		{ spm, spm, '2', '9', '5', spm, '3', spm,'8'},
		{'9', '6', spm, '7', '8', '3', spm, '1', '4'},
		{ spm, spm, '8', spm, '1', spm, '9', '5', '6' },
		{ '6', spm, '9', spm, spm, '8', spm, '2', spm },
 		{ '2', '5', spm, '6', '9', spm, '4', spm, '3' },
	};
	char easy_sudo8[9][9] = {
		{ spm, spm, '2', spm, '5', spm, '4', '3', '8' },
		{ spm, '5', spm, '6', '3', spm, spm, spm, '9' },
		{ '3', spm, '8', '4', spm, '2', '6', spm, '7' },
		{ '5', '4', spm, spm, '7', spm, spm, '9', '6' },
		{ '9', spm, spm, '5', '4', '6', spm, '8', '1' },
		{ spm, '7', '6', '9', spm, spm, spm, '4', spm },
		{ '7', '8', spm, '2', '6', '9', '3', '1', '4' },
		{ spm, spm, '9', spm, spm, '4', '8', spm, '5' },
		{ '1', '6', '4', spm, '8', spm, '9', '7', spm },
	};
	char easy_sudo9[9][9] = {
		{ '5', spm, spm, '2', spm, '8', spm, '1', spm },
		{ '1', spm, '8', '3', spm, '4', spm, '6', '2' },
		{ spm, '3', spm, '7', spm, '9', spm, spm, '5' },
		{ '2', '6', '7', spm, '3', '1', spm, '8', '4' },
		{ '3', spm, '9', '4', '8', '6', '2', spm, spm },
		{ spm, '8', spm, '5', spm, '7', spm, spm, '9' },
		{ spm, '1', '6', spm, spm, '5', '4', '2', '3' },
		{ '8', spm, spm, spm, '4', '3', spm, '9', '6' },
		{ spm, '4', spm, '6', '9', spm, '1', spm, '8' },
	};
	char easy_sudo10[9][9] = {
		{ '5', spm, spm, spm, '3', '9', spm, '7', spm },
		{ spm, '4', '6', '7', spm, '5', '3', spm, '1' },
		{ '7', spm, spm, spm, spm, '1', spm, '5', '8' },
		{ '1', '5', '3', spm, '6', spm, '2', spm, '7' },
		{ '6', spm, spm, '3', spm, '4', spm, '1', '9' },
		{ spm, '2', '9', spm, '5', '7', '8', spm, '3' },
		{ '8', '6', spm, spm, '1', spm, '4', '9', spm },
		{ spm, spm, '5', '4', '7', spm, '1', '8', spm },
		{ '2', '1', spm,'8', '9', spm, '7', '3', spm },
	};

			switch (num) {
			case 0:
				processing(easy_sudo1);
				break;
			case 1:
				processing(easy_sudo2);
				break;
			case 2:
				processing(easy_sudo3);
				break;
			case 3:
				processing(easy_sudo4);
				break;
			case 4:
				processing(easy_sudo5);
				break;
			case 5:
				processing(easy_sudo6);
				break;
			case 6:
				processing(easy_sudo7);
				break;
			case 7:
				processing(easy_sudo8);
				break;
			case 8:
				processing(easy_sudo9);
				break;
			case 9:
				processing(easy_sudo10);
				break;
			}
		}


		void test::startGame()
		{


			value = 1 + 14 * 16;
			using namespace std;
			char ch;
			int choice;
			char sp = ' ';

			std::random_device rd; // obtain a random number from hardware
			std::mt19937 eng(rd()); // seed the generator
			std::uniform_int_distribution<> distr(0, 9); // define the range

			while (true) {
				HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);

				CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
				GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
				SetCurrentConsoleFontEx(outcon, false, &font);

				SetConsoleTextAttribute(outcon, 0x0c);
				cout << "\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333" << endl;
				cout << "\333\260\260\260\260\260\260\260\260\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\260\260\260\260\260\260\333\333\333\333\333\260\260\260\260\260\260\260\260\260\260\333\333\333\260\260\333\333\333\333\333\333\333\260\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\260\260\333\333\333\333\333\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\260\260\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\260\260\333\333\333\333\333\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\260\260\333\333\333\333\333\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\260\260\333\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\260\260\260\260\260\260\260\260\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\260\260\260\260\260\260\333\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\333\333\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\260\260\333\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\333\333\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\333\333\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\260\260\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\260\260\333\333\333\333\333\333\260\260\333\333\333\333\333\260\260\333\333\333\333\333\333\260\260\333" << endl;
				cout << "\333\260\260\260\260\260\260\260\260\260\260\333\333\333\260\260\260\260\260\260\260\260\260\260\333\333\333\260\260\260\260\260\260\260\260\333\333\333\333\333\260\260\260\260\260\260\260\260\260\260\333\333\333\260\260\333\333\333\333\333\333\333\260\260\260\333\333\333\260\260\260\260\260\260\260\260\260\260\333" << endl;
				cout << "\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333" << endl;
				cout << "\n\n\n\n\n\n\nDo you want to play the game (y/n) : ";
				cin >> ch;
				if (ch == 'n' || ch == 'N') exit(1);
				cout << "What level do you want to play at? : " << endl;
				cout << "For very easy type 1" << endl;
				cout << "For easy type 2 " << endl;
				cout << "For medium type 3 " << endl;
				cout << "For hard type 4 " << endl;
				cin >> choice;
				break;
			}

			for (int n = 0; n<4; ++n) {
				int game_no = distr(eng);
				std::cout << game_no << ' '; // generate numbers 

				switch (choice) {
				case 1:
					getVeryEasyGame(game_no);
					break;
				case 2:
					getEasyGame(game_no);
					break;
				case 3:
					getMediumGame(game_no);
					break;
				case 4:
					getHardGame(game_no);
					break;
				}

			}
			cout << endl;

			char sudoku[9][9] = {
				{ sp, sp, sp, sp, sp, sp, '2', sp, sp },
				{ sp, sp, sp, '5', '3', '2', sp, sp, '4' },
				{ sp, sp, '2', sp, sp, '1', sp, '7', '6' },
				{ sp, sp, '1', sp, '4', sp, '6', sp, '7' },
				{ sp, sp, sp, sp, '5', sp, sp, sp, sp },
				{ '7', sp, '9', sp, '2', sp, '5', sp, sp },
				{ '8', '4', sp, '3', sp, sp, '1', sp, sp },
				{ '1', sp, sp, '6', '9', '8', sp, sp, sp },
				{ sp, sp, '5', sp, sp, sp, sp, sp, sp }
			};

			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, value);

			for (i = 0; i < 9; i++)
				for (j = 0; j< 9; j++) {
					cout << sudoku[i][j] << "|";
					if (j == 8)
						cout << endl;
				}
			cin >> ch;
		}

		int main() {

			test t = test();
			t.startGame();
		}
