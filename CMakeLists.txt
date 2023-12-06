cmake_minimum_required(VERSION 3.15)
project(DESproject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(Qt5 COMPONENTS Core Quick Gui Multimedia WaylandCompositor REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
    ${PYTHON_INCLUDE_DIRS}
)
include_directories(
    ${CMAKE_INCLUDE_PATH}/CommonAPI-3.2
    ${CMAKE_INCLUDE_PATH}
)
link_directories(
    ${CMAKE_LIBRARY_PATH}
)
include_directories(
    src-gen/CANSender/core/common
    src-gen/CANSender/core/proxy
    src-gen/CANSender/core/skel
    src-gen/CANSender/core/stub
    src-gen/CANSender/someip/common
    src-gen/CANSender/someip/proxy
    src-gen/CANSender/someip/stub

    src-gen/PiracerSender/core/common
    src-gen/PiracerSender/core/proxy
    src-gen/PiracerSender/core/skel
    src-gen/PiracerSender/core/stub
    src-gen/PiracerSender/someip/common
    src-gen/PiracerSender/someip/proxy
    src-gen/PiracerSender/someip/stub

    src-gen/PiracerController/core/common
    src-gen/PiracerController/core/proxy
    src-gen/PiracerController/core/skel
    src-gen/PiracerController/core/stub
    src-gen/PiracerController/someip/common
    src-gen/PiracerController/someip/proxy
    src-gen/PiracerController/someip/stub

    src-gen/IPCManager/core/common
    src-gen/IPCManager/core/proxy
    src-gen/IPCManager/core/skel
    src-gen/IPCManager/core/stub
    src-gen/IPCManager/someip/common
    src-gen/IPCManager/someip/proxy
    src-gen/IPCManager/someip/stub

    src-gen/InstrumentCluster/core/common
    src-gen/InstrumentCluster/core/proxy
    src-gen/InstrumentCluster/core/skel
    src-gen/InstrumentCluster/core/stub
    src-gen/InstrumentCluster/someip/common
    src-gen/InstrumentCluster/someip/proxy
    src-gen/InstrumentCluster/someip/stub

    src-gen/HeadUnit/core/common
    src-gen/HeadUnit/core/proxy
    src-gen/HeadUnit/core/skel
    src-gen/HeadUnit/core/stub
    src-gen/HeadUnit/someip/common
    src-gen/HeadUnit/someip/proxy
    src-gen/HeadUnit/someip/stub

    src-gen/PDCUnit/core/common
    src-gen/PDCUnit/core/proxy
    src-gen/PDCUnit/core/skel
    src-gen/PDCUnit/core/stub
    src-gen/PDCUnit/someip/common
    src-gen/PDCUnit/someip/proxy
    src-gen/PDCUnit/someip/stub

    src-gen/IVICompositor/core/common
    src-gen/IVICompositor/core/proxy
    src-gen/IVICompositor/core/skel
    src-gen/IVICompositor/core/stub
    src-gen/IVICompositor/someip/common
    src-gen/IVICompositor/someip/proxy
    src-gen/IVICompositor/someip/stub

    src-gen/RemoteSpeaker/core/common
    src-gen/RemoteSpeaker/core/proxy
    src-gen/RemoteSpeaker/core/skel
    src-gen/RemoteSpeaker/core/stub
    src-gen/RemoteSpeaker/someip/common
    src-gen/RemoteSpeaker/someip/proxy
    src-gen/RemoteSpeaker/someip/stub
)


set(SOMEIP_PROXY_PATH someip/proxy/v1/commonapi/)
set(SOMEIP_DEPLOYMENT_PATH someip/common/v1/commonapi/)
set(SOMEIP_STUBADAPTER_PATH someip/stub/v1/commonapi/)


add_executable(CANSender
        src/CANSender/CANSender.cpp
        src/CANSender/ReadCANThread.c
        src/CANSender/SpeedBuffer.c
        src/CANSender/DistanceBuffer.c
        src/CANSender/SendSomeipThread.cpp
        src/CANSender/CANSenderStubImpl.cpp
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/CANSender/${SOMEIP_STUBADAPTER_PATH}/CANSenderSomeIPStubAdapter.cpp
        src-gen/CANSender/${SOMEIP_DEPLOYMENT_PATH}/CANSenderSomeIPDeployment.cpp
)
target_link_libraries(CANSender CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(PiracerSender
        src/PiracerSender/PiracerSender.cpp
        src/PiracerSender/PiracerClass.cpp
        src/PiracerSender/PiracerSenderStubImpl.cpp
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/PiracerSender/${SOMEIP_STUBADAPTER_PATH}/PiracerSenderSomeIPStubAdapter.cpp
        src-gen/PiracerSender/${SOMEIP_DEPLOYMENT_PATH}/PiracerSenderSomeIPDeployment.cpp
)
target_link_libraries(PiracerSender ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(PiracerController
        src/PiracerController/PiracerController.cpp
        src/PiracerController/PiracerControllerStubImpl.cpp
        src/PiracerController/ControllerClass.cpp
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/PiracerController/${SOMEIP_STUBADAPTER_PATH}/PiracerControllerSomeIPStubAdapter.cpp
        src-gen/PiracerController/${SOMEIP_DEPLOYMENT_PATH}/PiracerControllerSomeIPDeployment.cpp
)
target_link_libraries(PiracerController ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(IPCManager
        src/IPCManager/IPCManager.cpp
        src/IPCManager/IPCManagerStubImpl.cpp
        src/IPCManager/IPCManagerSenderClass.cpp
        src/IPCManager/PiracerClass.cpp
        src-gen/CANSender/${SOMEIP_PROXY_PATH}/CANSenderSomeIPProxy.cpp
        src-gen/CANSender/${SOMEIP_DEPLOYMENT_PATH}/CANSenderSomeIPDeployment.cpp
        src-gen/PiracerSender/${SOMEIP_PROXY_PATH}/PiracerSenderSomeIPProxy.cpp
        src-gen/PiracerSender/${SOMEIP_DEPLOYMENT_PATH}/PiracerSenderSomeIPDeployment.cpp
        src-gen/PiracerController/${SOMEIP_PROXY_PATH}/PiracerControllerSomeIPProxy.cpp
        src-gen/PiracerController/${SOMEIP_DEPLOYMENT_PATH}/PiracerControllerSomeIPDeployment.cpp
        src-gen/InstrumentCluster/${SOMEIP_PROXY_PATH}/InstrumentClusterSomeIPProxy.cpp
        src-gen/InstrumentCluster/${SOMEIP_DEPLOYMENT_PATH}/InstrumentClusterSomeIPDeployment.cpp
        src-gen/HeadUnit/${SOMEIP_PROXY_PATH}/HeadUnitSomeIPProxy.cpp
        src-gen/HeadUnit/${SOMEIP_DEPLOYMENT_PATH}/HeadUnitSomeIPDeployment.cpp
        src-gen/PDCUnit/${SOMEIP_PROXY_PATH}/PDCUnitSomeIPProxy.cpp
        src-gen/PDCUnit/${SOMEIP_DEPLOYMENT_PATH}/PDCUnitSomeIPDeployment.cpp
        src-gen/IVICompositor/${SOMEIP_PROXY_PATH}/IVICompositorSomeIPProxy.cpp
        src-gen/IVICompositor/${SOMEIP_DEPLOYMENT_PATH}/IVICompositorSomeIPDeployment.cpp
        src-gen/RemoteSpeaker/${SOMEIP_PROXY_PATH}/RemoteSpeakerSomeIPProxy.cpp
        src-gen/RemoteSpeaker/${SOMEIP_DEPLOYMENT_PATH}/RemoteSpeakerSomeIPDeployment.cpp
        src-gen/IPCManager/${SOMEIP_STUBADAPTER_PATH}/IPCManagerSomeIPStubAdapter.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(IPCManager ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(InstrumentCluster
        src/InstrumentCluster/InstrumentCluster.cpp
        src/InstrumentCluster/InstrumentClusterStubImpl.cpp
        src/InstrumentCluster/InstrumentClusterSenderClass.cpp
        src/InstrumentCluster/InstrumentClusterQtClass.cpp
        src/InstrumentCluster/qml.qrc
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/InstrumentCluster/${SOMEIP_STUBADAPTER_PATH}/InstrumentClusterSomeIPStubAdapter.cpp
        src-gen/InstrumentCluster/${SOMEIP_DEPLOYMENT_PATH}/InstrumentClusterSomeIPDeployment.cpp
)
target_compile_definitions(InstrumentCluster
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(InstrumentCluster
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(HeadUnit
        src/HeadUnit/HeadUnit.cpp
        src/HeadUnit/HeadUnitStubImpl.cpp
        src/HeadUnit/HeadUnitQtClass.cpp
        src/HeadUnit/HeadUnitSenderClass.cpp
        src/HeadUnit/qml.qrc
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/HeadUnit/${SOMEIP_STUBADAPTER_PATH}/HeadUnitSomeIPStubAdapter.cpp
        src-gen/HeadUnit/${SOMEIP_DEPLOYMENT_PATH}/HeadUnitSomeIPDeployment.cpp
)
target_compile_definitions(HeadUnit
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(HeadUnit
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Multimedia CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(PDCUnit
        src/PDCUnit/PDCUnit.cpp
        src/PDCUnit/PDCUnitStubImpl.cpp
        src/PDCUnit/PDCUnitQtClass.cpp
        src/PDCUnit/PDCUnitSenderClass.cpp
        src/PDCUnit/qml.qrc
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/PDCUnit/${SOMEIP_STUBADAPTER_PATH}/PDCUnitSomeIPStubAdapter.cpp
        src-gen/PDCUnit/${SOMEIP_DEPLOYMENT_PATH}/PDCUnitSomeIPDeployment.cpp
)
target_compile_definitions(PDCUnit
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(PDCUnit
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Multimedia CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(IVICompositor
        src/IVICompositor/IVICompositor.cpp
        src/IVICompositor/IVICompositorStubImpl.cpp
        src/IVICompositor/IVICompositorQtClass.cpp
        src/IVICompositor/qml.qrc
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/IVICompositor/${SOMEIP_STUBADAPTER_PATH}/IVICompositorSomeIPStubAdapter.cpp
        src-gen/IVICompositor/${SOMEIP_DEPLOYMENT_PATH}/IVICompositorSomeIPDeployment.cpp
)
target_compile_definitions(IVICompositor
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(IVICompositor
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Multimedia Qt5::WaylandCompositor CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(RemoteSpeaker
        src/RemoteSpeaker/RemoteSpeaker.cpp
        src/RemoteSpeaker/RemoteSpeakerStubImpl.cpp
        src/RemoteSpeaker/DataBuffer.cpp
        src-gen/IPCManager/${SOMEIP_PROXY_PATH}/IPCManagerSomeIPProxy.cpp
        src-gen/IPCManager/${SOMEIP_DEPLOYMENT_PATH}/IPCManagerSomeIPDeployment.cpp
        src-gen/RemoteSpeaker/${SOMEIP_STUBADAPTER_PATH}/RemoteSpeakerSomeIPStubAdapter.cpp
        src-gen/RemoteSpeaker/${SOMEIP_DEPLOYMENT_PATH}/RemoteSpeakerSomeIPDeployment.cpp
)
target_link_libraries(RemoteSpeaker CommonAPI CommonAPI-SomeIP vsomeip3)


# Add install commands
install(TARGETS CANSender DESTINATION /usr/bin/pdc)
install(TARGETS InstrumentCluster DESTINATION /usr/bin/pdc)
install(TARGETS IVICompositor DESTINATION /usr/bin/pdc)
install(TARGETS PiracerController DESTINATION /usr/bin/pdc)
install(TARGETS RemoteSpeaker DESTINATION /usr/bin/pdc)
install(TARGETS HeadUnit DESTINATION /usr/bin/pdc)
install(TARGETS IPCManager DESTINATION /usr/bin/pdc)
install(TARGETS PDCUnit DESTINATION /usr/bin/pdc)
install(TARGETS PiracerSender DESTINATION /usr/bin/pdc)

