#include "MString.h"
bool operator ==(const MString& lhs, const MString& rhs)
{
    return 0 == strcmp(lhs.pointer_, rhs.pointer_);
}
bool operator ==(const char* lhs, const MString& rhs)
{
    return 0 == strcmp(lhs, rhs.pointer_);
}
bool operator ==(const MString& lhs, const char* rhs)
{
    return 0 == strcmp(lhs.pointer_, rhs);
}
bool operator !=(const MString& lhs, const MString& rhs)
{
    return 0 != strcmp(lhs.pointer_, rhs.pointer_);
}
bool operator !=(const char* lhs, const MString& rhs)
{
    return 0 != strcmp(lhs, rhs.pointer_);
}
bool operator !=(const MString& lhs, const char* rhs)
{
    return 0 != strcmp(lhs.pointer_, rhs);
}
bool operator <(const MString& lhs, const MString& rhs)
{
    return strcmp(lhs.pointer_, rhs.pointer_) < 0;
}
bool operator <(const char* lhs, const MString& rhs)
{
    return strcmp(lhs, rhs.pointer_) < 0;
}
bool operator <(const MString& lhs, const char* rhs)
{
    return strcmp(lhs.pointer_, rhs) < 0;
}
bool operator <=(const MString& lhs, const MString& rhs)
{
    return strcmp(lhs.pointer_, rhs.pointer_) <= 0;
}
bool operator <=(const char* lhs, const MString& rhs)
{
    return strcmp(lhs, rhs.pointer_) <= 0;
}
bool operator <=(const MString& lhs, const char* rhs)
{
    return strcmp(lhs.pointer_, rhs) <= 0;
}
bool operator >(const MString& lhs, const MString& rhs)
{
    return strcmp(lhs.pointer_, rhs.pointer_) > 0;
}
bool operator >(const char* lhs, const MString& rhs)
{
    return strcmp(lhs, rhs.pointer_) > 0;
}
bool operator >(const MString& lhs, const char* rhs)
{
    return strcmp(lhs.pointer_, rhs) > 0;
}
bool operator >=(const MString& lhs, const MString& rhs)
{
    return strcmp(lhs.pointer_, rhs.pointer_) >= 0;
}
bool operator >=(const char* lhs, const MString& rhs)
{
    return strcmp(lhs, rhs.pointer_) >= 0;
}
bool operator >=(const MString& lhs, const char* rhs)
{
    return strcmp(lhs.pointer_, rhs) >= 0;
}


MString operator +(const MString& lhs, const MString& rhs)
{
    MString temp(lhs);
    temp.size_ += rhs.size_;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+lhs.size_, rhs.pointer_, rhs.size_);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;
}
MString operator +(MString&& lhs, MString&& rhs)
{
    size_t l_len = lhs.size_;
    MString temp(std::move(lhs));
    temp.size_ += rhs.size_;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+l_len, rhs.pointer_, rhs.size_);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;
   
}
MString operator +(MString&& lhs, const MString& rhs)
{
    size_t l_len = lhs.size_;
    MString temp(std::move(lhs));
    temp.size_ += rhs.size_;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+l_len, rhs.pointer_, rhs.size_);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;
}
MString operator +(const MString& lhs, MString&& rhs)
{
    MString temp(lhs);
    temp.size_ += rhs.size_;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+lhs.size_, rhs.pointer_, rhs.size_);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;
}

