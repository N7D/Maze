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

	int a = 1, c[3000], c1 = 2, n, k = 0, height = 0, width = 0, speed = 50, complexety = 5,style = 3;
	int a1, a2, m[3000], j, h;
	int a0;




	system("CLS");
	
	while (complexety != 2 && complexety != 1 && complexety != 3 && complexety != 4) {
		if (lang == 1)
			cout << " Choose complexety. \n 1.Small\n 2.Medium \n 3.Large\n 4.Ultimate" << endl;
		if (lang == 2)
			cout << " �������� ������. \n 1.Small\n 2.Medium \n 3.Large\n 4.Ultimate" << endl;
		cin >> t;
		while (height % 2 == 0 || width % 2 == 0 || height < 5 || width < 5 || (height + 2)*(width + 2) >= 3000 || width>79) {
		if (t == "1" || t == "small" || t == "Small") {
			complexety = 1;
			width = 5 + rand() % 5;
			height = 5 + rand() % 5;
			speed = 60;
		}
		if (t == "2" || t == "medium" || t == "Medium") {
			complexety = 2;
			width = 8 + rand() % 8;
			height = 8 + rand() % 8;
			speed = 70;
		}
		if (t == "3" || t == "large" || t == "Large") {
			complexety = 3;
			width = 12 + rand() % 65;
			height = 11 + rand() % 10;
			speed = 80;
		}
		if (t == "4" || t == "ultimate" || t == "Ultimate") {
			complexety = 4;
			width = 79;
			height = 21;
			speed = 90;
		}
	}
	}
	system("CLS");
	while (style != 15 && style != 8) {
		if (lang == 1)
			cout << " Choose style. \n 1.Flat\n 2.Relief" << endl;
		if (lang == 2)
			cout << " �������� �����. \n 1.Flat\n 2.Relief" << endl;
		cin >> t;
		if (t == "1" || t == "flat" || t == "Flat") {
			style = 8;
		}
		if (t == "2" || t == "relief" || t == "Relief") {
			style = 15;
		}
	}



	Sleep(300);
	system("color 0F");
	system("CLS");
	system("color 0F");
	Sleep(300);
	if (lang == 1)
		cout << " Loading...";
	if (lang == 2)
		cout << " ��������...";
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
			SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | style));
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



	//�����������
	a1, a2, m[3000], j, h = 0;
	c1 = 0;
	if (lang == 1)
		cout << " Do you wanna to see auto-run? (Yes/No)" << endl;
	if (lang == 2)
		cout << " ������ ������� �� ������������ ���������? (Yes/No)" << endl;
	while (h == 0) {
		cin >> t;
		if (t == "yes" || t == "Yes" || t == "��" || t == "��") {
			h = 1;
			j = 0;
		}
		if (t == "no" || t == "No" || t == "���" || t == "���") {
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
					SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | style));
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
						if (style == 8)
							SetConsoleTextAttribute(hConsole, (WORD)((14 << 4) | 14));
						else
						
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

	for (int counter2 = 15; counter2 >7; counter2--) {
		Sleep(100);
		system("CLS");
		for (int counter = 0; counter < width*height; counter++) {
			if (b[counter] == ".")
				if (style == 8)
				SetConsoleTextAttribute(hConsole, (WORD)((14 << 4) | 14));
				else
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
			if (b[counter] == "#") {
				if (style == 8)
				SetConsoleTextAttribute(hConsole, (WORD)((counter2 << 4) | counter2));
				else
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
					if (style == 8)
						SetConsoleTextAttribute(hConsole, (WORD)((14 << 4) | 14));
					else
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

int main() {
	string t = "p";
	int lang = 0;
	system("color F0");

	while (lang != 2 && lang != 1) {
		cout << " Choose langauge. (Rus/Eng)" << endl;
		cin >> t;
		if (t == "Rus" || t == "rus") {
			lang = 2;
		}
		if (t == "Eng" || t == "eng") {
			lang = 1;
		}
	}
	do {
		t = "p";
		maze(lang);
		while (t != "yes" && t != "Yes" && t != "��" && t != "��" && t != "no" && t != "No" && t != "���" && t != "���") {
			if (lang == 1)
				cout << " Shall we do it all over again? (Yes/No)" << endl;
			if (lang == 2)
				cout << " ����� �� �����? (Yes/No)" << endl;
			cin >> (t);
		}
	} while (t == "yes" || t == "Yes" || t == "��" || t == "��");
	if (lang == 1)
		cout << " Well... then we finished, good bye." << endl;
	if (lang == 2)
		cout << " ������... ����� �� ���������, ������. " << endl;
	getchar();
	getchar();
	return 0;
}