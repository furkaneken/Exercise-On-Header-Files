#ifndef _PARENT_H
#define _PARENT_H

#include <string>
#include "account.h"

using namespace std;

class Parent
{
private:
	string name;
	Account & acc; //acc is referenced to the given account
public:
	Parent(string n, Account & a);
	void printAccountInfo();
	void depositMoney(const double & amount);
	void spendMoney(const double & amount);
	void payDebt(const double & amount);
	friend class Child;
};
#endif