MString operator +(const MString& lhs, const char* rhs)
{
    if(nullptr == rhs){
        std::cout << "err: rhs == nullptr";
        std::exit(-1);
    }
    size_t rhs_len = strlen(rhs);

    MString temp(lhs);
    temp.size_ += strlen(rhs);
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+lhs.size_, rhs, rhs_len);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;
}
MString operator +(MString&& lhs, const char* rhs)
{
    if(nullptr == rhs){
        std::cout << "err: rhs == nullptr";
        std::exit(-1);
    }
    size_t l_len = lhs.size_;
    size_t r_len = strlen(rhs);

    MString temp(std::move(lhs));
    temp.size_ += r_len;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+l_len, rhs, r_len);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;
}
MString operator +(const char* lhs, const MString& rhs)
{
    if(nullptr == lhs){
        std::cout << "err: rhs == nullptr";
        std::exit(-1);
    }
    size_t l_len = strlen(lhs);
    MString temp(lhs);
    temp.size_ += rhs.size_;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+l_len, rhs.pointer_, rhs.size_);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;

}
MString operator +(const char* lhs, MString&& rhs)
{
    if(nullptr == lhs){
        std::cout << "err: rhs == nullptr";
        std::exit(-1);
    }
    size_t l_len = strlen(lhs);
    MString temp(lhs);
    temp.size_ += rhs.size_;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char [temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    memmove(temp.pointer_+l_len, rhs.pointer_, rhs.size_);
    *(temp.pointer_+temp.size_) = 0x00;
    return temp;
}
MString operator +(const MString& lhs, char rhs)
{
    MString temp(lhs);
    temp.size_ += 1;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char[temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    *(temp.pointer_ + temp.size_ -1) = rhs;
    *(temp.pointer_ + temp.size_) = 0x00;
    return temp;
}
MString operator +(MString&& lhs, char rhs)
{
    MString temp(std::move(lhs));
    temp.size_ += 1;
    if(temp.size_ > temp.capacity_){
        temp.capacity_ = temp.size_*2;
        char* new_p = new char[temp.capacity_+1];
        strcpy(new_p, temp.pointer_);
        delete[] temp.pointer_;
        temp.pointer_ = new_p;
    }
    *(temp.pointer_ + temp.size_ -1) = rhs;
    *(temp.pointer_ + temp.size_) = 0x00;
    return temp;
}
MString operator +(char lhs, const MString& rhs)
{
    MString temp(rhs.size_ + 1, lhs);
    memmove(temp.pointer_+1, rhs.pointer_, rhs.size_);
    *(temp.pointer_ + temp.size_) = 0x00;
    return temp;
}
MString operator +(char lhs, MString&& rhs)
{
    MString temp(rhs.size_ + 1, lhs);
    memmove(temp.pointer_+1, rhs.pointer_, rhs.size_);
    *(temp.pointer_ + temp.size_) = 0x00;
    return temp;
}
std::istream& operator >>(std::istream& is, MString& ms)
{
    char buff[_MAX_SIZE];
    is >> buff;
    ms = buff;
    return is;
}
std::ostream& operator <<(std::ostream& os, const MString& ms)
{
    os << ms.pointer_;
    return os;
}
void swap(MString& x, MString& y)
{
    char* ptr = x.pointer_;
    x.pointer_ = y.pointer_;
    y.pointer_ = ptr;

    size_t tmp = x.size_;
    x.size_ = y.size_;
    y.size_ = tmp;

    tmp = x.capacity_;
    x.capacity_ = y.capacity_;
    y.capacity_ = tmp;
}
//constructors:
MString::~MString()
{
    if(pointer_ != nullptr){
        delete[] pointer_;
    }
    pointer_ = nullptr;
}

MString::MString()
{
    size_ = 0;
    capacity_ = 15;
    pointer_ = new char[capacity_ +1];
    *pointer_ = 0x00;
}

MString::MString(const MString& str)
{
    size_ = str.size_;
    capacity_= str.capacity_;
    pointer_ = new char[capacity_ +1];
    strcpy(pointer_, str.pointer_);
}

MString::MString(const MString& str, size_t pos, size_t len)
{
    size_ = (str.size_ > pos+len)? len : size_-pos;
    capacity_ = size_*2;
    pointer_ = new char[capacity_ +1];
    strncpy(pointer_, str.pointer_+pos, len);
    memset(pointer_+size_, 0x00, capacity_-size_);
}

MString::MString(const char* s)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_ = strlen(s);
    capacity_ = size_ * 2;
    pointer_ = new char[capacity_ +1];
    strcpy(pointer_, s);
}

MString::MString(const char* s, size_t n)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_ = strlen(s);
    if(n < size_){
        size_ = n;
    }
    capacity_ = size_*2;
    pointer_ = new char[capacity_ +1];
    strncpy(pointer_, s, size_);
    *(pointer_+size_) = 0x00;
}

MString::MString(size_t n, char c)
{
    size_ = n;
    capacity_ = n*2;
    pointer_ = new char[capacity_ +1];
    for(size_t i = 0; i < size_; ++i){
        *(pointer_ +i) = c;
    }
    memset(pointer_+size_, 0x00, capacity_-size_);
}


MString::MString(std::initializer_list<char> il)
{
    size_ = il.size();
    capacity_ = size_ *2;
    pointer_ = new char[capacity_ +1];
    strcpy(pointer_, il.begin());
    memset(pointer_+size_, 0x00, capacity_-size_);
}
MString::MString(MString&& str) noexcept : pointer_(str.pointer_), size_(str.size_), capacity_(str.capacity_)
{
    str.pointer_ = nullptr;
}

//operator=:
MString& MString::operator =(const MString& str)
{
    size_ = str.size_;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        delete[] pointer_;
        pointer_ = new_p;
    }
    memmove(pointer_, str.pointer_, size_);
    *(pointer_+size_) = 0x00;
    return *this;
}

MString& MString::operator =(const char* s)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_ = strlen(s);
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        delete[] pointer_;
        pointer_ = new_p;
    }
    memmove(pointer_, s, size_);
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::operator =(char c)
{
    size_ = 1;
    *pointer_ = c;
    /* memset(pointer_+size_, 0x00, capacity_-size_); */
    *(pointer_+size_) = 0x00;
    return *this;
}

MString& MString::operator =(std::initializer_list<char> il)
{
    size_ = il.size();
    if(size_ > capacity_){
        capacity_ = size_*2;
        delete[] pointer_;
        pointer_ = new char[capacity_+1];
    }
    strncpy(pointer_, il.begin(), size_);
    /* memset(pointer_+size_, 0x00, capacity_-size_); */
    *(pointer_+size_) = 0x00;
    return *this;
}

