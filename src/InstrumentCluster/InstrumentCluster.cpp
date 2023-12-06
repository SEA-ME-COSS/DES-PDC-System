#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>

#include "InstrumentClusterStubImpl.hpp"
#include "InstrumentClusterQtClass.hpp"
#include "InstrumentClusterSenderClass.hpp"

using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<InstrumentClusterStubImpl> InstrumentClusterService;

    runtime = CommonAPI::Runtime::get();
    InstrumentClusterService = std::make_shared<InstrumentClusterStubImpl>();
    runtime->registerService("local", "InstrumentCluster", InstrumentClusterService);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);
    
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("carinfo", &carinfo);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    
    InstrumentClusterSenderClass sender;
    sender.IPCManagerTargetProxy->getGearMode("InstrumentCluster", sender.callStatus, sender.returnMessage);
    sender.IPCManagerTargetProxy->getDirection("InstrumentCluster", sender.callStatus, sender.returnMessage);
    sender.IPCManagerTargetProxy->getLight("InstrumentCluster", sender.callStatus, sender.returnMessage);

    return app.exec();
}

