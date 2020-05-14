#ifndef __ITERATOR_
#define __ITERATOR_

#include <iostream>
#include <cstddef>

template <class T>
class C_Iterator;
template <class T>
class CR_Iterator;

template< class T >
class Iterator
{
    T* ptr;
public:
    friend class C_Iterator<T>;
    Iterator(){}
    Iterator(const Iterator& it): ptr(it.ptr){}
    Iterator(T* t): ptr(t){}

    Iterator base() const 
    {
        return *this;
    }

    T& operator *() const { return *ptr; }
    Iterator& operator =(const Iterator& it)
    {
        ptr = it.ptr;
        return *this;
    }

    Iterator operator +(int n) const
    {
        return ptr+n;
    }
    Iterator& operator ++() 
    {
        ++ptr;
        return *this;
    }
    Iterator operator ++(int)
    {
        Iterator temp(ptr);
        ++ptr;
        return temp;
    }
    Iterator& operator +=(int n)
    {
        ptr += n;
        return *this;
    }

    Iterator operator -(int n) const 
    {
        return ptr-n;
    }
    int operator -(T* t) const 
    {
        return ptr-t;
    }
    int operator -(const Iterator& it) const
    {
        return ptr-it.ptr;
    }
    Iterator& operator --()
    {
        --ptr;
        return *this;
    }
    Iterator operator --(int)
    {
        Iterator temp(ptr);
        --ptr;
        return temp;
    }
    Iterator operator -=(int n)
    {
        ptr -= n;
        return *this;
    }

    T& operator [](int n) const 
    {
        return *(ptr + n);
    }

    bool operator == (const Iterator& rhs) const { return ptr == rhs.ptr; }
    bool operator != (const Iterator& rhs) const { return ptr != rhs.ptr; }
    bool operator <(const Iterator& rhs) const { return ptr < rhs.ptr; }
    bool operator <=(const Iterator& rhs) const { return ptr <= rhs.ptr; }
    bool operator >(const Iterator& rhs) const { return ptr > rhs.ptr; }
    bool operator >=(const Iterator& rhs) const { return ptr >= rhs.ptr; }

    ~Iterator(){}
};

template< class T >
class R_Iterator 
{
    T* ptr;
public:
    R_Iterator(){}
    R_Iterator(const R_Iterator& it): ptr(it.ptr){}
    R_Iterator(T* t): ptr(t){}

    Iterator<T> base() const 
    {
        return Iterator<T>(ptr+1);
    }
    T& operator *() const { return *ptr; }
    R_Iterator& operator =(const R_Iterator& it)
    {
        ptr = it.ptr;
        return *this;
    }

    R_Iterator operator +(int n) const
    {
        return ptr-n;
    }
    R_Iterator& operator ++() 
    {
        --ptr;
        return *this;
    }
    R_Iterator operator ++(int)
    {
        R_Iterator temp(ptr);
        --ptr;
        return temp;
    }
    R_Iterator& operator +=(int n)
    {
        ptr -= n;
        return *this;
    }

    R_Iterator operator -(int n) const 
    {
        return ptr+n;
    }
    int operator -(T* t) const 
    {
        return t-ptr;
    }
    int operator -(const R_Iterator& it) const
    {
        return it.ptr-ptr;
    }
    R_Iterator& operator --()
    {
        ++ptr;
        return *this;
    }
    R_Iterator operator --(int)
    {
        R_Iterator temp(ptr);
        ++ptr;
        return temp;
    }
    R_Iterator operator -=(int n)
    {
        ptr += n;
        return *this;
    }

    T& operator [](int n) const 
    {
        return *(ptr + n);
    }

    bool operator == (const R_Iterator& rhs) const { return ptr == rhs.ptr; }
    bool operator != (const R_Iterator& rhs) const { return ptr != rhs.ptr; }
    bool operator <(const R_Iterator& rhs) const { return ptr > rhs.ptr; }
    bool operator <=(const R_Iterator& rhs) const { return ptr >= rhs.ptr; }
    bool operator >(const R_Iterator& rhs) const { return ptr < rhs.ptr; }
    bool operator >=(const R_Iterator& rhs) const { return ptr <= rhs.ptr; }

    ~R_Iterator(){}
};

