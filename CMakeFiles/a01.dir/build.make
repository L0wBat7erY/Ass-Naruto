# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/sierra/Desktop/share/Downloads/DSA171-A01-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sierra/Desktop/share/Downloads/DSA171-A01-master

# Include any dependencies generated for this target.
include CMakeFiles/a01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a01.dir/flags.make

CMakeFiles/a01.dir/main.cpp.o: CMakeFiles/a01.dir/flags.make
CMakeFiles/a01.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sierra/Desktop/share/Downloads/DSA171-A01-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a01.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a01.dir/main.cpp.o -c /home/sierra/Desktop/share/Downloads/DSA171-A01-master/main.cpp

CMakeFiles/a01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a01.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sierra/Desktop/share/Downloads/DSA171-A01-master/main.cpp > CMakeFiles/a01.dir/main.cpp.i

CMakeFiles/a01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a01.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sierra/Desktop/share/Downloads/DSA171-A01-master/main.cpp -o CMakeFiles/a01.dir/main.cpp.s

CMakeFiles/a01.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/a01.dir/main.cpp.o.requires

CMakeFiles/a01.dir/main.cpp.o.provides: CMakeFiles/a01.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/a01.dir/build.make CMakeFiles/a01.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/a01.dir/main.cpp.o.provides

CMakeFiles/a01.dir/main.cpp.o.provides.build: CMakeFiles/a01.dir/main.cpp.o


CMakeFiles/a01.dir/eventLib.cpp.o: CMakeFiles/a01.dir/flags.make
CMakeFiles/a01.dir/eventLib.cpp.o: eventLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sierra/Desktop/share/Downloads/DSA171-A01-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a01.dir/eventLib.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a01.dir/eventLib.cpp.o -c /home/sierra/Desktop/share/Downloads/DSA171-A01-master/eventLib.cpp

CMakeFiles/a01.dir/eventLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a01.dir/eventLib.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sierra/Desktop/share/Downloads/DSA171-A01-master/eventLib.cpp > CMakeFiles/a01.dir/eventLib.cpp.i

CMakeFiles/a01.dir/eventLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a01.dir/eventLib.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sierra/Desktop/share/Downloads/DSA171-A01-master/eventLib.cpp -o CMakeFiles/a01.dir/eventLib.cpp.s

CMakeFiles/a01.dir/eventLib.cpp.o.requires:

.PHONY : CMakeFiles/a01.dir/eventLib.cpp.o.requires

CMakeFiles/a01.dir/eventLib.cpp.o.provides: CMakeFiles/a01.dir/eventLib.cpp.o.requires
	$(MAKE) -f CMakeFiles/a01.dir/build.make CMakeFiles/a01.dir/eventLib.cpp.o.provides.build
.PHONY : CMakeFiles/a01.dir/eventLib.cpp.o.provides

CMakeFiles/a01.dir/eventLib.cpp.o.provides.build: CMakeFiles/a01.dir/eventLib.cpp.o


CMakeFiles/a01.dir/dbLib.cpp.o: CMakeFiles/a01.dir/flags.make
CMakeFiles/a01.dir/dbLib.cpp.o: dbLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sierra/Desktop/share/Downloads/DSA171-A01-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a01.dir/dbLib.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a01.dir/dbLib.cpp.o -c /home/sierra/Desktop/share/Downloads/DSA171-A01-master/dbLib.cpp

CMakeFiles/a01.dir/dbLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a01.dir/dbLib.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sierra/Desktop/share/Downloads/DSA171-A01-master/dbLib.cpp > CMakeFiles/a01.dir/dbLib.cpp.i

CMakeFiles/a01.dir/dbLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a01.dir/dbLib.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sierra/Desktop/share/Downloads/DSA171-A01-master/dbLib.cpp -o CMakeFiles/a01.dir/dbLib.cpp.s

CMakeFiles/a01.dir/dbLib.cpp.o.requires:

.PHONY : CMakeFiles/a01.dir/dbLib.cpp.o.requires

