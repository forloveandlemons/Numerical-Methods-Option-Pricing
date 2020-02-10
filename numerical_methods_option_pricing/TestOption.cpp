//testOption.copp

#include "EuropeanOption.hpp"
#include <vector>
#include "ExcelMechanisms.hpp"
#include "Range.cpp"
#include "DatasimException.hpp"

#include <cmath>
#include <list>
#include <string>
#include <iostream>
using namespace std;


int  main()
{
	//take a monotonically increasing range of underlying value of S and print the option price
	cout<<"Begin to calculate the option price given a range of underlying stock price"<<endl;
	EuropeanOption Option3;
	Option3.optType="C"; Option3.T=1.0; Option3.K=10; Option3.sig=0.5; Option3.r=0.12; Option3.b =Option3.r;    
	
	//create a vector to store the data of the sequence of stock price 

	long N=41;
	Vector<double, long> v1(N,0.0);
	//let the stock price begin from 5 ending at 45 , totally 41 numbers 
	double price =5.0;
	v1[v1.MinIndex()] = 5.0;
	v1[v1.MaxIndex()] = 45.0;
	
	for (long j=v1.MinIndex()+1; j<=v1.MaxIndex()-1; ++j)
	{
		v1[j]=v1[j-1] + 1;
	}
	
	//create another vector to store the option price
	Vector<double, long> v2(N, 0.0);
	for (long j=v2.MinIndex(); j<= v2.MaxIndex(); ++j)
	{
		v2[j]= Option3.Price(price);
		price++;
	}


	cout<<"Data has been created"<<endl;

	//print the chart 
	try 
	{
		printOneExcel(v1,v2, std::string("Option Price Against Underlying Stock Price"), std::string("Stock Price"), std::string("Option Price"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}

	//print the data 
	try
	{
		printOneExcel(v1, v2);
	}
	catch(DatasimException& e)
	{
		e.print();
	}
	
    return 0;
	
}