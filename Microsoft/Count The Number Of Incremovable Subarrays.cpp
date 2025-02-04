/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool check(int start, int end, vector<int> &arr) {
        int n = arr.size();
        if (end - start + 1 == n) return true;

        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (i >= start && i <= end) continue;
            if (!temp.empty() && temp.back() >= arr[i]) return false;
            temp.push_back(arr[i]);
        }
        return true;
    }

public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size(), count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(i, j, arr)) count++;
            }
        }
        return count;
    }
};

int main() {
    return 0;
}
