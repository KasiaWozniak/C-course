#include <iostream>
#include <utility>
using namespace std;

#include "user.h"
#include "linux.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

string Linux::distribution() {
    return distribution_;
  //  return this->distribution_;
}

size_t Linux::open_source_sympathizers_=0;

size_t Linux::open_source_sympathizers() {
    return Linux::open_source_sympathizers_;
}

Linux::Linux() {
    cout<< "+" << distribution_ << '\n';
    open_source_sympathizers_++;
}

Linux::Linux(string distribution) {
    distribution_=distribution;
    cout<< "+" << distribution_ << '\n';
    open_source_sympathizers_++;
}

Linux::~Linux() {
    open_source_sympathizers_--;
    cout<< "~" << distribution_ << '\n';
}

int Linux::add_user(string user_name, string password) {
    User Nowy;
    Nowy.user_name_=user_name;
    Nowy.password_=password;
    users_.push_back(Nowy);

    return users_.size()-1 ;
}

User Linux::user(int user_id) {
    return users_[user_id];
}

string Linux::user_home_directory(int user_id) {
    return "/home/" + user(user_id).user_name_ + "/";
}


const optional<string> Linux::graphic_environment(){
    return graphic_environment_;
};
optional<string> Linux::set_graphic_environment(string graphic){
    graphic_environment_ = graphic;
};