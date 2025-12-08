#include <iostream>
#include "Library.h"
#include <ctype.h>
#include<cstdlib>
using namespace std;
int main(){
    int key=0;
    string vv;
    do{
        cout<<"=== БИБЛИОТЕКА ==="<<endl;
        cout<<"1. Посмотреть все книги"<<endl;
        cout<<"2. Просмотреть всех пользователей"<<endl;
        cout<<"3. Добавить новую книгу"<<endl;
        cout<<"4. Зарегистрировать пользователя"<<endl;
        cout<<"5. Выдать книгу пользователю"<<endl;
        cout<<"6. Принять книгу от пользователя"<<endl;
        cout<<"7. Поиск книги по ISBN"<<endl;
        cout<<"8. Просмотреть профиль пользователя"<<endl;
        cout<<"9. Сохранить данные в файл"<<endl;
        cout<<"10. Выход"<<endl;
        cout<<"Ваш выбор: ";
        cin>>vv;
        cout<<endl;
        int k=0;
        string si;
        for (char c : vv){
            if(!isdigit(c)){
                system("clear");
                cout<<"ERROR - incorrect input"<<endl;
                cout<<"Y+Enter for resume"<<endl;
                cin>>si;
                system("clear");
                k=1;
                break;
            }

        }
        if (k==1){
            continue;
        }
        key=stoi(vv);
        if (key<1 || key>10){
            system("clear");
        cout<<"ERROR - incorrect input"<<endl;
        cout<<"Y+Enter for resume"<<endl;
                cin>>si;
                system("clear");
        }
        
    }while(key!=10);
}