#include<iostream>
using namespace std;

int gcd(int, int);


int gcd(int x, int y)
{
	if(y == 0)
	{
		cout<<x;
		return x;
	}
	else
		return gcd(y, x%y);
}

void main()
{
	int a=0;
	int b=0;
	cout<<"Enter 2 integers (required: int1 > int2) ";
	cin>>a>>b;

	cout<<"Greater common division is: ";
	gcd(a,b);
	cout<<endl;
}

