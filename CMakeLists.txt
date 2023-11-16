# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Define the project name as DESproject
project(DESproject)

# Enable auto UI generation, MOC, and RCC for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/5.15.0/gcc_64")

# Append C++ compiler flags, including -pthread and -std=c++0x
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")


# Find required Qt5 components (Core, Quick, Gui, Multimedia)
find_package(Qt5 COMPONENTS Core Quick Gui Multimedia WaylandCompositor REQUIRED)

# Find Python libraries
find_package(PythonLibs REQUIRED)

# Include Python include directories
include_directories(${PYTHON_INCLUDE_DIRS})

# Configure include and link directories
include_directories(
    src-gen-desproject
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
)
link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)


# Create executables and link libraries for the CANSender, PiracerSender, PiracerController, IPCManager, InstrumentCluster, HeadUnit, PDCUnit and IVICompositor targets
add_executable(CANSender
        src/CANSender/CANSender.cpp
        src/CANSender/ReadCANThread.c
        src/CANSender/SpeedBuffer.c
        src/CANSender/DistanceBuffer.c
        src/CANSender/SendSomeipThread.cpp
        src/CANSender/CANSenderStubImpl.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/CANSenderSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/CANSenderSomeIPDeployment.cpp
)
target_link_libraries(CANSender CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(PiracerSender
        src/PiracerSender/PiracerSender.cpp
        src/PiracerSender/PiracerClass.cpp
        src/PiracerSender/PiracerSenderStubImpl.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PiracerSenderSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/PiracerSenderSomeIPDeployment.cpp
)
target_link_libraries(PiracerSender ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(PiracerController
        src/PiracerController/PiracerController.cpp
        src/PiracerController/PiracerControllerStubImpl.cpp
        src/PiracerController/ControllerClass.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PiracerControllerSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/PiracerControllerSomeIPDeployment.cpp
)
target_link_libraries(PiracerController ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(IPCManager
        src/IPCManager/IPCManager.cpp
        src/IPCManager/IPCManagerStubImpl.cpp
        src/IPCManager/IPCManagerSenderClass.cpp
        src/IPCManager/PiracerClass.cpp
        src-gen-desproject/v1/commonapi/CANSenderSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/CANSenderSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PiracerSenderSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/PiracerSenderSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PiracerControllerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/PiracerControllerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/HeadUnitSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/HeadUnitSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PDCUnitSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/PDCUnitSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/IVICompositorSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IVICompositorSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/RemoteSpeakerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/RemoteSpeakerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(IPCManager ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(InstrumentCluster
        src/InstrumentCluster/InstrumentCluster.cpp
        src/InstrumentCluster/InstrumentClusterStubImpl.cpp
        src/InstrumentCluster/InstrumentClusterSenderClass.cpp
        src/InstrumentCluster/InstrumentClusterQtClass.cpp
        src/InstrumentCluster/qml.qrc
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPDeployment.cpp
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
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/HeadUnitSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/HeadUnitSomeIPDeployment.cpp
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
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PDCUnitSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/PDCUnitSomeIPDeployment.cpp
)
target_compile_definitions(PDCUnit
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(PDCUnit
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Multimedia CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(IVICompositor
        src/IVICompositor/IVICompositor.cpp
        src/IVICompositor/IVICompositorStubImpl.cpp
        src/IVICompositor/IVICompositorQtClass.cpp
        src/IVICompositor/IVICompositorSenderClass.cpp
        src/IVICompositor/qml.qrc
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/IVICompositorSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/IVICompositorSomeIPDeployment.cpp
)
target_compile_definitions(IVICompositor
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(IVICompositor
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Multimedia Qt5::WaylandCompositor CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(RemoteSpeaker
        src/RemoteSpeaker/RemoteSpeaker.cpp
        src/RemoteSpeaker/RemoteSpeakerStubImpl.cpp
        src/RemoteSpeaker/DataBuffer.cpp
        src-gen-desproject/v1/commonapi/RemoteSpeakerSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/RemoteSpeakerSomeIPDeployment.cpp
)
target_link_libraries(RemoteSpeaker CommonAPI CommonAPI-SomeIP vsomeip3)
