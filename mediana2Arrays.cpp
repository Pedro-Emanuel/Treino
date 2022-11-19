#include <iostream>
#include <vector>

using namespace std;

void juntarArrays(vector<int>& ar1, vector<int>& ar2, vector<int>& ar3) {
    auto it1 = ar1.begin();
    auto it2 = ar2.begin();

    while(it1 != ar1.end() && it2 != ar2.end()) {
        if(*(it1) <= *(it2)) {
            ar3.push_back(*(it1));
            it1++;
        } else {
            ar3.push_back(*(it2));
            it2++;
        }
    }

    if(it1 != ar1.end())
        while(it1 != ar1.end()) {
            ar3.push_back(*(it1));
            it1++;
        }
    else
        while(it2 != ar2.end()) {
            ar3.push_back(*(it2));
            it2++;
        }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ar3;
    juntarArrays(nums1, nums2, ar3);
    int tam = (int) ar3.size();
    if(tam % 2 == 0)
        return (ar3.at(tam / 2) + ar3.at((tam / 2) - 1)) / 2.0;
    return ar3.at(tam / 2);
}

int main() {
    vector<int> ar1 = {1,3,4,6,7}, ar2 = {1,2,5};
    cout << findMedianSortedArrays(ar1, ar2) << '\n';
}