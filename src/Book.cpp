#include "Book.h"
#include<iostream>
#include<stdexcept>
using namespace mybooklib;
Book::Book()
    : title(""), author(""),year(0),isbn(""),isAvaliable(false),borrowedBy(""){ 
    }
Book::~Book()
    {
    }
Book::Book(std::string name_p,std::string auth_p,int year_p,std::string isbn_p,bool isavaliable_p,std::string borrowedby_p)
    : title(name_p), author(auth_p),year(year_p),isbn(isbn_p),isAvaliable(isavaliable_p),borrowedBy(borrowedby_p)
    {
    }
std::string Book::GetAuthor() const {
    return author;
}
std::string Book::GetTitle() const {
    return title;
}
int Book::GetYear() const {
    return year;
}
std::string Book::GetISBN() const {
    return isbn;
}
std::string Book::GetBorrowedby() const {
    return borrowedBy;
}
bool Book::GetAvaliable() const{
    return isAvaliable;
}
void Book::borrowBook(const std::string& userName){
    if (!isAvaliable){
        std::cerr<<"ERROR - BOOK is not avaliable";
        return;
    }
    borrowedBy=userName;

}
void Book::returnBook(){
    if (isAvaliable){
        if (!isAvaliable){
        std::cerr<<"ERROR - BOOK is alredy return";
        return;
    }
    borrowedBy="";
    isAvaliable=true;
    }
}
void Book::displayInfo(){
    std::cout<<"Название книги: "<<title<<std::endl;
    std::cout<<"Автор: "<<author<<std::endl;
    std::cout<<"Год тиража: "<<year<<std::endl;
    std::cout<<"ISBN: "<<isbn<<std::endl;
    std::cout<<"Наличие: "<<isAvaliable<<std::endl;
    std::cout<<"Кто читает в данный момент: "<<borrowedBy<<std::endl;
}



