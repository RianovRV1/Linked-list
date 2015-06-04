#pragma once
#include "PostfixProcess.h"
using namespace std;

void do_oper(char op, List<float>* stack)
{
	float a, b;
	a = stack->DeleteFront();
	b = stack->DeleteFront();
	switch(op)
	{		
	case '+':
		stack->AddToFront(b+a);
		break;
	case '-':
		stack->AddToFront(b-a);
		break;
	case '*':
		stack->AddToFront(b*a);
		break;
	case '/':
		stack->AddToFront(b/a);
		break;
	}
}


float charToFloat(char num)
{
	float c = float(num);
	float d = (c-48);
	return d;
}
float str_to_num(string num)
{
	int digit = 1;
	int sum = 0;
	for (int j = (num.length()-1); j >= 0; --j)
	{
		float num2 = charToFloat(num.at(j));
		sum+=(digit*num2);
		digit *= 10;
	}
	return sum;
}

float postfix_process(string postfix)
{
	int i = 0;
	List<float>* stack = new List<float>();
	while(i < postfix.length())
	{
		if(postfix.at(i) == ' ')
				++i;
		if(!isOper(postfix.at(i)))
		{

			string num;
			while(postfix.at(i) != ' ')
			{
				num.push_back(postfix.at(i));
				++i;
			}
			stack->AddToFront(str_to_num(num));
		}
		else
		{
			do_oper(postfix.at(i), stack);
		}
		++i;
	}
	float returnVal = stack->DeleteFront();
	delete stack;
	return returnVal;
}