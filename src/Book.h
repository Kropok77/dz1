
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
    Book(std::string name_p,std::string auth_p,int year_p,std::string isbn_p,bool isavaliable_p,std::string borrowedby_p);
    const std::string& GetTitle() const;
    const  std::string& GetAuthor() const;
    const int& GetYear() const;
    const std::string& GetISBN() const;
    const std::string& GetBorrowedby() const;
    const bool& GetAvaliable() const;
    
    void borrowBook(const std::string& userName);
    void returnBook();
    void displayInfo();
};
}//
#endif 