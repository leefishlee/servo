#include "MainWindow.h"

#include <QApplication>
#include<StrategyFactory.h>
#include "StrategyFactory.h"
#include<strategies/MotorSettingsCustomization.h>





int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    StrategyFactory::registerStrategies();

 
    MainWindow w;
    w.show();
    return a.exec();
}
