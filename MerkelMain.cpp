
#include "MerkelMain.h"
#include <vector>
#include "orderbookentry.h"
#include <string>
#include <iostream>

void MerkelMain::init(){
    loadOrderBook();
    int input;
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::loadOrderBook(){
    OrderBookEntry order1(0.02186299, 252.76, "2020/03/17 17:01:24.884492", "ETH/USDT", OrderBookType::bid);
    OrderBookEntry order2(0.02126299, 255.76, "2020/03/17 17:01:24.884492", "ETH/USDT", OrderBookType::bid);
    orders.push_back(order1);
    orders.push_back(order2);
}


void MerkelMain::print(std:: string word){
    std::cout << word << std::endl;
}

void MerkelMain::printMenu(){
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Place an ask" << std::endl;
    std::cout << "4: Place a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
}

int MerkelMain::getUserOption(){
    int userOption;
    std::cout << "put in 1-6" << std::endl;
    std::cin >> userOption;
    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money." << std::endl;
    std::cout << "Analyse the market and make bids" << std::endl;
    std::cout << "and offers. " << std::endl;
}

void MerkelMain::printMarketStats(){
    print("MarketStats");
}

void MerkelMain::enterAsk(){
    print("enterAsk");
}

void MerkelMain::enterBid(){
    print("enterBid");
}

void MerkelMain::printWallet(){
    print("printWallet");
}

void MerkelMain::gotoNextTimeframe(){
    print("gotoNextTimeframe");
}

void MerkelMain::processUserOption(int userOption){
    if(userOption == 0){
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if(userOption == 1){
        printHelp();
    }
    if(userOption == 2){
        printMarketStats();
    }
    if(userOption == 3){
        enterAsk();
    }
    if(userOption == 4){
        enterBid();
    }
    if(userOption == 5){
        printWallet();
    }
    if(userOption == 6){
        gotoNextTimeframe();
    }
}


// double computeAveragePrice(std::vector<OrderBookEntry>& entries)
// {
//     double sumPrice{0};
//     for(OrderBookEntry &entry : entries)
//     {
//         sumPrice += entry.price;
//     }

//     return sumPrice/entries.size();
// }


