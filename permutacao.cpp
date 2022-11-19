#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string getPermutation(int n, int k) {
    string num;

    for(int i = 0; i < n; i++)
        num += to_string(i + 1);
    
    for(int i = 0; i < k - 1; i++) {
        next_permutation(num.begin(), num.end());
    }
    
    return {num};
}

int main() {
    cout << getPermutation(3, 6) << '\n';
}