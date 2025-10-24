cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Включение отладочной информации
set(CMAKE_BUILD_TYPE Debug)

# Добавляем все исходные файлы
add_executable(my_project main.c ./src/functions.c)

# Указываем include директории
target_include_directories(my_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Исправлено: применяем опции к правильной цели my_project
target_compile_options(my_project PRIVATE -g -O0)

# ДОБАВЬТЕ ЭТУ СТРОКУ - линковка математической библиотеки
target_link_libraries(my_project m)
