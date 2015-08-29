#include "Customer.h"
#include "LinkedQueue.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>
using namespace std;


void input(int, int, int);
int custCallTime(int);
int nextCustCallTime(int, int);
int custServiceTime(int);

void main()
{
	
	resultFile.open("Call_Simulation_Result");
	int n_time = 4; //upper limit of customer call
	int m_time = 4; //upper limit of service length
	int L_time = 30; //1 period of call service

	int n_rand = 0; //minute when customer call
	int m_rand = 0; //service length
	vector<int> serviceEnd (20,0);
	int j = 0;
	int n = 0;

	int cust_ID = 0;
	int waitTime = 0;
	int servicing_ID = 1;
	int longestLine = 0;
	int minuteLongestLine = 0;

	n_rand = custCallTime(n_time);
	resultFile<<"The first customer will call at minute "<<n_rand<<endl;

	Customer* cust = new Customer(0,0,0,0);
	LinkedQueue* list = new LinkedQueue();

	for(int i=1; i<=L_time; i++)
	{
		resultFile<<"Minute "<<i<<endl;
		
		//customers call in = enqueuing customer
		if(i == n_rand)
		{
			cust_ID++;
			resultFile<<"Customer "<<cust_ID<<" called\n";
			
			resultFile<<"Servicing customer "<<servicing_ID<<"\n";

			m_rand = custServiceTime(m_time);
			resultFile<<"Service length is for customer ID "<<cust_ID<<" is "<<m_rand<<" minutes.\n";

			if(list->size() == 0)
				waitTime = 0;
			else
			{
				waitTime = serviceEnd.at(j-1) - n_rand;
				
				if(waitTime < 0)
					waitTime = 0;
			}
				
			//scheduling next cust call
			n_rand = nextCustCallTime(i, n_time);
			resultFile<<"Next cust will call at minute "<<n_rand<<endl;

			serviceEnd.at(j) = m_rand + i + waitTime;
			resultFile<<"Service will end for customer ID "<<cust_ID<<" at minute "<<serviceEnd.at(j)<<endl;
			j++;

			resultFile<<"Wait time for customer ID "<<cust_ID<<" is "<<waitTime<<" minutes.\n";

			list->enqueue(cust, cust_ID, n_rand, m_rand, waitTime);
		
		}

		if(i == serviceEnd.at(n))
		{
			resultFile<<"Service end for customer ID "<<servicing_ID<<endl;
			servicing_ID++;
			list->dequeue();
			n++;
		}
		
		resultFile<<"List of customer in the line: \n";
		list->print_list();
		resultFile<<endl<<endl;

		if(i == 1)
		{
			longestLine = list->size();
			minuteLongestLine = i;
		}
		else
		{
			if(list->size() > longestLine)
			{
				longestLine = list->size();
				minuteLongestLine = i;
			}
		}

	}

	//resultFile<<"\n\n The longest line is at minute "<<minuteLongestLine<<" with "<<longestLine<<
	//	" customers in line.\n";
	resultFile.close();
}

void input(int n, int m, int L)
{
	cout<<"Customer's call time: ";
	cin>>n;

	cout<<endl;
	cout<<"Customer's service time: ";
	cin>>m;

	cout<<endl;
	cout<<"Minutes in 1 period: ";
	cin>>L;
}

int custCallTime(int n_time)
{
	int random_n = 0;

	random_n = rand() % n_time + 1;

	return random_n;
}

int custServiceTime(int m_time)
{
	int random_m = 0;

	random_m = rand() % m_time + 1;

	return random_m;
}

int nextCustCallTime(int n_rand, int n_input)
{
	int random_n = 0;
	int limit = 0;

	limit = n_rand + n_input;

	do
	{
		random_n = rand() % limit + 1;
	}while (random_n <= n_rand);

	return random_n;
}
