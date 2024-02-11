#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "date.hh"
class Book
{
public:
    Book(const std::string& author,const std::string& title);
    void print();
    void loan(Date& object);
    void renew();
    void give_back();
    Date loaningdate;
    Date returningdate;
    Date day;
    Date month;
    Date year;
private:
    bool loaned;
    std::string author_;
    std::string title_;
    Date currentdate;

};

#endif // BOOK_H
