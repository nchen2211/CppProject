#include<iostream>
using namespace std;
const int ht = 10000;
const int t = 1000;
const int h = 100;
const int ten = 10;
const int one = 1;

void main()
{
	int num = 0;
	int div;
	int first,second,third,forth,fifth;
	bool palindrome = false;
	do
	{
		cout<<"Enter 5 digits integer: "<<endl;
		cin>>num;
	}while(num < 10000);
		
	first = num / ht;
	num %= ht;
	second = num / t;
	num %= t;
	third = num / h;
	num %= h;
	forth = num / ten;
	num %= ten;
	fifth = num;

	if(first == fifth)
	{
		if(second == forth)
			palindrome = true;
		cout<<"The integer is a palindrome number."<<endl;
	}
	else
		cout<<"The integer is not a plaindrome number."<<endl;
}
	
	