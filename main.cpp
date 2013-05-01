#include <iostream>
#include "set.h"

using namespace std;

class ConSet: public Set{

   public:
      ConSet();
      ConSet(const ConSet &original);
      ConSet &operator=(const ConSet &equally);
      ~ConSet();

      friend ostream &operator<<(ostream &out, const ConSet &a);
};

ConSet::ConSet():
   Set()
{

}

ConSet::ConSet(const ConSet &equally):
   Set()
{

}

ConSet &ConSet::operator=(const ConSet &equally)
{
   Set::operator=(equally);
   return *this;
}

ConSet::~ConSet()
{

}

ostream &operator<<(ostream &out, const ConSet &a)
{
    int n = a.getN();
    int *elements_set = a.getE();
    for (int i=0; i<n; ++i){
        out << elements_set[i] << ' ';
    }
    out << endl;
    return out;
}


int main(){
    Set a,b,c;

    cout<<"Enter the number of elements and the first set"<<endl;
    cin>>a;
    cout<<endl;

    cout<<"Enter the number of elements and the second set"<<endl;
    cin>>b;
    cout<<endl;

    c = a+b;
    cout<<"Union sets"<<endl;
    cout<<c;
    cout<<endl;

    c=a*b;
    cout<<"Intersection sets"<<endl;
    cout<<c;
    cout<<endl;

    c=a-b;
    cout<<"Difference sets(1-2)"<<endl;
    cout<<c;
    cout<<endl;

    c=b-a;
    cout<<"Difference sets(2-1)"<<endl;
    cout<<c;
    cout<<endl;

    return 0;
}
