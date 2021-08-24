#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstring>

using std::begin;
using std::cin;
using std::cout;
using std::cerr;
using std::end;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

// #define NDEBUG

void changeVal(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void reset(int &i)
{
    i = 0;
}

bool findUpper(const string &s)
{
    for (auto c : s)
    {
        if (isupper(c))
            return true;
    }
    return false;
}

void lowerStr(string &s)
{
    for (auto &c : s)
    {
        if (isupper(c))
            c = tolower(c);
    }
}

int sum(initializer_list<int> il)
{
    int s = 0;
    for (const auto &i : il)
        s += i;
    return s;
}

void showVec(const vector<int> &vec, vector<int>::const_iterator it){
    #ifndef NDEBUG
        cerr << "vector size: " << vec.size() << endl
            << __func__ << endl
            << __FILE__ << endl
            << __LINE__ << endl
            << __TIME__ << endl
            << __DATE__ <<endl;
    #endif

    if(it != vec.cend()){
        cout << *it << endl;
        showVec(vec,++it);
    }
}

// bool str_subrange(){
//     return;
// }

int &get(int *arry, int idx){return arry[idx];}

//6.5.2
constexpr int new_sz() {return 42;}
constexpr size_t scale(size_t cnt) {return new_sz() * cnt;}

int main(int argc, char *argv[])
{
    // //6.10
    // int i1 = 2, i2 = 3;
    // cout << i1 << ' ' << i2 << endl;
    // changeVal(&i1, &i2);
    // cout << i1 << ' ' << i2 << endl;
    // //6.17
    // string s = "aaaaaaaaaAADFDFassssssssssssddddddddddxcvxcvxcvqeqe";
    // cout << findUpper(s) << endl;
    // lowerStr(s);
    // cout << s << endl;
    // //6.25
    // cout << argc << endl;
    // if(argv)
    //     while(*argv)
    //         cout << *argv++<<endl;
    // //6.27
    // cout << sum({1, 2, 3, 4, 5, 6, 7}) << endl;
    // //6.32
    // int ia[10];
    // for(int i = 0; i != 10; i++)
    //     get(ia,i) = i;

    //6.33
    vector<int> iv = {1,2,3,4,5,6};
    showVec(iv,iv.cbegin());

    // //6.5.2
    // int i = 2;
    // cout << scale(i) <<endl;
    // int a[scale(i)];
    // int a[i];

    using pf = decltype(showVec)*;
    vector<pf> fv;
    
    int i;
    decltype(i = 0) k = i;

    return 0;
}
