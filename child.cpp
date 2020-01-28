#include "child.h"
#include <iostream>

using namespace std;

Child::Child(string n, Parent & p) : name(n), acc(p.acc) {} //

void Child::displayAccountInfo()
{
	cout << endl << "******************************" << endl <<
		"The account balance is: " << acc.balance << "TL." << endl <<
		"The available account limit is: " << acc.limit - acc.debt << "TL." << endl <<
		"******************************" << endl;
}

void Child::spendMoney(const double & amount)
{
	if (amount > 200) //if the child attemps to pay more than 200TL, the program declines the request
	{
		cout << name <<" can not spend " << amount << "TL. Children can spend up to 200TL." << endl;
	}
	else
	{
		if (amount <= acc.balance) //if the child attempts to spend amount lower than balance
		{
			acc.balance -= amount;
			cout << name << " has successfully spent " << amount << "TL." << endl;
		}
		else //if the child attempts to spend amount higher than balance
		{
			if (amount - acc.balance <= acc.limit - acc.debt) //program calculates if the payment exceeds available limit
			{
				acc.debt += amount - acc.balance;
				acc.balance = 0;
				cout << name << " has successfully spent " << amount << "TL." << endl;
			}
			else
			{
				cout << "Requested payment exceeds available limit. No payment is done" << endl;
			}
		}
	
	}
}