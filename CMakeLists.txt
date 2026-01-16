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

add_executable(SetMapAss1
        Tech28/SetMapAssignment/SetMapAss1.cpp
        Tech28/SetMapAssignment/SetMapAss1.h)

add_executable(SetMapAss2
        Tech28/SetMapAssignment/SetMapAss2.cpp
        Tech28/SetMapAssignment/SetMapAss2.h)

add_executable(SetMapAss3
        Tech28/SetMapAssignment/SetMapAss3.cpp
        Tech28/SetMapAssignment/SetMapAss3.h)

add_executable(SetMapAss4
        Tech28/SetMapAssignment/SetMapAss4.cpp
        Tech28/SetMapAssignment/SetMapAss4.h)

add_executable(SetMapAss5
        Tech28/SetMapAssignment/SetMapAss5.cpp
        Tech28/SetMapAssignment/SetMapAss5.h)

add_executable(SetMapAss6
        Tech28/SetMapAssignment/SetMapAss6.cpp
        Tech28/SetMapAssignment/SetMapAss6.h)

add_executable(SetMapAss8
        Tech28/SetMapAssignment/SetMapAss8.cpp
        Tech28/SetMapAssignment/SetMapAss8.h)

add_executable(SetMapAssBasic01
        Tech28/SetMapAssignment/SetMapAssBasic01.cpp
        Tech28/SetMapAssignment/SetMapAssBasic01.h)

add_executable(SetMapAssBasic02
        Tech28/SetMapAssignment/SetMapAssBasic02.cpp
        Tech28/SetMapAssignment/SetMapAssBasic02.h)

add_executable(SetMapAssBasic03
        Tech28/SetMapAssignment/SetMapAssBasic03.cpp
        Tech28/SetMapAssignment/SetMapAssBasic03.h)

add_executable(SetMapAssBasic04
        Tech28/SetMapAssignment/SetMapAssBasic04.cpp
        Tech28/SetMapAssignment/SetMapAssBasic04.h)

add_executable(SetMapAssBasic05
        Tech28/SetMapAssignment/SetMapAssBasic05.cpp
        Tech28/SetMapAssignment/SetMapAssBasic05.h)

add_executable(SetMapAssBasic06
        Tech28/SetMapAssignment/SetMapAssBasic06.cpp
        Tech28/SetMapAssignment/SetMapAssBasic06.h)

add_executable(SetMapAssBasic07
        Tech28/SetMapAssignment/SetMapAssBasic07.cpp
        Tech28/SetMapAssignment/SetMapAssBasic07.h)

add_executable(SetMapAssBasic08
        Tech28/SetMapAssignment/SetMapAssBasic08.cpp
        Tech28/SetMapAssignment/SetMapAssBasic08.h)