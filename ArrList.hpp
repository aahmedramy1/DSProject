
#ifndef ArrList_hpp
#define ArrList_hpp

#include <stdio.h>

template <class T>
class ArrList
{
    T* arr;
    int size, count;
public:
    ArrList();
    int Length();
    void Append(T);
    void Expand();
    T At(int);
    void insertAt(int, T);
    void deleteAt(int);
    ~ArrList();
};

#endif /* ArrList_hpp */
