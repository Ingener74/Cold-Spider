/*
 * WorkWindow.h
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#ifndef COLD_SPIDER_SRC_WORKWINDOW_H_
#define COLD_SPIDER_SRC_WORKWINDOW_H_

#include <QtWidgets/qwidget.h>
#include "ui_work.h"

class WorkWindow: public QWidget, public Ui_WorkForm {
public:
    WorkWindow(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~WorkWindow();

    void onButton();
    void onDoWorkButton();
    void onDoWorkButton2();

    void firstStage();
    void secondStage();

    void doWork();
    void doWork2(Login_cr);

    ColdSpiderContext* _context;
};

#endif /* COLD_SPIDER_SRC_WORKWINDOW_H_ */
