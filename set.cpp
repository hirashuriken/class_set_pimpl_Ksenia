#include "set.h"

class Set::SetImplementation{

    int n;
    int *elements_set;

    int a;
    int *b;

public:

    SetImplementation();
    SetImplementation(const SetImplementation &equally); //конструктор копирования
    ~SetImplementation();

    friend ostream& operator<<(ostream &out ,const SetImplementation &a);
    friend istream& operator>>(istream &in,SetImplementation &a);

    SetImplementation operator+(const SetImplementation &unio) const;
    SetImplementation operator=(const SetImplementation &equally);
    SetImplementation operator*(const SetImplementation &intersect) const;
    SetImplementation operator-(const SetImplementation &differ) const;

    int getN()const;
    int *getE()const;

};

////////////////////


Set::Set():
   pimpl(0)
{
   pimpl = new SetImplementation();
}


Set::Set(const Set &equally):
    pimpl(0)
{
   pimpl = new SetImplementation(*(equally.pimpl));
}

Set::~Set()
{
   delete pimpl;
   pimpl = 0;
}


int Set::getN()const
{
   return pimpl->getN();
}

int *Set::getE()const
{
   return pimpl->getE();
}

////////////////////////

Set Set::operator=(const Set &equally){
    *(this->pimpl) = *(equally.pimpl);
    return *this;
}

Set Set::operator*(const Set &intersect) const{
    Set x;
    *(x.pimpl) = *(pimpl) * *(intersect.pimpl);
    return x;
}

Set Set::operator-(const Set &differ) const{
    Set x;
    *(x.pimpl) = *(pimpl) - *(differ.pimpl);
    return x;
}

///////////////////////////

Set::SetImplementation::SetImplementation():
    elements_set(0),n(0)
{
};

Set::SetImplementation::~SetImplementation(){
    delete[]elements_set;
    elements_set=0;
}

Set::SetImplementation::SetImplementation(const SetImplementation &equally){

    n = equally.n;

    elements_set = NULL;

    elements_set = new int[n];

    for (int i=0; i<n; ++i)
        elements_set[i] = equally.elements_set[i];
}

//////////////////////////////////

Set::SetImplementation Set::SetImplementation::operator+(const SetImplementation &unio) const{
    int r=0,N=n;
    int *c = new int[n+unio.n];

    for (int i=0; i<n+unio.n; ++i){
        c[i] = elements_set[i];
    }

    for (int l=0; l<unio.n; ++l){
        int k=0;
        for (int j=0; j<n; ++j){
            if (unio.elements_set[l] == c[j])
                ++k;
        }
        if (!k){
            c[n+r] = unio.elements_set[l];
            ++r;++N;
        }
    }

    SetImplementation x;
    x.elements_set = new int[N];
    x.n = N;
    for(int i = 0; i < N; ++i)
        x.elements_set[i] = c[i];
    return x;
}

Set::SetImplementation Set::SetImplementation::operator=(const SetImplementation &equally){

    n = equally.n;

    if (elements_set)
    delete []elements_set;

    elements_set = new int[n];

    for (int i=0; i<n; ++i)
        elements_set[i] = equally.elements_set[i];

    return *this;
}

Set::SetImplementation Set::SetImplementation::operator*(const SetImplementation &intersect) const{
    int N=0,r=0;
    int *c = new int[n+intersect.n];

    for (int i=0; i<intersect.n; ++i){
        int k=0;
        for (int j=0; j<n; ++j){
            if (elements_set[i] == intersect.elements_set[j])
                ++k;
        }
        if (k){
            c[r] = elements_set[i];
            ++N;++r;
        }
    }

    SetImplementation x;
    x.elements_set = new int[N];
    x.n = N;
    for(int i = 0; i < N; ++i)
        x.elements_set[i] = c[i];
    return x;
}

Set::SetImplementation Set::SetImplementation::operator-(const SetImplementation &differ) const{

    int r=0,N=0;
    int *c = new int[n+differ.n];

    for (int i=0; i<n; ++i){
        int k=0;
        for (int j=0; j<differ.n; ++j){
            if (elements_set[i] == differ.elements_set[j])
                ++k;
        }
        if (!k){
            c[r] = elements_set[i];
            ++r;++N;
        }
    }

    SetImplementation x;
    x.elements_set = new int[N];
    x.n = N;
    for(int i = 0; i < N; ++i)
        x.elements_set[i] = c[i];
    return x;
}


int Set::SetImplementation::getN()const
{
   return a;
}

int *Set::SetImplementation::getE()const
{
   return b;
}


