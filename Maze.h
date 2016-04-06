#pragma once
#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <ctime>
#include <windows.h> 
#include <stdio.h>
#include <chrono>
using namespace std;
int maze(int lang) {
start:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("color F0");

	setlocale(0, "rus");
	srand(time(0));
	string b[3000], t = "p";

	int a = 1, c[3000], c1 = 2, n, k = 0, height = 0, width = 0, speed = 150;
	int a1, a2, m[3000], j, h;
	int a0;


	

	system("CLS");

	if (lang == 1)
		cout << " Warning! No localization ahead. This unit will be reworked soon." << endl;
	if (lang == 2)
		cout << " Этот модуль нуждается в переработке " << endl;
	while (height % 2 == 0 || width % 2 == 0 || height < 5 || width < 5 || (height + 2)*(width + 2) >= 3000 || width>79) {
		cout << " Нечетные высота и ширина? 21 79: ";
		cin >> height >> width;
		if (height < 5) cout << " Маленикая высота!!!" << endl;
		if (width < 5) cout << " Маленикая ширина!!!" << endl;
		if ((height + 2)*(width + 2) >= 3000) cout << " Слишком большой лабиринт" << endl;
		if (width>79)cout << " Слишком большая ширина" << endl;
		if (width % 2 == 0 || height % 2 == 0)cout << " Числа должны быть нечетными!!" << endl;
	}

	Sleep(300);
	system("color 0F");
	system("CLS");
	system("color 0F");
	Sleep(300);
	if (lang == 1)
		cout << " Loading...";
	if (lang == 2)
		cout << " Загрузка...";
	Sleep(1000);
	system("CLS");

	height += 2;
	width += 2;
	for (int counter = 0; counter < height*width; counter++) {
		b[counter] = " ";
		if (counter < width)b[counter] = "#";
		if (counter>height*width - width - 1)b[counter] = "#";
		if (counter % width == 0)b[counter] = "#";
		if (counter % width == width - 1)b[counter] = "#";
	}
	while (a % 2 == 1)
		a = rand() % (width - 4) + width*height - width + 2;
	b[a] = ".";
	b[a - width] = ".";
	a = 1;
	while (a % 2 == 1)
		a = rand() % (width - 4) + 2;
	b[a] = ".";
	b[a + width] = ".";
	a += width * 2;
	cout << 1;
	while (c1>1) {
		a0 = a;
		if (k < 15) {
			c[c1] = a;
			c1++;
		}
		b[a] = ".";
		k = 0;
		while (a0 == a && k<15) {
			n = rand() % 4 + 1;
			if (n == 1 && b[a + 2] == " ")a++;
			if (n == 2 && b[a + width * 2] == " ")a += width;
			if (n == 3 && b[a - width * 2] == " ")a -= width;
			if (n == 4 && b[a - 2] == " ")a--;
			k++;
		}
		if (k == 15) {
			c[c1 - 1] = 0;
			c1 -= 2;
			a = c[c1];
			c1++;
		}
		if (a>0)
			b[a] = ".";
		if (a < 0)
			c1 = 0;
		if (k < 15) {
			if (n == 1)a++;
			if (n == 2)a += width;
			if (n == 3)a -= width;
			if (n == 4)a--;
			b[a] = ".";
		}
	}
	b[width * 2] = "#";
	for (int counter = 0; counter < width*height; counter++) {
		if (b[counter] == "#")b[counter] = "";
		if (b[counter] == " ")b[counter] = "#";
		if (counter>width * 2 || counter<width)
			if (b[counter] == ".")b[counter] = " ";
	}
	system("CLS");
	for (int counter = 0; counter < width*height; counter++) {
		if (b[counter] == "#") {
			SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 15));
			cout << b[counter];
			if (counter % width == width - 1)
				cout << endl;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		}
		else {
			if (b[counter] == " ") {
				cout << b[counter];
				if (counter % width == width - 1)
					cout << endl;
			}
			else {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
				cout << b[counter];
				if (counter % width == width - 1)
					cout << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			}

		}
	}
	//Прохождение
	a1, a2, m[3000], j, h = 0;
	c1 = 0;
	if (lang == 1)
		cout << " Do you wanna to see auto-run?" << endl;
	if (lang == 2)
		cout << " Хотите следить за прохождением лабиринта? " << endl;
	while (h == 0) {
		cin >> t;
		if (t == "yes" || t == "Yes" || t == "да" || t == "Да") {
			h = 1;
			j = 0;
		}
		if (t == "no" || t == "No" || t == "Нет" || t == "нет") {
			h = 1;
			j = 1;
		}
	}
	k = j;
	for (int counter = 0; counter < width; counter++) {
		for (int y = 0; y < width*height; y++)
			b[y] = b[y + 1];
	}
	for (int counter = 0; counter < width; counter++)
		if (b[counter] == ".")
			a = counter;
	for (int counter = width*(height - 3) - 1; counter < width*(height - 2); counter++)
		if (b[counter] == " ")
			a1 = counter;
	for (int counter = 0; counter < 3000; counter++)
		c[counter] = 0;
	b[a] = ".";
	while (a != a1) {
		if (k == 0) {
			system("CLS");


			for (int counter = 0; counter < width*height; counter++) {
				if (b[counter] == "#") {
					SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 15));
					cout << b[counter];
					if (counter % width == width - 1)
						cout << endl;
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				}
				else {
					if (b[counter] == " ") {
						cout << b[counter];
						if (counter % width == width - 1)
							cout << endl;
					}
					else {
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
						cout << b[counter];
						if (counter % width == width - 1)
							cout << endl;
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					}

				}
			}
			Sleep(speed);
		}
		n = 0;
		a2 = a;
		while (a2 == a) {
			n++;
			k = j;
			if (n == 1 && b[a - width] == " "&&a - width>0 && m[a - width] != 666)a -= width;
			if (n == 2 && b[a - 1] == " "&&m[a - 1] != 666)a--;
			if (n == 3 && b[a + 1] == " "&&m[a + 1] != 666)a++;
			if (n == 4 && b[a + width] == " "&&m[a + width] != 666)a += width;
			if (n == 5) {
				k = 1;
				n = 0;
				c1--;
				b[a] = " ";
				m[a] = 666;
				c1--;
				a = c[c1];
				c1++;
			}
		}
		b[a] = ".";
		c[c1] = a;
		c1++;

	}
	getchar();

	for (int counter2 = 8; counter2 <16; counter2++) {
		Sleep(100);
		system("CLS");
		for (int counter = 0; counter < width*height; counter++) {
			if (b[counter] == ".")

				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
			if (b[counter] == "#") {
				SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | counter2));
				cout << b[counter];
				if (counter % width == width - 1)
					cout << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			}
			else {
				if (b[counter] == " ") {
					cout << b[counter];
					if (counter % width == width - 1)
						cout << endl;
				}
				else {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
					cout << b[counter];
					if (counter % width == width - 1)
						cout << endl;
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				}
			}
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		}
	}
	

	return 0;
}