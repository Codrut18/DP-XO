# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Console.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Console.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Console.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Console.dir/flags.make

CMakeFiles/Console.dir/Console/main.cpp.obj: CMakeFiles/Console.dir/flags.make
CMakeFiles/Console.dir/Console/main.cpp.obj: CMakeFiles/Console.dir/includes_CXX.rsp
CMakeFiles/Console.dir/Console/main.cpp.obj: D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/Console/main.cpp
CMakeFiles/Console.dir/Console/main.cpp.obj: CMakeFiles/Console.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Console.dir/Console/main.cpp.obj"
	D:\SFMLMingw\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Console.dir/Console/main.cpp.obj -MF CMakeFiles\Console.dir\Console\main.cpp.obj.d -o CMakeFiles\Console.dir\Console\main.cpp.obj -c D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\Console\main.cpp

CMakeFiles/Console.dir/Console/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Console.dir/Console/main.cpp.i"
	D:\SFMLMingw\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\Console\main.cpp > CMakeFiles\Console.dir\Console\main.cpp.i

CMakeFiles/Console.dir/Console/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Console.dir/Console/main.cpp.s"
	D:\SFMLMingw\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\Console\main.cpp -o CMakeFiles\Console.dir\Console\main.cpp.s

# Object files for target Console
Console_OBJECTS = \
"CMakeFiles/Console.dir/Console/main.cpp.obj"

# External object files for target Console
Console_EXTERNAL_OBJECTS =

Console.exe: CMakeFiles/Console.dir/Console/main.cpp.obj
Console.exe: CMakeFiles/Console.dir/build.make
Console.exe: CMakeFiles/Console.dir/linklibs.rsp
Console.exe: CMakeFiles/Console.dir/objects1.rsp
Console.exe: CMakeFiles/Console.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Console.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Console.dir\link.txt --verbose=$(VERBOSE)
	C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe -noprofile -executionpolicy Bypass -file C:/src/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/Console.exe -installedDir C:/src/vcpkg/installed/x64-windows/debug/bin -OutVariable out

# Rule to build all files generated by this target.
CMakeFiles/Console.dir/build: Console.exe
.PHONY : CMakeFiles/Console.dir/build

CMakeFiles/Console.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Console.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Console.dir/clean

CMakeFiles/Console.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\cmake-build-debug D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\cmake-build-debug D:\FACULTATE\Facultate\An_2_sem_2\DP_DesignPattern\ProjectX0\DP-XO\cmake-build-debug\CMakeFiles\Console.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Console.dir/depend

