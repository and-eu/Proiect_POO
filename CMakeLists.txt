cmake_minimum_required(VERSION 3.27)
project(PR)

set(CMAKE_CXX_STANDARD 17)

add_executable(PR main.cpp
        Librarii/Produs.cpp
        Librarii/Produs.h
        Librarii/PlacaVideo.cpp
        Librarii/PlacaVideo.h
        Librarii/Procesor.cpp
        Librarii/Procesor.h
        Librarii/PlacaBaza.cpp
        Librarii/PlacaBaza.h
        Librarii/Memorie.cpp
        Librarii/Memorie.h
        Librarii/Stocare.cpp
        Librarii/Stocare.h)
