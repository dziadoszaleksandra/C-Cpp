#pragma once
#include <iostream>
using namespace std;

#define STACK_UNDERFLOW 0x01
#define STACK_OVERFLOW  0x02
#define OTHER_ERROR     0x00

class StackException 
{
public:
    StackException( int errCode = OTHER_ERROR ) : mErrCode(errCode) {}
    const char* getReason();
private:
    int mErrCode;
};

inline const char* StackException::getReason() 
{
    switch ( mErrCode ) 
    {
    case STACK_UNDERFLOW: return "ERROR: Stack underflow!";
    case STACK_OVERFLOW:  return "ERROR: Stack overflow!";
    default:              return "ERROR: Undefined error!";
    }
}

template <class T>
class Stack;

template <class T>
class StackItem 
{
private:
    T mKey;
    StackItem<T>* m_pNext;
private:
    StackItem( T key, StackItem<T>* next );
    ~StackItem();
    T getKey() const;
    void setKey(T key);
    StackItem<T>* getNext() const;
    void setNext( StackItem<T>* next );
    friend class Stack<T>;  
};

template <class T>
class Stack 
{
private:
    StackItem<T>* m_pHead;
public:
    Stack();
    ~Stack();
    void push(T key);
    T pop();
    T top() const;
    bool isEmpty() const;
    void del();
};

template <class T>
StackItem<T>::StackItem(T key, StackItem<T>* pNext) 
{
    mKey = key;
    m_pNext = pNext;
}

template <class T>
StackItem<T>::~StackItem() 
{

}

template <class T>
T StackItem<T>::getKey() const 
{
    return mKey;
}
template <class T>
void StackItem<T>::setKey(T key) 
{
    mKey = key;
}
template <class T>
StackItem<T>* StackItem<T>::getNext() const 
{
    return m_pNext;
}

template <class T>
void StackItem<T>::setNext(StackItem<T>* pNext) 
{
    m_pNext = pNext;
}

template <class T>
Stack<T>::Stack() 
{
    m_pHead = nullptr;
}

template <class T>
Stack<T>::~Stack() 
{
    while (!isEmpty())
        del();          
}

template <class T>
bool Stack<T>::isEmpty() const 
{
    return !m_pHead;
}

template <class T>
void Stack<T>::push(T key) 
{
    StackItem<T>* p = new(nothrow) StackItem<T>(key, m_pHead);
    if (!p)
        throw StackException( STACK_OVERFLOW );
    m_pHead = p;
}

template <class T>
T Stack<T>::top() const 
{
    if (isEmpty())
        throw StackException( STACK_UNDERFLOW );
    return m_pHead->getKey();
}

template <class T>
void Stack<T>::del() 
{
    if (isEmpty())
        throw StackException( STACK_UNDERFLOW );
    StackItem<T>* p = m_pHead;
    m_pHead = m_pHead->getNext();
    delete p;
}

template <class T>
T Stack<T>::pop() 
{
    if (isEmpty())
        throw StackException( STACK_UNDERFLOW );
    T Key = top();// m_pHead->getKey();
    del();
    return Key;
}
