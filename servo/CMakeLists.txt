cmake_minimum_required(VERSION 3.27.2)

project(servo)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)


find_package(Qt6 COMPONENTS Widgets QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(QT_VERSION_MAJOR 5)
else()
    set(QT_VERSION_MAJOR 6)
endif()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/StrategyFactory.cpp
    component/BottomWidget.cpp
    component/PageWidget.cpp
    component/ShadowWidget.cpp
    component/TopWidget.cpp
    strategies/MotorSettingsCustomization.cpp
)

set(PROJECT_HEADERS
    include/mainwindow.h
    include/StrategyFactory.h
    component/BottomWidget.h
    component/PageWidget.h
    component/ShadowWidget.h
    component/TopWidget.h
    strategies/PageCustomizationStrategy.h
  
)

set(QT_RESOURCES
    res/icons.qrc
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt6_wrap_cpp(QT_MOC_FILES ${PROJECT_HEADERS})
    qt6_add_resources(QT_RESOURCES_FILES ${QT_RESOURCES})
    qt_add_executable(servo
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${QT_MOC_FILES}
        ${QT_RESOURCES_FILES}
    )
    target_link_libraries(servo PRIVATE Qt6::Widgets)
    qt_finalize_executable(servo)
else()
    qt5_wrap_cpp(QT_MOC_FILES ${PROJECT_HEADERS})
    qt5_add_resources(QT_RESOURCES_FILES ${QT_RESOURCES})
    add_executable(servo
        ${PROJECT_SOURCES}
        ${QT_MOC_FILES}
        ${QT_RESOURCES_FILES}
    )
    target_link_libraries(servo PRIVATE Qt5::Widgets)
endif()
