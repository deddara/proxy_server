# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/145/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/145/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deddara/proxy_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deddara/proxy_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proxy_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proxy_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proxy_server.dir/flags.make

CMakeFiles/proxy_server.dir/proxy_server.cpp.o: CMakeFiles/proxy_server.dir/flags.make
CMakeFiles/proxy_server.dir/proxy_server.cpp.o: ../proxy_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deddara/proxy_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proxy_server.dir/proxy_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy_server.dir/proxy_server.cpp.o -c /home/deddara/proxy_server/proxy_server.cpp

CMakeFiles/proxy_server.dir/proxy_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy_server.dir/proxy_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deddara/proxy_server/proxy_server.cpp > CMakeFiles/proxy_server.dir/proxy_server.cpp.i

CMakeFiles/proxy_server.dir/proxy_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy_server.dir/proxy_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deddara/proxy_server/proxy_server.cpp -o CMakeFiles/proxy_server.dir/proxy_server.cpp.s

CMakeFiles/proxy_server.dir/Server.cpp.o: CMakeFiles/proxy_server.dir/flags.make
CMakeFiles/proxy_server.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deddara/proxy_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proxy_server.dir/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy_server.dir/Server.cpp.o -c /home/deddara/proxy_server/Server.cpp

CMakeFiles/proxy_server.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy_server.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deddara/proxy_server/Server.cpp > CMakeFiles/proxy_server.dir/Server.cpp.i

CMakeFiles/proxy_server.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy_server.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deddara/proxy_server/Server.cpp -o CMakeFiles/proxy_server.dir/Server.cpp.s

CMakeFiles/proxy_server.dir/Client.cpp.o: CMakeFiles/proxy_server.dir/flags.make
CMakeFiles/proxy_server.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deddara/proxy_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/proxy_server.dir/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proxy_server.dir/Client.cpp.o -c /home/deddara/proxy_server/Client.cpp

CMakeFiles/proxy_server.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy_server.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deddara/proxy_server/Client.cpp > CMakeFiles/proxy_server.dir/Client.cpp.i

CMakeFiles/proxy_server.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy_server.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deddara/proxy_server/Client.cpp -o CMakeFiles/proxy_server.dir/Client.cpp.s

# Object files for target proxy_server
proxy_server_OBJECTS = \
"CMakeFiles/proxy_server.dir/proxy_server.cpp.o" \
"CMakeFiles/proxy_server.dir/Server.cpp.o" \
"CMakeFiles/proxy_server.dir/Client.cpp.o"

# External object files for target proxy_server
proxy_server_EXTERNAL_OBJECTS =

proxy_server: CMakeFiles/proxy_server.dir/proxy_server.cpp.o
proxy_server: CMakeFiles/proxy_server.dir/Server.cpp.o
proxy_server: CMakeFiles/proxy_server.dir/Client.cpp.o
proxy_server: CMakeFiles/proxy_server.dir/build.make
proxy_server: CMakeFiles/proxy_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deddara/proxy_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable proxy_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proxy_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proxy_server.dir/build: proxy_server

.PHONY : CMakeFiles/proxy_server.dir/build

CMakeFiles/proxy_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proxy_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proxy_server.dir/clean

CMakeFiles/proxy_server.dir/depend:
	cd /home/deddara/proxy_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deddara/proxy_server /home/deddara/proxy_server /home/deddara/proxy_server/cmake-build-debug /home/deddara/proxy_server/cmake-build-debug /home/deddara/proxy_server/cmake-build-debug/CMakeFiles/proxy_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proxy_server.dir/depend

