#ifndef NODE_H
#define NODE_H
#include<iostream>

class Node
{
	friend class LList;
		
private:
	int value;
	Node* pNext; //pointer to the next node
public:
	Node();
	Node(int);
	Node(int, Node*);
	void setValue(int);
	void setNext(Node*);
	int getValue() const;
	Node* getNext() const;
};
#endif

