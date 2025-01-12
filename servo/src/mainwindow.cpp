#include "mainwindow.h"
#include <component/BottomWidget.h>
#include <component/PageWidget.h>
#include <component/TopWidget.h>
#include <QSplitter>
#include <QHeaderView>
#include <strategies/PageCustomizationStrategy.h> 
#include "StrategyFactory.h"


MainWindow::MainWindow(QWidget* parent)
{
	initUi();


	connect(treeWidget, &QTreeWidget::itemClicked, [&](QTreeWidgetItem* item, int) {
		if (nodeWidgetMap.contains(item)) {
			stackedWidget->setCurrentWidget(nodeWidgetMap.value(item));
		}
		});



	connect(treeWidget, &QTreeWidget::itemClicked, [&](QTreeWidgetItem* item, int) {
		// 如果之前有选中的父节点，重置其颜色
		if (lastSelectedParentItem) {
			lastSelectedParentItem->setBackground(0, QBrush(Qt::white)); // 重置背景颜色为默认
			lastSelectedParentItem->setForeground(0, QBrush(Qt::black)); // 重置文字颜色为默认
		}

		QTreeWidgetItem* parentItem = item->parent() ? item->parent() : item;

		// 更新上次选中的父节点指针
		lastSelectedParentItem = parentItem;

		// 为当前或父节点设置选中颜色
		parentItem->setBackground(0, QBrush(QColor(41, 171, 226))); // 设置背景颜色为蓝色
		parentItem->setForeground(0, QBrush(QColor(0, 102, 204))); // 将文字颜色设置为更深的蓝色

		// 如果点击的是子节点并且有对应的widget，则显示对应的widget
		if (item->parent() && nodeWidgetMap.contains(item)) {
			stackedWidget->setCurrentWidget(nodeWidgetMap.value(item));
		}
		else if (!item->parent()) {
			// 可以在这里处理顶层节点点击的逻辑，例如显示默认页面或特定信息
		}
		});


}

MainWindow::~MainWindow()
{
}

void MainWindow::initUi()
{
	this->resize(1200, 800);
	topWidget = new TopWidget(this);
	topWidget->setFixedHeight(50); // 可以设置固定高度

	QSplitter* splitter = new QSplitter(this);
	splitter->setOrientation(Qt::Horizontal);

	treeWidget = new QTreeWidget();

	treeWidget->setStyleSheet(qssStyle());

	treeWidget->setFocusPolicy(Qt::NoFocus);
	treeWidget->header()->hide();

	stackedWidget = new QStackedWidget();

	// 创建一个新的QWidget作为容器，用于垂直布局
	QWidget* containerWidget = new QWidget(this);
	QVBoxLayout* containerLayout = new QVBoxLayout(containerWidget);
	containerWidget->setLayout(containerLayout);
	

	nodeStructure = {
	  {tr("向导"), QStringList{"电机设置", "自动整定","应用设置"}},
	  {"控制", QStringList{"电流环", "速度环", "位置环"}},
	  {"配置", QStringList{"通信", "驱动器信息", "参数表", "功率级", "电机","反馈","限值","电流折返","数字I/O","模拟I/O","力控制","龙门架","误差校正","使能和故障"}},
	  {"运动", QStringList{"工作模式", "运动单位", "回零", "紧急停机"}},
	  {"调谐", QStringList{"示波器", "频率分析", "专家", "终端"}},
	  {"通用", QStringList{"偏好", "备份&恢复"}}
	};
	// 定义节点的插入顺序
	QList<QString> nodeOrder = { "向导", "配置", "控制", "运动", "调谐", "通用" };
	// 中文到英文的映射表
	QMap<QString, QString> chineseToEnglishMapping = {
		{tr("电机设置"), "Motor Settings"},
		{tr("自动整定"), "Auto Tuning"},
		{tr("应用设置"), "Application Settings"},
		{tr("电流环"), "Current Loop"},
		{tr("速度环"), "Speed Loop"},
		{tr("位置环"), "Position Loop"},
		{tr("通信"), "Communication"},
		{tr("驱动器信息"), "Driver Information"},
		{tr("参数表"), "Parameters Table"},
		{tr("功率级"), "Power Stage"},
		{tr("电机"), "Motor"},
		{tr("反馈"), "Feedback"},
		{tr("限值"), "Limits"},
		{tr("电流折返"), "Current Folding"},
		{tr("数字I/O"), "Digital I/O"},
		{tr("模拟I/O"), "Analog I/O"},
		{tr("力控制"), "Force Control"},
		{tr("龙门架"), "Gantry"},
		{tr("误差校正"), "Error Correction"},
		{tr("使能和故障"), "Enable and Fault"},
		{tr("工作模式"), "Work Mode"},
		{tr("运动单位"), "Motion Unit"},
		{tr("回零"), "Homing"},
		{tr("紧急停机"), "Emergency Stop"},
		{tr("示波器"), "Oscilloscope"},
		{tr("频率分析"), "Frequency Analysis"},
		{tr("专家"), "Expert"},
		{tr("终端"), "Terminal"},
		{tr("偏好"), "Preferences"},
		{tr("备份&恢复"), "Backup & Restore"}
	};



	// 按照指定顺序遍历和插入元素
	for (const auto& topLevelItemKey : nodeOrder) {
		QTreeWidgetItem* topLevelNode = new QTreeWidgetItem(treeWidget);
		topLevelNode->setText(0, topLevelItemKey);

		// 为父节点设置较大的字体
		QFont font = topLevelNode->font(0);
		font.setPointSize(font.pointSize() + 2); // 字体比默认大2个点
		topLevelNode->setFont(0, font);

		const QStringList& childItems = nodeStructure[topLevelItemKey];
		for (const QString& childText : childItems) {
			QTreeWidgetItem* childNode = new QTreeWidgetItem(topLevelNode);
			childNode->setText(0, childText);

			PageWidget* pageWidget = new PageWidget(childText);
			stackedWidget->addWidget(pageWidget);

			// 使用映射表转换中文名称为英文
			QString englishName = chineseToEnglishMapping.value(childText);

			// 根据当前页面的类型来选择正确的策略
			PageCustomizationStrategy* strategy = StrategyFactory::createStrategy(englishName, pageWidget);
			if (strategy) {
				
				strategy->customize(pageWidget);
				qDebug() << "获取策略";
			}		
			nodeWidgetMap.insert(childNode, pageWidget);

		}
	}

	stackedWidget->setStyleSheet("QStackedWidget { border: 10px solid transparent; }");

	// 自动调整列宽以适应内容
	 // 自动调整列宽以适应内容
	treeWidget->resizeColumnToContents(0);

	// 设置固定宽度
	treeWidget->setFixedWidth(200);

	// 向容器的布局中添加QStackedWidget和一个新的CustomWidget
	containerLayout->addWidget(stackedWidget);
	// 添加一个新的CustomWidget到布局中
	bottomWidget = new BottomWidget("底部固定区域");
	containerLayout->addWidget(bottomWidget);

	// 将容器QWidget添加到QSplitter
	splitter->addWidget(treeWidget);
	splitter->addWidget(containerWidget); // 使用容器替代直接添加stackedWidget

	QList<int> sizes = { 1, 3 };
	splitter->setSizes(sizes);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	mainLayout->setSpacing(0); // 设置组件间的间距
	// 将顶部QWidget添加到布局中
	mainLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->addWidget(topWidget);

	mainLayout->addWidget(splitter);
	this->setLayout(mainLayout);
	this->setStyleSheet("background-color: rgb(242, 244, 252);");

}

