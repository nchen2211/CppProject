#include "Node.h"
#include "LList.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

void main()
{
	LList list; //empty constructor implementation
	//LList list(20); //constructor with a single value as parameter
	int values; int count = 0;
	

	/*while(count < 13)
	{
		values = rand() % 100 + 1;
		list.append(values);
		count++;
	}*/

	list.append(42);
	list.append(68);
	list.append(35);
	list.append(1);
	list.append(75);
	list.append(25);
	list.append(79);
	list.append(59);
	list.append(63);
	list.append(65);
	list.append(6);
	list.append(46);
	list.append(55);


	list.print();
	cout<<endl;
	list.radixSort();

	 // append nodes to the list
    //list.append(100);
    //list.print();cout<<endl;
    //list.append(200);
    //list.print();cout<<endl;
    //list.append(300);
    //list.print();cout<<endl;
    //list.append(400);
    //list.print();cout<<endl;
    //list.append(500);
    //list.print();cout<<endl;


  //  // deleteNode nodes from the list
  //  list.deleteNode(400);
  //  list.print();cout<<endl;
  //  list.deleteNode(300);
  //  list.print();cout<<endl;
  //  list.deleteNode(200);
  //  list.print();cout<<endl;
  // 


}