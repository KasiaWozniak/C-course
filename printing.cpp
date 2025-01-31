#include <iostream>
#include <iterator> // ostream_iterator
#include <cstring>
#include <cctype>

using namespace std;

#include "printing.h"

#ifdef UNIMPLEMENTED_classFraction
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // UNIMPLEMENTED_classFraction

void print (int c){
cout << c << endl;
}

void print(double r){
    cout << r << endl;
}

void print(Fraction ulamek){
    cout << ulamek.numerator_ << "/" << ulamek.denominator_ << endl;
}

void print(const char *tekst){
    cout << tekst << endl;
}

void print(const NotCopyableType &obiekt){
    cout << obiekt.number_ << endl;
}

void print(const int tab[], int size){
    for (int i=0; i<size; i++) {
        cout << tab[i];
        if (i != size - 1) cout << ", ";
    }
    cout << endl;
}

void print(){
    cout << endl;
}