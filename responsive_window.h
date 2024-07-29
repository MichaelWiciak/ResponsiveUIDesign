//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVEWINDOW_H
#define RESPONSIVEWINDOW_H

#include "responsive_layout.h"
#include <QWidget>
#include <QScrollArea>

//using namespace std;

class ResponsiveWindow: public QWidget {

public:
    ResponsiveWindow();
    // Added a resize event
    void resizeEvent(QResizeEvent *e);


protected:
    void createWidgets();

private:
    ResponsiveLayout * rl;
    QWidget *widget;
    QScrollArea *scrollArea;
};


#endif //RESPONSIVEWINDOW_H
