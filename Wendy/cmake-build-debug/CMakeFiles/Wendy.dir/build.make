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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Maria/Downloads/Practica-6/Wendy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Wendy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Wendy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wendy.dir/flags.make

CMakeFiles/Wendy.dir/servidor.c.o: CMakeFiles/Wendy.dir/flags.make
CMakeFiles/Wendy.dir/servidor.c.o: ../servidor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Wendy.dir/servidor.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wendy.dir/servidor.c.o   -c /Users/Maria/Downloads/Practica-6/Wendy/servidor.c

CMakeFiles/Wendy.dir/servidor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wendy.dir/servidor.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Maria/Downloads/Practica-6/Wendy/servidor.c > CMakeFiles/Wendy.dir/servidor.c.i

CMakeFiles/Wendy.dir/servidor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wendy.dir/servidor.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Maria/Downloads/Practica-6/Wendy/servidor.c -o CMakeFiles/Wendy.dir/servidor.c.s

CMakeFiles/Wendy.dir/servidorDedicat.c.o: CMakeFiles/Wendy.dir/flags.make
CMakeFiles/Wendy.dir/servidorDedicat.c.o: ../servidorDedicat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Wendy.dir/servidorDedicat.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wendy.dir/servidorDedicat.c.o   -c /Users/Maria/Downloads/Practica-6/Wendy/servidorDedicat.c

CMakeFiles/Wendy.dir/servidorDedicat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wendy.dir/servidorDedicat.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Maria/Downloads/Practica-6/Wendy/servidorDedicat.c > CMakeFiles/Wendy.dir/servidorDedicat.c.i

CMakeFiles/Wendy.dir/servidorDedicat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wendy.dir/servidorDedicat.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Maria/Downloads/Practica-6/Wendy/servidorDedicat.c -o CMakeFiles/Wendy.dir/servidorDedicat.c.s

CMakeFiles/Wendy.dir/until.c.o: CMakeFiles/Wendy.dir/flags.make
CMakeFiles/Wendy.dir/until.c.o: ../until.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Wendy.dir/until.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wendy.dir/until.c.o   -c /Users/Maria/Downloads/Practica-6/Wendy/until.c

CMakeFiles/Wendy.dir/until.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wendy.dir/until.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Maria/Downloads/Practica-6/Wendy/until.c > CMakeFiles/Wendy.dir/until.c.i

CMakeFiles/Wendy.dir/until.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wendy.dir/until.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Maria/Downloads/Practica-6/Wendy/until.c -o CMakeFiles/Wendy.dir/until.c.s

CMakeFiles/Wendy.dir/jpg.c.o: CMakeFiles/Wendy.dir/flags.make
CMakeFiles/Wendy.dir/jpg.c.o: ../jpg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Wendy.dir/jpg.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wendy.dir/jpg.c.o   -c /Users/Maria/Downloads/Practica-6/Wendy/jpg.c

CMakeFiles/Wendy.dir/jpg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wendy.dir/jpg.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Maria/Downloads/Practica-6/Wendy/jpg.c > CMakeFiles/Wendy.dir/jpg.c.i

CMakeFiles/Wendy.dir/jpg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wendy.dir/jpg.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Maria/Downloads/Practica-6/Wendy/jpg.c -o CMakeFiles/Wendy.dir/jpg.c.s

CMakeFiles/Wendy.dir/mensaje.c.o: CMakeFiles/Wendy.dir/flags.make
CMakeFiles/Wendy.dir/mensaje.c.o: ../mensaje.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Wendy.dir/mensaje.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wendy.dir/mensaje.c.o   -c /Users/Maria/Downloads/Practica-6/Wendy/mensaje.c

CMakeFiles/Wendy.dir/mensaje.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wendy.dir/mensaje.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Maria/Downloads/Practica-6/Wendy/mensaje.c > CMakeFiles/Wendy.dir/mensaje.c.i

CMakeFiles/Wendy.dir/mensaje.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wendy.dir/mensaje.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Maria/Downloads/Practica-6/Wendy/mensaje.c -o CMakeFiles/Wendy.dir/mensaje.c.s

CMakeFiles/Wendy.dir/fitxer.c.o: CMakeFiles/Wendy.dir/flags.make
CMakeFiles/Wendy.dir/fitxer.c.o: ../fitxer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Wendy.dir/fitxer.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wendy.dir/fitxer.c.o   -c /Users/Maria/Downloads/Practica-6/Wendy/fitxer.c

CMakeFiles/Wendy.dir/fitxer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wendy.dir/fitxer.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Maria/Downloads/Practica-6/Wendy/fitxer.c > CMakeFiles/Wendy.dir/fitxer.c.i

CMakeFiles/Wendy.dir/fitxer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wendy.dir/fitxer.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Maria/Downloads/Practica-6/Wendy/fitxer.c -o CMakeFiles/Wendy.dir/fitxer.c.s

# Object files for target Wendy
Wendy_OBJECTS = \
"CMakeFiles/Wendy.dir/servidor.c.o" \
"CMakeFiles/Wendy.dir/servidorDedicat.c.o" \
"CMakeFiles/Wendy.dir/until.c.o" \
"CMakeFiles/Wendy.dir/jpg.c.o" \
"CMakeFiles/Wendy.dir/mensaje.c.o" \
"CMakeFiles/Wendy.dir/fitxer.c.o"

# External object files for target Wendy
Wendy_EXTERNAL_OBJECTS =

Wendy: CMakeFiles/Wendy.dir/servidor.c.o
Wendy: CMakeFiles/Wendy.dir/servidorDedicat.c.o
Wendy: CMakeFiles/Wendy.dir/until.c.o
Wendy: CMakeFiles/Wendy.dir/jpg.c.o
Wendy: CMakeFiles/Wendy.dir/mensaje.c.o
Wendy: CMakeFiles/Wendy.dir/fitxer.c.o
Wendy: CMakeFiles/Wendy.dir/build.make
Wendy: CMakeFiles/Wendy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Wendy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wendy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wendy.dir/build: Wendy

.PHONY : CMakeFiles/Wendy.dir/build

CMakeFiles/Wendy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wendy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wendy.dir/clean

CMakeFiles/Wendy.dir/depend:
	cd /Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Maria/Downloads/Practica-6/Wendy /Users/Maria/Downloads/Practica-6/Wendy /Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug /Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug /Users/Maria/Downloads/Practica-6/Wendy/cmake-build-debug/CMakeFiles/Wendy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Wendy.dir/depend
