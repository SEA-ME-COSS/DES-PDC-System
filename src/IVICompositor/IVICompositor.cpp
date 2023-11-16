#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>

#include "IVICompositorStubImpl.hpp"
#include "IVICompositorQtClass.hpp"
#include "IVICompositorSenderClass.hpp"

//using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    // Initialize the CommonAPI runtime and IVICompositorService
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IVICompositorStubImpl> IVICompositorService;

    // Create a CommonAPI runtime and register the IVICompositor service
    runtime = CommonAPI::Runtime::get();
    IVICompositorService = std::make_shared<IVICompositorStubImpl>();
    runtime->registerService("local", "IVICompositor", IVICompositorService);

    // Initialize the Qt Application
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);

    // Initialize the QML Application Engine
    QQmlApplicationEngine engine;
    
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
    
    IVICompositorSenderClass sender;
    sender.IPCManagerTargetProxy->getGearMode("IVICompositor", sender.callStatus, sender.returnMessage);

    return app.exec();
}

