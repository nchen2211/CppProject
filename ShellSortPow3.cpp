/*Shell Sort Power of Three*/
#include<iostream>
#include<math.h>
using namespace std; 

void main()
{
	int arr[] = {50,22,11,29,5,99,83,27,33,17,16,64};
	int arrSize = 0;
	int temp = 0;
	int increment = 0;
	int i = 0; int n = 0;
	int level = 0; int loop = 0; 
	int remainingElem = 0;
	double power  = 3.0;
	int mult = 0;

	
	arrSize = sizeof(arr)/sizeof(*arr);
	increment = arrSize / power;
	while(increment >= 2)//to determine how many times the list can be divided
	{
		increment = arrSize / power;
		power += 3;
		level++;
	}

	increment = 0;

	while(loop < level-1)
	{
		mult += 3;

		cout<<"FIRST loop "<<loop<<endl;
		cout<<"mult: "<<mult<<endl;
		increment = arrSize/mult;
		

		cout<<"increment: "<<increment<<endl;

		for(int i=0; i<increment; i++)
		{
			remainingElem = arrSize;
			cout<<"SECOND loop "<<i<<endl;
			while(increment < remainingElem)
			{
				cout<<"THIRD loop "<<n<<endl;
				cout<<"compare "<<arr[n]<<" with "<<arr[n+increment]<<endl; 
				if(arr[n] > arr[n+increment])
				{
					temp = arr[n+increment];
					arr[n+increment] = arr[n];
					arr[n] = temp;
				}
				n++;

				remainingElem -= increment;
			}
			
		}
		n = 0;
		loop++;
	
		cout<<endl<<endl;
		for(int n=0; n < 12;n++)
			cout<<arr[n]<<" ";

		cout<<endl<<endl;
	}

	
	//insertion sort
	int j = 0;
	int t = 0;

	for(int i=0; i<arrSize; i++)
	{
		j = i;

		while(j>0 && arr[j] < arr[j-1])
		{
			t = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = t;
			j--;
		}
	}

	cout<<endl<<endl;
		for(int n=0; n<arrSize; n++)
			cout<<arr[n]<<" ";

}
