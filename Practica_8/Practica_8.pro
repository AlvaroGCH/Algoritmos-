TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AgendaDispersionAbierta.cpp \
        ListaEnlazada.cpp \
        impresionListasEnlazadas.cpp \
        mainAgenda.cpp

HEADERS += \
    Agenda.h \
    Contacto.h \
    ListaEnlazada.h \
    Nodo.h \
    assertdomjudge.h \
    impresionListasEnlazadas.h
