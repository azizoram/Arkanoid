cmake_minimum_required(VERSION 3.16)
project(semwork)


set(CMAKE_CXX_STANDARD 14)
add_executable(semwork main.cpp GayObject.h Ball.h Ball.cpp Wall.h Brick.h Arkanoid.h GayObject.cpp GayBar.h Section.h Point.cpp Point.h Block.cpp Block.h)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(semwork Threads::Threads)