#include <iostream>
#include <string>
#include <stdio.h>

#include "Maze.h"

using namespace std;

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
		while (t != "yes" && t != "Yes" && t != "да" && t != "Да" && t != "no" && t != "No" && t != "Нет" && t != "нет") {
			if (lang == 1)
				cout << " Shall we do it all over again?" << endl;
			if (lang == 2)
				cout << " Может по новой? " << endl;
			cin >> t;
		}
	} while (t == "yes" || t == "Yes" || t == "да" || t == "Да");
	if (lang == 1)
		cout << " Well... then we finished, good bye." << endl;
	if (lang == 2)
		cout << " Хорошо... тогда мы закончили, прощай. " << endl;
	getchar();
	getchar();
	return 0;
}