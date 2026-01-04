cmake_minimum_required(VERSION 3.27)
project(Cpp_and_C__)

set(CMAKE_CXX_STANDARD 14)

include_directories(Basic)

add_executable(Cpp_and_C__
        Basic/HelloWorld.cpp
        Basic/HelloWorld.h)

add_executable(Variables
        Basic/Variables.cpp
        Basic/Variables.h)

add_executable(Namespace
        Basic/Namespace.cpp
        Basic/Namespace.h)


add_executable(InputOutPut
        Basic/InputOutPut.cpp
        Basic/InputOutPut.h)

# HackerRank
add_executable(BasicDataTypes
        HackerRank/BasicDataTypes.cpp
        HackerRank/BasicDataTypes.h)

add_executable(ConditionalStatements
        HackerRank/ConditionalStatements.cpp
        HackerRank/ConditionalStatements.h)

add_executable(ForLoop
        HackerRank/ForLoop.cpp
        HackerRank/ForLoop.h)

add_executable(Function
        HackerRank/Function.cpp
        HackerRank/Function.h)

#Data Structure and Algorithm
add_executable(BasicArray
        DataStructureAndAlgorithm/Array/BasicArray.cpp
        DataStructureAndAlgorithm/Array/BasicArray.h)


add_executable(ArrayDynamicWithFunction
        DataStructureAndAlgorithm/Array/ArrayDynamicWithFunction.cpp
        DataStructureAndAlgorithm/Array/ArrayDynamicWithFunction.h)

add_executable(BasicVector
        DataStructureAndAlgorithm/Vector/BasicVector.cpp
        DataStructureAndAlgorithm/Vector/BasicVector.h)

add_executable(BasicSet
        DataStructureAndAlgorithm/Set/BasicSet.cpp
        DataStructureAndAlgorithm/Set/BasicSet.h)

add_executable(PracticeSet1
        DataStructureAndAlgorithm/Set/PracticeSet1.cpp
        DataStructureAndAlgorithm/Set/PracticeSet1.h)

add_executable(PraticeMultiSet
        DataStructureAndAlgorithm/Set/PraticeMultiSet.cpp
        DataStructureAndAlgorithm/Set/PraticeMultiSet.h)


add_executable(BasicMap
        DataStructureAndAlgorithm/Map/BasicMap.cpp
        DataStructureAndAlgorithm/Map/BasicMap.h)
#28tech
add_executable(Bai1
        Tech28/Practice/Bai1.cpp
        Tech28/Practice/Bai1.h)


