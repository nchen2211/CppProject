#include "LinkedQueue.h"
#include<iostream>

LinkedQueue::LinkedQueue() : head(NULL), tail(NULL), count(0) {}

LinkedQueue::LinkedQueue(const LinkedQueue& list): head(NULL), tail(NULL), count(0){

	Node* curr = list.head;

	while(curr != NULL){
		this->enqueue(curr->cust_info, curr->cust_info->retCustID(),curr->cust_info->retCallTime(), 
			curr->cust_info->retServiceTime(), curr->cust_info->retWaitTime());
		curr = curr->next;

	}
}

LinkedQueue::~LinkedQueue()
{
	while(!this->empty())
		this->dequeue();
}

int LinkedQueue::size(){

	return count;
}

bool LinkedQueue::empty(){
	if(head == NULL && tail == NULL)
		return true;
	return false;
}

void LinkedQueue::enqueue(Customer* cust, int id, int call, int service, int wait){

	cust = new Customer(id,call,service,wait);
	Node* new_cust = new Node(cust, NULL);
	
 	if(this->size() == 0){
		head = new_cust;
		tail = new_cust;
	}
	else{
		tail->next = new_cust;
		tail = new_cust;
	}
		
	tail->next = NULL;
	count++;
}

void LinkedQueue::dequeue(){

	Node* old_head = head;

	if(this->empty())
		std::cout<<"The list is empty\n";
	else if(this->size() == 1){
		head = NULL;
		tail = NULL;
	}
	else
		head = head->next;

	delete old_head;
	count--;
}

void LinkedQueue::print_list(){

	Node* curr = head;

	if(this->size() == 0)
		std::cout<<"The list is empty. \n";
	else{

		while(curr != tail){
			curr->cust_info->print();
			curr = curr->next;
		}

		curr->cust_info->print(); // print last node information
	}

	
}