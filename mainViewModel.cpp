#include "mainViewModel.h"
#include <QDebug>

MainViewModel::MainViewModel(QObject *parent) : QObject(parent)
{

}

QQmlListProperty<MyData> MainViewModel::data()
{
//    QQmlListProperty<MyData> property = QQmlListProperty<MyData>(this, m_dataListAsPtr);
//    return property;
    return m_dataListAdapter.getAdaptedValue();
}

void MainViewModel::setData(const QList<std::shared_ptr<MyData>> &data)
{
    m_dataList = data;
    emit dataChanged();
}

void MainViewModel::addData(const QString &id, const QString &value)
{
    if(!validateNewMyData(id, value)){
        return;
    }
    std::shared_ptr<MyData> newData = std::make_shared<MyData>(id.toInt(),
                                                               value);
    m_dataList.append(newData);
    m_dataListAdapter.setData(m_dataList);
    setData(m_dataList);
}

bool MainViewModel::validateNewMyData(const QString &id, const QString &value){
    bool idOk = validateId(id);
    bool valOk = validateValue(value);
    return (idOk && valOk);
}

bool MainViewModel::validateId(const QString &id){
    if(id.trimmed().size() == 0){
        return false;
    }
    bool ok;
    id.toInt(&ok, 10);
    if(!ok){
        return false;
    }
    return true;
}

bool MainViewModel::validateValue(const QString &value){
    if(value.trimmed().size() == 0){
        return false;
    }else{
        return true;
    }
}


