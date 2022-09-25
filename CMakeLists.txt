cmake_minimum_required(VERSION 3.23)
project(Grandelia C)

set(CMAKE_C_STANDARD 99)

add_executable(Grandelia main.c graph/graph.c graph/graph.h data/my_data_structure.c data/my_data_structure.h graph/graph_ui.c graph/graph_ui.h graph/stack/stack.c graph/stack/stack.h)
