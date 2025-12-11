#include "Book.h"
#include<iostream>
#include<stdexcept>
using namespace mybooklib;
Book::Book()
    : title(""), author(""),year(0),isbn(""),isAvaliable(false),borrowedBy(""){ 
    }

Book::Book(std::string name_p,std::string auth_p,int year_p,std::string isbn_p,bool isavaliable_p,std::string borrowedby_p)
    : title(name_p), author(auth_p),year(year_p),isbn(isbn_p),isAvaliable(isavaliable_p),borrowedBy(borrowedby_p)
    {
    }
const std::string& Book::GetAuthor() const {
    return author;
}
const std::string& Book::GetTitle() const {
    return title;
}
const int& Book::GetYear() const {
    return year;
}
const std::string& Book::GetISBN() const {
    return isbn;
}
const std::string& Book::GetBorrowedby() const {
    return borrowedBy;
}
const bool& Book::GetAvaliable() const{
    return isAvaliable;
}
void Book::borrowBook(const std::string& userName){
    if (!isAvaliable){
        std::cerr<<"ERROR - BOOK is not avaliable";
        return;
    }
    borrowedBy=userName;
    isAvaliable=false;

}
void Book::returnBook(){
    borrowedBy="";
    isAvaliable=true;
    
}
void Book::displayInfo(){
    std::cout<<"Название книги: "<<title<<std::endl;
    std::cout<<"Автор: "<<author<<std::endl;
    std::cout<<"Год тиража: "<<year<<std::endl;
    std::cout<<"ISBN: "<<isbn<<std::endl;
    std::cout<<"Наличие: "<<isAvaliable<<std::endl;
    std::cout<<"Кто читает в данный момент: "<<borrowedBy<<std::endl;
    std::cout<<std::endl;
}



