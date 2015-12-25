/*
 * IdleWindow.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#include <iostream>

#include "IdleWindow.h"
#include "ColdSpiderFsm.h"

using namespace std;

IdleWindow::IdleWindow(QWidget* parent, Qt::WindowFlags f) :
        QWidget(parent, f) {
    setupUi(this);
    QObject::connect(pushButton, &QPushButton::clicked, this, &IdleWindow::onButton);
}

IdleWindow::~IdleWindow() {
}

void IdleWindow::onButton() {
    if (_context)
        _context->start(Login(loginLineEdit->text().toStdString()));
}

void IdleWindow::loginAction(Login_cr login) {
    cout << login << endl;
}
