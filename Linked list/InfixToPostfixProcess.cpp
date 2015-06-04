// Linked list.cpp 3: Defines the entry point for the console application.
// ~List
// yes or no for operator, int to see presidence 
// use a look ahead to determine spacing of Ints 
// while loop to empty the list out, while loop to empty until left paratheses 


#pragma once
#include "PostfixProcess.h"

using namespace std;
int _tmain(int wargc, _TCHAR* argv[])
{
	string infix, postfix; 
	float processed;
	infix = "11+3*(3+4)";
	cout << infix << endl;
	if(!validPara(infix))
	{
		cout << "cannot be computed, not a valid string" << endl;
	}
	else
	{
		postfix = infixToPostfix(infix);
		processed = postfix_process(postfix);
		cout << postfix << endl;
		cout << processed << endl;
	}
	system("PAUSE");
}
