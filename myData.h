#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>

class MyData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value
               READ value
               WRITE setValue
               NOTIFY valueChanged)
    Q_PROPERTY(int id
               READ id
               WRITE setId
               NOTIFY idChanged)
public:
    explicit MyData(QObject *parent = nullptr);
    explicit MyData(const int id, const QString val, QObject *parent = nullptr);
    ~MyData() override;
    QString value();
    void setValue(const QString &val);
    int id();
    void setId(const int _id);
signals:
    void valueChanged();
    void idChanged();
public slots:
private:
    QString m_value;
    int m_id;
};

#endif // MYDATA_H
