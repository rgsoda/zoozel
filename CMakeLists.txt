project(zoozel)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(zoozel_SRCS track.cpp obstacle.cpp mainwindow.cpp scene.cpp player.cpp main.cpp)
set(zoozel_MOC_HEADERS mainwindow.h)

qt4_automoc(${zoozel_SRCS})
qt4_wrap_cpp(zoozel_SRCS ${zoozel_MOC_HEADERS})

add_executable(zoozel ${zoozel_SRCS})
target_link_libraries(zoozel ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
