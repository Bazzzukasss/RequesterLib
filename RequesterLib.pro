QT += core

TEMPLATE = lib
CONFIG += staticlib c++17
DESTDIR = ../bin

SOURCES += \
    src/Builder.cpp \
    src/Requester.cpp \
    src/Client.cpp \
    src/common/Utils.cpp \
    src/client/ClientImpl.cpp \
    src/binance/RequestCreator.cpp \
    src/binance/RequestProcessor.cpp \
    src/binance/MarketAPI.cpp

HEADERS += \
    src/Builder.h \
    src/Client.h \
    src/Requester.h \
    src/common/Common.h \
    src/common/Utils.h \
    src/client/ClientImpl.h \
    src/interface/IBuilder.h \
    src/interface/IClient.h \
    src/interface/IClientImpl.h \
    src/interface/IMarketAPI.h \
    src/interface/IRequestCreator.h \
    src/interface/IRequestProcessor.h \
    src/interface/IRequester.h \
    src/binance/RequestCreator.h \
    src/binance/RequestProcessor.h \
    src/binance/MarketAPI.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
