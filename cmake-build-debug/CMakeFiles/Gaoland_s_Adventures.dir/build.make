# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/shello/Programs/Clion2022.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/shello/Programs/Clion2022.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shello/Documents/Gaoland-s-Adventures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shello/Documents/Gaoland-s-Adventures/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Gaoland_s_Adventures.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Gaoland_s_Adventures.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Gaoland_s_Adventures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gaoland_s_Adventures.dir/flags.make

CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o: CMakeFiles/Gaoland_s_Adventures.dir/flags.make
CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o: ../pruebaMain.cpp
CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o: CMakeFiles/Gaoland_s_Adventures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shello/Documents/Gaoland-s-Adventures/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o -MF CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o.d -o CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o -c /home/shello/Documents/Gaoland-s-Adventures/pruebaMain.cpp

CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shello/Documents/Gaoland-s-Adventures/pruebaMain.cpp > CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.i

CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shello/Documents/Gaoland-s-Adventures/pruebaMain.cpp -o CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.s

# Object files for target Gaoland_s_Adventures
Gaoland_s_Adventures_OBJECTS = \
"CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o"

# External object files for target Gaoland_s_Adventures
Gaoland_s_Adventures_EXTERNAL_OBJECTS =

../Gaoland_s_Adventures: CMakeFiles/Gaoland_s_Adventures.dir/pruebaMain.cpp.o
../Gaoland_s_Adventures: CMakeFiles/Gaoland_s_Adventures.dir/build.make
../Gaoland_s_Adventures: CMakeFiles/Gaoland_s_Adventures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shello/Documents/Gaoland-s-Adventures/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../Gaoland_s_Adventures"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Gaoland_s_Adventures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gaoland_s_Adventures.dir/build: ../Gaoland_s_Adventures
.PHONY : CMakeFiles/Gaoland_s_Adventures.dir/build

CMakeFiles/Gaoland_s_Adventures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Gaoland_s_Adventures.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Gaoland_s_Adventures.dir/clean

CMakeFiles/Gaoland_s_Adventures.dir/depend:
	cd /home/shello/Documents/Gaoland-s-Adventures/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shello/Documents/Gaoland-s-Adventures /home/shello/Documents/Gaoland-s-Adventures /home/shello/Documents/Gaoland-s-Adventures/cmake-build-debug /home/shello/Documents/Gaoland-s-Adventures/cmake-build-debug /home/shello/Documents/Gaoland-s-Adventures/cmake-build-debug/CMakeFiles/Gaoland_s_Adventures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Gaoland_s_Adventures.dir/depend
