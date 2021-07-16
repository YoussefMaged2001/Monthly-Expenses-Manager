#pragma once
#include "Wallet.h"
#include "Expense.h"
#include "Date.h"
#include <map>
#include <stack>
#include "Operation.h"
using namespace std;

class InformationProvider
{

public:
	vector<Wallet> wallets;
	vector<Expense> expenses;
	vector<string> categories;
	bool categoryFilter, dateFilter;
	unsigned int walletFilterID;
	map<string, bool>categoryFilterName;
	Date dateFilterDay;
	stack<Operation<Expense>> UndoExpenseChange;
	stack<Operation<Wallet>> UndoWalletChange;
	stack<Operation<Expense>> UndoExpenseByWallet;
	


public:
	void AddWallet(Wallet);
	bool AddWalletCheck(Wallet wallet);
	void AddExpense(Expense);
	void Add_category(string);
	Expense SearchExpense(string);
	vector<Expense> SearchExpense(string, string);
	vector<Expense> SearchExpense(string, unsigned int);
	int SearchExpense(unsigned int);
	Wallet SearchWallet(string);
	int SearchWallet(unsigned int);
	void DeleteWallet(unsigned int);
	void DeleteExpense(unsigned int);
	void Refund(unsigned int, int);
	vector<Expense> Filter();
	void UndoExpense();
	void UndoWallet();
	void reUndoWalletExpenses(Wallet wallet);
	


};


