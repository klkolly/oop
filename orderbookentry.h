
#pragma once
#include<string>


enum class OrderBookType {bid, ask, unknown};
class OrderBookEntry
{
    public: 
        /** Create a new OrderBookEntry with the price
        * set to the sent value
        */
       // Constructor
        OrderBookEntry(double long _price,
                       double _amount,
                       std::string _timestamp,
                       std::string _product,
                       OrderBookType _orderType);
 

        double long price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;

      

        static OrderBookType stringToOrderBookType(const std::string& s);
};


