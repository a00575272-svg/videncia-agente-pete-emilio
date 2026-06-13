TEMPLATE = app
TARGET   = AgentePETE

QT      += core gui widgets network
CONFIG  += c++17

INCLUDEPATH += $$PWD/include

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/ChatController.cpp \
    src/ChatWindow.cpp \
    src/Prompt.cpp \
    src/Message.cpp \
    src/calendarwin.cpp \
    src/dayagendadialog.cpp \
    src/newtaskdialog.cpp \
    src/OllamaProvider.cpp \
    src/DayMonYear.cpp \
    src/PersistenceManager.cpp \
    src/UserProfile.cpp

HEADERS += \
    include/MainWindow.h \
    include/ChatController.h \
    include/ChatWindow.h \
    include/Prompt.h \
    include/Message.h \
    include/calendarwin.h \
    include/dayagendadialog.h \
    include/newtaskdialog.h \
    include/OllamaProvider.h \
    include/PeteExceptions.h \
    include/DayMonYear.h \
    include/PersistenceManager.h \
    include/UserProfile.h \
    include/IDataStorage.h

FORMS += \
    calendarwin.ui \
    dayagendadialog.ui \
    newtaskdialog.ui
