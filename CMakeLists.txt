project(zoozel)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(zoozel_SRCS mainwindow.cpp scene.cpp player.cpp main.cpp)
qt4_automoc(${zoozel_SRCS})
add_executable(zoozel ${zoozel_SRCS})
target_link_libraries(zoozel ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
