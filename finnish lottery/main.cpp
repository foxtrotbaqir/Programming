#include <iostream>

using namespace std;
unsigned long int win_probability(int total_balls,int drawn_balls);
unsigned long int factorial(int num);
int main()
{
    int nbt;
    int nbd;
    cout << "Enter the total number of lottery balls: ";
    cin >> nbt;
    cout << "Enter the number of drawn balls: ";
    cin >> nbd;
    if(nbt<1){
        cout << "The number of balls must be a positive number." << endl;
        exit(EXIT_SUCCESS);
    }
    if(nbd>nbt){
        cout << "The maximum number of drawn balls is the total amount of balls."<<endl;
        exit(EXIT_SUCCESS);
    }
    unsigned long int result = win_probability(nbt,nbd);
    cout << "The probability of guessing all " << nbd << " balls correctly is 1/" << result <<endl;
    return EXIT_SUCCESS;
}
unsigned long int win_probability(int total_balls,int drawn_balls){
    // first add a factorial function which calculates the factorial of a number
    unsigned long int answer = (factorial(total_balls))/((factorial(total_balls-drawn_balls))*(factorial(drawn_balls)));
    return answer;
}
unsigned long int factorial(int num){
    unsigned long int answer = 1;
    for(int i =0;i<num;++i){
        answer = (num-i)*answer;
    }
    return answer;
}
