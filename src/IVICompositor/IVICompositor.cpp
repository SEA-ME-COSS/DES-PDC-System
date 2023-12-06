#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>
#include <string>

#include "IVICompositorStubImpl.hpp"
#include "IVICompositorQtClass.hpp"

using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IVICompositorStubImpl> IVICompositorService;

    runtime = CommonAPI::Runtime::get();
    IVICompositorService = std::make_shared<IVICompositorStubImpl>();
    runtime->registerService("local", "IVICompositor", IVICompositorService);
    
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);

    QQmlApplicationEngine engine;
    
    engine.rootContext()->setContextProperty("carinfo", &carinfo);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    &app, [url](QObject *obj, const QUrl &objUrl)
    {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    
    IPCManagerTargetProxy->getGearMode("IVICompositor", callStatus, returnMessage);

    return app.exec();
}

