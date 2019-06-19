#include "mainViewModel.h"
#include <QDebug>

MainViewModel::MainViewModel(QObject *parent) : QObject(parent)
{

}

QQmlListProperty<MyData> MainViewModel::data()
{
    return m_dataListAdapter.getAdaptedValue();
}

void MainViewModel::setData(const QList<std::shared_ptr<MyData>> &data)
{
    m_dataList = data;
    m_dataListAdapter.setData(m_dataList);
    emit dataChanged();
}

void MainViewModel::addData(const QString &id, const QString &value)
{
    if(!validateNewMyData(id, value)){
        return;
    }
    std::shared_ptr<MyData> newData = std::make_shared<MyData>(id.toInt(),
                                                               value, this);
    m_dataList.append(newData);
    setData(m_dataList);
}

void MainViewModel::deleteData(int id)
{
    for(int i=0; i<m_dataList.count(); i++){
        if(m_dataList[i]->id()==id){
            m_dataList.removeAt(i);
            break;
        }
    }
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


