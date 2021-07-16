#pragma once
#include <string>
#include <iostream>
using namespace std;
#include <type_traits>


template <typename T>
T getData(string text, bool useOnlyChoices = false, vector<T> choices = {})
{
	cout << text;
	T data;
	cin >> data;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad input, " << text;
		cin >> data;
	}
    while(useOnlyChoices){
		if (useOnlyChoices)
		{
			for (auto i : choices)
			{
				if (i == data)
					return data;
			}
		}
		cout << "Bad input, " << text;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> data;
    }
	return data;
}