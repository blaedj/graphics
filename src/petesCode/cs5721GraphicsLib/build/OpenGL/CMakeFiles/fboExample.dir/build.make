# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build

# Include any dependencies generated for this target.
include OpenGL/CMakeFiles/fboExample.dir/depend.make

# Include the progress variables for this target.
include OpenGL/CMakeFiles/fboExample.dir/progress.make

# Include the compile flags for this target's objects.
include OpenGL/CMakeFiles/fboExample.dir/flags.make

OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o: OpenGL/CMakeFiles/fboExample.dir/flags.make
OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o: ../OpenGL/fboExample.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/fboExample.dir/fboExample.cpp.o -c /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/fboExample.cpp

OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fboExample.dir/fboExample.cpp.i"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/fboExample.cpp > CMakeFiles/fboExample.dir/fboExample.cpp.i

OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fboExample.dir/fboExample.cpp.s"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/fboExample.cpp -o CMakeFiles/fboExample.dir/fboExample.cpp.s

OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.requires:
.PHONY : OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.requires

OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.provides: OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.requires
	$(MAKE) -f OpenGL/CMakeFiles/fboExample.dir/build.make OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.provides.build
.PHONY : OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.provides

OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.provides.build: OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o

OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o: OpenGL/CMakeFiles/fboExample.dir/flags.make
OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o: ../OpenGL/framebufferObject.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/fboExample.dir/framebufferObject.cpp.o -c /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/framebufferObject.cpp

OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fboExample.dir/framebufferObject.cpp.i"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/framebufferObject.cpp > CMakeFiles/fboExample.dir/framebufferObject.cpp.i

OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fboExample.dir/framebufferObject.cpp.s"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/framebufferObject.cpp -o CMakeFiles/fboExample.dir/framebufferObject.cpp.s

OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.requires:
.PHONY : OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.requires

OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.provides: OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.requires
	$(MAKE) -f OpenGL/CMakeFiles/fboExample.dir/build.make OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.provides.build
.PHONY : OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.provides

OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.provides.build: OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o

OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o: OpenGL/CMakeFiles/fboExample.dir/flags.make
OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o: ../OpenGL/GLSL.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/fboExample.dir/GLSL.cpp.o -c /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/GLSL.cpp

OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fboExample.dir/GLSL.cpp.i"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/GLSL.cpp > CMakeFiles/fboExample.dir/GLSL.cpp.i

OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fboExample.dir/GLSL.cpp.s"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL/GLSL.cpp -o CMakeFiles/fboExample.dir/GLSL.cpp.s

OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.requires:
.PHONY : OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.requires

OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.provides: OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.requires
	$(MAKE) -f OpenGL/CMakeFiles/fboExample.dir/build.make OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.provides.build
.PHONY : OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.provides

OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.provides.build: OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o

# Object files for target fboExample
fboExample_OBJECTS = \
"CMakeFiles/fboExample.dir/fboExample.cpp.o" \
"CMakeFiles/fboExample.dir/framebufferObject.cpp.o" \
"CMakeFiles/fboExample.dir/GLSL.cpp.o"

# External object files for target fboExample
fboExample_EXTERNAL_OBJECTS =

OpenGL/fboExample: OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o
OpenGL/fboExample: OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o
OpenGL/fboExample: OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o
OpenGL/fboExample: OpenGL/CMakeFiles/fboExample.dir/build.make
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libGLU.so
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libGL.so
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libSM.so
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libICE.so
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libX11.so
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libXext.so
OpenGL/fboExample: src/libsive-rtutil.a
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libboost_thread.a
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libboost_program_options.a
OpenGL/fboExample: /usr/lib/x86_64-linux-gnu/libboost_system.a
OpenGL/fboExample: /usr/lib/libsfml-system.so
OpenGL/fboExample: /usr/lib/libsfml-window.so
OpenGL/fboExample: /usr/lib/libsfml-graphics.so
OpenGL/fboExample: /usr/lib/libsfml-audio.so
OpenGL/fboExample: OpenGL/CMakeFiles/fboExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable fboExample"
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fboExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
OpenGL/CMakeFiles/fboExample.dir/build: OpenGL/fboExample
.PHONY : OpenGL/CMakeFiles/fboExample.dir/build

OpenGL/CMakeFiles/fboExample.dir/requires: OpenGL/CMakeFiles/fboExample.dir/fboExample.cpp.o.requires
OpenGL/CMakeFiles/fboExample.dir/requires: OpenGL/CMakeFiles/fboExample.dir/framebufferObject.cpp.o.requires
OpenGL/CMakeFiles/fboExample.dir/requires: OpenGL/CMakeFiles/fboExample.dir/GLSL.cpp.o.requires
.PHONY : OpenGL/CMakeFiles/fboExample.dir/requires

OpenGL/CMakeFiles/fboExample.dir/clean:
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL && $(CMAKE_COMMAND) -P CMakeFiles/fboExample.dir/cmake_clean.cmake
.PHONY : OpenGL/CMakeFiles/fboExample.dir/clean

OpenGL/CMakeFiles/fboExample.dir/depend:
	cd /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/OpenGL /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL /home/blaed/code/graphics/src/petesCode/cs5721GraphicsLib/build/OpenGL/CMakeFiles/fboExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : OpenGL/CMakeFiles/fboExample.dir/depend

