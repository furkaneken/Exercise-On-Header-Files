#include "parent.h"
#include <iostream>
#include <string>

using namespace std;

Parent::Parent(string n, Account & a) : name(n), acc(a) {}

void Parent::printAccountInfo()
{
	cout << endl << "******************************" << endl <<
		"The account balance is: " << acc.balance << "TL." << endl <<
		"The account debt is: " << acc.debt << "TL." << endl <<
		"The account limit is: " << acc.limit << "TL." << endl <<
		"The available account limit is: " << acc.limit - acc.debt << "TL." << endl <<
		"******************************" << endl;
}

void Parent::depositMoney(const double & amount)
{
	acc.balance += amount;
	cout << name << " has deposited " << amount << "TL." << endl;
}

void Parent::spendMoney(const double & amount)
{
	if (amount <= acc.balance) //if the parent attempts to spend amount lower than balance
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

void Parent::payDebt(const double & amount)
{
	if (amount <= acc.debt)
	{
		acc.debt -= amount;
		cout << name << " paid " << amount << "TL of debt." << endl;
	}
	else //parent can only pay debt if the amount is lower than the debt
	{
		cout << name << " attempts to pay more than debt. No payment is done." << endl;
	}
}