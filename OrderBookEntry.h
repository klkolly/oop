
#pragma once
#include<string>


enum class OrderBookType {bid, ask, unknown, sale};
/** object for book info,include price amount time product and order type*/
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

        static bool compareByTimestamp(const OrderBookEntry& e1, const OrderBookEntry& e2)
        {
        return e1.timestamp < e2.timestamp;
        }
        static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2)
        {
        return e1.price < e2.price;
        }
        static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2)
        {
        return e1.price > e2.price;
        }
};


