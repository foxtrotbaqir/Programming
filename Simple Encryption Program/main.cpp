#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string eword;
    int len = 0;
    cout << "Enter the encryption key: ";
    getline(cin, word);
    len =word.length();
    // Checking if the string is 26 characters long or not.
    if(len!=26){
        cout << "Error! The encryption key must contain 26 characters."<<endl;
        exit(EXIT_FAILURE);
    }
    // Checking if all characters in string are lowercase or not
    for(int i=0;i<len;++i){
        if(islower(word.at(i))==false){
            cout <<  "Error! The encryption key must contain only lower case characters."<<endl;
            //break;
            exit(EXIT_FAILURE);
        }
    }
    // Checking if only all English alphabets
    for(char c: alphabet){ // a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z

            int count = 0;
            for(char d: word){ // test word= a,b,c,d,e,f,g,h,j,k,l,m,n,o,p,q,r,s,t,u,v,w,z,y,x

                if(c==d){

                    break;
                }
                else{

                    if(count==25){
                    cout<<"Error! The encryption key must contain all alphabets a-z."<< endl;
                    exit(EXIT_FAILURE);
                     }
                }
                count = count+1;
            }
    }

    // check word to be encrypted stayawhileandlisten
    cout << "Enter the text to be encrypted: ";
    getline(cin, eword);
    // Checking if all characters in string are lowercase or not
    for(char c: eword){
        if(islower(c)==false){
            cout <<  "Error! The text to be encrypted must contain only lower case characters."<<endl;
            exit(EXIT_FAILURE);
        }
    }
    // encrypt read
    string encrypted;
    for(char c: eword){ // char length of "stayawhileandlisten" = 19
        size_t pos = alphabet.find(c); // pos of [n] at alphabet =
        if(pos!=string::npos){
            char d = word.at(pos); // encryption key at 0 = q
            encrypted += d; // [uyq]
        }
        else{
            encrypted += c;
        }

    }
    cout <<"Encrypted text: "<< encrypted << endl;
    return 0;
}
