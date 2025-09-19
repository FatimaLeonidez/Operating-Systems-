#include <iostream>
#include <string>
using namespace std;

int main(){
    string username, password, new_username, new_password, choice1;
    cout << "Powering on..." << endl;
    cout << "Would you like to log in or sign up?" << endl;
    getline(cin, choice1);

    if (choice1 == "sign up"){
        cout << "Enter  username: " << endl;
        getline(cin, new_username);
        cout << "Enter  password:" << endl;
        getline(cin, new_password);
        cout << "(8 charatcers minimimum including a lowercase and uppercase letter, number, and special character): " << endl;
            
    }
    else if (choice1 == "log in"){
        cout << "PLease enter username: " << endl;
        getline(cin, username);
        cout << "Please enter password" << endl;
        getline(cin, password);
        if (username == new_username && password == new_password){
            cout << "Entering..." << endl;
        }
        else{
            cout << "Wrong >:(" << endl;
        }
    }
    
    return 0;

