#include "topwidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

TopWidget::TopWidget(QWidget *parent) : QWidget(parent)
{
    InitUi();
}

void TopWidget::InitUi()
{


    QHBoxLayout* layout = new QHBoxLayout(this);

    //QLabel* placeholderLabel = new QLabel(this);
    //QPixmap placeholderPixmap(":/icons/mark.png"); // 替换为您图标文件的实际路径
    //placeholderLabel->setPixmap(placeholderPixmap.scaled(260, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // 根据需要调整尺寸和缩放方式
    //layout->addWidget(placeholderLabel);


    QLabel* tempLabel = new QLabel("");

    tempLabel->setFixedSize(30, 1);
    layout->addWidget(tempLabel);

    // 创建并配置按钮
    QPushButton* button1 = new QPushButton(QIcon(":/icons/connect.png"), tr("连接"));
    button1->setIconSize(QSize(26, 26));
    button1->setStyleSheet("QPushButton { border: none; }");
    layout->addWidget(button1);

    QPushButton* button2 = new QPushButton(QIcon(":/close.png"), tr("禁用"));
    button2->setIconSize(QSize(26, 26));
    button2->setStyleSheet("QPushButton { border: none; }");
    layout->addWidget(button2);

    QPushButton* button3 = new QPushButton(QIcon(":/icons/device.png"), tr("设备"));
    button3->setIconSize(QSize(26, 26));
    button3->setStyleSheet("QPushButton { border: none; }");
    layout->addWidget(button3);

    QPushButton* button4 = new QPushButton(QIcon(":/icons/save.png"), tr("保存"));
    button4->setIconSize(QSize(26, 26));
    button4->setStyleSheet("QPushButton { border: none; }");
    layout->addWidget(button4);

    // 在最后添加一个弹簧，使之前的控件靠左排列
    layout->addStretch(1);


    QPushButton* button5 = new QPushButton(QIcon(":/icons/alarm.png"), tr("告警"));
    button5->setIconSize(QSize(26, 26));
    button5->setStyleSheet("QPushButton { border: none; }");
    layout->addWidget(button5);

    QPushButton* button6 = new QPushButton(QIcon(":/icons/stop.png"), tr("急停"));
    button6->setIconSize(QSize(26, 26));
    button6->setStyleSheet("QPushButton { border: none; }");
    layout->addWidget(button6);


    layout->setContentsMargins(0, 0, 30, 0);

    layout->setSpacing(40);


    // 将布局设置到当前widget
    this->setLayout(layout);
}