MString& MString::operator =(MString&& str) noexcept
{
    if( pointer_ == str.pointer_ ){
        return *this;
    }
    char* p_temp = pointer_;
    pointer_ = str.pointer_;
    str.pointer_ = p_temp;
    size_t s_temp = size_;
    size_ = str.size_;
    str.size_ = s_temp;

    s_temp = capacity_;
    capacity_ = str.capacity_;
    str.capacity_ = s_temp;

    return *this;
}
//iterators:
MString::iterator MString::begin()  noexcept 
{
    return iterator(pointer_);
}
MString::iterator MString::end() noexcept
{
    return iterator(pointer_+size_);
}
MString::reverse_iterator MString::rbegin() noexcept
{
    return reverse_iterator(pointer_+size_-1);
}
MString::reverse_iterator MString::rend() noexcept
{
    return reverse_iterator(pointer_-1);
}
MString::const_iterator MString::begin() const noexcept 
{
    return const_iterator(pointer_);
}
MString::const_iterator MString::end() const noexcept
{
    return const_iterator(pointer_+size_);
}
MString::const_reverse_iterator MString::rbegin() const noexcept
{
    return const_reverse_iterator(pointer_+size_-1);
}
MString::const_reverse_iterator MString::rend() const noexcept
{
    return const_reverse_iterator(pointer_-1);
}
MString::const_iterator MString::cbegin() const noexcept 
{
    return const_iterator(pointer_);
}
MString::const_iterator MString::cend() const noexcept
{
    return const_iterator(pointer_+size_);
}
MString::const_reverse_iterator MString::crbegin() const noexcept
{
    return const_reverse_iterator(pointer_+size_-1);
}
MString::const_reverse_iterator MString::crend() const noexcept
{
    return const_reverse_iterator(pointer_-1);
}

void MString::clear() noexcept
{
    size_ = 0;
    *pointer_ = 0x00;
}

void MString::resize(size_t n)
{
    if(n > capacity_){
        capacity_ = (n > 2*capacity_? n:(2*capacity_));
        char* new_p = new char[capacity_ +1];
        strcpy(new_p, pointer_);
        delete[] pointer_;
        pointer_ = new_p;
    }
    size_ = n;
    *(pointer_ + size_) = 0x00;
}

void MString::resize(size_t n, char c)
{
    if(n > capacity_){
        capacity_ = (n > 2*capacity_? n:(2*capacity_));
        char* new_p = new char[capacity_ +1];
        strcpy(new_p, pointer_);
        delete[] pointer_;
        pointer_ = new_p;
    }

    if(n > size_){
        for(char* temp = pointer_+size_;
            size_ != n; ++size_){
            *temp++ = c;
        }
    }
    else{
        size_ = n;
    }
    *(pointer_ + size_) = 0x00;
}

void MString::reserve(size_t n)
{
    if(n > capacity_){
        capacity_ = (n > 2*capacity_? n:(2*capacity_));
        char* new_p = new char[capacity_ +1];
        strcpy(new_p, pointer_);
        delete[] pointer_;
        pointer_ = new_p;
    }
}

void MString::shrink_to_fit()
{
    if(capacity_ > size_){
        capacity_ = size_;
        char* new_p = new char[capacity_ +1];
        strcpy(new_p, pointer_);
        delete[] pointer_;
        pointer_ = new_p;
    }
}

//element access:

char& MString::operator [](size_t pos){ return *(pointer_ +pos);}

char& MString::at(size_t pos){ return *(pointer_ +pos); }

char& MString::back(){return *(pointer_ +size_ -1);}

char& MString::front(){ return *pointer_; }

const char& MString::operator [](size_t pos) const {return *(pointer_ +pos);}

const char& MString::at(size_t pos) const {return *(pointer_ + pos);}

const char& MString::back() const {return *(pointer_ +size_ -1);}

const char& MString::front() const {return *pointer_;}

//modifiers:
MString& MString::operator +=(const MString& str)
{
    size_ += str.size_;
    if(size_ > capacity_){
        expand();
    }

    strcat(pointer_, str.pointer_);
    return *this;
}

MString& MString::operator +=(const char* s)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_ += strlen(s);
    if(size_ > capacity_){
        expand();
    }

    strcat(pointer_, s);
    return *this;
}

MString& MString::operator +=(char c)
{
    size_ += 1;
    if(size_ > capacity_){
        expand();
    }

    *(pointer_ + size_ -1) = c;
    *(pointer_ + size_) = 0x00;

    return *this;
}

MString& MString::operator +=(std::initializer_list<char> il)
{
    size_ += il.size();
    if(size_ > capacity_){
        expand();
    }
    strcat(pointer_, il.begin());
    return *this;
}

//append:
MString& MString::append(const MString& str)
{
    size_ += str.size_;
    if(size_ > capacity_){
        expand();
    }
    strcat(pointer_, str.pointer_);
    return *this;
}
MString& MString::append(const MString& str, size_t subpos, size_t sublen)
{
    size_ += (str.size_ > subpos + sublen)? sublen : (str.size_- subpos);
    if(size_ > capacity_){
        expand();
    }
    else{
        *(pointer_+size_) = 0x00;
    }
    strncat(pointer_, str.pointer_+subpos, sublen);
    return *this;

}
MString& MString::append(const char* s)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_ += strlen(s);
    if(size_ > capacity_){
        expand();
    }
    strcat(pointer_, s);
    return *this;
}
MString& MString::append(const char* s, size_t n)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_ += n;
    if(size_ > capacity_){
        expand();
    }
    else{
        *(pointer_+size_) = 0x00;
    }
    strncat(pointer_, s, n);
    return *this;
}
MString& MString::append(size_t n, char c)
{
    size_t temp = size_;
    size_ += n;
    if(size_ > capacity_){
        expand();
    }
    else{
        *(pointer_+size_) = 0x00;
    }
    memset(pointer_+temp, c, n);
    return *this;
}
MString& MString::append(std::initializer_list<char> il)
{
    size_ += il.size();
    if(size_ > capacity_){
        expand();
    }
    else{
        *(pointer_+size_) = 0x00;
    }
    strncat(pointer_, il.begin(), il.size());
    return *this;
}

