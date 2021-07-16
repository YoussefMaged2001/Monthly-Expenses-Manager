#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include "Date.h"
using namespace std;

Date::Date(){
    time_t date = time(0);
    tm* currentDate = localtime(&date);
    this->day = currentDate->tm_mday; 
    this->month = (currentDate->tm_mon + 1);
    this->year = (currentDate->tm_year + 1900);

}

Date:: Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}


int Date::getDay(){
    return this->day;
}


int Date::getMonth(){
    return this->month;
}


int Date::getYear(){
    return this->year;
}

std::string Date::toString()
{

    return to_string(day) + "-" + to_string(month) +"-" + to_string(year);
}

bool Date::operator<(Date other)
{
    if (year < other.getYear())
        return true;

    if (year == other.getYear())
        if (month < other.getMonth())
            return true;
    if (year == other.getYear())
        if (month == other.getMonth())
            if(day < other.getDay())
                return true;
    return false;
}

bool Date::operator>(Date other)
{
    return other < Date(day,month,year);
}

bool Date::operator==(Date other)
{
    if (year == other.getYear())
        if (month == other.getMonth())
            if (day == other.getDay())
                return true;
    return false;
}

bool Date::operator>=(Date other)
{
    return (other == Date(day,month,year)) || (Date(day,month,year) > other);
}

bool Date::operator<=(Date other)
{
    return (other == Date(day, month, year)) || (Date(day, month, year) < other);
}









