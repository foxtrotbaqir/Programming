#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int diff1 =0;
    int diff2=0;
    // Write your code here
    int n = 0;
    cin >> n;
    if(n<=0){
        cout << "Only positive numbers accepted" << endl;
    }
    else{
        diff2 = n;
        for(int i=1;i<=n;++i){
            if(n % i == 0){
              a = i;
              b = n/a;
              diff1 = b-a;
            }
        if((diff1 < diff2) && (diff1 >=0) ){
            c = a;
            d = b;
            diff2 = diff1;
        }
        }
    cout << n << " = " << c << " * " << d << endl;
    }

    return 0;
}
