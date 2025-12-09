
#ifndef BOOK_K
#define BOOK_K
#include<string>
namespace mybooklib{
class Book {
   private:
    std::string title;
    std::string author;
    int year;
    std::string isbn;
    bool isAvaliable;
    std::string borrowedBy;
   public:
    Book();
    ~Book();
    Book(std::string name_p,std::string auth_p,int year_p,std::string isbn_p,bool isavaliable_p,std::string borrowedby_p);
     std::string GetTitle() const;
     std::string GetAuthor() const;
     int GetYear() const;
     std::string GetISBN() const;
     std::string GetBorrowedby() const;
    bool GetAvaliable() const;
    
    void borrowBook(const std::string& userName);//выдать книгу
    void returnBook();//вернуть книгу
    void displayInfo();//вывести информацию о книге в консоль
};
}
#endif 