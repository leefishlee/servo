#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include"ShadowWidget.h"

class BottomWidget : public QWidget {
public:
    explicit BottomWidget(const QString& content, QWidget* parent = nullptr);
    void initUi();
};

#endif // BOTTOMWIDGET_H
