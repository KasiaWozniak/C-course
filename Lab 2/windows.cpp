#include <iostream>
using namespace std;

#include "user.h"
#include "windows.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

string Windows::version() {
    return version_;
}

size_t Windows::activated_systems_=0;

size_t Windows::activated_systems() {
    return Windows::activated_systems_;
}

Windows::Windows() {
    ++activated_systems_;
    cout<< "Windows " << version_ << '\n';
}

Windows::Windows(string version) {
    version_=version;
    ++activated_systems_;
    cout<< "Windows " << version_ << '\n';
}

int Windows::add_user(string user_name, string password) {
    User Nowy;
    Nowy.user_name_=user_name;
    Nowy.password_=password;
    users_.push_back(Nowy);
    return users_.size()-1;
}

User Windows::user(int user_id) {
    return users_[user_id];
}

string Windows::user_home_directory(int user_id) {
    return "C:\\Users\\" + user(user_id).user_name_;
}
