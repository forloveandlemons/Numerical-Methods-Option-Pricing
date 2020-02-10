#include "Option.hpp"

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <cmath>
#include <string>
#include <iostream>
using namespace boost;

////////////////////constructor and destructors
Option::Option()
{//default constructor
    opt=boost::make_tuple(0,0,0,0,0,0);
};

Option::Option(double S,double K,double T,double r,double sig,double b)
{//constructor initializing parameters
    opt=boost::make_tuple(S,K,T,r,sig,b);
};

Option::Option(const OptionData& batch)
{//constructor with parameters of option stored in the OptionData tuple
    opt=batch;
};

Option::Option(const Option& option)
{//copy constructor
    opt=option.opt;
};

Option::~Option()
{//destructor
    
};

////////////////get functions that return corresponding parameters////////////////
const OptionData& Option::OptionTuple() const
{//get all parameters of an option
    return opt;
};

const double& Option::S() const
{//get stock price of an option
    return opt.get<0>();
};

const double& Option::K() const
{//get strike price of an option
    return opt.get<1>();
};

const double& Option::T() const
{//get expiry time of an option
    return opt.get<2>();
};

const double& Option::r() const
{//get risk-free-rate of an option
    return opt.get<3>();
};

const double& Option::sig() const
{//get volatility of an option
    return opt.get<4>();
};

const double& Option::b() const
{//get cost-of-carry of an option
    return opt.get<5>();
};

//////////////set functions that set option parameters//////////////
void Option::OptionTuple(const OptionData& optiondata)
{//set all the parameters at the same time with all stored in a tuple
    opt=optiondata;
};

void Option::S(double S_)
{//set underlying stock price of the option
    opt.get<0>()=S_;
};

void Option::K(double K_)
{//set strike price of the option
    opt.get<1>()=K_;
};

void Option::T(double T_)
{//set expiry time of an option
    opt.get<2>()=T_;
};

void Option::r(double r_)
{//set risk-free-rate of an option
    opt.get<3>()=r_;
};

void Option::sig(double sig_)
{//set volatility of an option
    opt.get<4>()=sig_;
};

void Option::b(double b_)
{//set cost-of-carry of an option
    opt.get<5>()=b_;
};


// Assignment operator overloading
Option& Option::operator = (const Option& option)
{
    opt=option.opt;
    return *this;
};

std::vector<double> Option::MeshArray(double start,double end,double h) const
{//function for creating MeshArray,range=[start,end] and step interval=h
    std::vector<double> mesh;
    mesh.reserve(100);
    for (double i=start; i<=end; i+=h)
        mesh.push_back(i);
    return mesh;
};


//////////////Pricing function/////////////

double Option::CallPrice() const
{//virtual function here
    std::cout<<"base class call price called"<<std::endl;
    return 0;
};

double Option::PutPrice() const
{//virtual function here
    std::cout<<"base class put price called"<<std::endl;
    return 0;
};

void Option::MeshStockprice(std::vector<double> StockpriceArray) const
{//return options and call put prices given a stock mesh array
    std::cout<<"base class call price called"<<std::endl;
};


