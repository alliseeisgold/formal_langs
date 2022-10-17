#include "Solver.h"

using std::exception;
using std::count;
using std::vector;


Helper Solver::Result(stack<Helper>& help_stack, char symbol) {
    Helper answer;
    size_t priority = (count(std::begin(Multiplier), std::end(Multiplier), symbol)) ? 1 : 2;
	if (help_stack.size() < priority)  {
    	throw Errors("Incorrect alpha");
	} else {
       	if (symbol == '+') {
            Helper second = help_stack.top();
            help_stack.pop();
            Helper first = help_stack.top();
            help_stack.pop();
	        answer = first + second;
        } else if (symbol == '*') {
            answer = help_stack.top();
            help_stack.pop();
            answer.Start();
        } else if (symbol == '.') {
            Helper second = help_stack.top();
            help_stack.pop();
            Helper first = help_stack.top();
            help_stack.pop();
            answer = first * second;
        }
    }
	return answer;	
}
size_t Solver::Solve(char X, size_t K) const {
    if (K == 0) {
    	return 0;
    }
    stack<Helper> Alphas;
    for (char symbol : alpha_) {
        int isSymbol = count(std::begin(Alphabet), std::end(Alphabet), symbol);
        int isOperator = count(std::begin(Operations), std::end(Operations), symbol);
        if (isSymbol != 0) {
        	int isNotEmpty = (symbol != Empty);
       	    Alphas.emplace(isNotEmpty, K);
           	if (symbol == X) {
                Alphas.top()[1] = 1;
            }
        } else if (isOperator != 0) { 
            Alphas.push(Result(Alphas, symbol));
        } else {
            throw Errors("Symbol isn't in the Alphabet");
    	}
   	 }
    if (Alphas.size() > 1) {
        throw Errors("Incorrect alpha");
    }
    return Alphas.top()[K];
}


