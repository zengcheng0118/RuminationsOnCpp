CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(picture)

include("../cfg.cmake")

INCLUDE_DIRECTORIES(
"include"
"test"
)

FILE(GLOB_RECURSE all_files
src/*.cpp
src/*.c
test/*.cpp
test/*.c
)

source_group_by_dir(all_files)
LINK_DIRECTORIES("${CMAKE_CURRRENT_SOURCE_DIR}/lib")
ADD_EXECUTABLE(${PROJECT_NAME} ${all_files})
# TARGET_LINK_LIBRARIES(${PROJECT_NAME} libgtest.a pthread)