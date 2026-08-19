cmake_minimum_required(VERSION 3.19)
project(05_2_QComboBox LANGUAGES CXX)

#이미지를 못불러 올경우 set코드 추가
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(05_2_QComboBox
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    resources.qrc


)

target_link_libraries(05_2_QComboBox
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS 05_2_QComboBox
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 05_2_QComboBox
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
