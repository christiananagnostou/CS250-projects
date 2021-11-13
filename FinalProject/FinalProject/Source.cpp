#include <iostream>
#include "Header.h"

boolean test::segmentValidityCheck(char(*m)[9], int segment, int num) {
	int row, column;
	switch (segment) {
	case 1:
		for (row = 0; row <= 2; row++)
			for (column = 0; column <= 2; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 2:
		for (row = 0; row <= 2; row++)
			for (column = 3; column <= 5; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 3:
		for (row = 0; row <= 2; row++)
			for (column = 6; column <= 8; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 4:
		for (row = 3; row <= 5; row++)
			for (column = 0; column <= 2; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 5:
		for (row = 3; row <= 5; row++)
			for (column = 3; column <= 5; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 6:
		for (row = 3; row <= 5; row++)
			for (column = 6; column <= 8; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 7:
		for (row = 6; row <= 8; row++)
			for (column = 0; column <= 2; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 8:
		for (row = 6; row <= 8; row++)
			for (column = 3; column <= 5; column++)
				if (m[row][column] == num)
					return false;
		break;
	case 9:
		for (row = 6; row <= 8; row++)
			for (column = 6; column <= 8; column++)
				if (m[row][column] == num)
					return false;
		break;
	}

	return true;
}

void test::printMatrix(char(*m)[9]) {
	int i, j;

	CONSOLE_FONT_INFOEX font;
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(outcon, false, &font);
	SetCurrentConsoleFontEx(outcon, false, &font);
	system("CLS");
	cout << "Your score: " << score << "\n             --- Sudoku ---" << endl;
	SetConsoleTextAttribute(outcon, 0x07);
	cout << " \311\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\313\315\315\315\273 " << endl;
	SetConsoleTextAttribute(outcon, 0x0c);

	for (i = 0; i < 9; i++)
		for (j = 0; j< 9; j++) {
			if (j == 0 && i != 0) {
				SetConsoleTextAttribute(outcon, 0x07);
				cout << " \314\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\316\315\315\315\271 " << endl;
				SetConsoleTextAttribute(outcon, 0x0c);
			}
			SetConsoleTextAttribute(outcon, 0x07);
			cout << " \272 ";
			SetConsoleTextAttribute(outcon, 0x0c);
			cout << m[i][j];
			SetConsoleTextAttribute(outcon, 0x07);

			if (j == 8)
				cout << " \272" << endl;
		}

	cout << " \310\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\312\315\315\315\274 " << endl;
	SetConsoleTextAttribute(outcon, 0x0c);
}

boolean test::constraintsCheck(char(*m)[9], int row, int col, int num) {
	int numrow, column;
	int segment; // Divide squares into nine segments

	if ((col <= 2) && (row <= 2))
		segment = 1;
	else if (((col > 2) && (col <= 5)) && (row <= 2))
		segment = 2;
	else if (((col > 5) && (col <= 8)) && (row <= 2))
		segment = 3;
	else if ((col <= 2) && ((row > 2)) && (row <= 5))
		segment = 4;
	else if (((col > 2) && (col <= 5)) && ((row > 2)) && (row <= 5))
		segment = 5;
	else if (((col > 5) && (col <= 8)) && ((row > 2)) && (row <= 5))
		segment = 6;
	else if (((col <= 2) && (row > 5)) && (row <= 8))
		segment = 7;
	else if (((col > 2) && (col <= 5)) && ((row > 5) && (row <= 8)))
		segment = 8;
	else if (((col > 5) && (row > 5)) && (row <= 8))
		segment = 9;


	//Check in row
	for (column = 0; column < 9; column++) {
		if (m[row][column] == num)
			return false;
	}
	//Check in column
	for (numrow = 0; numrow < 9; numrow++) {
		if (m[numrow][col] == num)
			return false;
	}

	if (!(segmentValidityCheck(m, segment, num)))
		return false;

	return true;
}


boolean test::isDone(char(*m)[9]) {
	char space = ' ';
	char temp = 'Z';
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j< 9; j++) {
			if (m[i][j] == space) {
				return false;
			}
			cout << endl;
		}
	return true;
}

void test::processing(char(*m)[9]) {
	char numb;
	int row, column;
	boolean flag = true;
	HANDLE hConsole;
	CONSOLE_FONT_INFOEX font;
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(outcon, false, &font);
	SetCurrentConsoleFontEx(outcon, false, &font);

	cout << "In processing method" << endl;
	printMatrix(m);

	while (!(isDone(m))) {
		printMatrix(m);
		cout << "Give me the number to enter: ";
		cin >> numb;
		cout << endl << "Give me row number to enter: ";
		cin >> row;
		row -= 1;
		cout << endl << "Give me the column number: ";
		cin >> column;
		column -= 1;
		flag = true;

		if (m[row][column] != ' ') {
			score -= 5;
			SetConsoleTextAttribute(outcon, 0xc7);
			printMatrix(m);
			Sleep(5);
			SetConsoleTextAttribute(outcon, 0x07);
			printMatrix(m);
			Sleep(5);
			SetConsoleTextAttribute(outcon, 0xc7);
			printMatrix(m);
			Sleep(5);
			SetConsoleTextAttribute(outcon, 0x0c);
			printMatrix(m);
			Sleep(5);
			SetConsoleTextAttribute(outcon, 0xc7);
			printMatrix(m);
			Sleep(5);
			SetConsoleTextAttribute(outcon, 0x07);
			printMatrix(m);
			Sleep(5);
			SetConsoleTextAttribute(outcon, 0xc7);
			printMatrix(m);
			Sleep(5);
			SetConsoleTextAttribute(outcon, 0x0c);
			printMatrix(m);
			cout << "You are overwriting a given number which is not allowed" << endl;
			flag = false;
		}


		if (flag) {
			if (constraintsCheck(m, row, column, numb))
				m[row][column] = numb;
			if (m[row][column] == ' '){
				if (score > 0){
					score -= 5;
				}
				SetConsoleTextAttribute(outcon, 0xc7);
				printMatrix(m);
				Sleep(5);
				SetConsoleTextAttribute(outcon, 0x07);
				printMatrix(m);
				Sleep(5);
				SetConsoleTextAttribute(outcon, 0xc7);
				printMatrix(m);
				Sleep(5);
				SetConsoleTextAttribute(outcon, 0x0c);
				printMatrix(m);
				Sleep(5);
				SetConsoleTextAttribute(outcon, 0xc7);
				printMatrix(m);
				Sleep(5);
				SetConsoleTextAttribute(outcon, 0x07);
				printMatrix(m);
				Sleep(5);
				SetConsoleTextAttribute(outcon, 0xc7);
				printMatrix(m);
				Sleep(5);
				SetConsoleTextAttribute(outcon, 0x0c);
				if (score <= 5){
					score = 0;
					printMatrix(m);
					cout << "You lost, please close the console...\n\n";
					Sleep(3600000);
					system("pause");
				}
				printMatrix(m);
				cout << "Incorrect, Please Try Again\n" << endl;
			}
			//If contraintsCheck fails then flash the number
		}
		else {
			//cout << "Number exists in either row or column" << endl;
			cout << "Give it another shot" << endl;
			system("pause");
		}

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
		{ '2', spm, '3', spm, spm, spm, '6', '7', '8' },
		{ '9', spm, '6', '8', '7', '2', spm, spm, spm },
		{ '8', spm, '7', '6', spm, '3', '9', '2', '5' },
		{ spm, '2', spm, spm, '3', spm, spm, '8', '6' },
		{ spm, '9', spm, '2', spm, '6', spm, '1', spm },
		{ spm, '6', spm, spm, '4', spm, '2', '5', spm },
		{ '1', spm, '9', spm, spm, spm, '4', spm, '2' },
		{ spm, spm, spm, '3', '6', '1', spm, spm, spm },
		{ spm, spm, '5', spm, spm, spm, '8', spm, spm }
	};

	char medium_sudo2[9][9] = {
		{ '2', spm, '6', spm, spm, '5', '8', '1', '3' },
		{ spm, spm, spm, '1', spm, '8', spm, spm, spm },
		{ '8', spm, '1', '3', spm, '6', spm, spm, '5' },
		{ spm, '1', '2', '8', '3', '9', '6', '4', spm },
		{ spm, spm, spm, '2', '6', '7', spm, spm, spm },
		{ '6', '7', '8', '4', '5', '1', '9', '3', '2' },
		{ '3', spm, spm, '5', spm, '4', spm, spm, '9' },
		{ spm, spm, spm, '6', spm, '2', spm, spm, spm },
		{ 9, spm, '4', spm, spm, spm, '2', spm, '8' }
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
		{ spm, spm, '8', '5', '4', '9', '6', '2', '1' },
		{ '2', '6', '4', spm, '1', '3', '9', '8', '5' },
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
		{ spm, spm, '2', '9', '5', spm, '3', spm, '8' },
		{ '9', '6', spm, '7', '8', '3', spm, '1', '4' },
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
		{ '2', '1', spm, '8', '9', spm, '7', '3', spm },
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
	using namespace std;
	char ch;
	int choice;
	char sp = ' ';
	score = 100;

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 9); // define the range

	while (true) {
		HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_FONT_INFOEX font;
		GetCurrentConsoleFontEx(outcon, false, &font);
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
		cout << "\n\n\n\n\n\nDo you want to play the game (y/n) : ";
		cin >> ch;
		if (ch == 'n' || ch == 'N') exit(1);
		cout << endl << "What level do you want to play at?" << endl;
		cout << "For very easy games type 1" << endl;
		cout << "For easy games type      2 " << endl;
		cout << "For medium games type    3 " << endl;
		cout << "For hard games type      4 " << endl;
		cout << "Enter you choice : ";
		cin >> choice;
		cout << endl;
		//Put in instructions for bad input and clear that input
		//Continue loop till a valid input entered for game type.
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

}

int main() {

	test t = test();
	t.startGame();
}