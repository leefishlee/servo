#ifndef PAGEWIDGET_H // ���û�ж���PAGEWIDGET_H��������
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
#endif // PAGEWIDGET_H ����ͷ�ļ�����