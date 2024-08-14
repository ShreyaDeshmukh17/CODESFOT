#include<iostream>
using namespace std;
int main()
{
	int num1,num2;
	char operation;
	cout<<"Enter the first number:"<<endl;
	cin>>num1;
	cout<<"Enter the operator to perform operation:"<<endl;
	cin>>operation;
	cout<<"Enter the second number:"<<endl;
	cin>>num2;
	
	switch(operation)
	{
		case '+':
			cout<<num1<<'+'<<num2<<"="<<num1+num2;
			break;
		case '-':
			cout<<num1<<'-'<<num2<<"="<<num1-num2;
			break;
		case '*':
			cout<<num1<<'*'<<num2<<"="<<num1*num2;
			break;
		case '/':
			cout<<num1<<'/'<<num2<<"="<<num1/num2;
			break;
	    default :
		cout<<"Syntax error";
		break;
	}
}
