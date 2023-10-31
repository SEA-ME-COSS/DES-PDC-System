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

# Append C++ compiler flags, including -pthread and -std=c++0x
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")


# Find required Qt5 components (Core, Quick, Gui, Multimedia)
find_package(Qt5 COMPONENTS Core Quick Gui Multimedia REQUIRED)

# Find Python libraries
find_package(PythonLibs REQUIRED)

# Include Python include directories
include_directories(${PYTHON_INCLUDE_DIRS})

# Configure include and link directories
include_directories(
    src-gen-desproject
    ${CMAKE_INCLUDE_PATH}/CommonAPI-3.2
    ${CMAKE_INCLUDE_PATH}
)
link_directories(
    ${CMAKE_LIBRARY_PATH}
)


# Create executables and link libraries for the CANSender, PiracerSender, PiracerOperator, IPCManager, InstrumentCluster, and HeadUnit targets
add_executable(CANSender
        src/CANSender/CANSender.cpp
        src/CANSender/ReadCANThread.c
        src/CANSender/CANBuffer.c
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

add_executable(PiracerOperator
        src/PiracerOperator/PiracerOperator.cpp
        src/PiracerOperator/ControllerClass.cpp
        src/PiracerOperator/PiracerOperatorStubImpl.cpp
        src/PiracerOperator/PiracerClass.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPDeployment.cpp
)
target_link_libraries(PiracerOperator ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(IPCManager
        src/IPCManager/IPCManager.cpp
        src/IPCManager/IPCManagerStubImpl.cpp
        src/IPCManager/IPCManagerSenderClass.cpp
        src-gen-desproject/v1/commonapi/CANSenderSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/CANSenderSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PiracerSenderSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/PiracerSenderSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/HeadUnitSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/HeadUnitSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(IPCManager CommonAPI CommonAPI-SomeIP vsomeip3)

add_executable(InstrumentCluster
        src/InstrumentCluster/InstrumentCluster.cpp
        src/InstrumentCluster/InstrumentClusterStubImpl.cpp
        src/InstrumentCluster/InstrumentClusterQtClass.cpp
        src/InstrumentCluster/qml.qrc
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


# Add install commands
install(TARGETS HeadUnit DESTINATION /usr/bin/headunit)
install(TARGETS CANSender DESTINATION /usr/bin/headunit)
install(TARGETS IPCManager DESTINATION /usr/bin/headunit)
install(TARGETS InstrumentCluster DESTINATION /usr/bin/headunit)
install(TARGETS PiracerOperator DESTINATION /usr/bin/headunit)
install(TARGETS PiracerSender DESTINATION /usr/bin/headunit)
