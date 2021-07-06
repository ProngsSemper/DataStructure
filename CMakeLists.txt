cmake_minimum_required(VERSION 3.19)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure List/SqListInsertDelete.cpp List/SqlListSearch.cpp List/LinkList.cpp List/DNode.cpp StackAndQueue/SqStack.cpp StackAndQueue/ShStack.cpp StackAndQueue/ListStack.cpp)