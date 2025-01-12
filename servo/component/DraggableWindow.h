
#ifndef DraggableWidget_H
#define DRAGGABLEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class DraggableWidget : public QWidget {
    Q_OBJECT
public:
    explicit DraggableWidget(QWidget *parent = nullptr) : QWidget(parent) {
        this->setStyleSheet(  "background-color: rgb(242 ,244 ,252);");
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            m_dragPosition = event->globalPos() - frameGeometry().topLeft();
            event->accept();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (event->buttons() & Qt::LeftButton) {
            move(event->globalPos() - m_dragPosition);
            event->accept();
        }
    }

private:
    QPoint m_dragPosition;
};

#endif 
