cmake_minimum_required(VERSION 3.16)

project(AgentePETE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(AgentePETE
    main.cpp
    UserProfile.h
    UserProfile.cpp
    IDataStorage.h
    PersistenceManager.h
    PersistenceManager.cpp
)

target_link_libraries(AgentePETE Qt6::Core)
