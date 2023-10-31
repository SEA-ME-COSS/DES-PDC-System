#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>

#include "HeadUnitStubImpl.hpp"
#include "HeadUnitQtClass.hpp"
#include "HeadUnitSenderClass.hpp"

using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    // Initialize the CommonAPI runtime and HeadUnitService
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<HeadUnitStubImpl> HeadUnitService;

    // Create a CommonAPI runtime and register the HeadUnit service
    runtime = CommonAPI::Runtime::get();
    HeadUnitService = std::make_shared<HeadUnitStubImpl>();
    runtime->registerService("local", "HeadUnit", HeadUnitService);

    // Initialize the Qt Application
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);

    // Register the HeadUnitQtClass as a QML type
    qmlRegisterType<HeadUnitQtClass>("DataModule", 1, 0, "HeadUnitQtClass");

    // Initialize the QML Application Engine
    QQmlApplicationEngine engine;

    // Set the "carinfo" context property in QML to the carinfo object
    engine.rootContext()->setContextProperty("carinfo", &carinfo);

    // Load the main QML file from resources
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    // Connect the engine objectCreated signal to handle application exit
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    &app, [url](QObject *obj, const QUrl &objUrl)
    {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // Load the QML file and start the application event loop
    engine.load(url);
    
    HeadUnitSenderClass sender;
    sender.IPCManagerTargetProxy->getGearMode("HeadUnit", sender.callStatus, sender.returnMessage);
    sender.IPCManagerTargetProxy->getDirection("HeadUnit", sender.callStatus, sender.returnMessage);
    sender.IPCManagerTargetProxy->getLight("HeadUnit", sender.callStatus, sender.returnMessage);

    return app.exec();
}

