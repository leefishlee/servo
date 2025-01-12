#include "ShadowWidget.h"
#include <QVBoxLayout>
#include <QEvent>

ShadowWidget::ShadowWidget(QWidget *parent) : QWidget(parent) {
    button = new QPushButton(tr("操作模式"), this);
    button->setStyleSheet("background-color: rgb(0,102,204); color: white; padding: 5px; border-radius: 3px;");

    // 使用QFontMetrics计算文本尺寸
    QFontMetrics metrics(button->font());
    int textHeight = metrics.height();

    // 设置按钮高度为文本高度加上一些额外的边距
    button->setFixedHeight(textHeight + 10);

    // 初始化时没有阴影效果
    shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(8);
    shadowEffect->setColor(QColor(0, 0, 0, 0));
    button->setGraphicsEffect(shadowEffect);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    this->setLayout(layout);
}

void ShadowWidget::enterEvent(QEnterEvent *event) {
    // 鼠标进入时设置阴影效果
    shadowEffect->setBlurRadius(20);
    shadowEffect->setColor(QColor(0, 0, 0, 80));
    shadowEffect->setOffset(2, 2);
    QWidget::enterEvent(event);
}

void ShadowWidget::leaveEvent(QEvent *event) {
    // 鼠标离开时移除阴影效果
    shadowEffect->setBlurRadius(0);
    shadowEffect->setColor(QColor(0, 0, 0, 0));
    QWidget::leaveEvent(event);
}
