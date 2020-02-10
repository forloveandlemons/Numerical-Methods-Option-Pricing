// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "Range.cpp"
#include "ArrayMechanisms.cpp"
#include "NormalGenerator.hpp"
#include <cmath>
#include <boost/tuple/tuple.hpp>
#include <iostream>
using namespace std;

using boost::tuple;

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	cout << endl << "Size of vector is " << l.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


 boost::tuples::tuple<double, double> SD_SE(const vector<double>&v, const double r, const double T)
{//create a function that calculate SD and standard error
	vector<double>::const_iterator i;
	double sum=0.0;
	double squareSum=0.0;
	long int M=0;
	
	for(i=v.begin(); i!=v.end(); i++)
	{
		sum_C=sum_C+ (*i);
		sum_Csquare=sum_Csquare + (*i) * (*i);
		M++;
	}
	
	double tmp = sum_Csquare - sum_C*sum_C/M;
	double sd = sqrt(tmp) * exp(-2*r*T)/(M-1);
	double se= sd/sqrt((double) M);
	boost::tuples::tuple<double, double>sd_se= boost::make_tuple(sd, se);
	return sd_se;
 }

 //print the tuple
 /*void print(boost::tuples::tuple<double, double>& t)
 {
	 double first = t.get<0>();
	 double second =t.get<1>();
	 cout<<first<<","<<second<<","<<endl;
 }*/


int main()
{
	
	cout <<  "1 factor MC with explicit Euler\n";
	OptionData myOption;
	myOption.K = 100;
	myOption.T = 1;
	myOption.r = 0.0;
	myOption.sig = 0.2;
	myOption.type = -1;	// Put -1, Call +1
	double S_0 = 100;
	
	long N = 100;
	cout << "Number of subintervals in time: ";
	cin >> N;

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	double VOld = S_0;
	double VNew;

	Vector<double, long> x = range.mesh(N);
	

	// V2 mediator stuff
	long NSim = 50000;
	cout << "Number of simulations: ";
	cin >> NSim;

	double k = myOption.T / double (N);
	double sqrk = sqrt(k);

	// Normal random number
	double dW;
	double price = 0.0;	// Option price

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	data = &myOption;

	vector<double> v1;
	int coun = 0; // Number of times S hits origin

	// A.
	for (long i = 1; i <= NSim; ++i)
	{ // Calculate a path at each iteration
			
		if ((i/10000) * 10000 == i)
		{// Give status after each 1000th iteration

				std::cout << i << std::endl;
		}

		VOld = S_0;
		for (long index = x.MinIndex()+1; index <= x.MaxIndex(); ++index)
		{

			// Create a random number
			dW = myNormal->getNormal();
				
			// The FDM (in this case explicit Euler)
			VNew = VOld  + (k * drift(x[index-1], VOld))
						+ (sqrk * diffusion(x[index-1], VOld) * dW);

			VOld = VNew;

			// Spurious values
			if (VNew <= 0.0) coun++;
		}
			
		double tmp = myOption.myPayOffFunction(VNew);
		//get the price in the cvector v1
		v1.push_back(tmp);

		price += (tmp)/double(NSim);
	}
	
	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);

	// Cleanup; V2 use scoped pointer
	delete myNormal;

	std::cout << "Price, after discounting: " << price << ", " << std::endl;
	std::cout << "Number of times origin is hit: " << coun << endl;

	//print the tuple and call the funtcion of standard_dev_and_err
	cout<<"Standard devition and standard error is: "<<endl;
    cout<<SD_SE(v1,myOption.r, myOption.T)<<endl;

	return 0;
}