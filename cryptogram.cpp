#include<iostream>
#include<string>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void main()
{
	int count = 0;
	string word;
	cout<<"Enter a string (length needs to be less than 50)"<<endl;
	getline(cin,word);
	int size = word.length();
	char parse[50];

	for(int i=0; i<size; i++)
	{
		if(word[i] == ' ')
			cout<<' ';
		else
		{
			if(islower(word[i]))
			{
				parse[i] = toupper(word[i]);
				parse[i]++;
				if(parse[i] > 1)
					parse[i] = (rand()%26) + 'A';
			}
			else
			{
				parse[i] = tolower(word[i]);
				parse[i]++;
				if(parse[i] > 1)
					parse[i] = (rand()%26) + 'a';
			}
		
			cout<<parse[i];	
		}
	}
}
