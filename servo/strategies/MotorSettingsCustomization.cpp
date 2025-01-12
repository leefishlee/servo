#include "MotorSettingsCustomization.h"

void MotorSettingsCustomization::customize(QWidget* widget)
{

    // 实现具体的定制逻辑
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->setContentsMargins(10, 10, 10, 10); // 留出空间显示阴影
    layout->setSpacing(0);

    // 创建标题栏
    QFrame* titleBar = new QFrame(widget);
    titleBar->setStyleSheet("background-color:rgb(0,102,204)"); // 设置标题栏颜色
    titleBar->setFixedHeight(30); // 设置标题栏高度

    // 创建并设置标题栏的布局
    QHBoxLayout* titleLayout = new QHBoxLayout(titleBar);
    titleLayout->setContentsMargins(5, 0, 5, 0); // 设置标题栏内边距

    // 创建并添加标题文本
    QLabel* titleLabel = new QLabel(tr("电机设置"), titleBar);
    titleLabel->setStyleSheet("color: white;"); // 设置标题文本颜色
    titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // 标题文本左对齐，垂直居中
    titleLayout->addWidget(titleLabel);

    layout->addWidget(titleBar); // 将标题栏添加到主布局
    // 添加弹簧
    layout->addStretch(1);

    // 设置布局和阴影效果等...
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(widget);
    shadowEffect->setBlurRadius(20); // 增大模糊半径使阴影更强烈
    shadowEffect->setColor(QColor(0, 0, 0, 160)); // 调整阴影颜色和透明度使阴影更深
    shadowEffect->setOffset(4, 4); // 增大偏移量使阴影显得更远更深
    widget->setGraphicsEffect(shadowEffect);
    widget->setStyleSheet("background-color:white;");

    widget->setLayout(layout);


}
