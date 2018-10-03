
cmake_minimum_required(VERSION 3.0)
project(fmt)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake")

set(SAMP_SDK_ROOT "${PROJECT_SOURCE_DIR}/lib/sdk")
find_package(SAMPSDK REQUIRED)
include_directories(${SAMPSDK_DIR})
include_directories(${SAMPSDK_DIR}/amx)

set(SAMPGDK_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/gdk")
set(SAMPGDK_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/lib/gdk")
find_package(SAMPGDK REQUIRED)
include_directories(${SAMPGDK_INCLUDE_DIR})

set(LIBRARY_ROOT "${PROJECT_SOURCE_DIR}/lib")
include_directories(${LIBRARY_ROOT})

set(SOURCE_ROOT "${PROJECT_SOURCE_DIR}/src")
include_directories(${SOURCE_ROOT})

if(WIN32)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
else()
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-stack-protector -O3 -g -fpack-struct=1 -fPIC -w -fpermissive")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-stack-protector -O3 -g -fpack-struct=1 -fPIC -w -fpermissive")
endif()

set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY True)
set(CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY True)

add_subdirectory(src)
add_samp_plugin(${PROJECT_NAME} ${PLUGIN_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

include(cotire)
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "${PROJECT_SOURCE_DIR}/src/Main.h")
cotire(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
