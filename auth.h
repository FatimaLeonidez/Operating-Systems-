#ifndef AUTH_H
#define AUTH_H

#include <string> 
using namespace std;

void sign_up(string& newUsername, string& newPassword); 
bool log_in(const string& newUsername, const string& newPassword);

#endif
