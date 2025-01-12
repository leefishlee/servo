// StrategyFactory.h
#ifndef STRATEGYFACTORY_H
#define STRATEGYFACTORY_H

#include <QObject>
#include <QString>
#include <functional>
#include <QMap>
#include<strategies/MotorSettingsCustomization.h>
class PageCustomizationStrategy;

class StrategyFactory {
public:
	using StrategyConstructor = std::function<PageCustomizationStrategy* (QObject*)>;

	static QMap<QString, StrategyConstructor> strategies;

	static void registerStrategy(const QString& name, StrategyConstructor constructor) {
		strategies.insert(name, constructor);
	}

	static PageCustomizationStrategy* createStrategy(const QString& name, QObject* parent = nullptr) {
		if (strategies.contains(name)) {
			return strategies.value(name)(parent);
		}
		return nullptr;
	}

	// ��һ�������ĳ�ʼ��������ע�������
	static void registerStrategies() {
		// ����ע�����в�����
		StrategyFactory::registerStrategy("Motor Settings", [](QObject* parent) -> PageCustomizationStrategy* {
			return new MotorSettingsCustomization(parent);
			});


	}

};

#endif // STRATEGYFACTORY_H
