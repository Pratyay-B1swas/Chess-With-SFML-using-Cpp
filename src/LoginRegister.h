#ifndef LOGIN_REGISTER_H
#define LOGIN_REGISTER_H

#include <string>

bool registerUser(const std::string& username, const std::string& password);
bool loginUser(const std::string& username, const std::string& password);

#endif // LOGIN_REGISTER_H
