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
CMAKE_BINARY_DIR = /home/user/DT/GameOfLife/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/board.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/board.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/board.dir/flags.make

lib/CMakeFiles/board.dir/board.c.o: lib/CMakeFiles/board.dir/flags.make
lib/CMakeFiles/board.dir/board.c.o: ../lib/board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/DT/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/board.dir/board.c.o"
	cd /home/user/DT/GameOfLife/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/board.dir/board.c.o   -c /home/user/DT/GameOfLife/lib/board.c

lib/CMakeFiles/board.dir/board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/board.dir/board.c.i"
	cd /home/user/DT/GameOfLife/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/DT/GameOfLife/lib/board.c > CMakeFiles/board.dir/board.c.i

lib/CMakeFiles/board.dir/board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/board.dir/board.c.s"
	cd /home/user/DT/GameOfLife/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/DT/GameOfLife/lib/board.c -o CMakeFiles/board.dir/board.c.s

# Object files for target board
board_OBJECTS = \
"CMakeFiles/board.dir/board.c.o"

# External object files for target board
board_EXTERNAL_OBJECTS =

lib/libboard.a: lib/CMakeFiles/board.dir/board.c.o
lib/libboard.a: lib/CMakeFiles/board.dir/build.make
lib/libboard.a: lib/CMakeFiles/board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/DT/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libboard.a"
	cd /home/user/DT/GameOfLife/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/board.dir/cmake_clean_target.cmake
	cd /home/user/DT/GameOfLife/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/board.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/board.dir/build: lib/libboard.a

.PHONY : lib/CMakeFiles/board.dir/build

lib/CMakeFiles/board.dir/clean:
	cd /home/user/DT/GameOfLife/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/board.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/board.dir/clean

lib/CMakeFiles/board.dir/depend:
	cd /home/user/DT/GameOfLife/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/DT/GameOfLife /home/user/DT/GameOfLife/lib /home/user/DT/GameOfLife/build /home/user/DT/GameOfLife/build/lib /home/user/DT/GameOfLife/build/lib/CMakeFiles/board.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/board.dir/depend

