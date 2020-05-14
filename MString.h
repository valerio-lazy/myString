#ifndef __MSTRING_
#define __MSTRING_

#include <utility>
#include <iostream>
#include <cstring>
#include <initializer_list>
#include "MIterator.hpp"

#define _MAX_SIZE 1024

class MString;

class MString
{
    char* pointer_;
    size_t size_;
    size_t capacity_;

    void expand();  //重新开辟空间并拷贝源内容

public:
    static const size_t npos = -1;

    typedef size_t size_type;
    typedef Iterator<char> iterator;
    typedef R_Iterator<char> reverse_iterator;
    typedef C_Iterator<char> const_iterator;
    typedef CR_Iterator<char> const_reverse_iterator;

    friend MString operator +(const MString& lhs, const MString& rhs);
    friend MString operator +(MString&& lhs, MString&& rhs);
    friend MString operator +(MString&& lhs, const MString& rhs);
    friend MString operator +(const MString& lhs, MString&& rhs);
    friend MString operator +(const MString& lhs, const char* rhs);
    friend MString operator +(MString&& lhs, const char* rhs);
    friend MString operator +(const char* lhs, const MString& rhs);
    friend MString operator +(const char* lhs, MString&& rhs);
    friend MString operator +(const MString& lhs, char rhs);
    friend MString operator +(MString&& lhs, char rhs);
    friend MString operator +(char lhs, const MString& rhs);
    friend MString operator +(char lhs, MString&& rhs);
    friend std::istream& operator >>(std::istream& is, MString& ms);
    friend std::ostream& operator <<(std::ostream& os, const MString& ms);
    friend void swap(MString& x, MString& y);
    friend bool operator ==(const MString& lhs, const MString& rhs);
    friend bool operator ==(const char* lhs, const MString& rhs);
    friend bool operator ==(const MString& lhs, const char* rhs);
    friend bool operator !=(const MString& lhs, const MString& rhs);
    friend bool operator !=(const char* lhs, const MString& rhs);
    friend bool operator !=(const MString& lhs, const char* rhs);
    friend bool operator <(const MString& lhs, const MString& rhs);
    friend bool operator <(const char* lhs, const MString& rhs);
    friend bool operator <(const MString& lhs, const char* rhs);
    friend bool operator <=(const MString& lhs, const MString& rhs);
    friend bool operator <=(const char* lhs, const MString& rhs);
    friend bool operator <=(const MString& lhs, const char* rhs);
    friend bool operator >(const MString& lhs, const MString& rhs);
    friend bool operator >(const char* lhs, const MString& rhs);
    friend bool operator >(const MString& lhs, const char* rhs);
    friend bool operator >=(const MString& lhs, const MString& rhs);
    friend bool operator >=(const char* lhs, const MString& rhs);
    friend bool operator >=(const MString& lhs, const char* rhs);

    
//constructors:
    MString();
    MString(const MString& str);
    MString(const MString& str, size_t pos, size_t len = npos);
    MString(const char* s);
    MString(const char* s, size_t n);
    MString(size_t n, char c);
    template <class IT>
        MString(IT begin, IT end);
    MString(std::initializer_list<char> il);
    MString(MString&& str) noexcept;

    ~MString();

    MString& operator =(const MString& str);
    MString& operator =(const char* s);
    MString& operator =(char c);
    MString& operator =(std::initializer_list<char> il);
    MString& operator =(MString&& str) noexcept;
//iterators:
    iterator begin() noexcept;
    iterator end() noexcept;
    reverse_iterator rbegin() noexcept;
    reverse_iterator rend() noexcept;

    const_iterator begin() const noexcept ;
    const_iterator end() const noexcept ;
    const_reverse_iterator rbegin() const noexcept ;
    const_reverse_iterator rend() const noexcept ;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;

//capacities:
    size_t size() const noexcept{return size_;}
    size_t length() const noexcept{return size_;}
    size_t max_size() const noexcept{return npos;}
    size_t capacity() const noexcept{return capacity_;}
    bool empty() const noexcept{return size_ == 0;}
    void clear() noexcept;
    void resize(size_t n);
    void resize(size_t n, char c);
    void reserve(size_t n = 0);
    void shrink_to_fit();   //收缩容量

//element access:
    char& operator [](size_t pos);
    char& at(size_t pos);
    char& back();
    char& front();
    const char& operator [](size_t pos) const;
    const char& at(size_t pos) const;
    const char& back() const;
    const char& front() const;

//modifiers:
    // operator +=:
    MString& operator +=(const MString& str);
    MString& operator +=(const char* s);
    MString& operator +=(char c);
    MString& operator +=(std::initializer_list<char> il);
    // append:
    MString& append(const MString& str);
    MString& append(const MString& str, size_t subpos, size_t sublen);
    MString& append(const char* s);
    MString& append(const char* s, size_t n);
    MString& append(size_t n, char c);
    MString& append(std::initializer_list<char> il);
    template < class IT>
        MString& append(IT begin, IT end);

