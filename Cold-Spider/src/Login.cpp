/*
 * Login.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#include <Login.h>

using namespace std;

Login::Login(const string& login) :
        _login(login) {
}

Login::~Login() {
}

bool Login::operator ==(const Login& r) const {
    return _login == r._login;
}

ostream& operator<<(ostream& out, const Login& r) {
    return out << r._login;
}
