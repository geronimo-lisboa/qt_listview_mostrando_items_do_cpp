#include "myData.h"
#include <QDebug>
MyData::MyData(QObject *parent) : QObject(parent)
{

}

MyData::MyData(const int id, const QString val, QObject *parent):
    QObject (parent),
    m_value(val),
    m_id(id)
{

}

MyData::~MyData()
{
    qDebug()<<"Deletando "<<m_id<<", "<<m_value;
}

QString MyData::value()
{
    return m_value;
}

void MyData::setValue(const QString &val)
{
    if(m_value == val)
    {
        return;
    }
    else
    {
        m_value = val;
        emit valueChanged();
    }
}

int MyData::id()
{
    return m_id;
}

void MyData::setId(const int _id)
{
    if(m_id == _id)
    {
        return;
    }
    else
    {
        m_id = _id;
        emit idChanged();
    }
}
