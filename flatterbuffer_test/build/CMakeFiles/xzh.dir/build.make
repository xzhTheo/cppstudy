# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/theo.xu/study/cppstudy/flatterbuffer_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/theo.xu/study/cppstudy/flatterbuffer_test/build

# Include any dependencies generated for this target.
include CMakeFiles/xzh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/xzh.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/xzh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xzh.dir/flags.make

CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o: CMakeFiles/xzh.dir/flags.make
CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o: /Users/theo.xu/study/cppstudy/flatterbuffer_test/flatterbuffer_test.cpp
CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o: CMakeFiles/xzh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/theo.xu/study/cppstudy/flatterbuffer_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o -MF CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o.d -o CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o -c /Users/theo.xu/study/cppstudy/flatterbuffer_test/flatterbuffer_test.cpp

CMakeFiles/xzh.dir/flatterbuffer_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xzh.dir/flatterbuffer_test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/theo.xu/study/cppstudy/flatterbuffer_test/flatterbuffer_test.cpp > CMakeFiles/xzh.dir/flatterbuffer_test.cpp.i

CMakeFiles/xzh.dir/flatterbuffer_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xzh.dir/flatterbuffer_test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/theo.xu/study/cppstudy/flatterbuffer_test/flatterbuffer_test.cpp -o CMakeFiles/xzh.dir/flatterbuffer_test.cpp.s

# Object files for target xzh
xzh_OBJECTS = \
"CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o"

# External object files for target xzh
xzh_EXTERNAL_OBJECTS =

xzh: CMakeFiles/xzh.dir/flatterbuffer_test.cpp.o
xzh: CMakeFiles/xzh.dir/build.make
xzh: CMakeFiles/xzh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/theo.xu/study/cppstudy/flatterbuffer_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable xzh"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xzh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xzh.dir/build: xzh
.PHONY : CMakeFiles/xzh.dir/build

CMakeFiles/xzh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xzh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xzh.dir/clean

CMakeFiles/xzh.dir/depend:
	cd /Users/theo.xu/study/cppstudy/flatterbuffer_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/theo.xu/study/cppstudy/flatterbuffer_test /Users/theo.xu/study/cppstudy/flatterbuffer_test /Users/theo.xu/study/cppstudy/flatterbuffer_test/build /Users/theo.xu/study/cppstudy/flatterbuffer_test/build /Users/theo.xu/study/cppstudy/flatterbuffer_test/build/CMakeFiles/xzh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xzh.dir/depend

