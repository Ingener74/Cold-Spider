/*
 * WorkWindow.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#include <iostream>

#include "ColdSpiderFsm.h"
#include "WorkWindow.h"

using namespace std;

WorkWindow::WorkWindow(QWidget* parent, Qt::WindowFlags f) :
        QWidget(parent, f) {
    setupUi(this);
    QObject::connect(pushButton, &QPushButton::clicked, this, &WorkWindow::onButton);
    QObject::connect(workPushButton, &QPushButton::clicked, this, &WorkWindow::onDoWorkButton);
    QObject::connect(workPushButton2, &QPushButton::clicked, this, &WorkWindow::onDoWorkButton2);
}

WorkWindow::~WorkWindow() {
}

void WorkWindow::onButton() {
    if (_context)
        _context->stop();
}

void WorkWindow::onDoWorkButton() {
    if (_context)
        _context->doWork();
    cout << "doWork button" << endl;
}

void WorkWindow::onDoWorkButton2() {
    if (_context)
        _context->doWork2(TestLogin);
}

void WorkWindow::firstStage() {
    label->setText(QString("Первая стадия"));
}

void WorkWindow::secondStage() {
    label->setText(QString("Вторая стадия"));
}

void WorkWindow::doWork() {
    label->setText(QString("Делать работу"));
    cout << __PRETTY_FUNCTION__ << endl;
}

void WorkWindow::doWork2(Login_cr login) {
    cout << __PRETTY_FUNCTION__ << " " << login << endl;
}
