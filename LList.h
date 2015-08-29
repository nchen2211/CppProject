#ifndef LLIST_H
#define LLIST_H
#include "Node.h"

class LList
{
private:
	Node* head;
	Node* tail;
	
public:
	LList();
	LList(int);
	~LList();
	void append(int); 
	void deleteNode(int);
	void print() const;
	int numOfElem() const;
	void radixSort();
	int maxValue() const;
	
};
#endif