CMakeFiles/a01.dir/dbLib.cpp.o.provides: CMakeFiles/a01.dir/dbLib.cpp.o.requires
	$(MAKE) -f CMakeFiles/a01.dir/build.make CMakeFiles/a01.dir/dbLib.cpp.o.provides.build
.PHONY : CMakeFiles/a01.dir/dbLib.cpp.o.provides

CMakeFiles/a01.dir/dbLib.cpp.o.provides.build: CMakeFiles/a01.dir/dbLib.cpp.o


CMakeFiles/a01.dir/processData.cpp.o: CMakeFiles/a01.dir/flags.make
CMakeFiles/a01.dir/processData.cpp.o: processData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sierra/Desktop/share/Downloads/DSA171-A01-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a01.dir/processData.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a01.dir/processData.cpp.o -c /home/sierra/Desktop/share/Downloads/DSA171-A01-master/processData.cpp

CMakeFiles/a01.dir/processData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a01.dir/processData.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sierra/Desktop/share/Downloads/DSA171-A01-master/processData.cpp > CMakeFiles/a01.dir/processData.cpp.i

CMakeFiles/a01.dir/processData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a01.dir/processData.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sierra/Desktop/share/Downloads/DSA171-A01-master/processData.cpp -o CMakeFiles/a01.dir/processData.cpp.s

CMakeFiles/a01.dir/processData.cpp.o.requires:

.PHONY : CMakeFiles/a01.dir/processData.cpp.o.requires

CMakeFiles/a01.dir/processData.cpp.o.provides: CMakeFiles/a01.dir/processData.cpp.o.requires
	$(MAKE) -f CMakeFiles/a01.dir/build.make CMakeFiles/a01.dir/processData.cpp.o.provides.build
.PHONY : CMakeFiles/a01.dir/processData.cpp.o.provides

CMakeFiles/a01.dir/processData.cpp.o.provides.build: CMakeFiles/a01.dir/processData.cpp.o


# Object files for target a01
a01_OBJECTS = \
"CMakeFiles/a01.dir/main.cpp.o" \
"CMakeFiles/a01.dir/eventLib.cpp.o" \
"CMakeFiles/a01.dir/dbLib.cpp.o" \
"CMakeFiles/a01.dir/processData.cpp.o"

# External object files for target a01
a01_EXTERNAL_OBJECTS =

a01: CMakeFiles/a01.dir/main.cpp.o
a01: CMakeFiles/a01.dir/eventLib.cpp.o
a01: CMakeFiles/a01.dir/dbLib.cpp.o
a01: CMakeFiles/a01.dir/processData.cpp.o
a01: CMakeFiles/a01.dir/build.make
a01: CMakeFiles/a01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sierra/Desktop/share/Downloads/DSA171-A01-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable a01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a01.dir/build: a01

.PHONY : CMakeFiles/a01.dir/build

CMakeFiles/a01.dir/requires: CMakeFiles/a01.dir/main.cpp.o.requires
CMakeFiles/a01.dir/requires: CMakeFiles/a01.dir/eventLib.cpp.o.requires
CMakeFiles/a01.dir/requires: CMakeFiles/a01.dir/dbLib.cpp.o.requires
CMakeFiles/a01.dir/requires: CMakeFiles/a01.dir/processData.cpp.o.requires

.PHONY : CMakeFiles/a01.dir/requires

CMakeFiles/a01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a01.dir/clean

CMakeFiles/a01.dir/depend:
	cd /home/sierra/Desktop/share/Downloads/DSA171-A01-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sierra/Desktop/share/Downloads/DSA171-A01-master /home/sierra/Desktop/share/Downloads/DSA171-A01-master /home/sierra/Desktop/share/Downloads/DSA171-A01-master /home/sierra/Desktop/share/Downloads/DSA171-A01-master /home/sierra/Desktop/share/Downloads/DSA171-A01-master/CMakeFiles/a01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a01.dir/depend

