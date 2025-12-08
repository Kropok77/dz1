#include "Library.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace myLibrary;
Library::Library(){
    this->loadFromFile();
}
Library::~Library(){
    books.clear();
    users.clear();
}

void Library::addBook(const Book& book){
    books.push_back(book);
    return;
}
void Library::addUser(const User& user){
    users.push_back(user);
    return;
}
void Library::borrowBook(const std::string& userName, const std::string& isbn){
    for (int i=0;i<books.size();i++){
        if (books[i].GetISBN()==isbn){
            if (books[i].GetAvaliable()){
                for (int x1=0;x1<users.size();x1++){
                    if (users[x1].GetName()==userName && users[x1].canBorrowMore()){
                        users[x1].addBook(isbn);
                    }
                }
            }
        }
    }
    return;
}
void Library::returnBook(const std::string& isbn){
    for (int x1=0;x1<users.size();x1++){
        for (int x2=0;x2<users[x1].GetBorrowedBooks().size();x2++){
            if (users[x1].GetBorrowedBooks()[x2]==isbn){
                users[x1].removeBook(isbn);
            }
        }
    }
    for (int i=0;i<books.size();i++){
        if (books[i].GetISBN()==isbn){
            books[i].returnBook();
        }
    }
    return;
}
Book* Library::findBookByISBN(const std::string& isbn){
    for (int i=0;i<books.size();i++){
        if (books[i].GetISBN()==isbn){
            return &books[i];
        }
    }
    return nullptr;
}
User* Library::findUserByName(const std::string& name){
    for (int i=0;i<users.size();i++){
        if (users[i].GetName()==name){
            return &users[i];
        }
    }
    return nullptr;
}
void Library::displayAllBooks(){
    std::cout<<"Каталог книг"<<std::endl;
    for (int i=0;i<books.size();i++){
        std::cout<<books[i].GetTitle()<<" "<<books[i].GetAuthor()<<" "<<books[i].GetISBN()<<std::endl;
    }
}
void Library::displayAllUsers(){
    std::cout<<"Список пользователей"<<std::endl;
    for (int i=0;i<users.size();i++){
        std::cout<<users[i].GetName()<<" "<<users[i].GetUserId()<<std::endl;
    }
}
void Library::saveToFile(){
    std::ofstream out;
    out.open(("../data/"+datafile));
    if (out.is_open()){
        out<<books.size()<<std::endl;
        for (int i=0;i<books.size();i++){
            out<<books[i].GetAuthor()<<" "<<" "<<books[i].GetISBN()<<" "<<books[i].GetTitle()<<" "<<books[i].GetYear()<<books[i].GetAvaliable()<<" "<<books[i].GetBorrowedby()<<std::endl;
        }
        out<<users.size()<<std::endl;
        for (int j=0;j<users.size();j++){
            out<<users[j].GetBorrowedBooks().size()<<" "<<users[j].GetMaxBooksAllowed()<<" "<<users[j].GetName()<<" "<<users[j].GetUserId()<<std::endl;
            for (int x=0;x<users[j].GetBorrowedBooks().size();x++){
                std::cout<<users[j].GetBorrowedBooks()[x]<<" ";
            }
            std::cout<<std::endl;

        }
    }
    out.close();
    return;
}
void Library::loadFromFile(){//Проверить!!

    std::ifstream in("../data/library_data.txt");

    int book_size;
    std::vector<Book> zz;
    if (in.is_open()){
        in>>book_size;
        std::string aut,ava,borowed="",isb,tit;
        bool avalib;
        int yea;
        
        for (int i=0;i<book_size;i++){
            borowed="";
            in>>aut>>isb>>tit>>yea>>avalib;
            if (avalib){
                in>>borowed;
            }
        }
        zz.push_back(Book(tit,aut,yea,isb,avalib,borowed));
        in.close();

    }
    int ussize;
    in>>ussize;
    int borsi,getma;
    std::string uname,uid,bbok;
    std::vector<User> uu;
    for (int j=0;j<ussize;j++){
        in>>borsi>>getma>>uname>>uid;
        std::vector<std::string> lam;
        for (int b=0;b<borsi;b++){
            in>>bbok;
            lam.push_back(bbok);
        }
        uu.push_back(User(uname,uid,lam,getma));
    }
    users=uu;
    books=zz;

}