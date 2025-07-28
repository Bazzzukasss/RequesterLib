QT += core

TEMPLATE = lib
CONFIG += staticlib c++17
DESTDIR = ../bin

SOURCES += \
    src/binance/Client.cpp \
    src/binance/ClientImpl.cpp \
    src/binance/MarketAPI.cpp \
    src/binance/RequestFactory.cpp \
    src/binance/Requester.cpp \
    src/common/Utils.cpp

HEADERS += \
    src/common/Common.h \
    src/common/Utils.h \
    src/interfaces/IClient.h \
    src/interfaces/IClientImpl.h \
    src/interfaces/IMarketAPI.h \
    src/interfaces/IRequestFactory.h \
    src/interfaces/IRequester.h \
    src/binance/Client.h \
    src/binance/ClientImpl.h \
    src/binance/MarketAPI.h \
    src/binance/RequestFactory.h \
    src/binance/Requester.h

INCLUDEPATH += \
    src \
    src/common \
    src/interfaces \
    src/binance

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
