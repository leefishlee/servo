#include "BottomWidget.h"

BottomWidget::BottomWidget(const QString& content, QWidget* parent)
{
    initUi();
}

void BottomWidget::initUi()
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(20, 0, 20, 0); // 根据需要调整边距
    mainLayout->setSpacing(10); // 根据需要调整间距

    ShadowWidget* Btn = new ShadowWidget(this);

    mainLayout->addWidget(Btn);
    mainLayout->addStretch(1); // 在按钮后面添加弹簧


    QStringList list1 = { tr("电流"), "0.0", tr("A") };
    QStringList list2 = { tr("速度"), "0.0", tr("rpm") };
    QStringList list3 = { tr("位置"), "0.0", tr("counts") };

    QList<QStringList> lists = { list1, list2, list3 };

    // 循环创建三组标签
    for (int i = 0; i < 3; ++i) {
        QHBoxLayout* groupLayout = new QHBoxLayout();
        groupLayout->setSpacing(20); // 设置组内组件的间距

        for (int j = 0; j < 3; ++j) {
            QLabel* label = new QLabel(lists[i][j]);
            if (j == 2) { // 每组的第三个标签加粗
                QFont font = label->font();
                font.setBold(true);
                label->setFont(font);
                mainLayout->addStretch(1); // 在按钮后面添加弹簧
            }
            groupLayout->addWidget(label);

        }

        mainLayout->addLayout(groupLayout);
        mainLayout->addStretch(1); // 在按钮后面添加弹簧

    }

    this->setLayout(mainLayout);

    // 设置阴影效果
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20); // 调整阴影效果参数
    shadowEffect->setColor(QColor(0, 0, 0, 160));
    shadowEffect->setOffset(4, 4);
    this->setGraphicsEffect(shadowEffect);

    // 设置背景颜色
    this->setStyleSheet("background-color:white;");

}
