#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MAINVIEWMODEL_H
