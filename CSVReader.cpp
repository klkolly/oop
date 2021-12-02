#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{
}


std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;

    std::ifstream csvFile{csvFilename};
    std::string line;
    if (csvFile.is_open())
    {
        std::cout << "Opened file " << csvFilename << std::endl;
        std::string line;
        while(getline(csvFile, line))
        {
            try
            {
                std::vector<std::string> tokens = tokenise(line, ',');
                OrderBookEntry entry = stringsToOBE(tokens);
                entries.push_back(entry);
            }
            catch( std::exception& e)
            {
                continue;
            }
        }
    }
    else
    {
        std::cout << "Problem opening file " << csvFilename << std::endl;
    }
    csvFile.close();



    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    

    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator,0);
    do{
        end = csvLine.find_first_of(separator,start);
        // if start == csvLine.length or start == end ## nothing more to find
        if(start == csvLine.length() || start == end) break;

        if(end >= 0 ){
            token = csvLine.substr(start, end - start);
        }else{
            //last one
            token = csvLine.substr(start, csvLine.length() - start);
        }

        tokens.push_back(token);
        start = end + 1;

    }while (end>0);


    
    return tokens;
}


/** string to orderbookentry*/
OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double price, amount;

    if (tokens.size() != 5)
    {
        //std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }

    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception& e)
    {
        std::cout << "Bad float! " << tokens[3]<< std::endl;
        std::cout << "Bad float! " << tokens[4]<< std::endl;
        throw;
    }

    OrderBookEntry obe{price,
                        amount,
                        tokens[0],
                        tokens[1],
                        OrderBookEntry::stringToOrderBookType(tokens[2])};

    return obe;
}

/** public*/
OrderBookEntry CSVReader::stringsToOBE(std::string priceString,
                                    std::string amountString,
                                    std::string timestamp,
                                    std::string product,
                                    OrderBookType orderType)
{
    double price, amount;
    try {
        price = std::stod(priceString);
        amount = std::stod(amountString);
    }catch(const std::exception& e){
        std::cout << "CSVReader::stringsToOBE Bad float! " << priceString<< std::endl;
        std::cout << "CSVReader::stringsToOBE Bad float! " << amountString<< std::endl;
        throw; // throw up to the calling function
    }
    OrderBookEntry obe{price,
                        amount,
                        timestamp,
                        product,
                        orderType};

    return obe;
}