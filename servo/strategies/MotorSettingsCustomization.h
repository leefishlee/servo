// MotorSettingsCustomization.h
#ifndef MOTORSETTINGSCUSTOMIZATION_H
#define MOTORSETTINGSCUSTOMIZATION_H

#include "PageCustomizationStrategy.h"
#include <QWidget>
#include"component/PageWidget.h"
class MotorSettingsCustomization : public PageCustomizationStrategy {
    Q_OBJECT
public:
    explicit MotorSettingsCustomization(QObject* parent = nullptr) : PageCustomizationStrategy(parent) {}

    void customize(QWidget* widget) override;
};

#endif // MOTORSETTINGSCUSTOMIZATION_H
