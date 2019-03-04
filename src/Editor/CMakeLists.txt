project ("Editor")

set(CMAKE_INCLUDE_CURRENTUI_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Widgets)

file(GLOB EDITOR_SRCS 
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

source_group("Sources" FILES ${EDITOR_SRCS})

file(GLOB EDITOR_HDRS 
	"${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

source_group("Headers" FILES ${EDITOR_HDRS})

file(GLOB EDITOR_FORMS 
	"${CMAKE_CURRENT_SOURCE_DIR}/*.ui"
)

source_group("Forms" FILES ${EDITOR_FORMS})

include_directories(
	${CMAKE_SOURCE_DIR}/src/include
)

add_executable(${PROJECT_NAME} WIN32
	${EDITOR_SRCS}
	${EDITOR_HDRS}
	${EDITOR_FORMS}
)

set(EDITOR_LIBRARIES
	ImageLib
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
)

target_link_libraries (${PROJECT_NAME}
	PRIVATE
	${EDITOR_LIBRARIES}
)
