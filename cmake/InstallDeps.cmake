cmake_minimum_required (VERSION 3.16)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
 
conan_cmake_configure(REQUIRES opencv/4.5.3
                      GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

find_package(OpenCV REQUIRED)

find_package(Qt5 COMPONENTS Widgets)

if(NOT Qt5_FOUND OR NOT Qt5Widgets_FOUND)

    conan_cmake_configure(REQUIRES qt/5.15.2
            GENERATORS cmake_find_package)

    conan_cmake_autodetect(settings)

    conan_cmake_install(PATH_OR_REFERENCE .
            BUILD missing
            REMOTE conancenter
            SETTINGS ${settings})

    find_package(Qt5 COMPONENTS Widgets REQUIRED)

endif()
