QT = core  #core 모듈만 프로젝트에 포함

#c++17 : c++버전/cmdline : Console 어플리케이션일 경우
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#소스코드를 명시
SOURCES += \
        main.cpp

# Default rules for deployment.
#qnx : 플랫폼이 QNX인 경우/target.path : 빌드된 실행파일이 위치할 디렉토리
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
