#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "InformationProvider.h";

using namespace std;

class FileHandler
{
public:
	static void initFileUser(string,string, string);
	static void initFileContent(string fileName,  vector<Wallet>, vector<Expense>,vector<string>);
	static vector<string> readUserRecord(string);
	static vector<string> readWalletRecordById(string, string);
	static vector<string> readWalletRecordByName(string, string);
	static vector<string> readExpenseRecordById(string, string);
	static vector<string> readExpenseRecordByName(string, string);
	static vector<Wallet> readWallets(string);
	static vector<Expense> readExpenses(string);
	static vector<string> readCategories(string);

};
