#include <iostream>

using namespace std;

string format(int i) {
    string s{to_string(i)};
    for(auto it = s.begin(); it != s.end(); it++)
        if(*it != ' ' && it+1 != s.end())
            s.insert(it+1, 1, ' ');
    return s;
}

int main() {
    for(int i = 1; i <= 10000; i++)
        cout << format(i) << ' ';
}