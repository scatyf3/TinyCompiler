# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.9/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.9/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/juanitahowe/Documents/GitHub/complier

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juanitahowe/Documents/GitHub/complier

# Utility rule file for clean_all.

# Include any custom commands dependencies for this target.
include CMakeFiles/clean_all.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clean_all.dir/progress.make

CMakeFiles/clean_all:
	rm -f *.o lex.yy.cpp y.tab.cpp y.output tcc

clean_all: CMakeFiles/clean_all
clean_all: CMakeFiles/clean_all.dir/build.make
.PHONY : clean_all

# Rule to build all files generated by this target.
CMakeFiles/clean_all.dir/build: clean_all
.PHONY : CMakeFiles/clean_all.dir/build

CMakeFiles/clean_all.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clean_all.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clean_all.dir/clean

CMakeFiles/clean_all.dir/depend:
	cd /Users/juanitahowe/Documents/GitHub/complier && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juanitahowe/Documents/GitHub/complier /Users/juanitahowe/Documents/GitHub/complier /Users/juanitahowe/Documents/GitHub/complier /Users/juanitahowe/Documents/GitHub/complier /Users/juanitahowe/Documents/GitHub/complier/CMakeFiles/clean_all.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/clean_all.dir/depend

