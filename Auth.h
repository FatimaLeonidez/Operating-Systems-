#pragma once
#include <string>
#ifndef AUTH_HEADER_H
#define AUTH_HEADER_H //comment: Don't worry about these. My file names on my VS are just different. Code is the same.

using namespace std;

bool sign_up(string& newUsername, string& newPassword);
bool log_in(const string& newUsername, const string& newPassword);

#endif
