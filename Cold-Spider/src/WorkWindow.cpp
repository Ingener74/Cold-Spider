/*
 * WorkWindow.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#include "ColdSpiderFsm.h"
#include "WorkWindow.h"

WorkWindow::WorkWindow(QWidget* parent, Qt::WindowFlags f) :
        QWidget(parent, f) {
    setupUi(this);
    QObject::connect(pushButton, &QPushButton::clicked, this, &WorkWindow::onButton);
}

WorkWindow::~WorkWindow() {
}

void WorkWindow::onButton() {
    if (_context)
        _context->stop();
}
