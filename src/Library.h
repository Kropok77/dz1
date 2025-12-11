#ifndef Library_h
#define Library_h
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"
using namespace UserLib;
using namespace mybooklib;
namespace myLibrary{
    class Library{
       private:
        std::vector<Book> books;
        std::vector<User> users;
        std::string datafile;
       public:
        Library();
        ~Library();
        void addBook(const Book& book);
        void addUser(const User& user);
        void borrowBook(const std::string& userName, const std::string& isbn);
        void returnBook(const std::string& isbn);
        Book* findBookByISBN(const std::string& isbn);
        User* findUserByName(const std::string& name);
        void displayAllBooks();
        void displayAllUsers();
        void saveToFile();
        void loadFromFile();
    };
}
#endif