#ifndef SHADOWWIDGET_H
#define SHADOWWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QEvent>

class ShadowWidget : public QWidget {
    Q_OBJECT

public:
    explicit ShadowWidget(QWidget *parent = nullptr);

protected:

    void leaveEvent(QEvent *event) override;
    void enterEvent(QEnterEvent *event) override;

private:
    QPushButton *button;
    QGraphicsDropShadowEffect *shadowEffect;
};

#endif // SHADOWWIDGET_H
