/*  Program:     Integer Set
    Author:      Noreen Chrysilla
    Class:	     CSCI 220 & 220L
    Date:	     9/14/2013
    Description: 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include "IntegerSet.h"
#include <iostream>
using namespace std;

void main()
{
	IntegerSet l,m,n,o;
	int option;
	int x,y;
	int comment;

	cout<<"ENTERING INTEGER SETS"<<endl;
	cout<<"Enter integer 0-127."<<endl;
	cout<<"Any insertion outside is invalid and will stop the entry."<<endl<<endl;
	cout<<"Enter first integer set: "<<endl<<endl;
	l.enterSet();
	cout<<endl;
	cout<<"Enter second integer set: "<<endl;
	m.enterSet();
	cout<<endl<<endl;


	cout<<"SETS COMPARISON"<<endl<<endl;
	if (l.isEqual(m))
		cout<<"The first and second sets are equal."<<endl<<endl;
	else
		cout<<"The first and second sets are not equal."<<endl<<endl;		

	if(l.isSubset(m))
		cout<<"The first is subset of the second set."<<endl<<endl;
	else
		cout<<"The first is not subset of the second set."<<endl<<endl;


	cout<<"UNION & INTERSECTION"<<endl<<endl;
	cout<<"Display union set?"<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	cin>>option;
	while (option != 1 && option != 2)
	{
		cout<<"Invalid option."<<endl;
		cout<<"Press 1 for displaying union. Press 2 for skip displaying."<<endl;
		cin>>option;
	}
	if(option == 1)
	{
		n = l.union2(m);
		cout<<"Union of first and second integer set is: ";
		n.print();
	}
	else if(option == 2)
	{
		cout<<"Union is not displayed."<<endl;
	}

	cout<<"Display intesection set?"<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	cin>>option;

	while (option != 1 && option != 2)
	{
		cout<<"Invalid option."<<endl;
		cout<<"Press 1 for displaying union. Press 2 for skip displaying."<<endl;
		cin>>option;
	}
	if(option == 1)
	{
		n = l.intersect2(m);
		cout<<"Intesection of first and second integer set is: ";
		n.print();
	}
	else if(option == 2)
	{
		cout<<"Intesection is not displayed."<<endl;
	}

	
	cout<<"INSERTING & REMOVING ELEMENT"<<endl<<endl;
	cout<<"Enter what element to insert: ";
	cin>>x;
	l.insertElement(x);
	cout<<endl;
	cout<<"The first set after insertion is: ";
	l.print();
	cout<<endl;

	cout<<"Enter what element to remove: ";
	cin>>y;
	l.removeElement(y);
	cout<<endl;
	cout<<"The first set after removal is: ";
	l.print();
	cout<<endl<<endl;

	cout << "Author: Noreen Chrysilla\n";
	cin>>comment;
}





