# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\immer_000\CLionProjects\ScoringProgram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\immer_000\CLionProjects\ScoringProgram\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/scoringC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scoringC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scoringC.dir/flags.make

CMakeFiles/scoringC.dir/main.cpp.obj: CMakeFiles/scoringC.dir/flags.make
CMakeFiles/scoringC.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\immer_000\CLionProjects\ScoringProgram\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scoringC.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\scoringC.dir\main.cpp.obj -c C:\Users\immer_000\CLionProjects\ScoringProgram\main.cpp

CMakeFiles/scoringC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scoringC.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\immer_000\CLionProjects\ScoringProgram\main.cpp > CMakeFiles\scoringC.dir\main.cpp.i

CMakeFiles/scoringC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scoringC.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\immer_000\CLionProjects\ScoringProgram\main.cpp -o CMakeFiles\scoringC.dir\main.cpp.s

# Object files for target scoringC
scoringC_OBJECTS = \
"CMakeFiles/scoringC.dir/main.cpp.obj"

# External object files for target scoringC
scoringC_EXTERNAL_OBJECTS =

scoringC.exe: CMakeFiles/scoringC.dir/main.cpp.obj
scoringC.exe: CMakeFiles/scoringC.dir/build.make
scoringC.exe: CMakeFiles/scoringC.dir/linklibs.rsp
scoringC.exe: CMakeFiles/scoringC.dir/objects1.rsp
scoringC.exe: CMakeFiles/scoringC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\immer_000\CLionProjects\ScoringProgram\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scoringC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\scoringC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scoringC.dir/build: scoringC.exe

.PHONY : CMakeFiles/scoringC.dir/build

CMakeFiles/scoringC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\scoringC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/scoringC.dir/clean

CMakeFiles/scoringC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\immer_000\CLionProjects\ScoringProgram C:\Users\immer_000\CLionProjects\ScoringProgram C:\Users\immer_000\CLionProjects\ScoringProgram\cmake-build-debug C:\Users\immer_000\CLionProjects\ScoringProgram\cmake-build-debug C:\Users\immer_000\CLionProjects\ScoringProgram\cmake-build-debug\CMakeFiles\scoringC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scoringC.dir/depend

