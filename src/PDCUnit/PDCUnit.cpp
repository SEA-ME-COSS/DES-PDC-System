#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>
#include <QCamera>
#include <QCameraInfo>

#include "PDCUnitStubImpl.hpp"
#include "PDCUnitQtClass.hpp"

using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    // Initialize the CommonAPI runtime and PDCUnitService
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PDCUnitStubImpl> PDCUnitService;

    // Create a CommonAPI runtime and register the PDCUnit service
    runtime = CommonAPI::Runtime::get();
    PDCUnitService = std::make_shared<PDCUnitStubImpl>();
    runtime->registerService("local", "PDCUnit", PDCUnitService);

    // Initialize the Qt Application
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);
    
    // Register the PDCUnitQtClass as a QML type
    qmlRegisterType<PDCUnitQtClass>("DataModule", 1, 0, "PDCUnitQtClass");

    // Initialize the QML Application Engine
    QQmlApplicationEngine engine;
    
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    
    if (cameras.isEmpty()) {
        qWarning("No camera available");
        return -1;
    }

    QCamera camera(cameras[0]);

    engine.rootContext()->setContextProperty("camera", &camera);

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

    return app.exec();
}

