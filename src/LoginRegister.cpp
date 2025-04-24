#include "LoginRegister.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool registerUser(const string& username, const string& password) {
    ofstream file("users.txt", ios::app);
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return false;
    }
    
    file << username << " " << password << endl;
    file.close();
    return true;
}

bool loginUser(const string& username, const string& password) {
    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return false;
    }
    
    string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}
