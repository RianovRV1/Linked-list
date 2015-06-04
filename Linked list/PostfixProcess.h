#include "InfixtoPostfix.h"
using namespace std;

void do_oper(char op, List<float>* stack);

float charToFloat(char num);

float str_to_num(string num);

float postfix_process(string postfix);
