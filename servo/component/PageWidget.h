#ifndef PAGEWIDGET_H // 如果没有定义PAGEWIDGET_H，则定义它
#define PAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QFrame>

class PageWidget : public QWidget {
public:
    explicit PageWidget(const QString &content, QWidget *parent = nullptr) ;
};
#endif // PAGEWIDGET_H 结束头文件保护