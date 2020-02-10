#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include "EuropeanOption.hpp"
//#include "AmericanOption.hpp"
using namespace std;

int main()
{
    //create 5 variables(the first 4 for question a1 and the 5th for question a2), keeping record of batch data parameters
    OptionData Batch1_Data(60,65,0.25,0.08,0.30,0.08);
    OptionData Batch2_Data(100,100,1.0,0.0,0.2,0.0);
    OptionData Batch3_Data(5,10,1.0,0.12,0.50,0.12);
    OptionData Batch4_Data(100.0,100.0,30.0,0.08,0.30,0.08);
    OptionData A2_Data(105,100,0.5,0.1,0.36,0);
    
    //create 5 objects of the derived class EuropeanOption for question a1&a2
    EuropeanOption batch1(Batch1_Data);
    EuropeanOption batch2(Batch2_Data);
    EuropeanOption batch3(Batch3_Data);
    EuropeanOption batch4(Batch4_Data);
    EuropeanOption a2(A2_Data);
    
    //create 5 vectors for storing All information(parameters,call put prices,call put gamma)
    vector<EuropeanOptionAll> OptionVector1;
    vector<EuropeanOptionAll> OptionVector2;
    vector<EuropeanOptionAll> OptionVector3;
    vector<EuropeanOptionAll> OptionVector4;
    vector<EuropeanOptionAll> OptionVectorA2;
    //create a vector for storing approximate result using divided difference method
    vector<EuropeanOptionAll> AllApproxiDataVector;

    
    vector<double> StockpriceArray1 = batch1.MeshArray(60.0,80.0,2);//initialize vector object StockArray1, storing Stock price sequence for Batch1
    vector<double> StockpriceArray2 = batch2.MeshArray(80.0,120.0,2.0);//initialize vector object StockArray, storing Stock price sequence for Batch2
    vector<double> StockpriceArray3 = batch3.MeshArray(5,10,0.5);//initialize vector object StockArray, storing Stock price sequence for Batch3
    vector<double> StockpriceArray4 = batch4.MeshArray(40.0,100.0,4.0);//initialize vector object StockArray, storing Stock price sequence for Batch4
    vector<double> StockpriceArrayA2 = a2.MeshArray(100,200,5);
    
    
    vector<double> ExpiryArray1 = batch1.MeshArray(0.10,0.51,0.02);//initialize vector object ExpiryArray1, storing Stock price sequence for Batch1
    vector<double> ExpiryArray2 = batch2.MeshArray(1.0,20,1);
    vector<double> ExpiryArray3 = batch3.MeshArray(1.0,10,1);
    vector<double> ExpiryArray4 = batch4.MeshArray(1.0,20,2);
    
    vector<double> VolatilityArray = batch1.MeshArray(0.10,0.61,0.04);
    
    vector<double> DiffArray = {0.0001,0.001,0.01,0.1,1,10};

    cout<<"***************************A1(a)*******************************"<<endl;
    //for each batch, calculate the call price using global function CallPrice, then calculate the put price using global function PutPrice
    cout<<"Batch 1:\n"<<batch1.Prices()<<endl;
    cout<<"Batch 2:\n"<<batch2.Prices()<<endl;
    cout<<"Batch 3:\n"<<batch3.Prices()<<endl;
    cout<<"Batch 4:\n"<<batch4.Prices()<<endl;
    
    cout<<"***************************A1(b)*******************************"<<endl;
    //for each batch, calculate the call price using global function CallPrice, then calculate the corresponding put price using global function PutCallParityCheck, the result should be the same as put prices in A1(a)
    cout<<"Batch 1:\n"<<batch1.CallPrice()<<' '<<batch1.PutCallParity()<<endl;
    cout<<"Batch 2:\n"<<batch2.CallPrice()<<' '<<batch2.PutCallParity()<<endl;
    cout<<"Batch 3:\n"<<batch3.CallPrice()<<' '<<batch3.PutCallParity()<<endl;
    cout<<"Batch 4:\n"<<batch4.CallPrice()<<' '<<batch4.PutCallParity()<<endl;
    
    cout<<"***************************A1(c)*******************************"<<endl;
    cout<<"Should be the same as (a) and (b)"<<endl;
    
    cout<<"***************************A1(d)*******************************"<<endl;
    
    //cout<<"result represented as [stock price] (Call Price, Put Price) for each Batch at each specific stock price"<<endl;
    cout<<"Batch 1: "<<endl; batch1.MeshStockprice(StockpriceArray1,OptionVector1);
    cout<<"Batch 2: "<<endl; batch2.MeshStockprice(StockpriceArray2,OptionVector2);
    cout<<"Batch 3: "<<endl; batch3.MeshStockprice(StockpriceArray3,OptionVector3);
    cout<<"Batch 4: "<<endl; batch4.MeshStockprice(StockpriceArray4,OptionVector4);
    
    
    cout<<"*******************A1(e)(1)*expiry_time************************"<<endl;
    //vector<double> ExpiryArray1 = MeshArray(0.10,0.51,0.02);//initialize vector object ExpiryArray1, storing Stock price sequence for Batch1
    //vector<double> ExpiryArray2 = MeshArray(1.0,20,1);
    //vector<double> ExpiryArray3 = MeshArray(1.0,10,1);
    //vector<double> ExpiryArray4 = MeshArray(1.0,20,2);
    
    cout<<"Batch 1: "<<endl; batch1.MeshExpiry(ExpiryArray1,OptionVector1);
    cout<<"Batch 2: "<<endl; batch2.MeshExpiry(ExpiryArray2,OptionVector2);
    cout<<"Batch 3: "<<endl; batch3.MeshExpiry(ExpiryArray3,OptionVector3);
    cout<<"Batch 4: "<<endl; batch4.MeshExpiry(ExpiryArray4,OptionVector4);
    
    cout<<"******************A1(e)(1)*volatility**************************"<<endl;
    //vector<double> VolatilityArray = MeshArray(0.10,0.61,0.04);
    //we use the same volatility steps for convenience

    cout<<"Batch 1: "<<endl; batch1.MeshVolatility(VolatilityArray,OptionVector1);
    cout<<"Batch 2: "<<endl; batch2.MeshVolatility(VolatilityArray,OptionVector2);
    cout<<"Batch 3: "<<endl; batch3.MeshVolatility(VolatilityArray,OptionVector3);
    cout<<"Batch 4: "<<endl; batch4.MeshVolatility(VolatilityArray,OptionVector4);
    
    cout<<"***************************A2(a)******************************"<<endl;
    //answers for option greeks
    cout<<a2.AllData()<<endl;
    
    cout<<"***************************A2(b)******************************"<<endl;
    //answers for greek given mesh stock price(stored in stock price array) and option parameters
    a2.MeshStockprice(StockpriceArrayA2,OptionVectorA2);
    
    cout<<"***************A2(c)*perform calculation in(a)****************"<<endl;
    //approximation of the option greek by approximating with different step intervals
    a2.ArrayDiffApproxi(DiffArray,AllApproxiDataVector);
    
    cout<<"***************A2(c)*perform calculation in(b)****************"<<endl;
    //approximation of option greek using divided difference approximation given a mesh stock price
    a2.ArrayDiffApproxi(DiffArray,AllApproxiDataVector,StockpriceArrayA2);
   

    return 0;
}

