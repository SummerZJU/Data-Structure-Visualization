#-------------------------------------------------
#
# Project created by QtCreator 2018-07-18T09:16:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DSVision
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    APP/APP.h \
    Common/CommandBase.h \
    Common/etlbase.h \
    Common/TreeBase.h \
    Common/Parameter/IntParameter.h \
    Common/Parameter/Parameter.h \
    Model/AVLTree.h \
    Model/BST.h \
    Model/Common.h \
    Model/LeftistHeap.h \
    Model/SplayTree.h \
    View/draw.h \
    View/drawwindow.h \
    View/dsview.h \
    View/returncommand.h \
    View/startcommand.h \
    View/startmenu.h \
    ViewModel/ViewModel.h \
    ViewModel/Commands/BSTErase.h \
    ViewModel/Commands/BSTFind.h \
    ViewModel/Commands/BSTInsert.h \
    View/ErrorView/DeleteError.h \
    View/ErrorView/FindError.h \
    View/ErrorView/InsertError.h \
    View/Sinks/TreeCommandNotification.h \
    View/Sinks/TreePropertyNotification.h \
    View/ErrorView/Error.h \
    ViewModel/Sinks/VMPropertySink.h \
    Common/Exception/ModelException.h \
    ViewModel/Commands/AVLTreeClear.h \
    ViewModel/Commands/AVLTreeErase.h \
    ViewModel/Commands/AVLTreeFind.h \
    ViewModel/Commands/AVLTreeInsert.h \
    ViewModel/Commands/BSTClear.h \
    ViewModel/Commands/BSTErase.h \
    ViewModel/Commands/BSTFind.h \
    ViewModel/Commands/BSTInsert.h \
    View/dswidget.h \
    ViewModel/Commands/SplayTreeClear.h \
    ViewModel/Commands/SplayTreeErase.h \
    ViewModel/Commands/SplayTreeFind.h \
    ViewModel/Commands/SplayTreeInsert.h

SOURCES += \
    APP/APP.cpp \
    Common/CommandBase.cpp \
    Common/Parameter/IntParameter.cpp \
    Common/Parameter/Parameter.cpp \
    Model/AVLTree.cpp \
    Model/BST.cpp \
    Model/LeftistHeap.cpp \
    Model/SplayTree.cpp \
    View/draw.cpp \
    View/drawwindow.cpp \
    View/dsview.cpp \
    View/main.cpp \
    View/returncommand.cpp \
    View/startcommand.cpp \
    View/startmenu.cpp \
    ViewModel/ViewModel.cpp \
    ViewModel/Commands/BSTErase.cpp \
    ViewModel/Commands/BSTFind.cpp \
    ViewModel/Commands/BSTInsert.cpp \
    View/ErrorView/DeleteError.cpp \
    View/ErrorView/FindError.cpp \
    View/ErrorView/InsertError.cpp \
    View/Sinks/TreeCommandNotification.cpp \
    View/Sinks/TreePropertyNotification.cpp \
    View/ErrorView/Error.cpp \
    ViewModel/Sinks/VMPropertySink.cpp \
    Common/Exception/ModelException.cpp \
    ViewModel/Commands/AVLTreeErase.cpp \
    ViewModel/Commands/AVLTreeFind.cpp \
    ViewModel/Commands/AVLTreeInsert.cpp \
    ViewModel/Commands/BSTClear.cpp \
    ViewModel/Commands/BSTErase.cpp \
    ViewModel/Commands/BSTFind.cpp \
    ViewModel/Commands/BSTInsert.cpp \
    View/dswidget.cpp \
    ViewModel/Commands/SplayTreeClear.cpp \
    ViewModel/Commands/SplayTreeErase.cpp \
    ViewModel/Commands/SplayTreeFind.cpp \
    ViewModel/Commands/SplayTreeInsert.cpp

RESOURCES += \
    View/viewqrc.qrc

