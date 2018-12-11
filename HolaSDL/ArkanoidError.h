#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

class ArkanoidError : public std::logic_error {
protected:
public:
	using std::logic_error::logic_error;
	~ArkanoidError();
};