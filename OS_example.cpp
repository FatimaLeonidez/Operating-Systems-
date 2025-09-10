#include <iostream>
using namespace std;

int main() {
    string debby;
    int carl;

    for (int i = 0; i < 5; i++) {
        cin >> carl;
        cin >> debby;
        cout << carl << "Hello, world, " << debby << endl;

        if(carl == 43 && debby == "Debra")
        {
            cout << "Success! Welcome to the club!" << endl;
            cout << "@@@@@" << endl;
            cout << "@@@@@" << endl;
            cout << "@@ @@" << endl;
        }
        else {
            cout << "No entry! Sorry, loser!" << endl;
        }
    }
}