template< class T >
class C_Iterator
{
    const T* ptr;
public:
    C_Iterator(){}
    C_Iterator(const C_Iterator& it): ptr(it.ptr){}
    C_Iterator(Iterator<T> it): ptr(it.ptr){}
    C_Iterator(const T* t): ptr(t){}

    Iterator<T> base() const 
    {
        return Iterator<T>((T*)(ptr));
    }

    const T& operator *() const { return *ptr; }
    C_Iterator& operator =(const C_Iterator& it)
    {
        ptr = it.ptr;
        return *this;
    }

    C_Iterator operator +(int n) const
    {
        return ptr+n;
    }
    C_Iterator& operator ++() 
    {
        ++ptr;
        return *this;
    }
    C_Iterator operator ++(int)
    {
        C_Iterator temp(ptr);
        ++ptr;
        return temp;
    }
    C_Iterator& operator +=(int n)
    {
        ptr += n;
        return *this;
    }

    C_Iterator operator -(int n) const 
    {
        return ptr-n;
    }
    int operator -(const C_Iterator& it) const
    {
        return ptr-it.ptr;
    }
    C_Iterator& operator --()
    {
        --ptr;
        return *this;
    }
    C_Iterator operator --(int)
    {
        C_Iterator temp(ptr);
        --ptr;
        return temp;
    }
    C_Iterator operator -=(int n)
    {
        ptr -= n;
        return *this;
    }

    const T& operator [](int n) const 
    {
        return *(ptr + n);
    }

    bool operator == (const C_Iterator& rhs) const { return ptr == rhs.ptr; }
    bool operator != (const C_Iterator& rhs) const { return ptr != rhs.ptr; }
    bool operator <(const C_Iterator& rhs) const { return ptr < rhs.ptr; }
    bool operator <=(const C_Iterator& rhs) const { return ptr <= rhs.ptr; }
    bool operator >(const C_Iterator& rhs) const { return ptr > rhs.ptr; }
    bool operator >=(const C_Iterator& rhs) const { return ptr >= rhs.ptr; }

    ~C_Iterator(){}
};
template< class T >
class CR_Iterator
{
    const T* ptr;
public:
    CR_Iterator(){}
    CR_Iterator(const CR_Iterator& it): ptr(it.ptr){}
    CR_Iterator(Iterator<T> it): ptr(it.ptr){}
    CR_Iterator(const T* t): ptr(t){}

    Iterator<T> base() const
    {
        return Iterator<T>((T*)(ptr+1));
    }
    const T& operator *() const { return *ptr; }
    CR_Iterator& operator =(const CR_Iterator& it)
    {
        ptr = it.ptr;
        return *this;
    }

    CR_Iterator operator +(int n) const
    {
        return ptr-n;
    }
    CR_Iterator& operator ++() 
    {
        --ptr;
        return *this;
    }
    CR_Iterator operator ++(int)
    {
        CR_Iterator temp(ptr);
        --ptr;
        return temp;
    }
    CR_Iterator& operator +=(int n)
    {
        ptr -= n;
        return *this;
    }

    CR_Iterator operator -(int n) const 
    {
        return ptr+n;
    }
    int operator -(const CR_Iterator& it) const
    {
        return it.ptr-ptr;
    }
    CR_Iterator& operator --()
    {
        ++ptr;
        return *this;
    }
    CR_Iterator operator --(int)
    {
        CR_Iterator temp(ptr);
        ++ptr;
        return temp;
    }
    CR_Iterator operator -=(int n)
    {
        ptr += n;
        return *this;
    }

    const T& operator [](int n) const 
    {
        return *(ptr + n);
    }

    bool operator == (const CR_Iterator& rhs) const { return ptr == rhs.ptr; }
    bool operator != (const CR_Iterator& rhs) const { return ptr != rhs.ptr; }
    bool operator <(const CR_Iterator& rhs) const { return ptr > rhs.ptr; }
    bool operator <=(const CR_Iterator& rhs) const { return ptr >= rhs.ptr; }
    bool operator >(const CR_Iterator& rhs) const { return ptr < rhs.ptr; }
    bool operator >=(const CR_Iterator& rhs) const { return ptr <= rhs.ptr; }

    ~CR_Iterator(){}
};
#endif


