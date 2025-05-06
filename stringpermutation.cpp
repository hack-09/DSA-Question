#include <bits/stdc++.h>

using namespace std;


void NextPermutation(string &str) {
    int n = str.length();
    int i = n - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }
    if (i < 0) {
        reverse(str.begin(), str.end());
        return;
    }
    int j = n - 1;
    while (j > i && str[j] <= str[i]) {
        j--;
    }
    swap(str[i], str[j]);
    reverse(str.begin() + i + 1, str.end());
}
int main() {
    string str = "2115";
    int n = str.length();
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));

    cout << endl;
    // Counting number of distinct permutations

    return 0;
}