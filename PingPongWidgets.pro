QT       += core gui
QT       += qml quick    # Добавьте QML и Quick модули для работы с QQmlEngine

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Вы можете сделать так, чтобы ваш код не компилировался, если он использует устаревшие API.
# Для этого раскомментируйте следующую строку.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # отключает все API, устаревшие до Qt 6.0.0

SOURCES += \
    ball.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    paddle.cpp \
    score.cpp

HEADERS += \
    ball.h \
    mainwindow.h \
    menuwindow.h \
    paddle.h \
    score.h

FORMS += \
    menuwindow.ui \
    mainwindow.ui \
    score.ui


# Стандартные правила для деплоя.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
