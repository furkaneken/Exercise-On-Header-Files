#ifndef _CHILD_H
#define _CHILD_H

#include <string>
#include "account.h"
#include "parent.h"

class Child
{
private:
	string name;
	Account & acc; //acc is referenced to the parents account
public:
	Child(string n, Parent & p); //constructor
	void displayAccountInfo(); //displays only the balance and available limit
	void spendMoney(const double & amount); //spends money on parents account
};
#endif