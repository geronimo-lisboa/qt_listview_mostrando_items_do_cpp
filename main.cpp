#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "myData.h"
#include "mainViewModel.h"

void registerTypesInQML()
{
    qmlRegisterType<MyData>("don.geronimo",1,0, "MyData");
    qmlRegisterType<MainViewModel>("don.geronimo",1,0, "MainViewModel");
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    registerTypesInQML();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
