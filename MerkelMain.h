
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "OrderBookEntry.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "OrderBook.h"
#include <algorithm>


class MerkelMain{
    public:
        MerkelMain() = default;
        /** Call this to start the sim */
        void init();


    private:
        OrderBook orderBook{"20200317.csv"};
        void print(std:: string word);
        void printMenu();
        int getUserOption();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void processUserOption(int userOption);
        
        std::vector<OrderBookEntry> orders;
        std::string currentTime;


};
