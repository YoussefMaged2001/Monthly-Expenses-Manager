#include<iostream>
#include"InformationProvider.h"
#include "FileHandler.h"
#include "logInAndRegister.h"
#include "addCategory.h"
#include "Menu.h"
#include "addExpense.h"
using namespace std;

InformationProvider* program = new InformationProvider();
string Username, Password;
void save()
{
	FileHandler::initFileUser("db.csv", Username, Password);
	FileHandler::initFileContent("db.csv", program->wallets, program->expenses, program->categories);
}
int main()
{
	atexit(save);
	while (true)
	{
		while (true)
		{
			system("CLS");
			cout << "------------------------------ Welcome To Monthly Expenses Manager ------------------------------\n";
			cout << "-Press (L) if you are already a user\n";
			cout << "-Press (S) if you are new\n";
			cout << "-Press (0) to exit\n";
			char choice = getData<char>("Please Enter your choice : ", true, vector<char>{'0', 'l', 's'});
			if (choice == '0')
				exit(1);
			else if (choice == 'l')
			{
				bool loggedIN = logIn("db.csv");
				if (loggedIN)
					break;
				else
					continue;
			}
			else if (choice == 's')
			{
				userSignUp("db.csv");
			}
		}


		program->wallets = FileHandler::readWallets("db.csv");
		program->categories = FileHandler::readCategories("db.csv");
		program->expenses = FileHandler::readExpenses("db.csv");



		program->Add_category("Shopping");
		program->Add_category("Transport");
		program->Add_category("Home");
		program->Add_category("Personal");
		program->Add_category("Education");

		MainMenu();

		


	}




































	/* 
	This line must be called before initilazing user & file content & getCategoryFromUser.
	program.categories= FileHandler::readCategories("db.csv");
	*/
}