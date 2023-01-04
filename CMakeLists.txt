cmake_minimum_required(VERSION 3.16)
project(semwork)


set(CMAKE_CXX_STANDARD 14)
add_executable(semwork main.cpp GameObject.h Ball.h Ball.cpp Wall.h Brick.h Arkanoid.h GameObject.cpp GameBar.h Section.h Point.cpp Point.h Fourangle.cpp Fourangle.h ViewField.cpp ViewField.h Figure.cpp Figure.h Bottom.cpp Bottom.h)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(semwork Threads::Threads)