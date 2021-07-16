#pragma once
#include "InformationProvider.h"
#include "Expense.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> showExpenses(vector<Expense> showedData)
{
	vector<int> choices;
	system("CLS");
	if (showedData.size() == 0)
	{
		cout << "No Data Found!";
		return vector<int>{0};
	}
	int showedDataSize = showedData.size();
	for (int i = 0; i < showedDataSize; i++) {
		cout << "Expense number "<< "(" << i + 1 << ") :" << endl;
		cout << "	Name: " << showedData[i].getName() << endl;
		cout << "	Category: " << showedData[i].getCategory() << endl;
		cout << "	Cost: " << showedData[i].getCost() << endl;
		cout << "	Date: " << showedData[i].getDate().getDay() << "-" << showedData[i].getDate().getMonth() << "-" << showedData[i].getDate().getYear() << endl;
		cout << "___________________________" << endl;
		choices.push_back(i + 1);
	}
	return choices;
}