void MString::push_back(char c)
{
    size_ += 1;
    if(size_ > capacity_){
        expand();
    }

    *(pointer_ + size_ -1) = c;
    *(pointer_ + size_) = 0x00;
}

//MString::assign:
MString& MString::assign(const MString& str)
{
    if(pointer_ == str.pointer_){
        return *this;
    }
    size_ = str.size_;
    if(size_ > capacity_){
        char* new_p = new char[capacity_+1];
        delete[] pointer_;
        pointer_ = new_p;
    }
    strcpy(pointer_, str.pointer_);
    return *this;
}
MString& MString::assign(const MString& str, size_t subpos, size_t sublen)
{
    size_ = (str.size_ > subpos + sublen)? sublen : (str.size_- subpos);
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        delete[] pointer_;
        pointer_ = new_p;
    }
    strncpy(pointer_, str.pointer_+subpos, size_);
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::assign(const char* s)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    if(pointer_ == s){
        return *this;
    }
    size_ = strlen(s);
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        delete[] pointer_;
        pointer_ = new_p;
    }
    strcpy(pointer_, s);
    return *this;
}
MString& MString::assign(const char* s, size_t n)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_ = (strlen(s) > n)? n:strlen(s);
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        delete[] pointer_;
        pointer_ = new_p;
    }
    strncpy(pointer_, s, size_);
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::assign(size_t n, char c)
{
    size_ = n;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        delete[] pointer_;
        pointer_ = new_p;
    }
    memset(pointer_, c, n);
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::assign(std::initializer_list<char> il)
{
    size_ = il.size();
    if(size_ > capacity_){
        capacity_ = size_*2;
        delete[] pointer_;
        pointer_ = new char[capacity_+1];
    }
    strncpy(pointer_, il.begin(), size_);
    *(pointer_ + size_) = 0x00;
    return *this;

}
MString& MString::assign(MString&& str) noexcept
{
    if( pointer_ == str.pointer_ ){
        return *this;
    }
    char* p_temp = pointer_;
    pointer_ = str.pointer_;
    str.pointer_ = p_temp;

    size_t s_temp = size_;
    size_ = str.size_;
    str.size_ = s_temp;

    s_temp = capacity_;
    capacity_ = str.capacity_;
    str.capacity_ = s_temp;

    return *this;
}

//insert:
MString& MString::insert(size_t pos, const MString& str)
{
    size_t copy_len = str.size_;
    size_ += copy_len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        memmove(new_p+pos, str.pointer_, copy_len);
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        strcpy(pointer_+pos+copy_len, pointer_+pos);
        strncpy(pointer_+pos, str.pointer_, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::insert(size_t pos, const MString& str, size_t subpos, size_t sublen)
{
    if(sublen > str.size_){
        sublen = str.size_ - pos;
    }
    size_ += sublen;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        memmove(new_p+pos, str.pointer_+subpos, sublen);
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        strcpy(pointer_+pos+sublen, pointer_+pos);
        strncpy(pointer_+pos, str.pointer_+subpos, sublen);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::insert(size_t pos, const char* s)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_t copy_len = strlen(s);
    size_ += copy_len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        strcat(new_p, s);
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        strcpy(pointer_+pos+copy_len, pointer_+pos);
        strncpy(pointer_+pos, s, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::insert(size_t pos, const char* s, size_t n)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    if(n > strlen(s)){
        n = strlen(s);
    }
    size_ += n;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, s, n);
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        strcpy(pointer_+pos+n, pointer_+pos);
        strncpy(pointer_+pos, s, n);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::insert(size_t pos, size_t n, char c)
{
    size_ += n;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        memset(new_p+pos, c, n);
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        strcpy(pointer_+pos+n, pointer_+pos);
        memset(pointer_+pos, c, n);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString::iterator MString::insert(const_iterator p, size_t n, char c)
{
    if(&*p < pointer_ || &*p > pointer_+size_){
        std::cout << "Iterator is invalid";
        std::exit(-1);
    }
    size_t pos = p.base() - this->begin();
    size_ += n;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        memset(new_p+pos, c, n);
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;

    }else{
        strcpy(pointer_+pos+n, pointer_+pos);
        memset(pointer_+pos, c, n);
    }

    *(pointer_+size_) = 0x00;
    return pointer_+pos;
}
MString::iterator MString::insert(const_iterator p, char c)
{
    if(&*p < pointer_ || &*p > pointer_+size_){
        std::cout << "Iterator is invalid";
        std::exit(-1);
    }
    size_t pos = p.base() - this->begin();
    size_ += 1;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        memset(new_p+pos, c, 1);
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;

    }else{
        strcpy(pointer_+pos+1, pointer_+pos);
        memset(pointer_+pos, c, 1);
    }

    *(pointer_+size_) = 0x00;
    return pointer_+pos;
}
MString& MString::insert(const_iterator p, std::initializer_list<char> il)
{
    if(&*p < pointer_ || &*p > pointer_+size_){
        std::cout << "Iterator is invalid";
        std::exit(-1);
    }
    size_t pos = p.base() - this->begin();
    size_ += il.size();
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        memset(new_p, 0x00, size_);
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, il.begin(), il.size());
        strcat(new_p, pointer_+pos);
        delete[] pointer_;
        pointer_ = new_p;

    }else{
        strcpy(pointer_+pos+il.size(), pointer_+pos);
        strncpy(pointer_+pos, il.begin(), il.size());
    }

    *(pointer_+size_) = 0x00;
    return *this;
}

