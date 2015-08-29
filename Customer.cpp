#include "Customer.h"
#include<iostream>
using namespace std;


Customer::Customer(int cust_ID, int call, int service, int wait)
{
	ID = cust_ID;
	callTime = call;
	serviceTime = service;
	waitTime = wait;
}

Customer::~Customer(){
	cout<<"Object Customer is deleted\n";
}

void Customer::setCustID(int iden)
{
	ID = iden;
}

void Customer::setCallTime(int n)
{
	callTime = n;
}

void Customer::setWaitTime(int wait)
{
	waitTime = wait;
}

void Customer::setServiceTime(int service)
{
	serviceTime = service;
}

int Customer::retCustID() const
{
	return ID;
}

int Customer::retCallTime() const
{
	return callTime;
}

int Customer::retServiceTime() const
{
	return serviceTime;
}

int Customer::retWaitTime() const
{
	return waitTime; 
}

void Customer::print()
{
	resultFile<<"Customer's ID: "<<retCustID()<<endl;
	//std::cout<<"Call time: minute "<<retCallTime()<<endl;
	//std::cout<<"Service length: "<<retServiceTime()<<" minute(s)."<<endl;
	//std::cout<<"Wait time: "<<retWaitTime()<<" minute(s)."<<endl<<endl;

}