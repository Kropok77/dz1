#include <iostream>
#include <cstdlib> 
#include <limits>  
#include "Library.h"

using namespace std;
using namespace myLibrary;

void clean() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void space_zad() {
    cout << "\nНажмите Enter, чтобы вернуться в меню...";

    if (cin.peek() == '\n') {
        cin.ignore();
    }
    cin.get(); 
}

int main() {
    Library liba;
    int key = 0;

    do {
        clean(); 

        cout << "=== БИБЛИОТЕКА ===" << endl;
        cout << "1. Посмотреть все книги" << endl;
        cout << "2. Просмотреть всех пользователей" << endl;
        cout << "3. Добавить новую книгу" << endl;
        cout << "4. Зарегистрировать пользователя" << endl;
        cout << "5. Выдать книгу пользователю" << endl;
        cout << "6. Принять книгу от пользователя" << endl;
        cout << "7. Поиск книги по ISBN" << endl;
        cout << "8. Просмотреть профиль пользователя" << endl;
        cout << "9. Сохранить данные в файл" << endl;
        cout << "10. Выход" << endl;
        cout << "Ваш выбор: ";

        if (!(cin >> key)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        string name_p1, auth_p1, isbn_p1, userid, name_u;
        int year;
        Book* foundBook = nullptr;
        User* foundUser = nullptr;

        switch (key) {
        case 1:
            clean(); 
            liba.displayAllBooks();
            space_zad(); 
            break;

        case 2:
            clean(); 
            liba.displayAllUsers();
            space_zad();
            break;

        case 3:
            clean(); 
            cout << "=== Добавление книги ===" << endl;
            cin.ignore(); 
            
            cout << "Название книги: ";
            getline(cin, name_p1);
            
            cout << "Автор: ";
            getline(cin, auth_p1);
            
            cout << "ISBN: ";
            cin >> isbn_p1;
            
            cout << "Год выпуска: ";
            cin >> year;
            liba.addBook(Book(name_p1, auth_p1, year, isbn_p1, true, ""));
           
            space_zad();
            break;

        case 4:
            clean();
            cout << "=== Регистрация пользователя ===" << endl;
            cin.ignore();
            
            cout << "Имя пользователя: ";
            getline(cin, name_u);
            
            cout << "UserID: ";
            cin >> userid;
            
            liba.addUser(User(name_u, userid, {}, 3));
            
            space_zad();
            break;

        case 5:
            clean();
            cout << "=== Выдать книгу ===" << endl;
            cin.ignore();
            
            cout << "Имя пользователя: ";
            getline(cin, name_u);
            
            cout << "ISBN книги: ";
            cin >> isbn_p1;
            
            liba.borrowBook(name_u, isbn_p1);
            
            space_zad(); 
            
            break;

        case 6:
            clean();
            cout << "=== Сдать книгу ===" << endl;
            cout << "ISBN книги: ";
            cin >> isbn_p1;
            
            liba.returnBook(isbn_p1);
            space_zad();
            break;

        case 7:
            clean();
            cout << "=== Найти книгу по ISBN ===" << endl;
            cout << "ISBN книги: ";
            cin >> isbn_p1;
            
            cout << endl;
            foundBook = liba.findBookByISBN(isbn_p1);
            if (foundBook != nullptr) {
                foundBook->displayInfo();
            } else {
                cout << "Книга не найдена." << endl;
            }
            space_zad();
            break;

        case 8:
            clean();
            cout << "=== Профиль пользователя ===" << endl;
            cin.ignore();
            cout << "Имя пользователя: ";
            getline(cin, name_u);
            
            cout << endl;
            foundUser = liba.findUserByName(name_u);
            if (foundUser != nullptr) {
                foundUser->displayProfile();
            } else {
                cout << "Пользователь не найден." << endl;
            }
            space_zad();
            break;

        case 9:
            clean();
            liba.saveToFile();
            cout << "Успешно" << endl;
            space_zad();
            break;

        case 10:
            clean();
            liba.saveToFile(); 
            break; 

        default:
            clean();
            cout << "Неверный ответ" << endl;
            space_zad();
        }

    } while (key != 10);

    return 0;
}