//
// Created by twak on 07/10/2019.
//

#ifndef RESPONSIVELAYOUT_H
#define RESPONSIVELAYOUT_H

#include <QtGui>
#include <QList>
#include <QLayout>
#include <QScrollArea>

class ResponsiveLayout : public QLayout {
public:
    ResponsiveLayout(): QLayout() {}
    ~ResponsiveLayout();

    // standard functions for a QLayout
    void setGeometry(const QRect &rect);

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);
    int getMaxWidth();

private:
    QList<QLayoutItem*> list_;
    int maxHeight;
    int countOfSetGeometry=0;
};
#endif // RESPONSIVELAYOUT_H
