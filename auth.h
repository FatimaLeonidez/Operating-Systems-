#pragma once
#include <string>
#ifndef AUTH_H
#define AUTH_H

using namespace std;

bool sign_up(string& newUsername, string& newPassword);
bool log_in(const string& newUsername, const string& newPassword);

#endif
