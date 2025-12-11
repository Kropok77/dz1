#include "User.h"
#include <iostream>
#include <algorithm> 

using namespace UserLib;

User::User()
    : name(""), userId(""), borrowedbooks({}), maxbooksallowed(3) {
}

User::User(std::string name_p, std::string userId_p, std::vector<std::string> borrowedbooks_p, int maxbooksallowed_p)
    : name(name_p), userId(userId_p), borrowedbooks(borrowedbooks_p), maxbooksallowed(maxbooksallowed_p) {
}

User::~User() {
    borrowedbooks.clear();
}

const std::string& User::GetName() const { return name; }
const std::string& User::GetUserId() const { return userId; }
const std::vector<std::string>& User::GetBorrowedBooks() const { return borrowedbooks; }
const int& User::GetMaxBooksAllowed() const { return maxbooksallowed; }

const bool User::canBorrowMore() {
    return borrowedbooks.size() < maxbooksallowed;
}

void User::addBook(const std::string& isbn) {
    borrowedbooks.push_back(isbn);
}

void User::removeBook(const std::string& isbn) {
    borrowedbooks.erase(
        std::remove(borrowedbooks.begin(), borrowedbooks.end(), isbn),
        borrowedbooks.end()
    );
}

void User::displayProfile() {
    std::cout << "Имя: " << name<<std::endl;
    std::cout<<"ID: " << userId << std::endl;
    std::cout << "Книг: " << borrowedbooks.size() << " / " << maxbooksallowed << std::endl;
    if (!borrowedbooks.empty()) {
        std::cout << "Список ISBN:" << std::endl;
        for (const auto& book : borrowedbooks) {
            std::cout << " - " << book << std::endl;
        }
    }
    std::cout<<std::endl;
}