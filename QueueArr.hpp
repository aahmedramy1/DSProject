//
//  QueueArr.hpp
//  ProjectTest
//
//  Created by Ahmed Ramy on 21/05/2022.
//

#ifndef QueueArr_hpp
#define QueueArr_hpp
#include <stdio.h>

template <class T>
class QueueArr
{
    T* arr;
    int count, size;
    int front, back;
public:
    QueueArr();
    int length();
    void enqueue(T);
    void dequeue();
    T Front();
    bool empty();
    bool full();
    ~QueueArr();
};

#endif /* QueueArr_hpp */
