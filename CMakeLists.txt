cmake_minimum_required(VERSION 3.27)
project(CAST256Algo)

set(CMAKE_CXX_STANDARD 23)

add_executable(CAST256AlgoEncrypt
        CAST256.h
        cryptomath.h
        includes.h
        CAST_Const.h
        CAST256.cpp
        CAST256Encrypt.cpp
        includes.cpp)

add_executable(CAST256AlgoDecrypt
        CAST256.h
        cryptomath.h
        includes.h
        includes.cpp
        CAST_Const.h
        CAST256.cpp
        CAST256Decrypt.cpp)

