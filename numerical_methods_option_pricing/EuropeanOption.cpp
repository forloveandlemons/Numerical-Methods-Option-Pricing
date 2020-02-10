// EurpeanOption.cpp

#include <boost/math/distributions.hpp>
#include <boost/math/distributions/normal.hpp>
#include "EuropeanOption.hpp"
#include <cmath>
#include <math.h>
#include <iostream>
using namespace boost::math;


double EuropeanOption::n(double x) const
{
	double A = 1.0/sqrt(2.0*3.1415);
	return A*exp(-x*x*0.5);
}


double EuropeanOption::N(double x) const
{ // The approximation to the cumulative normal distribution
    
	normal_distribution<>norm(0.0,1.0);

	return cdf(norm, x);
}


// Kernel Functions (Haug)
double EuropeanOption::CallPrice(double U) const
{

	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;


	return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));

}

double EuropeanOption::PutPrice(double U) const
{

	double tmp = sig * sqrt(T);
	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));

}

double EuropeanOption::CallDelta(double U) const
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;


	return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta(double U) const
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * (N(d1) - 1.0);
}


/////////////////////////////////////

void EuropeanOption::init()
{	// Initialise all default values

	// Default values
	r = 0.05;
	sig= 0.2;

	K = 110.0;
	T = 0.5;

	b = r;			// Black and Scholes stock option model (1973)
	
	optType = "C";		// European Call Option (this is the default type)
}

void EuropeanOption::copy( const EuropeanOption& o2)
{

	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;
	
	optType = o2.optType;
	
}

EuropeanOption::EuropeanOption() 
{ // Default call option

	init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor

	copy(o2);
}

EuropeanOption::EuropeanOption (const string& optionType)
{	// Create option type

	init();
	optType = optionType;

	if (optType == "c")
		optType = "C";

}



EuropeanOption::~EuropeanOption()
{

}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price(double U) const
{


	if (optType == "C")
	{	
		return CallPrice(U);
	}
	else
	{
		return PutPrice(U);
	}
}	

double EuropeanOption::parity(double optionPrice, double U, string optType) const
{
	if(optType=="C")
	{
		cout<<"calculating put price from call price\n";
		return optionPrice + K*exp(-r*T) - U;
	}
	else
	{
		cout<<"calculating call price from put price\n";
		return optionPrice - K*exp(-r*T) + U;
	}
}



double EuropeanOption::Delta(double U) const 
{
	if (optType == "C")
		return CallDelta(U);
	else
		return PutDelta(U);

}
double EuropeanOption::Gamma(double U) const
{
	double tmp = sig * sqrt(T);
	
	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return (n(d1) * exp((b-r)*T))/(U * tmp) ;
}

// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

	if (optType == "C")
		optType = "P";
	else
		optType = "C";
}


