#include "Node.h"

Node::Node()
	:pNext(NULL){}

Node::Node(int val)
	:value(val),pNext(NULL){}

Node::Node(int val, Node* next)
	:value(val),pNext(next){}

void Node::setValue(int val)
{
	value = val;
}

void Node::setNext(Node* next)
{
	pNext = next;
}

int Node::getValue() const
{
	return value;
}

Node* Node::getNext() const
{
	return pNext;
}
