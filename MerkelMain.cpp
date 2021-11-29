
#include "MerkelMain.h"


void MerkelMain::init(){
    // loadOrderBook();
    int input;
    currentTime = orderBook.getEarliestTime();

    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

// void MerkelMain::loadOrderBook(){
//     orders = CSVReader::readCSV("20200317.csv");
//     std::cout << "read " << orders.size() << " orders" << std::endl;
// }


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
    std::cout << "==================" << std::endl;
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

void MerkelMain::printMarketStats()
{
    
    for (const std::string& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;

        std::vector<OrderBookEntry> bidEntries = orderBook.getOrders(OrderBookType::bid, p, currentTime);
        std::cout << "bid seen: " << bidEntries.size() << std::endl;
        std::cout << "Max bid: " << OrderBook::getHighPrice(bidEntries) << std::endl;
        std::cout << "Min bid: " << OrderBook::getLowPrice(bidEntries) << std::endl;
    }

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
    std::cout << "Going to next time frame. " << std::endl;
    
    currentTime = orderBook.getNextTime(currentTime);
}

void MerkelMain::processUserOption(int userOption){

    if(userOption == 1){
        printHelp();
    }
    else if(userOption == 2){
        printMarketStats();
    }
    else if(userOption == 3){
        enterAsk();
    }
    else if(userOption == 4){
        enterBid();
    }
    else if(userOption == 5){
        printWallet();
    }
    else if(userOption == 6){
        gotoNextTimeframe();
    }
    else{
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
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


