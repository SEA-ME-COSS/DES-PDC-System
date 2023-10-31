#include <QGuiApplication>          // Include the QGuiApplication for Qt GUI applications.
#include <QQmlApplicationEngine>     // Include QQmlApplicationEngine for Qt Quick applications.
#include <QQmlContext>              // Include QQmlContext for setting context properties.
#include <QCursor>

#include "InstrumentClusterStubImpl.hpp"    // Include the InstrumentClusterStubImpl class.
#include "InstrumentClusterQtClass.hpp"     // Include the InstrumentClusterQtClass, which provides Qt integration.
#include "InstrumentClusterSenderClass.hpp" // Include the InstrumentClusterSenderClass class.

using namespace v1_0::commonapi; // Use the commonapi namespace.

int main(int argc, char *argv[])
{
    // Initialize CommonAPI runtime and InstrumentCluster service.
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<InstrumentClusterStubImpl> InstrumentClusterService;

    runtime = CommonAPI::Runtime::get();               // Get the CommonAPI runtime.
    InstrumentClusterService = std::make_shared<InstrumentClusterStubImpl>(); // Create the InstrumentCluster service.
    runtime->registerService("local", "InstrumentCluster", InstrumentClusterService); // Register the service.

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);  // Enable high-DPI scaling for Qt application.
    QGuiApplication app(argc, argv);  // Create a Qt GUI application.
    
    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);
    
    QQmlApplicationEngine engine;    // Create a Qt Quick Application Engine for QML.

    // Set a context property for "carinfo" to interact with the QML application.
    engine.rootContext()->setContextProperty("carinfo", &carinfo);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml")); // Define the URL for the QML interface.

    // Connect a lambda function to exit the application if object creation fails.
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);  // Load the QML interface from the specified URL.
    
    InstrumentClusterSenderClass sender;
    sender.IPCManagerTargetProxy->getGearMode("InstrumentCluster", sender.callStatus, sender.returnMessage);
    sender.IPCManagerTargetProxy->getDirection("InstrumentCluster", sender.callStatus, sender.returnMessage);
    sender.IPCManagerTargetProxy->getLight("InstrumentCluster", sender.callStatus, sender.returnMessage);

    return app.exec();  // Start the application event loop and return the exit code.
}

