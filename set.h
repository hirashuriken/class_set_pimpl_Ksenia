#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

class Set {

public:

    Set();
    Set(const Set &equally); //конструктор копирования
    ~Set();

    friend ostream& operator<<(ostream &out ,const Set &a);
    friend istream& operator>>(istream &in,Set &a);

    Set operator+(const Set &unio) const;
    Set operator=(const Set &equally);
    Set operator*(const Set &intersect) const;
    Set operator-(const Set &differ) const;

protected:
      int getN()const;
      int *getE()const;

private:

    class SetImplementation;
    SetImplementation *pimpl;




};

#endif // SET_H