QString MainWindow::qssStyle()
{
	return
		QString(
			"QTreeWidget {"
			"    background-color: rgb(242, 244, 252);"
			"    border: none;"
			"}"

			"QTreeWidget::item {"
			"    border: none;"
			"    border-bottom: 1px solid #dcdcdc;"
			"    padding: 2px;"
			"}"

			"QTreeWidget::item:selected {"
			"    background-color: rgb(41,171,226);"
			"    color: white;"
			"}"

			"QTreeWidget::branch {"
			"    width: 30px;"
			"}"

			"QTreeWidget::branch:has-children:!has-siblings:closed,"
			"QTreeWidget::branch:closed:has-children:has-siblings {"
			"     border-image: none;"
			"     image: url(:/icons/right.png);"
			"}"

			"QTreeWidget::branch:open:has-children:!has-siblings,"
			"QTreeWidget::branch:open:has-children:has-siblings  {"
			"     border-image: none;"
			"     image: url(:/icons/down.png);"
			"}"

			// 添加滑动条的样式
			"QScrollBar:vertical {"
			"    width: 12px;" // 调整为您希望的宽度
			"    background: rgba(0, 0, 0, 0%);" // 背景透明
			"    margin: 0px 0px 0px 0px;" // 移除边距
			"    border: none;" // 无边框
			"}"

			"QScrollBar::handle:vertical {"
			"    background: rgb(200, 200, 200);" // 滑块的背景颜色
			"    min-height: 0px;" // 滑块最小高度
			"   border-radius: 6px; /* 滑块圆角 */"
			"}"

			"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
			"    height: 0px;" // 设置为0移除箭头
			"}"

			"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
			"    background: none;" // 页面背景（滑块外的区域）
			"}"
		);
}

PageWidget* MainWindow::findWidgetByChildText(const QString& childText)
{
	for (auto it = nodeWidgetMap.begin(); it != nodeWidgetMap.end(); ++it) {
		if (it.key()->text(0) == childText) {
			return it.value();
		}
	}
	return nullptr; // 如果找不到，返回 nullptr
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		m_dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::LeftButton) {
		move(event->globalPos() - m_dragPosition);
		event->accept();
	}
}
