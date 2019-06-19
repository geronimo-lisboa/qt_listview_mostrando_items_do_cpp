#ifndef QMLLISTPROPERTYADAPTER_H
#define QMLLISTPROPERTYADAPTER_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>
#include <memory>
#include "myData.h"


class QmlListPropertyAdapter : public QObject
{
    Q_OBJECT
public:
    explicit QmlListPropertyAdapter(QObject *parent = nullptr);
    void setData(const QList<std::shared_ptr<MyData>>& data);
    QQmlListProperty<MyData> getAdaptedValue();
signals:

public slots:
private:
    QList<std::shared_ptr<MyData>> m_dataList;
    QList<MyData*> m_dataListAsPtr;
};

#endif // QMLLISTPROPERTYADAPTER_H
