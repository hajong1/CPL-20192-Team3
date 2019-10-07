cmake_minimum_required(VERSION 3.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(ProjName gui)
PROJECT(${ProjName})

#set(EyeSimulator_Version_Major 0)
#set(EyeSimulator_Version_Minor 1)

set (CMAKE_CXX_STANDARD 11)
#set (CMAKE_CXX_STANDARD 17)
#set (CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package( PkgConfig REQUIRED )

find_package( Threads REQUIRED )
find_package( OpenCV REQUIRED )
find_package( glfw3 REQUIRED )
find_package( assimp REQUIRED )
find_package( lua REQUIRED )

message(STATUS "Found Assimp library in ${ASSIMP_LIBRARIES}")

find_package( Boost REQUIRED )
message(STATUS "Found Boost include in ${Boost_INCLUDE_DIRS}")
message(STATUS "Found Boost library in ${Boost_LIBRARY_DIRS}")

#find_package( visp REQUIRED )
#message(STATUS "Found VISP in ${VISP_INCLUDE_DIRS}")
#message(STATUS "Found VISP in ${VISP_LIBRARIES}")

#message(STATUS "Found GLFW3 in ${GLFW_INCLUDE_DIRS}")
#message(STATUS "Found GLFW3 in ${GLFW3_LIBRARY}")

find_package( OpenGL REQUIRED )
message(STATUS "Found OPENGL in ${OPENGL_INCLUDE_DIR}")
message(STATUS "Found OPENGL in ${OPENGL_LIBRARY}")

find_package( glm REQUIRED )
message(STATUS "GLM included at ${GLM_INCLUDE_DIRS}")

set(stb ../../stb)
set(gl3w ../../gl3w/build)
set(imgui ../../imgui)
set(SyeCommon ../../SyeCommon)
set(EyeRpi ../EyeRpi/src)

#set(EyeCommonPath ../EyeCommon)
#set(MspPath ../Msp)
#set(PtammPath ../ptamm)

INCLUDE_DIRECTORIES(
	${OPENGL_INCLUDE_DIR}
	${GLM_INCLUDE_DIRS}
	${stb}
	${gl3w}/include
	${imgui}
	${imgui}/examples
	${SyeCommon}
	${EyeRpi}
	#${learnOpenGL}
	#${ShareCode}
	#${CommonPath}
   	#${EyeCommonPath}
    #${MspPath}
)

LINK_DIRECTORIES(
#${glad}
)

#set(BUILD_STATIC_LIB ON)
#set(BUILD_ASSIMP_TOOLS  ON)
#set(ASSIMP_BUILD_STATIC_LIB ON)

#INCLUDE_DIRECTORIES(${PtammPath})
#INCLUDE_DIRECTORIES("/usr/include/lua5.2")

add_definitions("-Wall" "-g")

file(GLOB SOURCES 
	${gl3w}/src/gl3w.c
	${imgui}/*.cpp
	${imgui}/examples/imgui_impl_glfw.cpp
	${imgui}/examples/imgui_impl_opengl3.cpp
	${SyeCommon}/misc/*.cpp
	${SyeCommon}/entity/*.cpp
	${SyeCommon}/opencv/*.cpp
	${SyeCommon}/opengl/*.cpp
	${SyeCommon}/lua/*
	${EyeRpi}/eyeKernel.cpp
	./src/*
)

message("SOURCES. [${SOURCES}]")
ADD_EXECUTABLE(${ProjName} ${SOURCES})

if (APPLE)
	find_library(COCOA_LIBRARY Cocoa)
	find_library(OpenGL_LIBRARY OpenGL)
	find_library(IOKIT_LIBRARY IOKit)
	find_library(COREVIDEO_LIBRARY CoreVideo)
	
	SET(EXTRA_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} )

	find_library(
		assimp_LIBRARIES
		NAMES assimp
	)
	message("yyyy ${assimp_LIBRARIES}")

elseif (UNIX)
	if(${CMAKE_SYSTEM} MATCHES Linux)
		message("		opengl tutorial source share.cpp gl3w.h 변경 >>>>>>>>>>>>>>>>> LINUX")
		SET(EXTRA_LIBS GL ${ASSIMP_LIBRARIES})
    endif()
endif ()

if(assimp_FOUND)
	message(" assimp link path : [${ASSIMP_LIBRARY_DIRS}]")
	message("	Found ASSIMP Package. [${ASSIMP_LIBRARIES}]")
	message("	Found ASSIMP Package. [${assimp_LIBRARIES}]")
	message("	link_directories(${CMAKE_SOURCE_DIR}/lib)")
#message("		Found ASSIMP Package. [${ASSIMP_STATIC_LIB}]")
#message("		Found ASSIMP Package. [${OpenCV_LIBS}]")
endif(assimp_FOUND)

link_directories(${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(
	${ProjName} 
	${CMAKE_THREAD_LIBS_INIT}
	${EXTRA_LIBS}
#${Boost_LIBRARY_DIRS}
	${OpenCV_LIBS} 
	${assimp_LIBRARIES}
	${LUA_LIBRARIES}
	pthread
	dl
	glfw
#glad
)
