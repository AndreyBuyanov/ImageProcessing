cmake_minimum_required (VERSION 3.8)

project("ImageLib")

file(GLOB SRCS 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/Filters/*.cpp"
)

file(GLOB HDRS 
	"${CMAKE_CURRENT_SOURCE_DIR}/include/ImageLib/*.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/ImageLib/Filters/*.hpp"
)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

#find_package(FreeImage)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
#	${FreeImage_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}
	SHARED 
	${SRCS}
	${HDRS}
)

#target_link_libraries(${PROJECT_NAME}
#	${FreeImage_LIBRARY}
#)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	DEFINE_SYMBOL ImageLib_EXPORTS
)
