/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int targetno;
        if (n % 2 == 0) {
            targetno = (nums[(n / 2)] + nums[((n / 2) - 1)]) / 2;
        } else {
            targetno = (nums[n / 2]);
        }
        int finmoves = 0;
        for (int i = 0; i < n; i++) {
            finmoves += abs(targetno - nums[i]);
        }
        return finmoves;
    }
};


int main() {
    Solution solution;

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = solution.minMoves2(nums);
    cout << "Minimum moves to equalize array: " << result << endl;

    return 0;
}
