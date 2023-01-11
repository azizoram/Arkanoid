cmake_minimum_required(VERSION 3.16)
project(arkanoid)


set(CMAKE_CXX_STANDARD 14)
add_executable(arkanoid main.cpp GameObject.h Ball.h Ball.cpp Brick.h Arkanoid.h GameObject.cpp Paddle.h Section.h Point.cpp Point.h Rectangle.cpp Rectangle.h ViewField.cpp ViewField.h ComplexObject.cpp ComplexObject.h Bottom.cpp Bottom.h Map.cpp Map.h BallBlock.h)
add_executable(tests tests.cpp Ball.h Ball.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(arkanoid Threads::Threads)


