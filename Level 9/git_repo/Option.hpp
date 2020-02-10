// Option.hpp

#ifndef OPTION_HPP
#define OPTION_HPP

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <cmath>
#include <string>
#include <iostream>

using namespace boost;

typedef boost::tuple<double,double,double,double,double,double> OptionData;//tuple for storing option parameters
typedef boost::tuple<double,double> CallPutPair;//tuple for storing call put price
typedef boost::tuple<OptionData,CallPutPair,CallPutPair,CallPutPair> OptionAll;//tuple for storing option data, call put prices, call put gamma(should be the same but we still keep both)


class Option
{//Option base class
private:
    
    OptionData opt;//all option parameters: (S,K,T,r,sig,b) stored in a boost tuple
    
public:	// Public functions
    
    Option();							    // default constructor
    Option(double,double,double,double,double,double);//constructor initializing parameters
    Option(const OptionData&);              //constructor given OptionData type data member
    Option(const Option& option);           // copy constructor
    virtual ~Option();                      // destructor
    
    // Get functions, retrieving parameters of the option
    const OptionData& OptionTuple() const;//return type should be const reference, in case other people have access to private data and change it
    const double& S() const;
    const double& K() const;
    const double& T() const;
    const double& r() const;
    const double& sig() const;
    const double& b() const;
    
    // Set functions, setting parameters for the option
    void OptionTuple(const OptionData&);
    void S(double);
    void K(double);
    void T(double);
    void r(double);
    void sig(double);
    void b(double);
    
    // Assignment operator overloading
    Option& operator = (const Option&);
    
    //function for creating a mesh array
    std::vector<double> MeshArray(double start,double end,double h) const;
    
    // Pricing function
    //declare as virtual function for polymorphism of European and American options
    virtual double CallPrice() const;
    virtual double PutPrice() const;
    
    //function for handing a mesh array of stock prices, expiry time, volatility
    virtual void MeshStockprice(std::vector<double> StockpriceArray) const;
    
};

#endif