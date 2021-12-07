#include "Wallet.h"

Wallet::Wallet()
{
    
}

/** insert currency to the wallet */
void Wallet::insertCurrency(std::string type, double amount)
{

    if((currencies[type] + amount)<0)
    {
        throw "not enough money";
    }
    currencies[type] += amount;


}
/** remove currency from the wallet */
bool Wallet::removeCurrency(std::string type, double amount)
{
    return false;
}
/** check if the wallet contains this much currency or more */
bool Wallet::containsCurrency(std::string type, double amount)
{
    return false;
}
/** generate a string representation of the wallet */
std::string Wallet::toString()
{
    std::string s;
    for (std::pair<std::string,double> pair : currencies)
    {
    std::string currency = pair.first;
    double amount = pair.second;
    s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}
