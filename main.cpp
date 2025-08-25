#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Interface/Interface.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/CarScreen/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    // 3) 关联 CPP 对象
    engine.rootContext()->setContextProperty("ui", INTERFACE);
    engine.load(url);

    return app.exec();
}
