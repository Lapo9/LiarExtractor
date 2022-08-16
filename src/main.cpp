#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cwchar>
#include <Windows.h>

#include "Extractor.h"




std::string decorate(std::string oneLineText) {
	std::string top = "\t\t\t+";
	std::string semiTop = "\t\t\t|";
	int length = oneLineText.size();

	for (int i = 0; i < length + 4; ++i) {
		top += "-";
		semiTop += " ";
	}
	top += "+\n";
	semiTop += "|\n";

	return top + semiTop + "\t\t\t|  " + oneLineText + "  |\n" + semiTop + top;
}




int main() {
	//set console font size
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	info.nFont = 0;
	info.dwFontSize.X = 0;
	info.dwFontSize.Y = 24;
	info.FontFamily = FF_DONTCARE;
	info.FontWeight = FW_NORMAL;
	std::wcscpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &info);

	Extractor extractor{ "categories/categorie.txt" };
	std::string title = "";
	std::cout << "e: estrai prossimo\tc: estrai a caso\tr: reset\t x: exit\n";
	char command;
	std::cin >> command;
	while (command != 'x') {
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		switch (command) {
		case 'e':
			std::cout << decorate(extractor.extractNext());
			break;
		case 'c':
			std::cout << decorate(extractor.extract());
			break;		
		case 'r':
			extractor.shuffle();
			std::cout << "Categorie mischiate!";
			break;
		}
		std::cout << "\n\ne: estrai prossimo\tc: estrai a caso\tr: reset\t x: exit\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cin >> command;
	}
}