MString& MString::erase(size_t pos, size_t len)
{
    if(len == npos){
        memset(pointer_ +pos, 0x00, size_);
        size_ = pos;
        return *this;
    }
    memset(pointer_ +pos, 0x00, len);
    if(pos+len < capacity_){
        strcpy(pointer_ +pos, pointer_+pos+len);
    }
    size_ -= len;
    return *this;
}

MString::iterator MString::erase(iterator p)
{
    if(&*p < pointer_ || &*p > pointer_+size_){
        std::cout << "Iterator is invalid";
        std::exit(-1);
    }
    size_ -= 1;
    char* ptr = &*p;
    strcpy(ptr, ptr+1);
    return ptr;
}
MString::iterator MString::erase(iterator first, iterator last)
{
    if(&*first >= pointer_ && &*last <= pointer_+size()){
        size_ -= last -first;
        strcpy(&*first, &*last);
        return first;
    }

    std::cout << "Iterators are invalid";
    std::exit(-1);

}

MString& MString::replace(size_t pos, size_t len, const MString& str)
{
    size_t copy_len = str.size_;    //被拷贝字符的长度
    size_t b_len = size_-pos-len;   //源串分割后段字符串
    size_ += copy_len-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, str.pointer_,copy_len);
        strcpy(new_p+pos+copy_len, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        memmove(pointer_+pos+copy_len, pointer_+pos+len, b_len);
        memmove(pointer_+pos, str.pointer_, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::replace(const_iterator i1, const_iterator i2,
                          const MString& str)
{
    if(i1 < pointer_ || i2 > pointer_+size_){
        std::cout << "Iterators are invalid";
        std::exit(-1);
    }
    size_t pos = i1-pointer_;
    size_t len = i2-i1;
    if(i2 < i1){
        len = size_ - pos;
    }
    size_t copy_len = str.size_;    //被拷贝字符的长度
    size_ += copy_len-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, str.pointer_,copy_len);
        strcpy(new_p+pos+copy_len, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        strcpy(pointer_+pos+copy_len, pointer_+pos+len);
        memmove(pointer_+pos, str.pointer_, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::replace(size_t pos, size_t len, const MString& str,
                          size_t subpos, size_t sublen)
{
    size_t b_len = size_-pos-len;   //源串分割后段字符串长度
    if(sublen > str.size_){
        sublen = str.size_-subpos;
    }
    size_ += sublen-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, str.pointer_+subpos,sublen);
        strcpy(new_p+pos+sublen, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else if(str.pointer_+subpos > pointer_+pos && str.pointer_+subpos <= pointer_+pos+sublen+b_len){
        //内存重叠
        MString tmp(str.pointer_+subpos, sublen);
        memmove(pointer_+pos+sublen, pointer_+pos+len, b_len);
        memmove(pointer_+pos, tmp.pointer_, sublen);
    }
    else{
        strcpy(pointer_+pos+sublen, pointer_+pos+len);
        memmove(pointer_+pos, str.pointer_+subpos, sublen);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::replace(size_t pos, size_t len, const char* s)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_t copy_len = strlen(s);    //被拷贝字符的长度
    size_t b_len = size_-pos-len;   //源串分割后段字符串长度
    size_ += copy_len-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, s,copy_len);
        strcpy(new_p+pos+copy_len, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        memmove(pointer_+pos+copy_len, pointer_+pos+len, b_len);
        memmove(pointer_+pos, s, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::replace(const_iterator i1, const_iterator i2,
                          const char* s)
{
    if(i1 < pointer_ || i2 > pointer_+size_ || nullptr == s){
        std::cout << "err: Paramenters are invalid";
        std::exit(-1);
    }
    size_t pos = i1-pointer_;
    size_t len = i2-i1;
    if(i2 < i1){
        len = size_ - pos;
    }
    size_t copy_len = strlen(s);    //被拷贝字符的长度
    size_t b_len = size_-pos-len;   //源串分割后段字符串
    size_ += copy_len - len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, s,copy_len);
        strcpy(new_p+pos+copy_len, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        memmove(pointer_+pos+copy_len, pointer_+pos+len, b_len);
        memmove(pointer_+pos, s, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::replace(size_t pos, size_t len, const char* s, size_t n)
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }
    size_t b_len = size_-pos-len;   //源串分割后段字符串长度
    n = (n>strlen(s))? strlen(s):n;    //被拷贝字符的长度
    size_ += n-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, s,n);
        strcpy(new_p+pos+n, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else if((s > pointer_+pos) && (s <= pointer_+pos+n+b_len)){
        //内存重叠
        MString tmp(s, n);
        memmove(pointer_+pos+n, pointer_+pos+len, b_len);
        memmove(pointer_+pos, tmp.pointer_, n);
        
    }
    else{
        memmove(pointer_+pos+n, pointer_+pos+len, b_len);
        memmove(pointer_+pos, s, n);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::replace(const_iterator i1, const_iterator i2,
                          const char* s, size_t n)
{
    if(i1 < pointer_ || i2 > pointer_+size_ || s == nullptr){
        std::cout << "err: Paramenters are invalid";
        std::exit(-1);
    }
    size_t pos = i1-pointer_;
    size_t len = i2-i1;
    if(i2 < i1){
        len = size_ - pos;
    }
    size_t b_len = size_-pos-len;   //源串分割后段字符串长度
    size_t copy_len = n>strlen(s)?strlen(s):n;    //被拷贝字符的长度
    size_ += copy_len-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(new_p+pos, s,copy_len);
        strcpy(new_p+pos+copy_len, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else if((s > pointer_+pos) && (s <= pointer_+pos+n+b_len)){
        //内存重叠
        MString tmp(s, n);
        memmove(pointer_+pos+n, pointer_+pos+len, b_len);
        memmove(pointer_+pos, tmp.pointer_, n);
        
    }
    else{
        memmove(pointer_+pos+n, pointer_+pos+len, b_len);;
        memmove(pointer_+pos, s, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
MString& MString::replace(size_t pos, size_t len, size_t n, char c)
{
    size_t b_len = size_-pos-len;
    size_ += n-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        memset(new_p+pos, c, n);
        strcpy(new_p+pos+n, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        memmove(pointer_+pos+n, pointer_+pos+len, b_len);
        memset(pointer_+pos, c, n);
    }
    *(pointer_+size_) = 0x00;
    return *this;

}
MString& MString::replace(const_iterator i1, const_iterator i2,
                          size_t n, char c)
{
    if(i1 < pointer_ || i2 > pointer_+size_){
        std::cout << "参数错误";
        std::exit(-1);
    }
    size_t pos = i1-pointer_;
    size_t len = i2-i1;
    if(i2 < i1){
        len = size_ - pos;
    }

    size_t b_len = size_-pos-len;   //源串分割后段字符串长度
    size_ += n-len;
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        memset(new_p+pos, c, n);
        strcpy(new_p+pos+n, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        memmove(pointer_+pos+n, pointer_+pos+len, b_len);
        memset(pointer_+pos, c, n);
    }
    *(pointer_+size_) = 0x00;
    return *this;

}
MString& MString::replace(const_iterator i1, const_iterator i2,
                          std::initializer_list<char> il)
{
    if(i1 < pointer_ || i2 > pointer_+size_){
        std::cout << "参数错误";
        std::exit(-1);
    }
    size_t pos = i1-pointer_;
    size_t len = i2-i1;
    if(i2 < i1){
        len = size_ - pos;
    }

    size_t b_len = size_-pos-len;   //源串分割后段字符串长度
    size_t copy_len = il.size();
    size_ += copy_len-len;
    auto s = il.begin();
    if(size_ > capacity_){
        capacity_ = size_*2;
        char* new_p = new char[capacity_+1];
        strncpy(new_p, pointer_, pos);
        strncpy(pointer_+pos, s, copy_len);
        strcpy(new_p+pos+copy_len, pointer_+pos+len);
        delete[] pointer_;
        pointer_ = new_p;
    }
    else{
        memmove(pointer_+pos+copy_len, pointer_+pos+len, b_len);;
        strncpy(pointer_+pos, s, copy_len);
    }
    *(pointer_+size_) = 0x00;
    return *this;
}
void MString::swap(MString& str)
{
    if( pointer_ == str.pointer_ ){
        return;
    }
    char* p_temp = pointer_;
    pointer_ = str.pointer_;
    str.pointer_ = p_temp;
    size_t s_temp = size_;
    size_ = str.size_;
    str.size_ = s_temp;

    s_temp = capacity_;
    capacity_ = str.capacity_;
    str.capacity_ = s_temp;
}
void MString::pop_back()
{
    size_ -= 1;
    *(pointer_+size_) = 0x00;
}
size_t MString::copy(char* s, size_t len, size_t pos) const
{
    if(nullptr == s || pos >= size_){
        return 0;
    }
    size_t ret =0;
    while(len != 0){
        *s++ = *(pointer_+pos+ret++);
        if(*(pointer_+pos+ret) == 0x00)
            break;
        --len;
    }
    *s = 0x00;
    return ret;
}
size_t MString::find(const MString& str, size_t pos) const noexcept
{
    if(pos >= size_)
        return npos;

    char* p = strstr(pointer_+pos, str.pointer_);
    if(p == nullptr){
        return npos;
    }

    return p-pointer_;
}
size_t MString::find(const char* s, size_t pos) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        return npos;
    }

    char* p = strstr(pointer_+pos, s);
    if(p == nullptr){
        return npos;
    }

    return p-pointer_;

}
size_t MString::find(const char* s, size_t pos, size_type n) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        return npos;
    }
    char buff[n];
    memmove(buff, s, n);
    buff[n] = 0x00;
    char* p = strstr(pointer_+pos, buff);
    if(p == nullptr){
        return npos;
    }
    return p-pointer_;

}
size_t MString::find(char c, size_t pos) const noexcept
{
    if(pos >= size_)
        return npos;
    size_t ret = pos;
    for(; ret < size_-pos; ++ret)
        if(*(pointer_+ret) == c)
            return ret;
    return npos;

}
size_t MString::rfind(const MString& str, size_t pos) const noexcept
{
    if(pos == npos){
        pos = size_;
    }
    else if(pos < str.size_){
        return npos;
    }
    const char* ret = pointer_+pos;
    while(ret >= pointer_){
        while(*ret != *str.pointer_){
            --ret;
        }
        const char *temp = ret+1;
        const char *obj = str.pointer_+1;
        while(*temp == *obj){
            ++temp;
            ++obj;

            if(*obj == 0x00){
                return ret-pointer_;
            }else if(*temp == 0x00){
                return npos;
            }
        }
        --ret;
    }
    return npos;
}
size_t MString::rfind(const char* s, size_t pos) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos < strlen(s)){
        return npos;
    }else if(pos > size_){
        pos = size_;
    }
    const char* ret = pointer_+pos;
    while(ret >= pointer_){
        while(*ret != *s){
            --ret;
        }
        const char* temp = ret+1;
        const char* obj = s+1;
        while(*temp == *obj){
            ++temp;
            ++obj;

            if(*obj == 0x00){
                return ret-pointer_;
            }else if(*temp == 0x00){
                return npos;
            }
        }
        --ret;
    }
    return npos;

}
size_t MString::rfind(const char* s, size_t pos, size_type n) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos < strlen(s) || n == 0){
        return npos;
    }else if(pos > size_){
        pos = size_;
    }
    const char* ret = pointer_+pos;
    while(ret >= pointer_){
        while(*ret != *s){
            --ret;
        }
        const char* temp = ret+1;
        const char* obj = s+1;
        while(*temp == *obj){
            ++temp;
            ++obj;

            if(obj == s+n || *obj == 0x00){
                return ret-pointer_;
            }else if(*temp == 0x00){
                return npos;
            }
        }
        --ret;
    }
    return npos;

}
size_t MString::rfind(char c, size_t pos) const noexcept
{
    if(pos >= size_){
        pos = size_-1;
    }
    for(const char* ptr = pointer_+pos; ptr >= pointer_; --ptr){
        if(*ptr == c){
            return ptr-pointer_;
        }
    }
    return npos;
}

size_t MString::find_first_of(const MString& str, size_t pos)const noexcept
{
    if(pos >= size_){
        return npos;
    }
    char* ret = strpbrk(pointer_+pos, str.pointer_);
    if(ret == nullptr){
        return npos;
    }
    return ret-pointer_;
}
size_t MString::find_first_of(const char* s, size_t pos) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        return npos;
    }
    char* ret = strpbrk(pointer_+pos, s);
    if(ret == nullptr){
        return npos;
    }
    return ret-pointer_;

}
size_t MString::find_first_of(const char* s, size_t pos, size_t n) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_ || n == 0){
        return npos;
    }else if(n > strlen(s)){
        n = strlen(s);
    }
    char buff[n+1];
    memmove(buff, s, n);
    buff[n] = 0x00;
    char* ret = strpbrk(pointer_+pos, buff);
    if(ret == nullptr){
        return npos;
    }
    return ret-pointer_;
}
size_t MString::find_first_of(char c, size_t pos) const noexcept
{
    if(pos >= size_)
        return npos;
    size_t ret = pos;
    for(; ret < size_-pos; ++ret)
        if(*(pointer_+ret) == c)
            return ret;
    return npos;
}

size_t MString::find_last_of(const MString& str, size_t pos)const noexcept
{
    if(pos >= size_){
        pos = size_-1;
    }
    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = str.pointer_; p < str.pointer_+str.size_; ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count){
            buf[c_count++] = *p;
        }
    }
    //在给定范围从后往前依次对比
    char* ptr = pointer_+pos;
    while(ptr >= pointer_){
        for(i = 0; i< c_count; ++i){
            if(*ptr == buf[i])
                return ptr-pointer_;
        }
        --ptr;
    }
    return npos;

}
size_t MString::find_last_of(const char* s, size_t pos) const
{    
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        pos = size_-1;
    }
    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = s; *p != 0x00; ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count){
            buf[c_count++] = *p;
        }
    }
    //在给定范围从后往前依次对比
    char* ptr = pointer_+pos;
    while(ptr >= pointer_){
        for(i = 0; i< c_count; ++i){
            if(*ptr == buf[i])
                return ptr-pointer_;
        }
        --ptr;
    }
    return npos;
}
size_t MString::find_last_of(const char* s, size_t pos, size_t n) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        pos = size_-1;
    }else if(n > strlen(s)){
        n = strlen(s);
    }else if( n == 0 ){
        return npos;
    }
    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = s; p < s+n; ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count){
            buf[c_count++] = *p;
        }
    }
    //在给定范围从后往前依次对比
    char* ptr = pointer_+pos;
    while(ptr >= pointer_){
        for(i = 0; i< c_count; ++i){
            if(*ptr == buf[i])
                return ptr-pointer_;
        }
        --ptr;
    }
    return npos;
}
size_t MString::find_last_of(char c, size_t pos) const noexcept
{
    if(pos >= size_){
        pos = size_-1;
    }
    for(const char* ptr = pointer_+pos; ptr >= pointer_; --ptr){
        if(*ptr == c){
            return ptr-pointer_;;
        }
    }
    return npos;
}

