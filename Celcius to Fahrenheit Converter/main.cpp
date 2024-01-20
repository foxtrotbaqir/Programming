#include <iostream>

using namespace std;

int main()
{
    float c = 0;
    cout << "Enter a temperature: ";
    cin >> c;
    float c2f = (c*1.8)+32;
    cout << c << " degrees Celsius is "
<< c2f <<" degrees Fahrenheit" << endl;
    float f2c = (c-32)/1.8;
    cout << c << " degrees Fahrenheit is " <<
            f2c << " degrees Celsius" << endl;
    // Write your code here

    return 0;
}
