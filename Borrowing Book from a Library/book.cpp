#include "book.hh"
#include "date.hh"
#include <iostream>

Book::Book(const std::string& author,const std::string& title):
    author_(author),title_(title)
{
    Book::loaned = false; //default value of loaned flag
// additional logic Date today(5, 5, 2020); day = 5, month = 5 and year = 2020
}
// methods implementation
void Book::print(){
    std::cout << author_<<" : "<<title_<<std::endl;
    if(Book::loaned){
        std::cout<<"- loaned: ";
        Book::loaningdate.print();
        std::cout<<"- to be returned: ";
        Book::returningdate.print();
    }
    else if(!Book::loaned){
   std::cout<<"- available"<<std::endl;
    }

}
void Book::loan(Date &object){ // today is an instance of class date  If a book can be loaned (unless it is already loaned), the loan method creates a loaning date (given as a parameter) and a returning date that is 28 days after the loanibng date.
 if(Book::loaned){
     std::cout<<"Already loaned: cannot be loaned"<<std::endl;
}
 else if(!Book::loaned){
     //Book::print();
     Book::loaningdate = object;
     Book::returningdate = Book::loaningdate;
     Book::returningdate.advance(28);
     Book::loaned = true;
 }
}
void Book::renew(){
    if(Book::loaned){
        Book::returningdate.advance(28);
       // Book::print();
    }
    else if(!Book::loaned){
       std::cout<<"Not loaned: cannot be renewed"<<std::endl;
    }
}

void Book::give_back(){
    if(Book::loaned){
     Book::loaned = false;
    }
    else{
        std::cout<<"You cannot return a book which you have not taken"<<std::endl;
    }
}
