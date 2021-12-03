#include "OrderBook.h"
#include <map>
#include <iostream>


/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
};
/** return vector of all know products in the dataset*/
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> p;
    std::map<std::string, bool> prodMap;

    for (const OrderBookEntry&e :orders )
    {
        prodMap[e.product]=true;
    }

    for(const auto& e : prodMap)
    {
        p.push_back(e.first);
    }


    return p ;
};
/** return vector of Orders according to the sent filters*/
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                std::string product,
                                                std::string timestamp)
{
    std::vector<OrderBookEntry> p;
    for (const OrderBookEntry&e :orders )
    {
        if(e.product == product &&
          e.timestamp == timestamp &&
          e.orderType == type)
        {
            p.push_back(e);
        }
    }

    return p;
};

/** return the price of the highest bid in the sent set */
double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max{0};
    max = orders[0].price;

    for(const OrderBookEntry&order :orders)
    {
        
        if(order.price > max) {max = order.price;};
    }

    return max;
};

      
/** return the price of the lowest bid in the sent set */
double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
        
    double min{0};
    min = orders[0].price;
    for(const OrderBookEntry& e : orders)
    {
        if(e.price < min) {min = e.price;};
    }
    return min;

};

std::string OrderBook::getEarliestTime()
{
    std::string timestamp;
    timestamp = orders[0].timestamp;
    for (const OrderBookEntry& e : orders)
    {
        if(e.timestamp< timestamp) {timestamp = e.timestamp;};
    }

    return timestamp;
}


std::string OrderBook::getNextTime(const std::string& timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }
    if (next_timestamp == "")
    {
        next_timestamp = getEarliestTime();
    }
    return next_timestamp;


}

void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}



std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp){
// asks = orderbook.asks in this timeframe
// bids = orderbook.bids in this timeframe
// sales = []
// sort asks lowest first
// sort bids highest first
// for ask in asks:
{
    // for bid in bids:
    {
        // if bid.price >= ask.price # we have a match
        {
            // sale = new orderbookentry()
            // sale.price = ask.price
            // if bid.amount == ask.amount: # bid completely clears ask
            {
                // sale.amount = ask.amount
                // sales.append(sale)
                // bid.amount = 0 # make sure the bid is not processed again
                // # can do no more with this ask
                // # go onto the next ask
                // break
            }
            // if bid.amount > ask.amount: # ask is completely gone slice the bid
            {
                // sale.amount = ask.amount
                // sales.append(sale)
                // # we adjust the bid in place
                // # so it can be used to process the next ask
                // bid.amount = bid.amount - ask.amount
                // # ask is completely gone, so go to next ask
                // break
            }
            // if bid.amount < ask.amount # bid is completely gone, slice the ask
            {
                // sale.amount = bid.amount
                // sales.append(sale)
                // # update the ask
                // # and allow further bids to process the remaining amount
                // ask.amount = ask.amount - bid.amount
                // bid.amount = 0 # make sure the bid is not processed again
                // # some ask remains so go to the next bid
                // continue
            }
        }
    }
}
// return sales
}