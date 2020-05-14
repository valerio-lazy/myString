#include <utility>
#include <iostream>
#include "MString.h"
using namespace std;

void test()
{
    MString s("xxxxxvalerio");
    MString t("xxxxxminshuai");
    const char* p = "bieyuan";
    cout << s << endl
        << "size: " << s.size() << " capacity: " << s.capacity()
        << " " << static_cast<const void*>(&s[0]) << endl;
    cout << t << endl
        << "size: " << t.size() << " capacity: " << t.capacity()
        << " " << static_cast<const void*>(&t[0]) << endl;
    cout << s.compare(t) << endl;
    cout << s.compare(3,5, t) << endl;
    cout << s.compare(2,7, t, 3, 5) << endl;
    cout << s.compare(p) << endl;
    cout << s.compare(1, 3, p) << endl;
    cout << s.compare(7, 5, p, 5) << endl;
    /* s.swap(t); */
    /* cout << s << endl */
    /*     << "size: " << s.size() << " capacity: " << s.capacity() */
    /*     << " " << static_cast<const void*>(&s[0]) << endl; */
    /* cout << t << endl */
    /*     << "size: " << t.size() << " capacity: " << t.capacity() */
    /*     << " " << static_cast<const void*>(&t[0]) << endl; */

}

void test01()
{
    string t1("valerio+");
    string t2("minshuai");
    string s;
    char p[5] = {'b','i','e','\0','x'};
    cout << strlen(p) << endl;
    cout << s << endl
        << "size: " << s.size() << " capacity: " << s.capacity()
        << " " << static_cast<const void*>(&s[0]) << endl;

    /* s = std::move(t1)+std::move(t2); */
    s = t1 + p;
    /* MString::iterator it = s.insert(s.begin(), s.rbegin(), s.rbegin()+5); */
    cout << s << endl
        << "size: " << s.size() << " capacity: " << s.capacity()
        << " " << static_cast<const void*>(&s[0]) << endl;
}

void test02()
{
    /* string s("abcdefghijklmnopqrstuvwxyz"); */
    /* string t("minshuai"); */
    MString s("abcdefghijklmnopqrstuvwxyz");
    MString t("minshuai");
    cout << s << endl
        << "size: " << s.size() << " capacity: " << s.capacity()
        << " " << static_cast<const void*>(&s[0]) << endl;
    /* cout << t << endl */
    /*     << "size: " << t.size() << " capacity: " << t.capacity() */
    /*     << " " << static_cast<const void*>(&t[0]) << endl; */

    s.assign(s.rbegin()+5, s.rend());
    /* printf("%p\n", pp); */
    /* printf("%p\n", s.c_str()); */
    cout << s << endl 
        << "size: " << s.size() << " capacity: " << s.capacity() 
        << " " << static_cast<const void*>(&s[0]) << endl;
    /* cout << t << endl */
    /*     << "size: " << t.size() << " capacity: " << t.capacity() */
    /*     << " " << static_cast<const void*>(&t[0]) << endl; */
}

void test03()
{
    MString s("valerio");
    MString t("minshuai");

    if(s == t) cout << "s and t are equal" << endl;
    if(s != t) cout << "s and t are not equal" << endl;
    if(s < t) cout << "s is less than t" << endl;
    if(s <= t) cout << "s is less than or equal to t" << endl;
    if(s > t) cout << "s is greater than t" << endl;
    if(s >= t) cout << "s is greater than or equal to t" << endl;

    /* s.shrink_to_fit(); */
    /* cout << s << endl */ 
    /*     << "size: " << s.size() << " capacity: " << s.capacity() */ 
    /*     << " " << static_cast<const void*>(s.c_str()) << endl; */
}
void test04()
{
    MString s("valeriominshuaibieyuan");
    /* MString s("bieyuan"); */
    cout << s << endl 
        << "size: " << s.size() << " capacity: " << s.capacity() 
        << " " << static_cast<const void*>(s.c_str()) << endl;
    /* char* p = &s[15]; */
    /* s.replace(7, 8, p, 7); */
    /* s.replace(7, 8, p, 7); */
    /* s.replace(s.begin()+7, s.begin()+15, s.rbegin(), s.rbegin()+7);; */
    /* s.replace(3, 2, s, 0, 10); */
    /* s.replace(0, 15, s); */
    s.replace(s.begin(), s.begin()+15, s.begin(), s.end());
    cout << s << endl 
        << "size: " << s.size() << " capacity: " << s.capacity() 
        << " " << static_cast<const void*>(s.c_str()) << endl;
}

void test05()
{
    MString str("There are two needles in this haystack with needles.");
    MString str2("needle");
    std::size_t found = str.find(str2);
    if(found != MString::npos)
        cout << "first 'neddle' found at: " << found << endl;

    found = str.find("needles are small", found+1, 6);
    if(found != MString::npos)
        cout << "second 'neddle' found at: " << found << endl;

    found = str.find("haystack");
    if(found != MString::npos)
        cout << "'haystack' also found at: " << found << endl;

    found = str.find('.');
    if(found != MString::npos)
        cout << "Period found at: " << found << endl;

    str.replace(str.find(str2), str2.length(), "preposition");
    cout << str << endl;

    found = str.find('p');
    if(found != MString::npos)
        cout << found << endl;
}
void test06()
{
    MString str ("sixth sick sheik's sixth sheep's sick.");
    MString key ("sabcde");
    /* char* p = nullptr; */
    /* std::size_t found = str.rfind(key, 5); */
    /* if (found!=MString::npos) */
    /*     str.replace (found,key.length(),"seventh"); */
    /* cout << str << endl; */
    /* cout << found << endl; */

    /* std::size_t found = str.find_last_of(key, 18); */
    std::size_t found = str.find_last_not_of('e');
    if(found != MString::npos){
        cout << "The character found is : '" << *(str.begin()+found)
            << "' Position: " << found << endl;
    }else{
        cout << "no found" << endl;
    }
    cout << str.size() << endl;
    return ;
}
void test07()
{
    string s("abcakocbhduaw,");
    char buf[255] = {0};
    int c_count = 0;
    for(char* p = &s[0]; p <= &s[0]+s.size(); ++p){
        int i = 0;
        for(i = 0; i < c_count; ++i){
            if(*p == buf[i])
                break;
        }
        if(i == c_count){
            buf[c_count++] = *p;
        }
    }
}

void test08()
{
    MString s{'a','b','c'};
    cout << s << endl;
}
int main()
{
    /* test(); */
    /* test01(); */
    /* test02(); */
    /* test03(); */
    /* test04(); */
    /* test05(); */
    /* test06();   //find系列函数 */
    /* test07();   //自定义函数 */
    test08();
    return 0;
}

