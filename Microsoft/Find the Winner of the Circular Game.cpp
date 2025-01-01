/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        int i = 0;
        while (nums.size() > 1) {
            int idx = (i + k - 1) % nums.size();
            nums.erase(nums.begin() + idx);
            i = idx;
        }
        return nums[0];
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;

    int winner = sol.findTheWinner(n, k);
    cout << "The winner is friend number: " << winner << endl;

    return 0;
}

