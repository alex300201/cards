cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

# Global configs
set(CMAKE_DEBUG_POSTFIX "-debug")

# CMake options
if (WIN32)
	set(CMAKE_USE_RELATIVE_PATHS ON)
endif ()

# Modules
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Project setup
project(
		cards
		VERSION 1.0.0
		LANGUAGES CXX
)

# Vendor

# Target
add_subdirectory(poker)