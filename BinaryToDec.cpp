/*Program: HLL
Author: Noreen Chrysilla
Class: CSCI 150
Date: Due on March 16th, 2015
Description: Create 2 functions: dec to binary with signed int parameter that return a string, binary to dec with a string parameter that returns signed int.

I certify that the code below is my own work.
	
	Exception(s): N/A*/

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

const double logBase = 2.0;

int binToDec(string);
string decToBin(signed int);
int calculateBin(string,int,int,int);
string oppositeBin(string);
bool isNegative(signed int);
string decimalToBin(int);
string binaryAddOne(string,int);


void main()
{
	string test1 = "00111011";
	string test2 = "11110010";
	string test3 = "11110000"; //to test continuous 1+1 binary addition

	int dec1 = 37;
	int dec2 = -17;
	int dec3 = -13;

	cout<<"Binary to decimal"<<"\n";
	cout<<"decimal value of "<<test1<<": "<<binToDec(test1)<<"\n";
	cout<<"decimal value of "<<test2<<": "<<binToDec(test2)<<"\n";
	cout<<"decimal value of "<<test3<<": "<<binToDec(test3)<<"\n"<<"\n";

	cout<<"Decimal to binary"<<"\n";
	cout<<"binary of "<<dec1<<": "<<decToBin(dec1)<<"\n";
	cout<<"binary of "<<dec2<<": "<<decToBin(dec2)<<"\n";
	cout<<"binary of "<<dec3<<": "<<decToBin(dec3)<<"\n";
}

int binToDec(string binary)
{
	int dec = 0;
	int res = 0;
	int bits = 7;
	int power = 7;
	int count = 0;
	int i = 0;
	int j = bits;

	//binary opposite
	if(binary.at(0) == '1')
	{
		binary = oppositeBin(binary);	
		int j = bits;

		binary = binaryAddOne(binary,j);
		res = 0 -calculateBin(binary, power, dec, i);
	}
	else
		res = calculateBin(binary, power, dec, i);

	return res;
}

string decToBin(signed int dec)
{
	int bits = 7;
	int i = 0; int j = bits;
	string revBin; 
	
	if(!isNegative(dec))
		revBin = decimalToBin(dec);
	else
	{
		dec  = 0 - dec;
		revBin = decimalToBin(dec);

		revBin = oppositeBin(revBin);
		revBin = binaryAddOne (revBin,j);
	}

	return revBin;
}


int calculateBin(string bin, int powr, int dec, int index)//calculate binary
{
	int bits = 7;

	for(index=0; index<=bits; index++)
	{
		if(bin.at(index) == '0')
			dec += 0;
		else if(bin.at(index) == '1')
			dec += pow(logBase, powr);

		powr--;
	}

	return dec;		 
}

string oppositeBin(string binary)
{
	int i = 0;
	int bits = 7;
	while(i <= bits) //opposite binary
	{
		if(binary.at(i) == '0')
			binary.at(i) = '1';
		else
			binary.at(i) = '0';

		i++;
	}

	return binary;
}


string binaryAddOne(string binary, int j)
{
	if(binary.at(j) == '0')
		binary.at(j) = '1';
	else if(binary.at(j) == '1')
	{
		binary.at(j) = '0';
		j--;

		if(binary.at(j) == '0')
			binary.at(j) = '1';
		else
		{
			//cont 1+1 binary addition
			while(binary.at(j) != '0') 
			{
				binary.at(j) = '0';
				j--;
			}

			binary.at(j) = '1';
		}
	}

	return binary;
}


bool isNegative(signed int dec)
{
	if(dec < 0)
		return true;
	return false;
}

string decimalToBin(int dec)//convert decimal to binary regardless the sign of the dec
{
	int rem = 0;
	int quot = 0;
	int count = 0;
	int bits = 7;
	string binary;
	string revBin;

	while(count<=bits)
	{
		while(dec != 0)
		{
			quot = dec / 2;
			rem = dec % 2;

			if(rem == 0)
				binary += "0";
			else
				binary += "1";

			dec = quot;
			count++;
		}

		binary += "0";
		count++;
	}	

	for (string::reverse_iterator rit=binary.rbegin(); rit!=binary.rend(); ++rit)
		revBin += *rit;

	return revBin;
}
