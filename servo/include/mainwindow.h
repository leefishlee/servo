#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QTreeWidget>
#include <QMap>
#include <QStackedWidget>
#include <QTreeWidgetItem>
#include <component/TopWidget.h>
#include <QMouseEvent>
#include <component/BottomWidget.h>
#include <component/PageWidget.h>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void initUi();

	QTreeWidget* treeWidget;
	QStackedWidget* stackedWidget;
	QMap<QTreeWidgetItem*, PageWidget*> nodeWidgetMap;
	TopWidget* topWidget;

	QString qssStyle();

	// 类成员变量初始化为nullptr
	QTreeWidgetItem* lastSelectedParentItem = nullptr;

	QMap<QString, QStringList> nodeStructure;

	BottomWidget* bottomWidget;

	QMap<QString, QString> nameMapping;

	PageWidget* findWidgetByChildText(const QString& childText);
protected:
	void mousePressEvent(QMouseEvent* event) override;

	void mouseMoveEvent(QMouseEvent* event) override;

private:
	QPoint m_dragPosition;
};
#endif // MAINWINDOW_H
