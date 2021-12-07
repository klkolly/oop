#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"


int main()
{
    Wallet wallet{};
    wallet.insertCurrency("BTC", 1.5);
   
    std::cout << wallet.toString() << std::endl;
    // MerkelMain app{};
    // app.init();

}

