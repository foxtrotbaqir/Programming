#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    owner_(owner),has_credit_(has_credit)
{
// it needs to generate an amount on the type of account if it is current, savings or credit card account. so that it can be printed out as per the name given to account object.
    generate_iban(); // generates a specific iban number to that account.
Account::balance = 0;
}

void Account::print() const{
std::cout << Account::owner_ << " : " << Account::iban_ << " : " << Account::balance << " euros" << std::endl;
return;
// it should print the information of that account based on what account it is.

}
void Account::set_credit_limit(int amount){
if(Account::has_credit_ == true){
    // if its a credit card account then use the amount variable to fetch the value and save it in credit limit variable. if has_credit_ is false then print error "Cannot set credit limit: the account has no credit card"
   Account::credit_limit = amount;
return;
}
else if(Account::has_credit_ == false){
std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;
return;
}
}

void Account::save_money(int amount){
// adds amount into balance of that account.
Account::balance += amount;
return;
}

void Account::take_money(int amount){
// Subtracts amount from balance of that account.
    if(Account::has_credit_ == true and amount <= Account::credit_limit+Account::balance){
        Account::balance -= amount;
        //Account::credit_limit += Account::balance;
      std::cout << amount << " euros taken: new balance of " << Account::iban_ <<" is "<< Account::balance <<" euros"<< std::endl;
      return;
    }
else if(amount<=  Account::balance ){
Account::balance -= amount;
std::cout << amount << " euros taken: new balance of " << Account::iban_ <<" is "<< Account::balance <<" euros"<< std::endl;
return;
}
else if(amount> Account::balance and  Account::has_credit_ == false){
    std::cout << "Cannot take money: balance underflow" <<std::endl;
    return;
}
else if(Account::has_credit_ == true and amount > Account::credit_limit+Account::balance){
      std::cout << "Cannot take money: credit limit overflow" << std::endl;
    }
}

void Account::transfer_to(Account& object, int amount){
// transfers amount from the present account to the specified account object. and subtracts amount from the balance.
if(amount<=Account::balance){
    Account::take_money(amount);
object.save_money(amount);
}
else if(Account::has_credit_ == true and amount <= Account::credit_limit+Account::balance){
    Account::take_money(amount);
object.save_money(amount);
}
else if(Account::has_credit_ == true and amount > Account::credit_limit+Account::balance){
    Account::take_money(amount);
    std::cout << "Transfer from "<<Account::iban_ <<" failed"<<std::endl;
}
else if(amount>Account::balance){
    Account::take_money(amount);
    std::cout<< "Transfer from "<<Account::iban_<<" failed" << std::endl;
}
return;
}
// Setting initial value for tgfgtatic attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "PK00 1234 ";
    iban_.append(suffix);
return;
}

