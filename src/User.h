#ifndef User_h
#define User_h
#include <string>
#include <vector>
namespace UserLib{
    class User{
       private:
        std::string name;
        std::string userId;
        std::vector<std::string> borrowedbooks;
        int maxbooksallowed;
       public:
        User();
        User(std::string name_p,std::string userId_p,std::vector<std::string> borrowedbooks_p,int maxbooksallowed_p);
        ~User();
        const std::string& GetName() const;
        const std::string& GetUserId() const;
        const std::vector<std::string>& GetBorrowedBooks() const;
        const int& GetMaxBooksAllowed() const;
        const bool canBorrowMore(); 
        void addBook(const std::string& isbn);
        void removeBook(const std::string& isbn);
        void displayProfile();
    };
       
}
#endif