#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H
#include <string> 
using namespace std;

class Authenticator{
    public:
        bool authenticate(const string& username, const string& password); 
}

#endif
