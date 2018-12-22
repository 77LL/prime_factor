# ソース一覧
set(sources
	main.cpp
	)

# ヘッダ一覧
set(headers
	Solver.h
	)

set(target ${PROJECT_NAME})

add_executable(${target} ${sources} ${headers})

add_executable(simple prim_factor.cpp)

message(${PROJECT_BINARY_DIR})
# 出力先を指定
set_target_properties(${target} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set_target_properties(simple PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

