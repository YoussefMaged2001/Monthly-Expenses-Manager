#pragma once
#include "Expense.h"
unsigned int Expense::nextId = 0;
Expense::Expense(string name, string category, double cost, Date date , unsigned int walletId)
{
	this->category = category;
	this->name = name;
	this->cost = cost;
	this->date = date;
	id = nextId;
	this->walletId = walletId;
	loadNextId();
	
}

void Expense::loadNextId()
{
	nextId++;
}
string Expense::getName()
{
	return name;
}
string Expense::getCategory()
{
	return category;
}
double Expense::getCost()
{
	return cost;
}
unsigned int Expense::getId()
{
	return id;
}
Date Expense::getDate()
{
	return date;
}

unsigned int Expense::getWalletId()
{
	return walletId;
}

void Expense::setId(unsigned int value)
{
	this->id = value;
}
