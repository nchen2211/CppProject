#pragma once
#include<fstream>
ofstream resultFile;

class Customer
{
public:
	Customer(int,int,int,int);
	~Customer();
	void setCustID(int);
	void setCallTime(int);
	void setWaitTime(int);
	void setServiceTime(int);
	int retCustID() const;
	int retCallTime() const;
	int retWaitTime() const;
	int retServiceTime() const;
	void print();
	

private:
	int ID;
	int callTime;
	int waitTime;
	int serviceTime;
};
