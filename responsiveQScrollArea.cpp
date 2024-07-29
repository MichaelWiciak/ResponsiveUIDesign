#include "responsiveQScrollArea.h"

// Improves the scrollArea class byy adding an additional margin
QSize responsiveQScrollArea::sizeHint() const {
    auto widgetSize = widget()->sizeHint();
    return QSize(widgetSize.width()+6,widgetSize.height()+6);
}