    // assign:
    MString& assign(const MString& str);
    MString& assign(const MString& str, size_t subpos, size_t sublen);
    MString& assign(const char* s);
    MString& assign(const char* s, size_t n);
    MString& assign(size_t n, char c);
    MString& assign(std::initializer_list<char> il);
    MString& assign(MString&& str) noexcept;
    template <class IT>
        MString& assign(IT begin, IT end);
    // insert:
    MString& insert(size_t pos, const MString& str);
    MString& insert(size_t pos, const MString& str, size_t subpos, size_t sublen);
    MString& insert(size_t pos, const char* s);
    MString& insert(size_t pos, const char* s, size_t n);
    MString& insert(size_t pos, size_t n, char c);
    iterator insert(const_iterator p, size_t n, char c);
    iterator insert(const_iterator p, char c);
    MString& insert(const_iterator p, std::initializer_list<char> il);
    template <class IT>
        iterator insert(iterator p, IT begin, IT end);

    // erase:
    MString& erase(size_t pos = 0, size_t len = npos);
    iterator erase(iterator p);
    iterator erase(iterator first, iterator last);

    // replace:
    MString& replace(size_t pos, size_t len, const MString& str);
    MString& replace(const_iterator i1, const_iterator i2,
                     const MString& str);
    MString& replace(size_t pos, size_t len, const MString& str,
                     size_t subpos, size_t sublen);
    MString& replace(size_t pos, size_t len, const char* s);
    MString& replace(const_iterator i1, const_iterator i2,
                     const char* s);
    MString& replace(size_t pos, size_t len, const char* s, size_t n);
    MString& replace(const_iterator i1, const_iterator i2,
                     const char* s, size_t n);
    MString& replace(size_t pos, size_t len, size_t n, char c);
    MString& replace(const_iterator i1, const_iterator i2,
                     size_t n, char c);
    MString& replace(const_iterator i1, const_iterator i2,
                     std::initializer_list<char> il);

    template <class IT>
        MString& replace(const_iterator i1, const_iterator i2,
                         IT first, IT last);

    void swap(MString& str);
    void pop_back();
    void push_back(char c);

//String operations:
    const char* c_str() const{return pointer_;}
    const char* data() const noexcept {return pointer_;};
    size_t copy(char* s, size_t len, size_t pos = 0) const;
    //rfind
    size_t find(const MString& str, size_t pos =0) const noexcept;
    size_t find(const char* s, size_t pos = 0) const;
    size_t find(const char* s, size_t pos, size_type n) const;
    size_t find(char c, size_t pos = 0) const noexcept;
    //rfind:
    size_t rfind(const MString& str, size_t pos =npos) const noexcept;
    size_t rfind(const char* s, size_t pos = npos) const;
    size_t rfind(const char* s, size_t pos, size_type n) const;
    size_t rfind(char c, size_t pos = npos) const noexcept;
    //find_first_of:
    size_t find_first_of(const MString& str, size_t pos =0)const noexcept;
    size_t find_first_of(const char* s, size_t pos = 0) const;
    size_t find_first_of(const char* s, size_t pos, size_t n) const;
    size_t find_first_of(char c, size_t pos = 0) const noexcept;
    //find_last_of:
    size_t find_last_of(const MString& str, size_t pos =npos)const noexcept;
    size_t find_last_of(const char* s, size_t pos = npos) const;
    size_t find_last_of(const char* s, size_t pos, size_t n) const;
    size_t find_last_of(char c, size_t pos = npos) const noexcept;
    //find_first_not_of:
    size_t find_first_not_of(const MString& str, size_t pos =0)const noexcept;
    size_t find_first_not_of(const char* s, size_t pos = 0) const;
    size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
    size_t find_first_not_of(char c, size_t pos = 0) const noexcept;
    //find_last_not_of:
    size_t find_last_not_of(const MString& str, size_t pos = npos)const noexcept;
    size_t find_last_not_of(const char* s, size_t pos = npos) const;
    size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
    size_t find_last_not_of(char c, size_t pos = npos) const noexcept;

    MString substr(size_t pos = 0, size_t len = npos) const;

