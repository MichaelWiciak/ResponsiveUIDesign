#ifndef RESPONSIVEQSCROLLAREA_H
#define RESPONSIVEQSCROLLAREA_H

#include <iostream>
#include <QApplication>
#include <QScrollArea>

// Extended class of scroll area for better functionality
class responsiveQScrollArea : public QScrollArea
{
    using QScrollArea::QScrollArea;
public:

    virtual void resizeEvent(QResizeEvent *event) override
    {
        // Define content margins here
        setViewportMargins(0, 0, 0, 0);
        QScrollArea::resizeEvent(event);
    }
    virtual QSize sizeHint() const override;
};

#endif // RESPONSIVEQSCROLLAREA_H



