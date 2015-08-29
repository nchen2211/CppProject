#include "IntegerSet.h"
#include <iostream>
#include <iomanip>
using namespace std;

IntegerSet::IntegerSet(int arr[], int size)
{
	emptySet();

	for(int i=0; i<size; i++)
		insertElement(arr[i]);
}

void IntegerSet::emptySet()
{
	for(int n=0; n<128; n++)
		intSet[n] = 0;
}

void IntegerSet::enterSet()
{
	int integer;
	int count = 0;
	do
	{
		cout<<"Enter number within 0 - 127:";
		cin>>integer;
		if(validEntry(integer))
		{
			intSet[integer] = 1;
			count++;
		}
		else if (integer < 0)
			cout<<"Entry terminated";
	}
	while(validEntry(integer));
	cout<<endl;
	cout<<"Total entry: "<<count<<endl;
}

void IntegerSet::print()const
{
	int n = 1;
	bool empty = true;
	cout<<"{";

	for(int y=0; y<128; y++)
	{
		if(intSet[y])
		{
			cout<<y<<", ";
		}
	}

	if(empty)
		cout<<"{ }";

	cout<<" }"<<endl;
}

IntegerSet IntegerSet::union2(const IntegerSet& u)
{
	IntegerSet temp;

	for(int x=0; x<128; x++)
		if(intSet[x] == 1 || u.intSet[x] == 1)
			temp.intSet[x] = 1;
	
	return temp;
}

IntegerSet IntegerSet::intersect2(const IntegerSet &i)
{
	IntegerSet temp;

	for(int x=0; x<128; x++)
		if (intSet[x] == 1 && i.intSet[x] == 1)
			temp.intSet[x] = 1;

	return temp;
}

void IntegerSet::insertElement(int a)
{
	while (intSet[a] == 1)
	{
		cout<<"Entry invalid";
		cout<<"Enter element to insert."<<endl;
		cin>>a;
	}
	if(validEntry(a) && intSet[a]!=1)
		intSet[a] = 1;
}

void IntegerSet::removeElement(int b)
{
	while (intSet[b] == 0)
	{
		cout<<"Element removed is invalid";
		cout<<"Enter element to remove."<<endl;
		cin>>b;
	}
	if(validEntry(b && intSet[b]!=0))
		intSet[b] = 0;
}

bool IntegerSet::isEqual(const IntegerSet &y)
{
	for(int c=0; c<127; c++)
		if(intSet[c] != y.intSet[c])
		return false;

	return true;
}

bool IntegerSet::isSubset(const IntegerSet &s)
{
	for (int z=0; z<=128; z++)
		if(intSet[z] == 1)
		{
			if(intSet[z] == s.intSet[z])
			return true; 
		}
	return false;
}



