cmake_minimum_required(VERSION 3.19)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure List/SqListInsertDelete.cpp List/SqlListSearch.cpp List/LinkList.cpp List/DNode.cpp StackAndQueue/SqStack.cpp StackAndQueue/ShStack.cpp StackAndQueue/ListStack.cpp StackAndQueue/SqQueQue.cpp StackAndQueue/LinkQueQue.cpp Tree/BinaryTreePreInPost.cpp Tree/ThreadedBinaryTree.cpp Tree/ToThreadBinaryTree.cpp Tree/BST.cpp Chart/AdjacencyMatrix.cpp Chart/AdjacencyList.cpp Sort/QuickSort.cpp)