    //compare:
    int compare(const MString& str) const noexcept;
    int compare(size_t pos, size_t len, const MString& str) const;
    int compare(size_t pos, size_t len, const MString& str,
                size_t subpos, size_t sublen) const;
    int compare(const char* s) const;
    int compare(size_t pos, size_t len, const char* s) const;
    int compare(size_t pos, size_t len, const char* s, size_t n) const;
    
};

template<class IT>
MString::MString(IT begin, IT end)
{
    size_ = end - begin;
    capacity_ = size_ *2;
    pointer_ = new char[capacity_ +1];
    char* temp = pointer_;
    while(begin != end){
        *temp++ = *begin++;
    }
    *(pointer_+size_) = 0x00;
}

template <class IT>
MString& MString::append(IT begin, IT end)
{
    size_t pos = size_;
    size_ += end - begin;
    if(size_ > capacity_){
        expand();
    }
    else{
        *(pointer_+size_) = 0x00;
    }
    char* ptr = pointer_+pos;
    while(begin != end){
        *ptr++ = *begin++;
    }
    return *this;
}

template <class IT>
MString& MString::assign(IT begin, IT end)
{
    size_ = end-begin;
    if(end.base() < begin.base()  && end.base()-this->begin() < size_){
        //反向迭代器区间与源数据地址重叠时
        iterator it = this->begin();
        while(it < end.base()){
            *it++ = *begin++;
        }
        iterator d_it = this->end()-1;
        while(d_it - it > 2 ){
            char temp = *it;
            *it++ = *begin++;
            *d_it-- = temp;
        }
        *(pointer_+size_) = 0x00;
        return *this;
    }

    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        delete pointer_;
        pointer_ = new_p;
    }
    
    iterator it = this->begin();
    while(begin != end){
        *it++ = *begin++;
    }
    *(pointer_+size_) = 0x00;
    return *this;
}

template<class IT>
MString::iterator MString::insert(iterator p, IT begin, IT end)
{
    if(&*p < pointer_ || &*p > pointer_+size_){
        std::cout << "Iterator is invalid";
        std::exit(-1);
    }
    size_t pos = p - this->begin();
    size_t len = end-begin;     //要插入的长度
    char* ptr = pointer_+pos;   //插入点地址

    size_ += len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        ptr = new_p + pos;
        while(begin != end){
            *ptr++ = *begin++;
        }
        strcat(new_p, pointer_+pos);
        delete pointer_;
        pointer_ = new_p;
    }
    else if(p <= begin.base() && p <= end.base()
            && this->end() >= begin.base() && this->end() >= end.base())
    {
        //如果内存重叠
        MString temp(begin, end);
        strcpy(ptr+len, ptr);
        for(iterator it = temp.begin(); it != temp.end(); ++it){
            *ptr++ = *it;
        }
    }
    else{
        strcpy(ptr+len, ptr);
        while(begin != end){
            *ptr++ = *begin++;
        }
    }
    *(pointer_+size_) = 0x00;
    return pointer_+pos;
}
template <class IT>
MString& MString::replace(const_iterator i1, const_iterator i2,
                         IT begin, IT end)
{
    if(i1 < pointer_ || i2 > pointer_+size_){
        std::cout << "参数错误";
        std::exit(-1);
    }
    size_t pos = i1-pointer_;
    size_t len = i2-i1;
    if(i2 < i1){
        len = size_ - pos;
    }   //判断传入迭代器合法性

    size_t copy_len = end-begin;    //被拷贝字符的长度
    size_t b_len = size_-(pos+len);;   //源串分割后段字符串长度
    char* ptr = pointer_+pos;
    char* s = (begin.base()-end.base()<0)?(&*begin.base()) : (&*end.base());

    size_ += copy_len - len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        ptr = new_p + pos;
        memmove(new_p, pointer_, pos);
        while(begin != end){
            *ptr++ = *begin++;
        }
        memmove(new_p+pos+copy_len, pointer_+pos+len, b_len);
        delete pointer_;
        pointer_ = new_p;
    }
    else if((s >= pointer_+pos) && (s <= pointer_+pos+copy_len+b_len)){
        MString tmp(begin,end);
        memmove(pointer_+pos+copy_len, pointer_+pos+len, b_len);
        memmove(pointer_+pos, tmp.pointer_, copy_len);

    }
    else{
        memmove(pointer_+pos+copy_len, pointer_+pos+len, b_len);;
        while(begin != end){
            *ptr++ = *begin++;
        }
    }
    *(pointer_+size_) = 0x00;
    return *this;
}

#endif
