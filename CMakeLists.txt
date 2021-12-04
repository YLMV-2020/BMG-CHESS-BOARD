cmake_minimum_required(VERSION 3.0)
project(Chess)

option(SFML_BUILD_DOC OFF)
option(SFML_BUILD_EXAMPLES OFF)
option(SFML_BUILD_TEST_SUITE OFF)
add_subdirectory(Chess/vendor/sfml)

include_directories(Chess/vendor/sfml/include)

file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio sfml-graphics sfml-network sfml-system sfml-window 
${SFML_LIBRARIES})

file(COPY Chess/images DESTINATION ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_target_properties(sfml-graphics PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_target_properties(sfml-audio PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_target_properties(sfml-network PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_target_properties(sfml-system PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_target_properties(sfml-window PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
