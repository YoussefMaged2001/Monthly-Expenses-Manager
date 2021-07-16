#pragma once
#include <string>
#include "Date.h"
#include <vector>
using namespace std;
class Wallet
{
protected:
	static unsigned int nextId;
	string name , category;
	unsigned long long balance;
	unsigned int id , monthlyIncome;
	Date monthStartDate;

public:
	Wallet(string, string, unsigned long long, unsigned int , Date);
	Wallet() {}
	void loadNextID();
	string GetName();
	string GetCategory();
	Date getStartDate();
	unsigned long long GetBalance();
	unsigned int GetId();
	unsigned int GetMonthlyIncome();
	void deposit(int);
	void withdraw(int);
	void setID(unsigned int);
	~Wallet();
};


