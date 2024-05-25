# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.27.9/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.27.9/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/juanitahowe/Documents/GitHub/complier/CMakeFiles /Users/juanitahowe/Documents/GitHub/complier//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/juanitahowe/Documents/GitHub/complier/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Compilerlab3

# Build rule for target.
Compilerlab3: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Compilerlab3
.PHONY : Compilerlab3

# fast build rule for target.
Compilerlab3/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/build
.PHONY : Compilerlab3/fast

lexer.o: lexer.cpp.o
.PHONY : lexer.o

# target to build an object file
lexer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/lexer.cpp.o
.PHONY : lexer.cpp.o

lexer.i: lexer.cpp.i
.PHONY : lexer.i

# target to preprocess a source file
lexer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/lexer.cpp.i
.PHONY : lexer.cpp.i

lexer.s: lexer.cpp.s
.PHONY : lexer.s

# target to generate assembly for a file
lexer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/lexer.cpp.s
.PHONY : lexer.cpp.s

parser.o: parser.cpp.o
.PHONY : parser.o

# target to build an object file
parser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/parser.cpp.o
.PHONY : parser.cpp.o

parser.i: parser.cpp.i
.PHONY : parser.i

# target to preprocess a source file
parser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/parser.cpp.i
.PHONY : parser.cpp.i

parser.s: parser.cpp.s
.PHONY : parser.s

# target to generate assembly for a file
parser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/parser.cpp.s
.PHONY : parser.cpp.s

sign_table.o: sign_table.cpp.o
.PHONY : sign_table.o

# target to build an object file
sign_table.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/sign_table.cpp.o
.PHONY : sign_table.cpp.o

sign_table.i: sign_table.cpp.i
.PHONY : sign_table.i

# target to preprocess a source file
sign_table.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/sign_table.cpp.i
.PHONY : sign_table.cpp.i

sign_table.s: sign_table.cpp.s
.PHONY : sign_table.s

# target to generate assembly for a file
sign_table.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Compilerlab3.dir/build.make CMakeFiles/Compilerlab3.dir/sign_table.cpp.s
.PHONY : sign_table.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Compilerlab3"
	@echo "... lexer.o"
	@echo "... lexer.i"
	@echo "... lexer.s"
	@echo "... parser.o"
	@echo "... parser.i"
	@echo "... parser.s"
	@echo "... sign_table.o"
	@echo "... sign_table.i"
	@echo "... sign_table.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

