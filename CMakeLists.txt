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
#LeetCode

add_executable(TwoSum1
        LeetCode/TwoSum1.cpp
        LeetCode/TwoSum1.h)

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

add_executable(Struct1
        DataStructureAndAlgorithm/Struct/Struct1.cpp
        DataStructureAndAlgorithm/Struct/Struct1.h)

add_executable(Array2D
        DataStructureAndAlgorithm/2D_Array/Array2D.cpp
        DataStructureAndAlgorithm/2D_Array/Array2D.h)

add_executable(ArrayADT
        DataStructureAndAlgorithm/ArrayADT/ArrayADT.cpp
        DataStructureAndAlgorithm/ArrayADT/ArrayADT.h)

add_executable(StructLibrary
        DataStructureAndAlgorithm/Struct/StructLibrary.cpp
        DataStructureAndAlgorithm/Struct/StructLibrary.h)

add_executable(Recursion1
        DataStructureAndAlgorithm/Recursion/Recursion1.cpp
        DataStructureAndAlgorithm/Recursion/Recursion1.h)

add_executable(Fibonacci_1
        DataStructureAndAlgorithm/Recursion/Fibonacci_1.cpp
        DataStructureAndAlgorithm/Recursion/Fibonacci_1.h)

add_executable(TranKienPhong_218060786_1
        DataStructureAndAlgorithm/LinkList/Tran_Kien_Phong_Practice1_A.cpp
        DataStructureAndAlgorithm/LinkList/Tran_Kien_Phong_Practice1_A.h)

add_executable(LinkList1
        DataStructureAndAlgorithm/LinkList/LinkList1.cpp
        DataStructureAndAlgorithm/LinkList/LinkList1.h)

add_executable(DoublyLinkedList
        DataStructureAndAlgorithm/LinkList/DoublyLinkedList.cpp
        DataStructureAndAlgorithm/LinkList/DoublyLinkedList.h)

add_executable(QueueADT
        DataStructureAndAlgorithm/Queue/QueueADT.cpp
        DataStructureAndAlgorithm/Queue/QueueADT.h)

add_executable(QueueLinkedList
        DataStructureAndAlgorithm/Queue/QueueLinkedList.cpp
        DataStructureAndAlgorithm/Queue/QueueLinkedList.h)

add_executable(Tran_Kien_Phong_Practice2_A
        DataStructureAndAlgorithm/Queue/Tran_Kien_Phong_Practice2_A.cpp
        DataStructureAndAlgorithm/Queue/Tran_Kien_Phong_Practice2_A.h)

add_executable(Fix_For_TranKienPhongPractice2A
        DataStructureAndAlgorithm/Queue/Fix_For_TranKienPhongPractice2A.cpp
        DataStructureAndAlgorithm/Queue/Fix_For_TranKienPhongPractice2A.h )


add_executable(TrueCircularQueueADT
        DataStructureAndAlgorithm/Queue/TrueCircularQueueADT.cpp
        DataStructureAndAlgorithm/Queue/TrueCircularQueueADT.h )

add_executable(QueueByLinkedList
        DataStructureAndAlgorithm/Queue/QueueByLinkedList.cpp
        DataStructureAndAlgorithm/Queue/QueueByLinkedList.h )

add_executable(2180607876_TranKienPhong_practice3A
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3A.cpp
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3A.h)

add_executable(2180607876_TranKienPhong_practice3B
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3B.cpp
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3B.h)

add_executable(2180607876_TranKienPhong_practice3C
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3C.cpp
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3C.h)

add_executable(2180607876_TranKienPhong_practice3D
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3D.cpp
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3D.h)

add_executable(2180607876_TranKienPhong_practice3E
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3E.cpp
        DataStructureAndAlgorithm/Stack/2180607876_TranKienPhong_practice3E.h)


add_executable(QueueSolveQuestion3
        DataStructureAndAlgorithm/Queue/QueueSolveQuestion3.cpp
        DataStructureAndAlgorithm/Queue/QueueSolveQuestion3.h )

add_executable(Stack1
        DataStructureAndAlgorithm/Stack/Stack1.cpp
        DataStructureAndAlgorithm/Stack/Stack1.cpp)

add_executable(TranKienPhong_2180607876_2
        DataStructureAndAlgorithm/LinkList/Tran_Kien_Phong_Practice1_B.cpp
        DataStructureAndAlgorithm/LinkList/Tran_Kien_Phong_Practice1_B.h)
#28tech

    # =================== Prefix ======================
add_executable(Prefix1
        Tech28/Prefix/Prefix1.cpp
        Tech28/Prefix/Prefix1.h)

add_executable(Prefix2
        Tech28/Prefix/Prefix2.cpp
        Tech28/Prefix/Prefix2.h)

add_executable(Prefix2D
        Tech28/Prefix/Prefix2D.cpp
        Tech28/Prefix/Prefix2D.h)

add_executable(Bai1
        Tech28/Practice/Bai1.cpp
        Tech28/Practice/Bai1.h)
    # =================== Pointer ======================
add_executable(PracticePointer
        Tech28/PointerAssignment/PracticePointer.cpp
        Tech28/PointerAssignment/PracticePointer.h)

add_executable(PracticePointer2
        Tech28/PointerAssignment/PracticePointer2.cpp
        Tech28/PointerAssignment/PracticePointer2.h)

add_executable(PracticePointer3
        Tech28/PointerAssignment/PracticePointer3.cpp
        Tech28/PointerAssignment/PracticePointer3.h)

add_executable(PracticePointer4
        Tech28/PointerAssignment/PracticePointer4.cpp
        Tech28/PointerAssignment/PracticePointer4.h)

add_executable(PracticePointer5
        Tech28/PointerAssignment/PracticePointer5.cpp
        Tech28/PointerAssignment/PracticePointer5.h)

    # =================== Set Map ======================

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

add_executable(SetMapAss7
        Tech28/SetMapAssignment/SetMapAss7.cpp
        Tech28/SetMapAssignment/SetMapAss7.h)

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

add_executable(Bai32
        Tech28/SetMapAssignment/WeeklyContest/Bai32.cpp
        Tech28/SetMapAssignment/WeeklyContest/Bai32.h)

add_executable(Bai30
        Tech28/SetMapAssignment/WeeklyContest/Bai30.cpp
        Tech28/SetMapAssignment/WeeklyContest/Bai30.h)

add_executable(LinkedListBai1
        Tech28/LinkedList/LinkedListBai1.cpp
        Tech28/LinkedList/LinkedListBai1.h)