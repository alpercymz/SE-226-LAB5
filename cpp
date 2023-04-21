#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include <algorithm>
using namespace std;
vector<string> words = {"apple", "banana", "orange", "kiwi", "grape", "pear", "peach", "pineapple"};
string pass_gen(){
    int userNumber = 3;
    while (3<=userNumber<=7){
        cout<<"Enter the words number that you want to select from the list (between [3,7] included): "<<endl;
        cin>>userNumber;
        cout<<userNumber<<endl;
        if (userNumber<3 or userNumber>7) {
            cout << "Wrong Number !" << endl;
            userNumber = 3;
        }
        else {
            break;
        }
    }
    vector<string> userWords;
    for (int i = 0; i < userNumber ; ++i) {
        string word = words[rand() % words.size()];
        userWords.push_back(word);
        cout<<word<<endl;
    }
    string password = "";
    for (string & word : userWords) {
        password += word;

    }
    reverse(password.begin(), password.end());
    cout<<"User Password is : "<<password<<endl;
    return password;
}
string rep_with_upper(string parola){
    string result;
    char randomLetter= parola[rand()%parola.size()];
    for (char c : parola) {
        if (c==randomLetter) {
            result += ::toupper(c);
        }
        else{
            result+=c;

        }

    }
    return result;
}
string swap_letters(string sifre){
    string head=sifre.substr(0,2);
    string tail=sifre.substr(sifre.size()-2);
    string mid = sifre.substr(2,sifre.size()-4);
    string updPassword = tail + mid + head;
    cout<<updPassword<<endl;
    return updPassword;
}
bool search_letter(string sifre, char letter){
    bool isFound= false;

    for (int i = 0; i < sifre.size(); ++i) {
        if (sifre[i] == letter)
            isFound= true;
            break;
    }
    return isFound;
}
int main() {
    string passworddd = pass_gen();
    string newPassword = rep_with_upper(passworddd);
    string sonParola = swap_letters(newPassword);

    cout << "Is 'a' in the password? :" << search_letter(sonParola,'a')<< endl;
    return 0;
}
