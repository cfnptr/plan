# Copyright 2024-2024 Nikita Fediuchin. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "Prevented in-tree build")
endif()

if(TARGET plan-static)
	return()
endif()

project(plan VERSION 0.0.1 LANGUAGES CXX
	DESCRIPTION "Portable programming language."
	HOMEPAGE_URL "https://github.com/cfnptr/plan")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(PLAN_BUILD_SHARED "Build Plan shared library" ON)
option(PLAN_BUILD_TESTS "Build Plan library tests" ON)

configure_file(cmake/defines.hpp.in include/garden/defines.hpp)

set(PLAN_SOURCES source/compiler.cpp source/virtual-machine.cpp)
add_library(plan-static STATIC ${PLAN_SOURCES})
target_include_directories(plan-static PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(PLAN_BUILD_SHARED)
	add_library(plan-shared SHARED ${PLAN_SOURCES})
	set_target_properties(plan-shared PROPERTIES
		OUTPUT_NAME "plan" WINDOWS_EXPORT_ALL_SYMBOLS ON)
	target_include_directories(plan-shared PUBLIC ${PROJECT_SOURCE_DIR}/include)
endif()

if(PLAN_BUILD_TESTS)
	enable_testing()

	add_executable(TestPlanMath tests/test-math.cpp)
	target_link_libraries(TestPlanMath PUBLIC plan-static)
	add_test(NAME TestPlanMath COMMAND TestPlanMath)
endif()