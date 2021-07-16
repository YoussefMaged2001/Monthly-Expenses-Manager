#pragma once
#include "logInAndRegister.h"
#include "InputChecker.h"
#include <string>
#include "InformationProvider.h"

extern InformationProvider* program;

using namespace std;
void getExpenseFromUser(unsigned int walletId)
{

	int walletsSize = program->wallets.size();
	system("CLS");
	string name, category;
	double cost;
	int day, month, year;
	cout << "Enter expense name: ";
	cin.ignore();
	getline(cin, name);
	vector<int> categoriesChoices;
	cout << "Choose the corresponding number for the category" << endl;
	for (int i = 0; i < program->categories.size(); i++)
	{
		cout << "(" << i + 1 << ") " << program->categories[i] << endl;
		categoriesChoices.push_back(i + 1);
	}
	int categoryChoice = getData<int>("Enter expense number: ", true, categoriesChoices);
	category = program->categories[categoryChoice - 1];

	cost = getData<double>("Enter expense cost: ");
	day = getData<int>("Enter expense day: ");
	month = getData<int>("Enter expense month: ");
	year = getData<int>("Enter expense year: ");

	Date date(day, month, year);



	Expense programExpense(name, category, cost, date, walletId);

	char choice = getData<char>("are you sure you want to add this data?(y/n) : ", true, vector<char>{'y', 'n'});
	if (choice == 'y')
	{
		program->AddExpense(programExpense);
		
	}
}

