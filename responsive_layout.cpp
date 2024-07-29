//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>


using namespace std;

// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {

    QLayout::setGeometry(r);

    // Initialises our variables
    float percentOfWidth = r.width()/100;
    float percentOfHeight = r.height()/100;
    int countOfMenu = 0;
    int searchX=0, searchY=0;
    int countOfSearch = 0;
    int countOfAdvert = 0;
    this->maxHeight=0;
    int horizontalMode=0, compactMode=0, verticalMode=0;
    int initialScreen=0;
    // Check and calculate aspect ratios and decide what layout should be used
    double ratio = static_cast<double>(r.width()) / r.height();
    if (countOfSetGeometry<=3){
        horizontalMode=1;
        initialScreen=1;
    }
    else if (r.width()<500 && r.height()<500){
        compactMode = 1;
    }
    else if (ratio<=1.2){
        verticalMode=1;
    }
    else{
        horizontalMode=1;
    }
    countOfSetGeometry+=1;
    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {
        QLayoutItem *o = list_.at(i);
        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());
            if (label == NULL) // null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;
            // Assigns all of the widgets into appropriate positions
            else if (label -> text() == kNavTabs )
                if (compactMode==1){
                    label -> setGeometry(-1,-1,0,0);
                }
                else{
                    label -> setGeometry(r.x()+percentOfWidth,(2*r.height()/20)+r.y()+2*percentOfHeight,r.width()-2*percentOfWidth, r.height()/10 - 2*percentOfHeight);
                }
            else if (label -> text() == kSearchResult ){
                if (horizontalMode==1){
                    if (searchY==4&&initialScreen==1){
                        label -> setGeometry(-1,-1,0,0);
                    }
                    else if (searchX==0){
                        label -> setGeometry(0+r.x()+5*percentOfWidth, (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6), r.width()/6 -1*percentOfWidth, r.width()/6 -1*percentOfWidth);
                        searchX++;
                        this->maxHeight= (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6)+ r.width()/6;
                    }
                    else if (searchX==3){
                        label -> setGeometry(0+r.x()+5*percentOfWidth + searchX*r.width()/6, (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6), r.width()/6 -1*percentOfWidth, r.width()/6 -1*percentOfWidth);
                        searchX=0;
                        searchY++;
                        this->maxHeight=  (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6) + r.width()/6;
                    }
                    else {
                        label -> setGeometry(0+r.x()+5*percentOfWidth + searchX*r.width()/6, (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6), r.width()/6 -1*percentOfWidth, r.width()/6 -1*percentOfWidth);
                        searchX++;
                        this->maxHeight= (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6) + r.width()/6;
                    }
                    countOfSearch++;
                }
                else if (verticalMode==1){
                    int sizeBuffer = (2*r.height()/10)+r.y()+percentOfHeight*9 + 3*r.height()/20 + r.height()/10;
                    label -> setGeometry(0+r.x()+5*percentOfWidth, sizeBuffer + searchY*(1.5*r.width()/2 -percentOfWidth), 1.5*r.width()/2 -6*percentOfWidth, 1.5*r.width()/2 -6*percentOfWidth);
                    searchY++;
                    countOfSearch++;
                    this->maxHeight= sizeBuffer + searchY*(1.5*r.width()/2 -percentOfWidth) -4*percentOfWidth;
                }
                else{ // Has to be compact mode.
                    label -> setGeometry(0+r.x()+1*percentOfWidth, (4*r.height()/5)+r.y()+2*percentOfHeight + searchY*(r.width() -1*percentOfWidth), r.width() -2*percentOfWidth, r.width() -2*percentOfWidth);
                    searchY++;
                    countOfSearch++;
                    this->maxHeight= (4*r.height()/5)+r.y()+2*percentOfHeight + searchY*(r.width() -1*percentOfWidth);
                }
            }
            else if (label -> text() == kHomeLink ){
                if (compactMode==1){
                    label -> setGeometry (0+r.x() + percentOfWidth,0+r.y()+percentOfHeight,(2*r.width()/5) -2*percentOfWidth,r.height()/5 - percentOfHeight);
                }
                else if (horizontalMode==1){
                    label -> setGeometry (0+r.x() + percentOfWidth,0+r.y() + percentOfHeight,(2*r.width()/5) -2*percentOfWidth,r.height()/20 - percentOfHeight);
                }
                else{
                    label -> setGeometry (0+r.x() + percentOfWidth,0+r.y() + percentOfHeight,(2*r.width()/5) -2*percentOfWidth,r.height()/20 - percentOfHeight);
                }
            }
            else if (label -> text() == kLanguage )
                if (compactMode==1){
                    label -> setGeometry (-1, -1, 0, 0);
                }
                else{
                    label -> setGeometry (r.width()-(3*r.width()/5)+r.x() + percentOfWidth,0+r.y() + percentOfHeight,(r.width()/5) -2*percentOfWidth,r.height()/20 - percentOfHeight);
                }

            else if (label -> text() == kShoppingBasket )
                if (compactMode==1){
                    label -> setGeometry (r.width()-r.width()/5+r.x(),0+r.y() + percentOfHeight,r.width()/5 - 1*percentOfWidth,r.height()/5 - percentOfHeight);
                }
                else{
                    label -> setGeometry (r.width()-r.width()/5+r.x() + 1*percentOfWidth,0+r.y() + percentOfHeight,r.width()/5 - 2*percentOfWidth,r.height()/20 - percentOfHeight);
                }

            else if (label -> text() == kSignIn )
                if (compactMode==1){
                    label -> setGeometry (r.width()-(3*r.width()/5)+r.x() + 1*percentOfWidth,0+r.y() + percentOfHeight,(r.width()/5) -2*percentOfWidth + (r.width()/5) -percentOfWidth,r.height()/5 - percentOfHeight);
                }
                else{
                    label -> setGeometry (r.width()-(2*r.width()/5)+r.x() + 1*percentOfWidth,0+r.y() + percentOfHeight,(r.width()/5) -2*percentOfWidth,r.height()/20 - percentOfHeight);
                }

            else if (label -> text() == kMenu ){
                if ((verticalMode==1||compactMode==1) && countOfMenu>=2){
                    label -> setGeometry (-1,-1,0,0);
                }
                else if (compactMode==1){
                    label -> setGeometry (r.x()+ countOfMenu*(r.width()/2)+percentOfWidth,(r.height()/5)+r.y()+percentOfHeight,(r.width()/2)-2*percentOfWidth, (r.height()/5));
                    countOfMenu+=1;
                }
                else if (verticalMode==1){
                    label -> setGeometry (r.x()+ countOfMenu*(r.width()/2)+percentOfWidth,(r.height()/20)+r.y()+percentOfHeight,(r.width()/2)-2*percentOfWidth, (r.height()/20));
                    countOfMenu+=1;
                }
                else{
                    label -> setGeometry (r.x()+ countOfMenu*(r.width()/5)+percentOfWidth,(r.height()/20)+r.y()+percentOfHeight,(r.width()/5)-2*percentOfWidth, (r.height()/20));
                    countOfMenu+=1;
                }
            }
            else if (label -> text() == kAdvert ){
                if (countOfAdvert>=2){
                    label -> setGeometry (-1,-1,0,0);
                }
                else if (compactMode==1){
                    label -> setGeometry (-1,-1,0,0);
                    countOfAdvert++;
                }
                else if (verticalMode==1){
                    if (countOfAdvert==0){
                        label -> setGeometry (0+r.x()+percentOfWidth*5,(2*r.height()/10)+r.y()+percentOfHeight*8 + 3*r.height()/20,r.width()-10*percentOfWidth, r.height()/10);
                        countOfAdvert++;
                    }
                    else if (countOfAdvert==1){
                        label -> setGeometry (0+r.x()+1.5*r.width()/2+percentOfWidth, (2*r.height()/10)+r.y()+percentOfHeight*9 + 3*r.height()/20 + r.height()/10 ,0.5*r.width()/2-6*percentOfWidth, searchY*(1.5*r.width()/2 -percentOfWidth) -5*percentOfWidth);
                        countOfAdvert++;
                    }
                }
                else{
                    if (countOfAdvert==0){
                        label -> setGeometry (0+r.x()+percentOfWidth*5,(3.25*r.height()/10)+r.y(),r.width()-10*percentOfWidth, r.height()/10);
                        countOfAdvert++;
                    }
                    else if (countOfAdvert==1){
                        label -> setGeometry (0+r.x()+5*percentOfWidth + 4*r.width()/6,(4.25*r.height()/10)+r.y() + 1*percentOfWidth,2*r.width()/6-10*percentOfWidth, searchY*(r.width()/6) -1*percentOfWidth );
                        countOfAdvert++;
                    }
                }
            }
            else if (label -> text() == kSearchText)
                if (verticalMode==1){
                    label -> setGeometry (0+r.x()+percentOfWidth*5,(2*r.height()/10)+r.y()+percentOfHeight*5,(r.width())-percentOfWidth*10, r.height()/20);
                }
                else if (compactMode==1){
                    label -> setGeometry (0+r.x()+percentOfWidth,(2*r.height()/5)+r.y()+2*percentOfHeight,(r.width())-2*percentOfWidth, r.height()/5-percentOfHeight);
                }
                else{
                    label -> setGeometry (0+r.x()+percentOfWidth*5,(2*r.height()/10)+r.y()+percentOfHeight*5,(3*r.width()/5)-percentOfWidth*5, r.height()/20);
                }
            else if (label -> text() == kSearchButton)
                if (verticalMode ==1){
                    label -> setGeometry (0+r.x() + 5*percentOfWidth,(2*r.height()/10)+r.y()+percentOfHeight*7 + 2*r.height()/20,r.width()/5, r.height()/20);
                }
                else if (compactMode==1){
                    label -> setGeometry (3*r.width()/4+r.x() + percentOfWidth,(3*r.height()/5)+r.y()+2*percentOfHeight,r.width()/4 - 2*percentOfWidth, r.height()/5-percentOfHeight);
                }
                else
                {
                    label -> setGeometry ((2*r.width()/5)+r.x()+2*r.width()/5 +percentOfWidth,(2*r.height()/10)+r.y()+percentOfHeight*5,(r.width()/5) -6*percentOfWidth, r.height()/20);
                }
            else if (label -> text() == kSearchOptions ){
                if (verticalMode==1){
                    label -> setGeometry (0+r.x() + 5*percentOfWidth,(2*r.height()/10)+r.y()+percentOfHeight*6 + r.height()/20,(r.width())-10*percentOfWidth, r.height()/20);
                }
                else if (compactMode==1){
                    label -> setGeometry (0+r.x() + percentOfWidth,(3*r.height()/5)+r.y()+2*percentOfHeight,3*r.width()/4 - percentOfWidth, r.height()/5-percentOfHeight);
                }
                else{
                    label -> setGeometry ((2*r.width()/5)+r.x()+r.width()/5 +percentOfWidth,(2*r.height()/10)+r.y()+percentOfHeight*5,(r.width()/5)-percentOfWidth, r.height()/20);
                }
            }
            else if (label -> text() == kSearchForward ){
                if (initialScreen==1){
                    label -> setGeometry(-1,-1,0,0);
                }
                else if (compactMode==1){
                    label -> setGeometry (r.width()/2+1*percentOfWidth, this->maxHeight+80,r.width()/2-2*percentOfWidth, 80-percentOfWidth);
                    this->maxHeight+= 80;
                }
                else if (verticalMode==1){
                    label -> setGeometry (r.width()/2+1*percentOfWidth, this->maxHeight+80,r.width()/2-6*percentOfWidth, 80-percentOfWidth);
                    this->maxHeight+= 80;
                }

                else{
                    label -> setGeometry (0+r.x()+5.5*percentOfWidth + 4*r.width()/6 + (2*r.width()/6-10*percentOfWidth)/2, (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6) + r.width()/12, (2*r.width()/6-10*percentOfWidth)/2 - percentOfWidth/2, r.width()/12 -1*percentOfWidth);
                }
            }
            else if (label -> text() == kSearchBackward ){
                if (initialScreen==1){
                    label -> setGeometry(-1,-1,0,0);
                }
                else if (compactMode==1){
                    label -> setGeometry (0+r.x()+percentOfWidth, this->maxHeight+80,r.width()/2-2*percentOfWidth, 80-percentOfWidth);
                }
                else if (verticalMode==1){
                    label -> setGeometry (0+r.x()+5*percentOfWidth, this->maxHeight+80,r.width()/2-6*percentOfWidth, 80-percentOfWidth);
                }
                else{
                    label -> setGeometry (0+r.x()+5*percentOfWidth + 4*r.width()/6, (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6) + r.width()/12, (2*r.width()/6-10*percentOfWidth)/2 - percentOfWidth/2, r.width()/12 -1*percentOfWidth);
                }
            }

            else if (label -> text() == kRefresh ){
                if (initialScreen==1){
                    label -> setGeometry(-1,-1,0,0);
                }
                else if (compactMode==1){
                    label -> setGeometry (0+r.x()+percentOfWidth, this->maxHeight - 80,r.width() - 2*percentOfWidth, 80-percentOfWidth);
                    this->maxHeight+= 80+percentOfWidth;
                }
                else if (verticalMode==1){
                    label -> setGeometry (0+r.x()+5*percentOfWidth, this->maxHeight - 80,r.width() - 10*percentOfWidth, 80-percentOfWidth);
                    this->maxHeight+= 80;
                }
                else{
                    label -> setGeometry (0+r.x()+5*percentOfWidth + 4*r.width()/6, (4.25*r.height()/10)+r.y() + 1*percentOfWidth + searchY*(r.width()/6), 2*r.width()/6-10*percentOfWidth, r.width()/12 -1*percentOfWidth);
                }
            }


            else // otherwise: disappear label by moving out of bounds
                label -> setGeometry (-1,-1,0,0);

        }
        catch (std::bad_cast) {
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }
    }
}

// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

int ResponsiveLayout::getMaxWidth() {
    return this->maxHeight;
}
