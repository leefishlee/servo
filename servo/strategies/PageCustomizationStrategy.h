// PageCustomizationStrategy.h
#ifndef PAGECUSTOMIZATIONSTRATEGY_H
#define PAGECUSTOMIZATIONSTRATEGY_H

#include <QObject>
#include <QWidget>
#include"component/PageWidget.h"
class PageCustomizationStrategy : public QObject {
    Q_OBJECT
public:
    explicit PageCustomizationStrategy(QObject* parent = nullptr) : QObject(parent) {}

    virtual void customize(QWidget* widget) = 0;

signals:
    void customizationDone();
};

#endif // PAGECUSTOMIZATIONSTRATEGY_H
