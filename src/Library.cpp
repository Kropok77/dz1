#include "Library.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 

using namespace myLibrary;

Library::Library() {
    datafile = "library_data.txt"; 
    loadFromFile();
}

Library::~Library() {
    books.clear();
    users.clear();
}

void Library::addBook(const Book& book) {
    if (book.GetYear()<1400){
        std::cout << "ERROR: Book date is incorrect foramt" << std::endl;
        return;
    }
    std::cout << "\nУспешно! Книга добавлена." << std::endl;
    books.push_back(book);
}

void Library::addUser(const User& user) {
    users.push_back(user);
}

void Library::borrowBook(const std::string& userName, const std::string& isbn) {
    
    Book* book = findBookByISBN(isbn);
    User* user = findUserByName(userName);

    if (book == nullptr) {
        std::cout << "ERROR: Book not found" << std::endl;
        return;
    }
    if (user == nullptr) {
        std::cout << "ERROR: User not found" << std::endl;
        return;
    }

    if (!book->GetAvaliable()) {
        std::cout << "ERROR: Book is not available." << std::endl;
        return;
    }
    if (!user->canBorrowMore()) {
        std::cout << "ERROR: User reached max book limit." << std::endl;
        return;
    }

    book->borrowBook(userName);
    user->addBook(isbn);
}

void Library::returnBook(const std::string& isbn) {
    Book* book = findBookByISBN(isbn);
    if (book == nullptr) {
        std::cout << "ERROR: Book not found!" << std::endl;
        return;
    }

    std::string userName = book->GetBorrowedby();
    User* user = findUserByName(userName);

    book->returnBook();

    if (user != nullptr) {
        user->removeBook(isbn);
    }
}

Book* Library::findBookByISBN(const std::string& isbn) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].GetISBN() == isbn) {
            return &books[i];
        }
    }
    return nullptr;
}

User* Library::findUserByName(const std::string& name) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].GetName() == name) {
            return &users[i];
        }
    }
    return nullptr;
}

void Library::displayAllBooks() {
    std::cout << "===Каталог книг===" << std::endl;
    for (int i = 0; i < books.size(); i++) {
        books[i].displayInfo();
    }
}

void Library::displayAllUsers() {
    std::cout << "===Список пользователей===" << std::endl;
    for (int i = 0; i < users.size(); i++) {
        users[i].displayProfile();
    }
}

void Library::saveToFile() {
    std::ofstream out("./data/" + datafile);
    if (!out.is_open()) {
        out.open(datafile);
    }

    if (out.is_open()) {
        for (int i = 0; i < books.size(); i++) {
            out << "BOOK" << std::endl;
            out << "Title: " << books[i].GetTitle() << std::endl;
            out << "Author: " << books[i].GetAuthor() << std::endl;
            out << "Year: " << books[i].GetYear() << std::endl;
            out << "ISBN: " << books[i].GetISBN() << std::endl;
            out << "Avaliable: " << (books[i].GetAvaliable() ? "yes" : "no") << std::endl;
            out << "BorrowedBy: " << books[i].GetBorrowedby() << std::endl;
        }
        out << "---USERS---" << std::endl;
        for (int i = 0; i < users.size(); i++) {
            out << "USER" << std::endl;
            out << "Name: " << users[i].GetName() << std::endl;
            out << "UserID: " << users[i].GetUserId() << std::endl;
            out << "BorrowedBooks: ";

            
            std::vector<std::string> bBooks = users[i].GetBorrowedBooks();
            for (int j = 0; j < bBooks.size(); j++) {
                out << bBooks[j];
                if (j < bBooks.size() - 1) {
                    out << "|";
                }
            }
            out << std::endl;
            out << "MaxBooks: " << users[i].GetMaxBooksAllowed() << std::endl;
        }
    }
    out.close();
}

void Library::loadFromFile() {
    std::ifstream in("./data/" + datafile);
    if (!in.is_open()) {
        in.open(datafile);
    }

    if (in.is_open()) {
        std::string line;
        std::string title_p, author_p, isbn_p, borrowedby_p;
        int year_p;
        bool avaliable_p;
        
        std::string name_u, userid;
        int maxbooks;

        while (getline(in, line)) {
            if (line == "BOOK") {
                getline(in, line); title_p = line.substr(7);
                getline(in, line); author_p = line.substr(8);
                
                getline(in, line); 
                if(line.size() > 6) year_p = std::stoi(line.substr(6));
                else year_p = 0;

                getline(in, line); isbn_p = line.substr(6);
                getline(in, line); avaliable_p = (line.substr(11) == "yes");
                getline(in, line); borrowedby_p = line.substr(12);

                books.push_back(Book(title_p, author_p, year_p, isbn_p, avaliable_p, borrowedby_p));
            }
            else if (line == "USER") {
                std::vector<std::string> borowedBook;
                
                getline(in, line); name_u = line.substr(6);
                getline(in, line); userid = line.substr(8);
                
                getline(in, line);
                std::string bstr = line.substr(15); 
                
                if (!bstr.empty()) {
                    std::stringstream ss(bstr);
                    std::string segment;
                    while(std::getline(ss, segment, '|')) {
                        if(!segment.empty()){
                            borowedBook.push_back(segment);
                        }
                    }
                }

                getline(in, line); 
                maxbooks = std::stoi(line.substr(10));
                
                users.push_back(User(name_u, userid, borowedBook, maxbooks));
            }
        }
    }
    in.close();
}