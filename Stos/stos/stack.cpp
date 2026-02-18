// template <class T>
// StackItem<T>::StackItem( T key, StackItem<T>* pNext ) {
// 
//     mKey = key;
//     m_pNext = pNext;
// }
// template <class T>
// StackItem<T>::~StackItem() 
// {
// 
//    
// }
// template <class T>
// T StackItem<T>::getKey() const 
// {
// 
//     return mKey;
// }
// 
// template <class T>
// void StackItem<T>::setKey( T key ) 
// {
//     mKey=key;
// }
// template <class T>
// StackItem<T>* StackItem<T>::getNext() const 
// {
//     return m_pNext;
// }
// 
// template <class T>
// void StackItem<T>::setNext( StackItem<T>* pNext ) 
// {
//     m_pNext = pNext;
// }
// template <class T>
// Stack<T>::Stack() 
// {
// 
//     m_pHead = nullptr;
// }
// 
// template <class T>
// Stack<T>::~Stack() 
// {
//     while( !isEmpty())
//         del();
// }
// 
// template <class T>
// bool Stack<T>::isEmpty() const 
// {
//     return !m_pHead;
// }
// 
// template <class T>
// void Stack<T>::push( T key ) 
// {
//     StackItem<T>* p = new StackItem<T>( key, m_pHead );
//     m_pHead = p;
// }
// 
// template <class T>
// T Stack<T>::top() const 
// {
//     if( isEmpty())
//         throw StackException( STACK_UNDERFLOW );
// 
//     return m_pHead->getKey();
// }
// 
// template <class T>
// void Stack<T>::del() 
// {
//     if( isEmpty())
//         throw StackException( STACK_UNDERFLOW );
// 
//     StackItem<T>* p = m_pHead;
//     m_pHead = m_pHead->getNext();
//     delete p;
// }
// 
// template <class T>
// T Stack<T>::pop() 
// {
// if( isEmpty())
//         throw StackException( STACK_UNDERFLOW );
// 
//     T Key = m_pHead->getKey();
//     del();
//     return Key;
// }