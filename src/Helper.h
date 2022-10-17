#pragma once
#include <algorithm>
#include <vector>
#include "Variables.h"

using std::vector;

class Helper {
public:
    Helper() = default;
    Helper(const Helper&) = default;
    Helper& operator=(const Helper&) = default;
    Helper(size_t WordLen,  size_t K);
    size_t &operator[](size_t index);
    Helper operator*(const Helper& current);
    Helper operator+(const Helper& current);
    void Start();
private:
	size_t minLength_ = 0;
    vector<size_t> minPref_;
};