size_t MString::find_first_not_of(const MString& str, size_t pos)const noexcept
{
    if(pos > size_){
        pos = size_;
    }
    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = str.pointer_; p < str.pointer_+str.size_; ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count){
            buf[c_count++] = *p;
        }
    }

    //依次比对，找到第一个和buf都不匹配的字符
    const char* ptr = pointer_+pos;
    while(ptr < pointer_+size_){
        for(i = 0; i < c_count; ++i){
            if(*ptr == buf[i])
                break;
        }
        if(i == c_count){
            return ptr-pointer_;
        }
        ++ptr;
    }
     return npos;
}
size_t MString::find_first_not_of(const char* s, size_t pos) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos > size_){
        pos = size_;
    }

    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = s; p < s+strlen(s); ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count)
            buf[c_count++] = *p;
    }

    //依次比对，找到第一个和buf都不匹配的字符
    const char* ptr = pointer_+pos;
    while(ptr < pointer_+size_){
        for(i = 0; i < c_count; ++i){
            if(*ptr == buf[i])
                break;
        }
        if(i == c_count)
            return ptr-pointer_;
        ++ptr;
    }
     return npos;
}
size_t MString::find_first_not_of(const char* s, size_t pos, size_t n) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(n > strlen(s)){
        n = strlen(s);
    }else if(pos > size_){
        pos = size_;
    }

    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = s; p < s+n; ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count)
            buf[c_count++] = *p;
    }

    //依次比对，找到第一个和buf都不匹配的字符
    const char* ptr = pointer_+pos;
    while(ptr < pointer_+size_){
        for(i = 0; i < c_count; ++i){
            if(*ptr == buf[i])
                break;
        }
        if(i == c_count)
            return ptr-pointer_;
        ++ptr;
    }
     return npos;
}
size_t MString::find_first_not_of(char c, size_t pos) const noexcept
{
    if(pos > size_){
        return npos;
    }
    const char* ptr = pointer_+pos;
    while(ptr < pointer_+size_){
        if(*ptr != c)
            return ptr-pointer_;
        ++ptr;
    }
     return npos;
}
//find_last_not_of:
size_t MString::find_last_not_of(const MString& str, size_t pos)const noexcept
{
    if(pos >= size_){
        pos = size_-1;
    }
  
    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = str.pointer_; p < str.pointer_+str.size_; ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count)
            buf[c_count++] = *p;
    }

    char* ptr = pointer_+pos;
    while(ptr >= pointer_){
        for(i = 0; i < c_count; ++i){
            if(*ptr == buf[i])
                break;
        }
        if(i == c_count)
            return ptr-pointer_;
        --ptr;
    }
    return npos;
}
size_t MString::find_last_not_of(const char* s, size_t pos) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        pos = size_-1;
    }
  
    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = s; p < s+strlen(s); ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count)
            buf[c_count++] = *p;
    }

    char* ptr = pointer_+pos;
    while(ptr >= pointer_){
        for(i = 0; i < c_count; ++i){
            if(*ptr == buf[i])
                break;
        }
        if(i == c_count)
            return ptr-pointer_;
        --ptr;
    }
    return npos;

}
size_t MString::find_last_not_of(const char* s, size_t pos, size_t n) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        pos = size_-1;
    }else if(n > strlen(s)){
        n = strlen(s);
    }else if(n == 0){
        return npos;
    }
  
    char buf[255] = {0};    //存储str中所有不同的字符
    int c_count = 0;        //统计str中不同字符的数量
    int i = 0;
    for(const char* p = s; p < s+n; ++p){
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count)
            buf[c_count++] = *p;
    }

    char* ptr = pointer_+pos;
    while(ptr >= pointer_){
        for(i = 0; i < c_count; ++i){
            if(*ptr == buf[i])
                break;
        }
        if(i == c_count)
            return ptr-pointer_;
        --ptr;
    }
    return npos;
}
size_t MString::find_last_not_of(char c, size_t pos) const noexcept
{
    if(pos > size_){
        pos = size_-1;
    }
    const char* ptr = pointer_+pos;
    while(ptr >= pointer_){
        if(*ptr != c)
            return ptr-pointer_;
        --ptr;
    }
    return npos;
}
MString MString::substr(size_t pos, size_t len) const
{
    if(pos >= size_){
        return nullptr;
    }else if(len > size_-pos){
        len = size_-pos;
    }
    return MString(pointer_+pos, len);
}
//compare:
int MString::compare(const MString& str) const noexcept
{
    return memcmp(pointer_, str.pointer_, size_+1);
}
int MString::compare(size_t pos, size_t len, const MString& str) const
{
    if(pos >= size_){
        return -1;
    }else if(len > size_-pos){
        len = size_ - pos;
    }

    return memcmp(pointer_+pos, str.pointer_, len+1);

}
int MString::compare(size_t pos, size_t len, const MString& str,
            size_t subpos, size_t sublen) const
{
    if(pos >= size_){
        return -1;
    }else if(len > size_-pos){
        len = size_ - pos;
    }

    if(subpos >= str.size_){
        return 1;
    }else if(sublen > str.size_-subpos){
        sublen = str.size_-pos;
    }
    
    return memcmp(pointer_+pos, str.pointer_+subpos, len+1);
}
int MString::compare(const char* s) const
{
    return memcmp(pointer_, s, size_+1);
}
int MString::compare(size_t pos, size_t len, const char* s) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        return -1;
    }else if(len > size_-pos){
        len = size_ - pos;
    }
    return memcmp(pointer_+pos, s, len+1);
}
int MString::compare(size_t pos, size_t len, const char* s, size_t n) const
{
    if(nullptr == s){
        std::cout << "err: s == nullptr";
        std::exit(-1);
    }else if(pos >= size_){
        return -1;
    }else if(len > size_-pos){
        len = size_ - pos;
    }else if( n > strlen(s) ){
        n = strlen(s);
    }
    return memcmp(pointer_+pos, s, n+1);
}
void MString::expand()
{
    capacity_ = size_ *2;
    char* temp = new char[capacity_ +1];
    strcpy(temp, pointer_);
    delete[] pointer_;
    pointer_ = temp;
    *(pointer_+size_) = 0x00;
}
