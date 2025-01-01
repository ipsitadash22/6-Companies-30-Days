/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //formula use (x-h)^2+(y-k)^2<=r^2(formula if the points x and y lies in circle)
        //where h and k are center
        for(int x = x1; x <= x2; x++) {
            for(int y = y1; y <= y2; y++) {
                //ham check kar rhe hai ki har point lie karta hai kya circle mai
                int result = ((x - xCenter) * (x - xCenter)) + ((y - yCenter) * (y - yCenter));
                
                if(result <= (radius * radius)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int radius, xCenter, yCenter, x1, y1, x2, y2;

    // Taking input from the user
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "Enter the x and y coordinates of the circle's center: ";
    cin >> xCenter >> yCenter;

    cout << "Enter the bottom-left corner coordinates of the rectangle (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the top-right corner coordinates of the rectangle (x2, y2): ";
    cin >> x2 >> y2;

    Solution sol;
    bool result = sol.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);

    // Displaying the result
    if (result) {
        cout << "The circle and rectangle overlap." << endl;
    } else {
        cout << "The circle and rectangle do not overlap." << endl;
    }

    return 0;
}
