#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    cout << "Enter a number: ";
    cin >> n;
    int cube = pow(n,3);
    double int_range = pow(2,32);
    if((cube < int_range) && (cube > (-1*int_range))){
    cout << "The cube of " << n << " is " << cube << "." << endl;
    }
    else{
        cout << "Error! The cube of " << n << " is not " << cube << "." << endl;
    }
    return EXIT_SUCCESS;
}
