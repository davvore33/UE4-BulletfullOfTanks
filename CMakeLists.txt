cmake_minimum_required (VERSION 2.6)
project (UE4)
set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS 1 CACHE BOOL "" FORCE)
SET(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 1 CACHE BOOL "" FORCE)
set(CMAKE_CXX_COMPILER "C:/cygwin64/bin/clang-3.9.exe")
set(CMAKE_C_COMPILER "C:/cygwin64/bin/clang-3.9.exe")

include("C:/Users/matteo/Documents/Unreal Projects/BulletfullOfTanks/Intermediate/ProjectFiles/IncludeDirectories.cmake")
include("C:/Users/matteo/Documents/Unreal Projects/BulletfullOfTanks/Intermediate/ProjectFiles/Definitions.cmake")
include("C:/Users/matteo/Documents/Unreal Projects/BulletfullOfTanks/Intermediate/ProjectFiles/BulletfullOfTanksEditor.cmake")

set(MONO_ROOT_PATH "C:/Program Files/Epic Games/UE_4.17/Engine/Binaries/DotNET")
set(BUILD cd /d "${MONO_ROOT_PATH}")

# Custom target for BulletfullOfTanksEditor project, Development configuration
add_custom_target(BulletfullOfTanksEditor-Development ${BUILD} && UnrealBuildTool.exe BulletfullOfTanksEditor Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/BulletfullOfTanks/BulletfullOfTanks.uproject" -game -progress)
add_custom_target(BulletfullOfTanksEditor-Development-CLEAN ${BUILD} && UnrealBuildTool.exe BulletfullOfTanksEditor Win64 Development -project="C:/Users/matteo/Documents/Unreal Projects/BulletfullOfTanks/BulletfullOfTanks.uproject" -clean)

add_executable(PleaseIgnoreMe ${BulletfullOfTanksEditor_FILES})