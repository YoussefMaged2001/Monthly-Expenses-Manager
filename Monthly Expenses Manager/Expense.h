#pragma once
#include <string>
#include "Date.h"
#include <vector>
using namespace std;

class Expense
{
private:
	static unsigned int nextId;
	unsigned int id;
	string  category,name;
	double cost;
	Date date;
	unsigned int walletId;

public:
	static void loadNextId();
	Expense(string name, string category, double cost, Date date, unsigned int walletId);
	Expense() {}
	string getName();
	string getCategory();
	unsigned int getId();
	double getCost();
	Date getDate();
	unsigned int getWalletId();
	void setId(unsigned int);
};



