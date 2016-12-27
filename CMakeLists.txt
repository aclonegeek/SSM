cmake_minimum_required(VERSION 3.2)
project(SSM)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Set default build type explicitly to Release
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build type." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

if(NOT SFML_ROOT)
    set(SFML_ROOT "C:/SFML/2.4.1")
endif()

# Find SFML
set(SFML_STATIC_LIBRARIES FALSE)
find_package(SFML REQUIRED COMPONENTS graphics window system)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${SFML_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
    src/Main.cpp
    src/Game.cpp
    src/StateManager.cpp
    src/GameState.cpp
    src/MenuState.cpp
)

add_executable(SSM ${SOURCE_FILES})

target_link_libraries(SSM ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Install executable
install(TARGETS SSM
    RUNTIME DESTINATION .
)