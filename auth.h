#pragma once
#include <string>
#ifndef AUTH_H
#define AUTH_H

using namespace std;

bool sign_up(string& newUsername, string& newPassword); //This function exists to establish the proper conditions to sign up and create an account.
bool log_in(const string& newUsername, const string& newPassword); //This function establishes the conditions to log in successfully after an account has been created.

#endif
