/*
 * Login.h
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#ifndef COLD_SPIDER_SRC_LOGIN_H_
#define COLD_SPIDER_SRC_LOGIN_H_

#include <string>
#include <iostream>

class Login {
public:
    Login(const std::string& login);
    virtual ~Login();

    bool operator==(const Login&) const;

    friend std::ostream& operator<<(std::ostream&, const Login&);

    std::string _login;
};

typedef const Login& Login_cr;

const Login TestLogin("Test");

#endif /* COLD_SPIDER_SRC_LOGIN_H_ */
