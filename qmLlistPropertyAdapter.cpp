#include "qmLlistPropertyAdapter.h"

QmlListPropertyAdapter::QmlListPropertyAdapter(QObject *parent) : QObject(parent)
{

}

void QmlListPropertyAdapter::setData(const QList<std::shared_ptr<MyData>>& data)
{
    m_dataList = data;
    m_dataListAsPtr.clear();
    for(auto i:m_dataList){
        m_dataListAsPtr.append(i.get());
    }
}

QQmlListProperty<MyData> QmlListPropertyAdapter::getAdaptedValue()
{
    QQmlListProperty<MyData> property = QQmlListProperty<MyData>(this, m_dataListAsPtr);
    return property;
}
