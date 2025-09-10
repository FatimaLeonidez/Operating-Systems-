#include <iostream>
#include <string>
using namespace std;

int main(){
    string username, password, new_username, new_password, choice1;
    cout << "Powering on..." << endl;
    cout << "Would you like to log in or sign up?" << endl;
    cin >> choice1;
    if (choice1 == "log in"){
        cout << "PLease enter username: " << endl;
        cin >> username;
        cout << "Please enter password" << endl;
        cin >> password;
        if (username == new_username && password == new_password){
            cout << "Entering..." << endl;
        }
        else{
            cout << "Wrong >:(" << endl;
        }
    }
    
    return 0;
}