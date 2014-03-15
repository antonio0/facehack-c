######################################################################
# Automatically generated by qmake (3.0) Sat Mar 15 13:51:25 2014
######################################################################

TEMPLATE = app
TARGET = test
INCLUDEPATH += . lib_json

# Input
HEADERS += FBApi.h \
           HttpClient.h \
           MainWindowContainer.h \
           ui_fbapi_gui.h \
           UT.h \
           lib_json/json_batchallocator.h \
           lib_json/include/json/autolink.h \
           lib_json/include/json/config.h \
           lib_json/include/json/features.h \
           lib_json/include/json/forwards.h \
           lib_json/include/json/json.h \
           lib_json/include/json/reader.h \
           lib_json/include/json/value.h \
           lib_json/include/json/writer.h \
           lib_json/json_internalarray.inl \
           lib_json/json_internalmap.inl \
           lib_json/json_valueiterator.inl
FORMS += fbapi_gui.ui
SOURCES += FBApi.cpp \
           HttpClient.cpp \
           main.cpp \
           MainWindowContainer.cpp \
           UT.cpp \
           lib_json/json_reader.cpp \
           lib_json/json_value.cpp \
           lib_json/json_writer.cpp
QT += webkit webkitwidgets network script widgets gui core
INCLUDEPATH += lib_json/include
