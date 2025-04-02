cmake_minimum_required(VERSION 3.26)
project(AutoCorrect)

set(CMAKE_CXX_STANDARD 17)

add_executable(AutoCorrect main.cpp
        Cursor.h
        Cursor.cpp
        Font.h
        Font.cpp
        StateEnum.h
        States.h
        States.cpp
        TextInput.h
        TextInput.cpp
        Word.h
        Word.cpp
        FileReader.h
        FileReader.cpp
        Heap.h
        Heap.cpp
        WordSort.h
        WordSort.cpp
        AutoCorrect.h
        AutoCorrect.cpp
        Backspace.h
        Backspace.cpp)

target_link_libraries(AutoCorrect sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)