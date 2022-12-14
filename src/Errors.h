#pragma once
#include <string>

using std::string;
using std::exception;

class Errors : public exception {
public:
    string error;
    explicit Errors(string error) : error(std::move(error)) {}
    const char * what() const noexcept override { return error.c_str(); }
};

