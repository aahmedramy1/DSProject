
#include "ArrList.hpp"
#include <cassert>

template <class T>
ArrList<T>::ArrList()
{
    size=5;
    arr=new T[size];
    count=0;
}

template <class T>
int ArrList<T>::Length()
{
    return count;
}

template <class T>
void ArrList<T>::Append(T val)
{
    if(count==size)
        Expand();
    arr[count]=val;
    count++;
}

template <class T>
void ArrList<T>::Expand()
{
    size*=2;
    T* tmp=new T[size];
    for(int i=0; i<count;i++)
        tmp[i]=arr[i];
    delete arr;
    arr=tmp;
}

template <class T>
T ArrList<T>::At(int pos)
{
    assert(pos<count);
    return arr[pos];
}

template <class T>
void ArrList<T>::insertAt(int pos, T val)
{
    assert(pos<count);
    if(count==size)
        Expand();
    for(int i=count;i>pos; i--)
        arr[i]=arr[i-1];
    arr[pos]=val;
    count++;
}

template <class T>
void ArrList<T>::deleteAt(int pos)
{
    assert(pos<count);
    for(int i=pos;i<count-1;i++)
        arr[i]=arr[i+1];
    count--;
}

template <class T>
ArrList<T>::~ArrList()
{
    delete[] arr;
}
