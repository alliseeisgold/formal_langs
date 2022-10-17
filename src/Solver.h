#pragma once
#include <stack>
#include <string>
#include "Helper.h"
#include "Errors.h" 

using std::vector;
using std::stack;
using std::string;

class Solver {
public:
    string alpha_;
    static Helper Result(stack<Helper>& help_stack, char symbol);
    explicit Solver(std::string_view alpha) : alpha_(alpha) {}
    size_t Solve(char X, size_t K) const;
};

