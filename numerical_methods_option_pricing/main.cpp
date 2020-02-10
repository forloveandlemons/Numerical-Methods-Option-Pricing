#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
//#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"
using namespace std;

int main()
{
    OptionData AMER(110,100,DBL_MAX,0.1,0.1,0.02);//american data parameters stored in an OptionData tuple
    cout<<AMER<<endl;
    AmericanOption amer(AMER);//create AmericanOption object, initialize with AMER parameters
    cout<<amer.Prices()<<endl;
    vector<AmericanOptionAll> OptionVectorAmer;//create a vector to store parameters and call put prices of option
    vector<double> StockpriceArrayAmer = amer.MeshArray(100,150,5);//stock price mesh array:[100,150], interval=5
    amer.MeshStockprice(StockpriceArrayAmer,OptionVectorAmer);//generate option prices given mesh stock prices and store all the information in the OptionVectorAmer vector

    return 0;
}

