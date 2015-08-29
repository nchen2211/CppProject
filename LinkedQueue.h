#include "Customer.h"

class LinkedQueue
{
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue&);
	~LinkedQueue();

	int size();
	bool empty();
	void enqueue(Customer*, int,int,int,int);
	void dequeue();
	void print_list();

private:

	class Node{

		friend class LinkedQueue;

	public:
		Node(Customer* cust, Node* n){

			cust_info = cust;
			next = n;
		}

	private:
		Customer* cust_info;
		Node* next;
	};

	Node* head;
	Node* tail;
	int count;

};

