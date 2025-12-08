#include "User.h"
#include <iostream>
#include <stdexcept>
using namespace UserLib;
User::User()
    : name(""),userId(""),borrowedbooks({}),maxbooksallowed(3){
}
User::User(std::string name_p,std::string userId_p,std::vector<std::string> borrowedbooks_p,int maxbooksallowed_p)
    : name(name_p), userId(userId_p),borrowedbooks(borrowedbooks_p),maxbooksallowed(maxbooksallowed_p){
}
User::~User(){
    borrowedbooks.clear();
}
std::string User::GetName() const{
    return name;
}
std::string User::GetUserId() const{
    return userId;
}
std::vector<std::string> User::GetBorrowedBooks() const{
    return borrowedbooks;
}
int User::GetMaxBooksAllowed() const{
    return maxbooksallowed;
}
bool User::canBorrowMore(){
    if (borrowedbooks.size()<maxbooksallowed-1){
        return true;
    }
    return false;
}
void User::addBook(const std::string& isbn){
    borrowedbooks.push_back(isbn);

}
void User::removeBook(const std::string& isbn){
    borrowedbooks.erase(std::remove(borrowedbooks.begin(),borrowedbooks.end(),isbn),borrowedbooks.end()); //проверить работу!!!
}
void User::displayProfile(){
    std::cout<<"Имя пользователя: "<<name<<std::endl;
    std::cout<<"ID пользователя: "<<userId<<std::endl;
    std::cout<<"Максимально доступное количество книг доступное пользователю: "<<maxbooksallowed<<std::endl;
    std::cout<<"Выданные книги:"<<std::endl;
    for (int i=0;i<borrowedbooks.size();i++){
        std::cout<<borrowedbooks[i]<<std::endl;
    }
    return;
}
