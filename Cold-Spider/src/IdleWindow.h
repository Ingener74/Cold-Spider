/*
 * IdleWindow.h
 *
 *  Created on: Dec 19, 2015
 *      Author: pavel
 */

#ifndef COLD_SPIDER_SRC_IDLEWINDOW_H_
#define COLD_SPIDER_SRC_IDLEWINDOW_H_

#include <QtWidgets/qwidget.h>
#include "ui_idle.h"

class IdleWindow: public QWidget, public Ui_IdleForm {
public:
    IdleWindow(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~IdleWindow();

    void onButton();

    class ColdSpiderContext* _context;
};

#endif /* COLD_SPIDER_SRC_IDLEWINDOW_H_ */
