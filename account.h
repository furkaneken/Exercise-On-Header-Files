#ifndef _ACCOUNT_H
#define _ACCOUNT_H
class Account
{
private:
	double balance;
	double limit;
	double debt;
public:
	Account(const double & bal, const double &lim, const double &deb);
	friend class Parent;
	friend class Child; //parent and child classes are friend to account class so they can alter its values
};
#endif