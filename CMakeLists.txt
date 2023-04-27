# CMakeLists.txt 会自动创建两个变量，PROJECT_SOURCE_DIR和PROJECT_NAME
# ${PROJECT_SOURCE_DIR}：本CMakeLists.txt所在的文件夹路径
# ${PROJECT_NAME}：本CMakeLists.txt的project名称

# 检查cmake的版本，至少为3.13
cmake_minimum_required(VERSION 3.13)

project(copy
        VERSION 0.0.0
        DESCRIPTION "cp with progress bar"
        HOMEPAGE_URL "https://bougainvilleas.github.io/lotus"
        LANGUAGES C)
# message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")
# message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")
# message("CMAKE_PROJECT_VERSION_MAJOR = ${CMAKE_PROJECT_VERSION_MAJOR}")
# message("CMAKE_SYSTEM = ${CMAKE_SYSTEM}")
# message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
# message("CMAKE_SYSTEM_VERSION = ${CMAKE_SYSTEM_VERSION}")
set(CMAKE_C_STANDARD 99)

#  默认存放库文件的位置
# 如果产生的是静态库并且没有指定 CMAKE_ARCHIVE_OUTPUT_DIRECTORY 则存放在该目录下，动态库也类似
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
# 默认存放静态库的文件夹位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib/static)
# 默认存放动态库的文件夹位置
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib/shared)

# 设置 ${CMAKE_INSTALL_INCLUDEDIR} install() 使用
# https://cmake.org/cmake/help/latest/module/GNUInstallDirs.html#module:GNUInstallDirs
include(GNUInstallDirs)

# 让库文件搜索以${PROJECT_SOURCE_DIR}/为基础
# 不设置
# #include "${PROJECT_SOURCE_DIR}/file/file.h"
# 设置
# #include "file/file.h"
include_directories(${PROJECT_SOURCE_DIR}/src)


# Recurse into the "src/file" and "src/progress" subdirectories. 
# This does not actually cause another cmake executable to run. 
# The same process will walk through the project's entire directory structure.
add_subdirectory(src/file)
add_subdirectory(src/progress)
# main func
add_subdirectory(src/main)


# CPack
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
# project(copy VERSION 0.1.2) 
# 会设置 ${CMAKE_PROJECT_NAME} = copy
# 会设置 ${CMAKE_PROJECT_VERSION} = 0.1.2
# 会设置 ${${CMAKE_PROJECT_NAME}_VERSION_MAJOR} = 0
# 会设置 ${${CMAKE_PROJECT_NAME}_VERSION_MINOR} = 1
# 会设置 ${${CMAKE_PROJECT_NAME}_VERSION_PATCH} = 2
set(CPACK_PACKAGE_VERSION "${CMAKE_PROJECT_VERSION}")
# set(CPACK_PACKAGE_VERSION_MAJOR "${${CMAKE_PROJECT_NAME}_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${${CMAKE_PROJECT_NAME}_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${${CMAKE_PROJECT_NAME}_VERSION_PATCH}")
set(CPACK_SYSTEM_NAME "${CMAKE_SYSTEM}")

set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)