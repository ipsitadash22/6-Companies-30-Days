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
    int smooth(vector<vector<int>>& img, int x, int y){
        int m = img.size();
        int n = img[0].size();
        int sum = 0;
        int count = 0;

   //loop will traverse all 9 valid indexes of the 3*3 matrix
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
                int xIdx = x + i;
                int yIdx = y + j;
                if (xIdx >= 0 && yIdx >= 0 && xIdx < m && yIdx < n) {
                    sum += img[xIdx][yIdx];
                    count++;
                }
            }

        return sum / count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));//initiallised a vector array with 0

        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                ans[i][j] = smooth(img, i, j);
            }
        }
        return ans;
    }
};

/* 
   NOTE !!! 
   
   Main error was because I was passing entire array in the function 
   thats why memeory limit was exceeded so instead pass address only  
   (pass by reference)
   */

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> img(m, vector<int>(n));
    cout << "Enter the elements of the image matrix row by row:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> img[i][j];
        }
    }

    Solution sol;
    vector<vector<int>> result = sol.imageSmoother(img);

    // Print the resulting smoothed image
    cout << "Smoothed Image:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

