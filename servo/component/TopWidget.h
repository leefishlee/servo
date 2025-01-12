#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>

class TopWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TopWidget(QWidget *parent = nullptr);

    void InitUi();
};

#endif // TOPWIDGET_H
