// EuropeanOption.hpp


#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp


#include <string>
using namespace std;

class EuropeanOption
{
private:		

	void init();	// Initialise all default values
	void copy(const EuropeanOption& o2);

	// 'Kernel' functions for option calculations
	double CallPrice(double U) const;
	double PutPrice(double U) const;
	double CallDelta(double U) const;
	double PutDelta(double U) const;	

	// Gaussian function
	double N(double x) const;
	double n(double x) const;

public:

	// Member data public for convenience; anyway, the format will 
	// not change for a plain option.

	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double b;		// Cost of carry

	string optType;	// Option name (call, put)
	string unam;	// Name of underlying asset


public:	// Public functions
	EuropeanOption();							// Default call option
	EuropeanOption(const EuropeanOption& option2);	// Copy constructor
	EuropeanOption (const string& optionType);	// Create option type
	virtual ~EuropeanOption();	

	EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price and sensitivities based on the underlying asset price
	double Price(double U) const;
	double Delta(double U) const;
	//Gamma for put and call are same 
	double Gamma(double U) const; 

	//put-call parity function
	double parity(double optionPrice, double U, string opType) const;
	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)


};

#endif