/*
 * main.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#include <iostream>

#include <QtWidgets/qapplication.h>

#include "IdleWindow.h"
#include "WorkWindow.h"
#include "ColdSpiderFsm.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    try {
        cout << "Cold Spider" << endl;

        IdleWindow idle;
        WorkWindow work;
        ColdSpiderContext context(work, idle);
        idle._context = &context;
        work._context = &context;

        context.start();

        return app.exec();

    } catch (exception const& e) {
        cerr << e.what() << endl;
    }
}

