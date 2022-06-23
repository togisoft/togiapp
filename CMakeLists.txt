cmake_minimum_required(VERSION 3.23.2)
find_package(wxWidgets REQUIRED)
project(togiapp VERSION 1.0)

if(UNIX)
  # Add file textension *.bin to all executables on Unix (Linux, OSX, BSD ...)
  set(CMAKE_EXECUTABLE_SUFFIX ".bin")
endif()

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_MAIN_DIR ${PROJECT_DIR}/src)
set(PROJECT_SOURCE_DIR ${PROJECT_MAIN_DIR}/sources)
set(PROJECT_HEADER_DIR ${PROJECT_MAIN_DIR}/headers)
set(PROJECT_LIBS_DIR ${PROJECt_MAIN_DIR}/libs)
set(PROJECT_RESOURCE_DIR ${PROJECT_DIR}/resources)

set( 
    PROJECT_HEADERS
    ${PROJECT_LIBS_DIR}/main.hpp
    ${PROJECT_LIBS_DIR}/Login.hpp
    ${PROJECT_LIBS_DIR}/Prefs.hpp
    ${PROJECT_LIBS_DIR}/Connection.hpp
    ${PROJECT_LIBS_DIR}/Dashboard.hpp

)

set(
    PROJECT_SOURCE
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/Login.cpp
    ${PROJECT_SOURCE_DIR}/Connection.cpp
    ${PROJECT_SOURCE_DIR}/Dashboard.cpp
)

set(PROJECT_RESOURCE
    ${PROJECT_RESOURCE_DIR}/logo.png
)

file(DOWNLOAD "https://raw.githubusercontent.com/vector-of-bool/cmrc/master/CMakeRC.cmake"
                 "${CMAKE_BINARY_DIR}/CMakeRC.cmake")
include("${CMAKE_BINARY_DIR}/CMakeRC.cmake")

cmrc_add_resource_library(
    togiapp-resources

    ALIAS togiapp::rc
    NAMESPACE togiapp
    resources/logo.png
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE} )

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_HEADER_DIR})

target_compile_definitions(${PROJECT_NAME} PRIVATE ${wxWidgets_DEFINITIONS} "$<$<CONFIG:DEBUG>:${wxWidgets_DEFINITIONS_DEBUG}>")
target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} togiapp::rc)
target_link_libraries(${PROJECT_NAME} PRIVATE odbccpp odbccpp_static)
