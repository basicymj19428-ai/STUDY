cmake_minimum_required(VERSION 3.19)  #Cmake에서 버전

#프로젝트의 이름과 사용된 언어가 C++임을 명시
project(ConsoleApplication LANGUAGES CXX)

#Qt에서 사용할 모듈 명시
find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

#프로젝트에서 추가할 소스코드 파일을 명시
qt_add_executable(ConsoleApplication
    main.cpp
)

target_link_libraries(ConsoleApplication
    PRIVATE
        Qt::Core
)

install(TARGETS ConsoleApplication
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
