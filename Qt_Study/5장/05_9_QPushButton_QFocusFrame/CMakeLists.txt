cmake_minimum_required(VERSION 3.19)
project(05_9_08_QPushButton_QFocusFrame LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(05_9_08_QPushButton_QFocusFrame
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    widget.ui
)

target_link_libraries(05_9_08_QPushButton_QFocusFrame
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS 05_9_08_QPushButton_QFocusFrame
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 05_9_08_QPushButton_QFocusFrame
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
