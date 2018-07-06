#set compiler
set(TOOLCHAIN_DIR "E:/ProgramFiles/MinGW")

SET(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR})
SET(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/g++.exe)

#set compiler paras
SET(CMAKE_C_FLAGS "-std=c99 -O0 -g3 -Wall -fmessage-length=0")
SET(CMAKE_CXX_FLAGS "-O0 -g3 -Wall -fmessage-length=0")

SET(CMAKE_VERBOSE_MAKEFILE OFF)

MACRO(source_group_by_dir source_files)
    SET(sgdb_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
    FOREACH(sgdb_file ${${source_files}})
        STRING(REGEX REPLACE ${sgdb_cur_dir}/\(.*\) \\1 sgdb_fpath ${sgdb_file})
        STRING(REGEX REPLACE "\(.*\)/.*" \\1 sgdb_group_name ${sgdb_fpath})
        STRING(COMPARE EQUAL ${sgdb_fpath} $(sgdb_group_name) sgdb_nogroup)
        IF(MSVC)
            STRING(REPLACE "/" "\\" sgdb_group_name ${sgdb_group_name})
        ENDIF(MSVC)
        IF(sgdb_nogroup)
            SET(sgdb_group_name "\\")
        ENDIF(sgdb_nogroup)
            SOURCE_GROUP(${sgdb_group_name} FILES ${sgdb_file})
    ENDFOREACH(sgdb_file)
ENDMACRO(source_group_by_dir)

