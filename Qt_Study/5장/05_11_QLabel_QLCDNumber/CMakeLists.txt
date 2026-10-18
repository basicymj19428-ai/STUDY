cmake_minimum_required(VERSION 3.19)
project(05_11_QLabel_QLCDNumber LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(05_11_QLabel_QLCDNumber
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    resourses.qrc
)

target_link_libraries(05_11_QLabel_QLCDNumber
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS 05_11_QLabel_QLCDNumber
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 05_11_QLabel_QLCDNumber
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
