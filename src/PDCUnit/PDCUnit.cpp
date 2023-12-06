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
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PDCUnitStubImpl> PDCUnitService;

    runtime = CommonAPI::Runtime::get();
    PDCUnitService = std::make_shared<PDCUnitStubImpl>();
    runtime->registerService("local", "PDCUnit", PDCUnitService);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);
    
    qmlRegisterType<PDCUnitQtClass>("DataModule", 1, 0, "PDCUnitQtClass");

    QQmlApplicationEngine engine;
    
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    
    if (cameras.isEmpty()) {
        qWarning("No camera available");
        return -1;
    }

    QCamera camera(cameras[0]);

    engine.rootContext()->setContextProperty("camera", &camera);

    engine.rootContext()->setContextProperty("carinfo", &carinfo);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    &app, [url](QObject *obj, const QUrl &objUrl)
    {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}

