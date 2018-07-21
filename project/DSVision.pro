#-------------------------------------------------
#
# Project created by QtCreator 2018-07-18T09:16:46
#
#-------------------------------------------------

QT       += core gui

RC_FILE = proj.rc

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
    Common/Common.h \
    Model/LeftistHeap.h \
    Model/SplayTree.h \
    View/draw.h \
    View/drawwindow.h \
    View/dsview.h \
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
    ViewModel/Commands/HFTreeClear.h \
    ViewModel/Commands/HFTreeErase.h \
    ViewModel/Commands/HFTreeFind.h \
    ViewModel/Commands/HFTreeInsert.h \
    ViewModel/Commands/LeftistHeapClear.h \
    ViewModel/Commands/LeftistHeapErase.h \
    ViewModel/Commands/LeftistHeapInsert.h \
    Model/HFTree.h \
    Model/LeftistHeap.h \
    ViewModel/Commands/RBTClear.h \
    ViewModel/Commands/RBTErase.h \
    ViewModel/Commands/RBTFind.h \
    ViewModel/Commands/RBTInsert.h \
    Model/RBT.h \

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
    APP/main.cpp \
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
    ViewModel/Commands/HFTreeClear.cpp \
    ViewModel/Commands/HFTreeErase.cpp \
    ViewModel/Commands/HFTreeFind.cpp \
    ViewModel/Commands/HFTreeInsert.cpp \
    ViewModel/Commands/LeftistHeapErase.cpp \
    ViewModel/Commands/LeftistHeapInsert.cpp \
    Model/HFTree.cpp \
    Model/LeftistHeap.cpp \
    ViewModel/Commands/RBTClear.cpp \
    ViewModel/Commands/RBTErase.cpp \
    ViewModel/Commands/RBTFind.cpp \
    ViewModel/Commands/RBTInsert.cpp \
    Model/RBT.cpp

RESOURCES += \
    View/viewqrc.qrc


