#define AUTHENTICATOR_H
#ifndef AUTHENTICATOR_H
#include <string> 

class Authenticator{
    public:
        bool authenticate(const string& username, const string& password); 
}

#endif
