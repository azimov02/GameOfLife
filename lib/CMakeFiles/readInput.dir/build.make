# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/DT/GameOfLife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/DT/GameOfLife

# Include any dependencies generated for this target.
include lib/CMakeFiles/readInput.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/readInput.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/readInput.dir/flags.make

lib/CMakeFiles/readInput.dir/readInput.c.o: lib/CMakeFiles/readInput.dir/flags.make
lib/CMakeFiles/readInput.dir/readInput.c.o: lib/readInput.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/DT/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/readInput.dir/readInput.c.o"
	cd /home/user/DT/GameOfLife/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/readInput.dir/readInput.c.o   -c /home/user/DT/GameOfLife/lib/readInput.c

lib/CMakeFiles/readInput.dir/readInput.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/readInput.dir/readInput.c.i"
	cd /home/user/DT/GameOfLife/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/DT/GameOfLife/lib/readInput.c > CMakeFiles/readInput.dir/readInput.c.i

lib/CMakeFiles/readInput.dir/readInput.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/readInput.dir/readInput.c.s"
	cd /home/user/DT/GameOfLife/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/DT/GameOfLife/lib/readInput.c -o CMakeFiles/readInput.dir/readInput.c.s

# Object files for target readInput
readInput_OBJECTS = \
"CMakeFiles/readInput.dir/readInput.c.o"

# External object files for target readInput
readInput_EXTERNAL_OBJECTS =

lib/libreadInput.a: lib/CMakeFiles/readInput.dir/readInput.c.o
lib/libreadInput.a: lib/CMakeFiles/readInput.dir/build.make
lib/libreadInput.a: lib/CMakeFiles/readInput.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/DT/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libreadInput.a"
	cd /home/user/DT/GameOfLife/lib && $(CMAKE_COMMAND) -P CMakeFiles/readInput.dir/cmake_clean_target.cmake
	cd /home/user/DT/GameOfLife/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/readInput.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/readInput.dir/build: lib/libreadInput.a

.PHONY : lib/CMakeFiles/readInput.dir/build

lib/CMakeFiles/readInput.dir/clean:
	cd /home/user/DT/GameOfLife/lib && $(CMAKE_COMMAND) -P CMakeFiles/readInput.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/readInput.dir/clean

lib/CMakeFiles/readInput.dir/depend:
	cd /home/user/DT/GameOfLife && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/DT/GameOfLife /home/user/DT/GameOfLife/lib /home/user/DT/GameOfLife /home/user/DT/GameOfLife/lib /home/user/DT/GameOfLife/lib/CMakeFiles/readInput.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/readInput.dir/depend
