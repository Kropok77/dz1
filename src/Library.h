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
        std::vector<Book> books;//каталог книг
        std::vector<User> users;//список зарегестрированных пользователей
        std::string datafile;
       public:
        Library();
        ~Library();
        void addBook(const Book& book);//добавить книгу
        void addUser(const User& user);//зарегестрировать пользователя
        void borrowBook(const std::string& userName, const std::string& isbn);//выдать книгу пользователю
        void returnBook(const std::string& isbn);//принять книгу от пользоваетеля
        Book* findBookByISBN(const std::string& isbn);// найти книгу по ISBN (может вернуть nullptr)
        User* findUserByName(const std::string& name);//найти пользователя по фамилии
        void displayAllBooks();// вывести каталог всех книг
        void displayAllUsers();//вывести список всех пользователей
        void saveToFile();// сохранить состояние библиотеки в файл
        void loadFromFile();// загрузить состояние из файла
    };
}
#endif;