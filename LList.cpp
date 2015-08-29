#include "LList.h"
#include<vector>
using namespace std;
const int binSize = 10;

LList::LList()
{
	head = tail = NULL;
}

LList::LList(int val)
{
	//create a new node as both head and tail
	head = new Node(val);
	tail = head;
}


LList::~LList(void)
{
}

void LList::append(int val)
{
	//create a new node
	Node* newNode = new Node();
	newNode->setValue(val);
	newNode->setNext(NULL);

	//create a temp pointer
	Node* temp = head;

	if(temp != NULL)//parse until the end of list
	{
		while(temp->getNext() != NULL)
			temp = temp->getNext();

		temp->setNext(newNode);//newNode become the last node in the list
	}
	else
		head = newNode;
}

void LList::deleteNode(int val)
{
	//create a temp pointer
	Node *temp = head;

	if(temp == NULL)
		return;

	//if head is the only node in the list
	if(temp->getNext() == NULL)
	{
		delete temp;
		head = NULL;
	}
	else
	{
		Node* prev;
		
		while(temp->getValue() != val)
			temp = temp->getNext();//parsing through the nodes

		if(temp->getValue() == val)
		{
			prev = temp;
			temp = temp->getNext();
		}

		prev->setNext(temp->getNext());
	}

	delete temp;
}

void LList::print() const
{
	Node* temp =  head;

	//if the list is empty
	if(temp == NULL)
		cout<<"The list is empty \n";

	//one node in the list
	if(temp->getNext() == NULL)
		cout<<temp->getValue();
	else
	{
		//parse the list and print
		while(temp != NULL)
		{
			cout<<temp->getValue()<<" ";
			temp = temp->getNext();
		}

	}
}

int LList::numOfElem() const
{
	int count = 0;

	Node* temp = head;
	if(temp == NULL)
		return 0;
	else
	{
		while(temp != NULL)
		{
			count++;
			temp = temp->getNext();
		}
	}
	
	return count;
}

//int LList::maxValue() const
//{
//	Node* cur = head;
//	Node* next;
//	int max = cur->getValue();
//	int count = 0;
//
//	next = cur->getNext();
//	while(cur != NULL)
//	{
//		
//		if(next > cur)
//		{
//			cout<<"\ncompare: "<<cur->getValue()<<" and "<<next->getValue()<<endl;
//			max = next->getValue();
//			cout<<"max: "<<max<<endl;
//		/*
//			cur = cur->getNext();
//			next = cur->getNext();*/
//			cout<<"cur: "<<cur->getValue()<<endl;
//			cout<<"next: "<<next->getValue()<<endl;
//		}
//		else
//			max = max;
//	
//		cur = cur->getNext();
//		next = cur->getNext();
//		count++;
//	}
//	cout<<"count: "<<count;
//	return max;
//}


		

void LList::radixSort()
{
	//int bucket[10] = {0};	
	int i = 0; int j = 0;
	int decPoint = 0;

	vector<int> v (LList::numOfElem());
	vector<int> vRes (LList::numOfElem());
	Node* temp = head; //given array
	//create an array of binSize node pointers
	Node* bin[binSize]; 
	

	//initialize the array to NULL
	for(int i=0; i<binSize; i++)
		bin[i] = NULL;

	i = 0;

	while(decPoint < 3)
	{
		while(i <= 12)
		{
			v[i] = temp->getValue() % 10;
		
			if(bin[v[i]] == NULL)
			{
				cout<<"\nno elem"<<endl;
				Node* newNode = new Node;
				newNode->setValue(temp->getValue());
				cout<<"newNode: "<<newNode->getValue()<<endl;

				bin[v[i]] = new Node;
				bin[v[i]]->setValue(newNode->getValue());
			
				cout<<"bin"<<v[i]<<": "<<bin[v[i]]->getValue()<<endl;
				bin[v[i]]->setNext(NULL);
			}
			else if(bin[v[i]] != NULL) //if there is more than 1 elem in one index
			{
				cout<<"\none/more elem"<<endl;
				Node* newNode = new Node;	
				newNode->setValue(temp->getValue());
				newNode->setNext(NULL);
				cout<<"newNode: "<<newNode->getValue()<<endl;
				Node* temp1 = bin[v[i]];


				if(temp1->getNext() == NULL)//if there is only one element in the list
				{
					cout<<"hh"<<endl;
					temp1->setNext(newNode);
					cout<<"bin"<<v[i]<<": "<<bin[v[i]]->getValue()<<endl;
	
					temp1 = temp1->getNext();
					cout<<"bin"<<v[i]<<": "<<temp1->getValue()<<endl;
					
					temp1->setNext(NULL);
				}
				else if(temp1->getNext() != NULL)//if there is > 1 elem in the list
				{
					while(temp1->getNext() != NULL)
					{
						temp1 = temp1->getNext();//parse the list until the last node
						cout<<"bin"<<v[i]<<": "<<temp1->getValue()<<endl;
					}

					temp1->setNext(newNode);//place the newnode at the end of the list
			
					temp1 = temp1->getNext();
					//temp1 ->setNext
				}
			
			}

			
			i++;
			temp = temp->getNext();

		}//end while

		cout<<"yahoo"<<endl;
		int n = 0;
		Node* temp2 = bin[n];
		//cout<<"bin[0]"<<bin[n]->getValue()<<endl;
		
		while(n <= 12)
		{
			cout<<"\nn now: "<<n<<endl;
			cout<<"hahaha: "<<temp2->getValue()<<endl;
			if(temp2->getValue() == 0) //if there's no elem in the array in n index
			{
				temp2->setValue(0);
				cout<<"v["<<n<<"] = "<< temp2->getValue()<<endl;
				temp2 = temp2->getNext();
				n++;
			}
			else
			{
				if(temp2->getNext() == NULL)//if there's only 1 elem
				{
					v[n] = temp2->getValue();
					cout<<"v["<<n<<"] = "<< temp2->getValue()<<endl;
					n++;
					//temp2 = temp2->getNext();
					//cout<<"temp2: "<< temp2->getValue()<<endl;
				}
				else
				{
					while(temp2->getNext() != NULL)
					{
						//cout<<"bin"<<v[5]<<": "<<temp2->getValue()<<"-->";
						v[n] = temp2->getValue();
						cout<<"v["<<n<<"] = "<< temp2->getValue()<<endl;
						n++;
						temp2 = temp2->getNext();
					}
				}
				temp2 = bin[n];
			}
		}

	/*	cout<<"\n\nPrint new vector"<<endl;
		for(int x=0; x<binSize; x++)
			cout<<vRes[x]<<" ";*/
	
		decPoint++;
		
	}
	
}




	