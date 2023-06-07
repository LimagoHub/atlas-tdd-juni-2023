cmake_minimum_required(VERSION 3.25)
project(loggerProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(loggerProjekt main.cpp Logger.h Writer.h ConsolenWriter.h Multiplizierer.h MultipliziererImpl.h MultipliziererOptimierer.h MathClient.h)
