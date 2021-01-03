cmake_minimum_required(VERSION 3.17)
project(AlgoShiz)

set(CMAKE_CXX_STANDARD 14)

include_directories(Arrays)
include_directories(Events)
include_directories(Math)
include_directories(Search)
include_directories(Sorts)
include_directories(Structures)

add_executable(AlgoShiz
        Arrays/Generator.hpp
        Arrays/Utils.hpp
        Events/Event.hpp
        Math/Average.hpp
        Math/DCT.hpp
        Math/Differentiation.hpp
        Math/Division.hpp
        Math/Factorial.hpp
        Math/Factorization.hpp
        Math/Fibonacci.hpp
        Math/Gamma.hpp
        Math/Integration.hpp
        Math/Interpolation.hpp
        Math/Power.hpp
        Math/Similarity.hpp
        Math/SLAE.hpp
        Math/Sqrt.hpp
        Math/Utils.hpp
        Search/BinarySearch.hpp
        Search/LinearSearch.hpp
        Sorts/BeadSort.hpp
        Sorts/BubbleSort.hpp
        Sorts/BucketSort.hpp
        Sorts/CombSort.hpp
        Sorts/CountingSort.hpp
        Sorts/HeapSort.hpp
        Sorts/InsertionSort.hpp
        Sorts/MergeSort.hpp
        Sorts/QuickSort.hpp
        Sorts/RadixSort.hpp
        Sorts/SelectionSort.hpp
        Sorts/ShakerSort.hpp
        Structures/LinkedList.hpp
        Structures/Vector.hpp
        main.cpp)
