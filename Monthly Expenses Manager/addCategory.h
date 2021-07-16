#pragma once
#include "InformationProvider.h"
#include <string>
#include "InputChecker.h"
#include "logInAndRegister.h"
#include "FileHandler.h"
extern InformationProvider* program;

void getCategoryFromUser()
{
	string category;
	system("CLS");
	cout << "Enter category name : ";
	cin.ignore();
	getline(cin, category);
	char c = getData<char>("are you sure you want to add this data ? (y / n) : ", 1, vector <char> {'y', 'n'});
	if (c == 'y')
	{
		program->Add_category(category);
		
	}

}
