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
CMAKE_SOURCE_DIR = /home/vinivice/academico/inic_cient/IMEvolve

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vinivice/academico/inic_cient/IMEvolve/build

# Include any dependencies generated for this target.
include include/CMakeFiles/bibliotecas.dir/depend.make

# Include the progress variables for this target.
include include/CMakeFiles/bibliotecas.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/bibliotecas.dir/flags.make

include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o: include/CMakeFiles/bibliotecas.dir/flags.make
include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o: ../src/funcaoObjetivo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vinivice/academico/inic_cient/IMEvolve/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o"
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o -c /home/vinivice/academico/inic_cient/IMEvolve/src/funcaoObjetivo.cpp

include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.i"
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vinivice/academico/inic_cient/IMEvolve/src/funcaoObjetivo.cpp > CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.i

include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.s"
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vinivice/academico/inic_cient/IMEvolve/src/funcaoObjetivo.cpp -o CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.s

include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.requires:
.PHONY : include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.requires

include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.provides: include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.requires
	$(MAKE) -f include/CMakeFiles/bibliotecas.dir/build.make include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.provides.build
.PHONY : include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.provides

include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.provides.build: include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o

include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o: include/CMakeFiles/bibliotecas.dir/flags.make
include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o: ../src/individuo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vinivice/academico/inic_cient/IMEvolve/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o"
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o -c /home/vinivice/academico/inic_cient/IMEvolve/src/individuo.cpp

include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.i"
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vinivice/academico/inic_cient/IMEvolve/src/individuo.cpp > CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.i

include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.s"
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vinivice/academico/inic_cient/IMEvolve/src/individuo.cpp -o CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.s

include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.requires:
.PHONY : include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.requires

include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.provides: include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.requires
	$(MAKE) -f include/CMakeFiles/bibliotecas.dir/build.make include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.provides.build
.PHONY : include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.provides

include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.provides.build: include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o

# Object files for target bibliotecas
bibliotecas_OBJECTS = \
"CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o" \
"CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o"

# External object files for target bibliotecas
bibliotecas_EXTERNAL_OBJECTS =

include/libbibliotecas.a: include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o
include/libbibliotecas.a: include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o
include/libbibliotecas.a: include/CMakeFiles/bibliotecas.dir/build.make
include/libbibliotecas.a: include/CMakeFiles/bibliotecas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libbibliotecas.a"
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && $(CMAKE_COMMAND) -P CMakeFiles/bibliotecas.dir/cmake_clean_target.cmake
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bibliotecas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/bibliotecas.dir/build: include/libbibliotecas.a
.PHONY : include/CMakeFiles/bibliotecas.dir/build

include/CMakeFiles/bibliotecas.dir/requires: include/CMakeFiles/bibliotecas.dir/__/src/funcaoObjetivo.cpp.o.requires
include/CMakeFiles/bibliotecas.dir/requires: include/CMakeFiles/bibliotecas.dir/__/src/individuo.cpp.o.requires
.PHONY : include/CMakeFiles/bibliotecas.dir/requires

include/CMakeFiles/bibliotecas.dir/clean:
	cd /home/vinivice/academico/inic_cient/IMEvolve/build/include && $(CMAKE_COMMAND) -P CMakeFiles/bibliotecas.dir/cmake_clean.cmake
.PHONY : include/CMakeFiles/bibliotecas.dir/clean

include/CMakeFiles/bibliotecas.dir/depend:
	cd /home/vinivice/academico/inic_cient/IMEvolve/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vinivice/academico/inic_cient/IMEvolve /home/vinivice/academico/inic_cient/IMEvolve/include /home/vinivice/academico/inic_cient/IMEvolve/build /home/vinivice/academico/inic_cient/IMEvolve/build/include /home/vinivice/academico/inic_cient/IMEvolve/build/include/CMakeFiles/bibliotecas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/bibliotecas.dir/depend

