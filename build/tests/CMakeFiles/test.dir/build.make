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
CMAKE_SOURCE_DIR = /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test.dir/flags.make

tests/CMakeFiles/test.dir/test.c.o: tests/CMakeFiles/test.dir/flags.make
tests/CMakeFiles/test.dir/test.c.o: ../tests/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/test.dir/test.c.o"
	cd /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test.dir/test.c.o   -c /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/tests/test.c

tests/CMakeFiles/test.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/test.c.i"
	cd /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/tests/test.c > CMakeFiles/test.dir/test.c.i

tests/CMakeFiles/test.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/test.c.s"
	cd /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/tests/test.c -o CMakeFiles/test.dir/test.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

tests/libtest.a: tests/CMakeFiles/test.dir/test.c.o
tests/libtest.a: tests/CMakeFiles/test.dir/build.make
tests/libtest.a: tests/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libtest.a"
	cd /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test.dir/build: tests/libtest.a

.PHONY : tests/CMakeFiles/test.dir/build

tests/CMakeFiles/test.dir/clean:
	cd /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test.dir/clean

tests/CMakeFiles/test.dir/depend:
	cd /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/tests /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests /mnt/c/Users/Kenan/OneDrive/Desktop/UFAZ/DevTech/GameOfLife/build/tests/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test.dir/depend
