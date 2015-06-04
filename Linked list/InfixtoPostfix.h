
#include "LinkedList.h"
using namespace std;
int operPrec(char op)
{
	if(op == '+' || op == '-')
		return 1;
	if(op == '*' || op == '/')
		return 2;
	if(op == '(')
		return 3;
	if(op == ')') 
		return 0;
}
bool validPara(string str)
{
	int leftpara, rightpara;
	bool valid = true;
	bool isValid = true;
	leftpara = 0;
	rightpara = 0;
	int i = 0;
	while(valid && i < str.length())
	{
		if(str.at(i) == '(')
			{
				++leftpara;
			}
			if(str.at(i) == ')')
			{
				++rightpara;
			}
			if(rightpara > leftpara)
			{
				valid = false;
				isValid = false;
				continue;
			}
			++i;
	}
	if(leftpara != rightpara)
		isValid = false;

	return isValid;
}
bool isOper(char op)
{
	if( op == '(' || op == ')' || op == '*' || op == '/' || op == '+' || op == '-')
		return true;
	else
		return false;
}
string infixToPostfix(string str)
{
	string postfix;
	List<char> *stack = new List<char>();
	while(!str.empty())
	{
		if(!isOper(str.front()))
		{
			postfix.push_back(str.front());
			str.erase(0,1);
		}
		else if(isOper(str.front()))	
		{
			if(postfix.empty())//doesnt work if *+ or/ at front
			{
				stack->AddToFront(str.front());
				str.erase(0,1);
			}
			else
			{
				postfix.push_back(' ');
				if (str.front() == ')')
				{
					while(stack->getItem() != '(')
					{
						postfix.push_back(stack->DeleteFront());
					}
					stack->DeleteFront();
				}
				else
				{
					while(!stack->isEmpty() && stack->getItem() != '(' && operPrec(stack->getItem()) >= operPrec(str.front()))
					{
						postfix.push_back(stack->DeleteFront());
					}
					stack->AddToFront(str.front());
				}
				str.erase(0,1);
				//if(operPrec(stack->getItem()) >= operPrec(str.front()))
				//{
				//	string oper;
				//	oper = "()";
				//	if(str.front() == oper.at(1))
				//	{
				//		
				//		while(stack->getItem() != oper.at(0))
				//		{
				//			postfix.push_back(stack->DeleteFront());
				//		}
				//		stack->DeleteFront();
				//		//str.erase(0,1);
				//	}
				//	else
				//	{
				//		while(operPrec(stack->getItem()) >= operPrec(str.front()) && !stack->isEmpty())
				//		{
				//			postfix.push_back(stack->DeleteFront());
				//		}
				//		stack->AddToFront(str.front());
				//	}
				//str.erase(0,1);
				//}
			}
		}
	}
	while(!stack->isEmpty())
	{
		postfix.push_back(' ');
		postfix.push_back(stack->DeleteFront());
	}
	delete stack;
	return postfix;
}