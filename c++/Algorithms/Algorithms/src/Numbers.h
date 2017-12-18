/** 
*  @file Numbers.h
*  @brief A compendium of algorithms that have to do with number manipulation.
*
*  This contains a set of functions that demonstrate some interesting
*  algorithms that have to do with number manipulation. Library usage
*  is meant to be kept to a minimum as this is meant to practice my
*  algorithm skills, which libraries, if nothing else, is created to
*  keep one from having to write algorithms.
*
*  @author Robert Newcomb (notrms)
*  @bug No known bugs.
*/

#pragma once
#include <cmath>

/** @brief Returns the number Pi
*
*  @return Pi, with maximum supported accuracy.
*/
double Pi()
{
	return atan(1) * 4;
}

/** @brief Factorial n, or n!
*
*  @param n The input of the math expression "n!".
*  @return The output of the math expression "n!".
*/
double Factorial(int n)
{
	if (n == 1) return 1;
	
	return n * Factorial(n - 1);
}

/** @brief Finds Euler's number to the nth decimal digit.
*
*  This will only be as accurate as the double type is, which
*  is of course platform dependent.
*
*  @param accuracy The decimal depth of e.
*         Note that this is restricted to double accuracy.
*  @return Euler's number e, with an accuracy related to accuracy
*/
double EulersNumber(int accuracy = 10)
{
	double e = 0.0;

	for (int i = 0; i <= accuracy; i++)
	{
		e += (2 * i + 2) / Factorial(2 * i + 1);
	}

	return e;
}

//////////////////BEGIN CHALLENGES//////////////////

/** @brief Finds Pi to the nth decimal digit.
*
*  This will only be as accurate as the double type is, which
*  is of course platform dependent. For me, this is 18 digits.
*
*  @param nth The "length" of the Pi decimal to attempt to generate.
*         Note that this is restricted to double accuracy.
*  @return Pi, with nth accuracy.
*/
double FindPiToNth(int nth)
{
	//this multiplies our Pi number by 10^nth, giving us a huge int. we truncate the int (and do some rounding math),
	//then we multiply by 10^-nth, which gives us our pi with nth accuracy.
	return (uint64_t)(Pi() * pow(10, nth) + 0.5) * pow(10, -nth);
}

/** @brief Finds Euler's number, typically denoted "e", to the nth decimal digit.
*
*  This will only be as accurate as the double type is, which
*  is of course platform dependent. For me, this is 18 digits.
*
*  @param nth The "length" of the e decimal to attempt to generate.
*         Note that this is restricted to double accuracy.
*  @return Pi, with nth accuracy.
*/
double FindEulersNumberToNth(int nth)
{
	//exactly the same algorithm as our FindPiToNth() calculation.
	return (uint64_t)(EulersNumber() * pow(10, nth) + 0.5) * pow(10, -nth);
}

/** @brief Finds the nth fibonacci number of the fibonacci sequence.
*
*  @param n The number, by index, of the fibonacci sequence.
*         Note that this is restricted to 64bit integer length.
*  @return The nth number of the fibonacci sequence.
*/
uint64_t GetFibonacciNumber(int n)
{
	uint64_t a = 0, b = 1, c, i;
	
	if (n == 0) return a;

	for (i = 2; i <= n; i++) //unwound to deal with 1 and 2
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

///Prime Factorization - Have the user enter a number and find all Prime Factors (if there are any) and display them.

int GetPrimeFactors(int targetNumber, int primeFactors[], size_t size)
{
	for(int i = 2; ;)
	return 0;
}

int GetPrimes(int limit, int* sieve)
{
	for (int i = 0; i < limit; i++)
	{

	}
	return 0;
}