#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include <QSharedPointer>
#include <QList>
#include <QQmlListProperty>
#include <memory>

#include "myData.h"
#include "qmLlistPropertyAdapter.h"


class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<MyData> datas
               READ data
               NOTIFY dataChanged)
public:
    explicit MainViewModel(QObject *parent = nullptr);
    QQmlListProperty<MyData> data();
    void setData(const QList<std::shared_ptr<MyData>> &data);

    Q_INVOKABLE void addData(const QString &id, const QString &value);
    Q_INVOKABLE void deleteData(int id);
signals:
    void dataChanged();
public slots:

private:
    QList<std::shared_ptr<MyData>> m_dataList;
    QmlListPropertyAdapter m_dataListAdapter;
    bool validateNewMyData(const QString &id, const QString &value);
    bool validateId(const QString &id);
    bool validateValue(const QString &value);
};

#endif // MAINVIEWMODEL_H
