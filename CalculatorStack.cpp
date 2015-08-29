#include <iostream>      
#include <stack>
#include <vector>
using namespace std;

#define MAX_SIZE 20;

void infixToPostfix (char*, char*);
int infixarrSize(char*);
int postfixEval(char*, char*, int);
int operatorEval(int, int, char);
bool isNumber(char*, int);
bool isOperator(char*, int);

int infixarrSize(char* infix)
{
	int i = 0;
	int count = 0;
	
	while(infix[i] != '0')
	{
		count++;
		i++;
	}
	return count;
}


void infixToPostfix (char* infix, char* postfix)
{
	stack<char> S;
	int size = MAX_SIZE;
	int j=0;
	char oper = ' ';
	char entry = ' ';

	for(int i=0; i < infixarrSize(infix); i++)
	{
		entry = infix[i];
		
		if(entry >= '0' && entry <= '9') // what about if the # is greater than 9
		{	
			postfix[j] = infix[i];
			//cout<<"postfix inside #: "<<postfix[j];
			j++;
		}

		if(i != 0 && (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'))
		{
				if(infix[i] == '+' || infix[i] == '-')
				{
					if(S.size() == 0)
						S.push(infix[i]);
					else
					{
						if(S.top() == '+' || S.top() == '-')
						{
							S.push(infix[i]);
							//cout<<"S.top(): "<<S.top()<<endl;
						}
						else if(S.top() == '*' || S.top() == '/')
						{
							while(S.size() > 0)
							{
								postfix[j] = S.top();
								S.pop();
								j++;
							}

							S.push(infix[i]);
						}
					}	
				}
				else if(infix[i] == '*' || infix[i] == '/')
					S.push(infix[i]);

				//cout<<"postfix inside #: "<<postfix[j];
			
		}
		
		if(i == infixarrSize(infix)-1)
		{
			for(int n=0; n<=S.size(); n++)
			{
				postfix[j] = S.top();
				S.pop();
				j++; 
			}
		}

	}

}

bool isNumber(char* postfix, int index)
{
	if(postfix[index] >= '0' && postfix[index] <= '9')
		return true;
	else
		return false;
}

bool isOperator(char* postfix, int index)
{
	if(postfix[index] == '+' || postfix[index] == '-' || postfix[index] == '*' || postfix[index] == '/')
		return true;
	else
		return false;

}


int postfixEval(char* infix, char* postfix, int postfixArrSize)
{
	stack<int> postfixStack;
	//stack<int> trial;
	int num1 = ' ';
	int num2 = ' ';
	char oper = ' ';                             
	int result = 0;

	//store postfix array into an postfixStack
	for(int i=0; i<postfixArrSize; i++)
	{
		cout<<i<<" loop"<<endl;
		if(isNumber(postfix,i))
		{
			postfixStack.push(postfix[i]-'0');
			cout<<"char push: "<<postfixStack.top()<<endl;
		}
		else if(isOperator(postfix,i))
		{
			cout<<"oper found: "<<postfix[i]<<endl;
			oper = postfix[i];
			num1 = postfixStack.top();
			cout<<"num1: "<<num1<<endl;
			postfixStack.pop();
			num2 = postfixStack.top();
			cout<<"num2: "<<num2<<endl;
			postfixStack.pop();

			result = ((char)operatorEval(num1, num2, oper));
			cout<<"result: "<<result<<endl;
			postfixStack.push(result);
			//trial.push(result);
			cout<<"postfixStack.top(): "<<postfixStack.top()<<endl;
		//	cout<<"trial.top(): "<<trial.top()<<endl;
		}

	}
	
	return result;
}

int operatorEval(int num1, int num2, char oper)
{
	int result = 0;

	if(oper == '+')
	{
		result = num1 + num2;
	}
	else if(oper == '-')
	{
		result = num2 - num1;
	}
	else if(oper == '*')
	{
		result = num1 * num2;
	}
	else if(oper == '/')
	{
		result = num2 / num1;
	}
	
	//cout<<"result from function: "<<result<<endl;
	return result;
}


void main()
{
	char *postfix;
	char *infix;
	
	int i = 0;
	int size = MAX_SIZE;
	int count = 0;
	char entry = ' ';

	cout<<"Enter infix expression. "<<endl;
	infix = new char [size];

	while(entry != '0')
	{
		cin>>entry;
		infix[i] = entry;
		
		while(i == 0 && (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'))
		{
			cout<<"Please insert an operand before an operator '"<<infix[i]<<"'";
			cin>>infix[i];
		}
		i++;
		count++;	
	}

	for(int i=0; i<count-1; i++)
		cout<<infix[i]<<' ';
	
	postfix = new char[count-1];
	cout<<"Postfix expression"<<endl;

	infixToPostfix(infix, postfix);

	for(int i=0; i<count -1; i++)
		cout<<postfix[i]<<' ';

	cout<<endl;

	cout<<"Evaluation result from postfix expression above is = ";
		
	cout<<postfixEval(infix, postfix,count);

}



			
