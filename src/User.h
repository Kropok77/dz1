#ifndef User_h
#define User_h
#include <string>
#include <vector>
namespace UserLib{
    class User{
       private:
        std::string name;
        std::string userId;
        std::vector<std::string> borrowedbooks;//список выданных книг
        int maxbooksallowed;//максимум книг которые можно взять(Обычно 3)
       public:
        User();
        User(std::string name_p,std::string userId_p,std::vector<std::string> borrowedbooks_p,int maxbooksallowed_p);
        ~User();
        std::string GetName() const;
        std::string GetUserId() const;
        std::vector<std::string> GetBorrowedBooks() const;
        int GetMaxBooksAllowed() const;
        bool canBorrowMore(); //проверка можно ли взять книгу
        void addBook(const std::string& isbn);//добавить книгу пользователю
        void removeBook(const std::string& isbn);//убрать книгу от пользователя
        void displayProfile();
    };
       
}
#endif;