#pragma once
#include <iostream>
#include <string>
#include "InformationProvider.h"
#include "FileHandler.h"
#include "InputChecker.h"
 extern InformationProvider* program;
extern string Username, Password;

bool logIn(string fileName)
{
	system("CLS");
	cout << "------------------------------ Welcome Again! ------------------------------\n";
	vector<string> userInfo = FileHandler::readUserRecord(fileName);
	vector<string> userEnteredData(2);
	cin.ignore();
	while (true)
	{
		cout << "Please Enter Your Username : ";
		getline(cin, userEnteredData[0]);
		if (userEnteredData[0] == "back")
			return 0;
		cout << "Please Enter Your Password: ";
		getline(cin, userEnteredData[1]);
		if (userInfo[0] == userEnteredData[0] && userInfo[1] == userEnteredData[1])
		{
			Username = userEnteredData[0];
			Password = userEnteredData[1];
			return 1;
		}
		else
		{
			cout << "Invalid UserName or Password!\n";
			cout << "Try again or press (back) to go back\n";
		}
	}

}
void userSignUp(string fileName)
{
	system("CLS");
	cout << "------------------------------ Sign Up ------------------------------\n";
	cout << "Warning : The Previous Account will be deleted!\n";
	char c = getData<char>("are you sure you want to continue ? (y / n) : ", 1, vector <char> {'y', 'n'});
	if (c == 'n')
	{
		return;
	}
	string username, password, passwordConfirmation;
	cout << "Please Enter Your Username : ";
	cin.ignore();
	getline(cin, username);
	cout << "Please Enter Your Password : ";
	getline(cin, password);
	while (true)
	{
		cout << "Please Enter Your Password Again : ";
		getline(cin, passwordConfirmation);
		if (password == passwordConfirmation)
			break;
		else
			cout << "Invalid Password Please enter the same password!\n";
	}
	FileHandler::initFileUser(fileName, username, password);

}
