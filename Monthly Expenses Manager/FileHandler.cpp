#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void FileHandler::initFileUser(string fileName, string username, string password)
{
	ofstream file(fileName);
	file << "username" << "," << "password" << endl;
	file << username << "," << password << endl;
	file.close();

}
void FileHandler::initFileContent(string fileName, vector<Wallet> wallets, vector<Expense> expenses, vector<string>categories)
{
	int numOfWallets = wallets.size();
	int numOfExpenses = expenses.size();
	int numOfCategories = categories.size();

	ofstream file(fileName, ios_base::app);


	file << "walletID" << "," << "name" << "," << "category" << "," << "balance" << "," << "monthlyIncome" << "," << "monthstartdate" << endl;
	for (int i = 0; i < numOfWallets; i++) {
		file << wallets[i].GetId() << "," << wallets[i].GetName() << "," << wallets[i].GetCategory() << "," << wallets[i].GetBalance() << "," << wallets[i].GetMonthlyIncome() << "," << wallets[i].getStartDate().getDay() << "-" << wallets[i].getStartDate().getMonth() << "-" << wallets[i].getStartDate().getYear() << endl;
	}

	file << "expenseID" << "," << "name" << "," << "category" << "," << "cost" << "," << "date" << "," << "walletId" << endl;
	for (int i = 0; i < numOfExpenses; i++) {
		file << expenses[i].getId() << "," << expenses[i].getName() << "," << expenses[i].getCategory() << "," << expenses[i].getCost() << "," << expenses[i].getDate().getDay() << "-" << expenses[i].getDate().getMonth() << "-" << expenses[i].getDate().getYear() << "," << expenses[i].getWalletId() << endl;
	}

	file << "categories" << endl;
	for (int i = 0; i < numOfCategories; i++)
	{
		file << categories[i] << endl;
	}
	file.close();

}
vector<string> FileHandler::readUserRecord(string fileName) {
	vector<string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string username;
	string password;
	int count = 0;
	while (getline(file, username, ',') && !isFound)
	{
		count++;
		getline(file, password, '\n');
		if (count == 2) {
			isFound = 1;
			record.push_back(username);
			record.push_back(password);
			file.close();

			return record;
		}
	}
}
vector<string> FileHandler::readWalletRecordById(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string name, category;
	string balance;
	string monthlyIncome, id;
	string monthStartDate;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, balance, ',');
		getline(file, monthlyIncome, ',');
		getline(file, monthStartDate, '\n');

		if (id == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(balance);
			record.push_back(monthlyIncome);
			record.push_back(monthStartDate);
			file.close();
			return record;
		}
	}

}
vector<string> FileHandler::readWalletRecordByName(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string name, category;
	string balance;
	string monthlyIncome, id;
	string monthStartDate;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, balance, ',');
		getline(file, monthlyIncome, ',');
		getline(file, monthStartDate, '\n');

		if (name == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(balance);
			record.push_back(monthlyIncome);
			record.push_back(monthStartDate);
			file.close();
			return record;
		}
	}

}
vector<string> FileHandler::readExpenseRecordById(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string id, name;
	string category, date;
	string cost, walletid;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, cost, ',');
		getline(file, date, ',');
		getline(file, walletid, '\n');

		if (id == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(cost);
			record.push_back(date);
			record.push_back(walletid);
			file.close();
			return record;
		}
	}

}
vector<string> FileHandler::readExpenseRecordByName(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string id, name;
	string category, date;
	string cost, walletid;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, cost, ',');
		getline(file, date, ',');
		getline(file, walletid, '\n');

		if (name == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(cost);
			record.push_back(date);
			record.push_back(walletid);
			file.close();
			return record;
		}
	}

}
vector<Wallet> FileHandler::readWallets(string fileName) {

	vector<Wallet> records;

	ifstream file(fileName);
	string name;
	string category;
	string balance;
	string monthlyIncome;
	string record;
	string monthStartDate;

	bool inRange = 0;
	int i = 0;
	string walletId;
	while (getline(file, record, '\n'))
	{
		if (record.find("walletID") != -1) {
			inRange = 1;
			continue;
		}
		if (record.find("expenseID") != -1) {
			inRange = 0;
			break;
		}
		if (inRange) {

			//ID
			int index = record.find(",");
			walletId = record.substr(0, index);
			record.erase(0, index + 1);

			//Name
			index = record.find(",");
			name = record.substr(0, index);
			record.erase(0, index + 1);

			//Category
			index = record.find(",");
			category = record.substr(0, index);
			record.erase(0, index + 1);

			//Balance
			index = record.find(",");
			balance = record.substr(0, index);
			record.erase(0, index + 1);

			//Monthly Income
			index = record.find(",");
			monthlyIncome = record.substr(0, index);
			record.erase(0, index + 1);

			//MonthStartDate
			monthStartDate = record;

			unsigned int castedId = stoul(walletId, nullptr, 10);
			string castedName = name;
			string castedCategory = category;
			unsigned long long castedBalance = stoull(balance, nullptr, 10);
			unsigned int castedMonthlyIncome = stoul(monthlyIncome, nullptr, 10);

			index = monthStartDate.find("-");
			int day = stoi(monthStartDate.substr(0, index));
			monthStartDate.erase(0, index + 1);


			index = monthStartDate.find("-");
			int month = stoi(monthStartDate.substr(0, index));
			monthStartDate.erase(0, index + 1);


			int year = stoi(monthStartDate);

			Date date(day, month, year);

			Wallet wallet(castedName, castedCategory, castedBalance, castedMonthlyIncome, date);
			wallet.setID(castedId);

			records.push_back(wallet);

		}
	}
	return records;
}
vector<Expense> FileHandler::readExpenses(string fileName)
{

	vector<Expense> records;

	ifstream file(fileName);
	string record;
	string expenseId;
	string name;
	string category;
	string cost;
	string date;
	string walletId;

	bool inRange = 0;
	int userCount = 0;

	while (getline(file, record, '\n'))
	{
		if (record.find("expenseID") != -1) {
			inRange = 1;
			continue;
		}
		if (record.find("categories") != -1 ) {
			inRange = 0;
			break;
		}

		if (inRange) {

			//ID
			int index = record.find(",");
			expenseId = record.substr(0, index);
			record.erase(0, index + 1);

			//Name
			index = record.find(",");
			name = record.substr(0, index);
			record.erase(0, index + 1);

			//Category
			index = record.find(",");
			category = record.substr(0, index);
			record.erase(0, index + 1);

			//Balance
			index = record.find(",");
			cost = record.substr(0, index);
			record.erase(0, index + 1);

			//Monthly Income
			index = record.find(",");
			date = record.substr(0, index);
			record.erase(0, index + 1);

			//MonthStartDate
			walletId = record;


			unsigned int castedId = stoul(expenseId, nullptr, 10);
			string castedName = name;
			string castedCategory = category;
			unsigned long long castedCost = stoull(cost, nullptr, 10);
			unsigned int castedWalletId = stoul(walletId, nullptr, 10);

			index = date.find("-");
			int day = stoi(date.substr(0, index));
			date.erase(0, index + 1);
			cout <<endl<< date<<endl;
			cout << endl << day << endl;
			index = date.find("-");
			int month = stoi(date.substr(0, index));
			date.erase(0, index + 1);
			cout << endl << date << endl;
			cout << endl << month << endl;

			int year = stoi(date);

			Date dateObj(day, month, year);

			Expense expense(castedName, castedCategory, castedCost, dateObj, castedWalletId);
			expense.setId(castedId);

			records.push_back(expense);

		}
	}
	return records;
}
vector<string> FileHandler::readCategories(string fileName) {


	vector<string> records;

	ifstream file(fileName);
	string record;

	bool inRange = 0;
	int userCount = 0;

	while (getline(file, record, '\n'))
	{
		if (record.find("categories") != -1) {
			inRange = 1;
			continue;
		}
		if (record.find("username") != -1 && userCount == 2) {
			inRange = 0;
			break;
		}
		if (record.find("username") != -1) {
			userCount++;
		}

		if (inRange) {

			//CATEGORY
			records.push_back(record);

		}
	}
	return records;

}
