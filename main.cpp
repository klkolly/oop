#include <iostream>
#include <string>
#include <vector>
#include "orderbookentry.h"
#include "MerkelMain.h"

std::vector<std::string> tokenise(std::string csvLine, char separator){
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




int main(){

    //string csvLine = 'thing,thing2,thing3' 
    std::string csvLine = "thing,thing2,thing3";

    std::vector<std::string> tokens = tokenise(csvLine,',');
    for (const std::string& t : tokens)
    {
    std::cout << t << std::endl;
    }

    // MerkelMain app{};
    // app.init();

    return 0;
}

