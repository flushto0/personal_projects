// The challenge list I am using can be found here: https://github.com/karan/Projects

#include <iostream>
#include <iomanip>
#include "Numbers.h"
using namespace std;

void PrintFibonacciSequence(int n)
{
	for(int i = 0; i <= n; i++) std::cout << GetFibonacciNumber(i) << " ";
}

int main()
{
	PrintFibonacciSequence(35);

	return 0;
}