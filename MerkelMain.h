
#pragma once
#include<vector>
#include "orderbookentry.h"


class MerkelMain{
    public:
        MerkelMain() = default;
        /** Call this to start the sim */
        void init();


    private:
        void loadOrderBook();
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

        // private:
        //     void loadOrderBook();
        //     void printMenu();
        //     void printHelp();
        //     void printMarketStats();
        //     void enterOffer();
        //     void enterBid();
        //     void printWallet();
        //     void gotoNextTimeframe();
        //     int getUserOption();
        //     void processUserOption(int userOption);
};
