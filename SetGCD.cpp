/*Program: gcd.cpp
Name: Noreen Chrysilla
Class: CSCI 140
Project 2*/

#include<iostream>
using namespace std;

int ArrayGCD(int *arr, int firstIndex, int lastIndex);

int ArrayGCD(int *arr, int first, int last)
{
    int x = 0, y = 0, gcd = 0;
    if(first == last)
    {
        gcd = arr[first];
        return gcd;
    }
    else
    {
        x = ArrayGCD(arr,first,(first+last)/2);
        y = ArrayGCD(arr,(first+last)/2+1,last);

        if(x < 0)
        {
            x = -x;
        }
        if(y < 0)
        {
            y = -y;
        }
        while(x != y)
        {
            if(x > y)
            {
                x = x-y;
            }
            else
            {
                y = y-x;
            }
        }
        gcd = x;
        return gcd;
    }
}

int main(void)
{
    int a[20], n = 0, i = 0, gcd = 0;
    cout<<"Enter the number of elements of the array: "<<endl;
    cin>>n;
    printf("Enter the elements of the array:");
    for(i=0; i<n; i++)
		cin>>a[i];

    gcd = ArrayGCD(a,0,n-1);
    cout<<"The greatest common divisor is: "<<gcd;
    return 0;
}