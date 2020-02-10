// AmericanOption.hpp

#ifndef AmericanOption_hpp
#define AmericanOption_hpp

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <cmath>
#include <string>
#include <iostream>
#include "Option.hpp"

using namespace boost;

typedef boost::tuple<double,double,double,double,double,double> OptionData;//tuple for storing option parameters
typedef boost::tuple<double,double> CallPutPair;//tuple for storing call put price
typedef boost::tuple<OptionData,CallPutPair,CallPutPair,CallPutPair> EuropeanOptionAll;//tuple for storing European option data, call put prices, call put gamma(should be the same but we still keep both)
typedef boost::tuple<OptionData,CallPutPair> AmericanOptionAll;//tuple for storing American option data, call put prices, call put gamma(should be the same but we still keep both)

class AmericanOption:public Option
{
private:
    
    //OptionData opt;//all option parameters: (S,K,T,r,sig,b) stored in a boost tuple
    
public:	// Public functions
    
    AmericanOption();							    // default constructor
    AmericanOption(double,double,double,double,double);//constructor initializing parameters. no parameter T
    AmericanOption(const OptionData&); //constructor given OptionData type data member
    AmericanOption(const AmericanOption& option);	// copy constructor
    virtual ~AmericanOption();                      // destructor
    
    // Assignment operator overloading
    AmericanOption& operator = (const AmericanOption&);
    
    // Pricing function
    virtual double CallPrice() const;
    virtual double PutPrice() const;
    
    //function convenient for call and price output
    CallPutPair Prices() const;
    
        
    //use an OptionAll tuple to store all the information of our option such as prices, delta, gamma etc.
    AmericanOptionAll AllData() const;
    
    //function for handing a mesh array of stock prices, expiry time, volatility
    //virtual void MeshStockprice(std::vector<double> StockpriceArray) const;
    virtual void MeshStockprice(std::vector<double> StockpriceArray,std::vector<AmericanOptionAll> AllDataVector) const;
};

#endif