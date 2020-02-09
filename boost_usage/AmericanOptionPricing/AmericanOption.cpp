#include "AmericanOption.hpp"

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <cmath>
#include <string>
#include <iostream>
using namespace boost;

////////////////////constructor and destructors
AmericanOption::AmericanOption():Option()
{//default constructor
    T(DBL_MAX);
};

AmericanOption::AmericanOption(double S,double K,double r,double sig,double b):Option(S,K,DBL_MAX,r,sig,b)
{//constructor initializing parameters
    //opt=boost::make_tuple(S,K,T,r,sig,b);
};

AmericanOption::AmericanOption(const OptionData& batch):Option(batch)
{//set Expiry time as perpetual
    T(DBL_MAX);
};

AmericanOption::AmericanOption(const AmericanOption& option):Option(option)
{//set Expiry time as perpetual
    T(DBL_MAX);
};

AmericanOption::~AmericanOption()
{//destructor
    //std::cout<<"European destructor called"<<std::endl;
};

//////////////////////////////////////////////////////////////////////
// Assignment operator overloading
AmericanOption& AmericanOption::operator = (const AmericanOption& option)
{
    Option::operator=(option);//copy data in the base class
    //opt=option.opt;
    return *this;
};

//////////////Pricing function/////////////
double AmericanOption::CallPrice() const
{//closed form formula of perpetual american call option price
    double tmp=pow((b()/(sig()*sig())-0.5)*(b()/(sig()*sig())-0.5)+2*r()/(sig()*sig()),0.5);
    double y1=0.5-b()/(sig()*sig())+tmp;
    double C =K()/(y1-1)*pow(((y1-1)/y1)*(S()/K()),y1);
    return C ;
};

double AmericanOption::PutPrice() const
{//closed form formula of perpetual american put option price
    double tmp=pow((b()/(sig()*sig())-0.5)*(b()/(sig()*sig())-0.5)+2*r()/(sig()*sig()),0.5);
    double y2=0.5-b()/(sig()*sig())-tmp;
    double P =K()/(1-y2)*pow(((y2-1)/y2)*(S()/K()),y2);
    return P ;
};

AmericanOptionAll AmericanOption::AllData() const
{//return parameters and call put prices of perpetual american option
    AmericanOptionAll all=make_tuple(OptionTuple(),Prices());
    return all;
};

CallPutPair AmericanOption::Prices() const
{//return call put price pair in a tuple
    CallPutPair prices(CallPrice(),PutPrice());
    return prices;
};

void AmericanOption::MeshStockprice(std::vector<double> StockpriceArray,std::vector<AmericanOptionAll> AllDataVector) const
{//given mesh stock price, print option parameters and option prices, then store all the information(option parameters,call put prices) in a vector for further use
    for(int i=0;i<StockpriceArray.size();i++)
    {
        OptionData tmp=make_tuple(StockpriceArray[i],K(),T(),r(),sig(),b());//assign the current stock price value to current batch
        AmericanOption tmp_obj(tmp);
        std::cout<<(tmp_obj.AllData()).get<0>()<<' '<<(tmp_obj.AllData()).get<1>()<<std::endl;
        //store call & put prices,(and also greeks for convenience or further use) vector into the vector according to exercise requirement
        AllDataVector.push_back(tmp_obj.AllData());
    }
};




