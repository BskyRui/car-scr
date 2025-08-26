cmake_minimum_required(VERSION 3.16)

project(CarScreen VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 自动调用 Qt 的资源编译器 (rcc) 来处理 .qrc 文件
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appCarScreen
    main.cpp
)

# 创建、管理 qml 模块
qt_add_qml_module(appCarScreen
    URI CarScreen
    VERSION 1.0
    QML_FILES
        Main.qml
        HMI/App.qml
        HMI/AC.qml
        HMI/ControlCenter.qml
        HMI/Home.qml
        HMI/Settings.qml

    SOURCES
        Interface/Interface.h
        Interface/Interface.cpp
        RESOURCES resourcesa.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCarScreen PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCarScreen
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCarScreen
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCarScreen
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
