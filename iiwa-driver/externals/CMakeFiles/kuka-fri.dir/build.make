# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yezhao/code/kuka-dev/iiwa-driver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yezhao/code/kuka-dev/iiwa-driver/externals

# Utility rule file for kuka-fri.

# Include the progress variables for this target.
include CMakeFiles/kuka-fri.dir/progress.make

CMakeFiles/kuka-fri: CMakeFiles/kuka-fri-complete


CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-install
CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-mkdir
CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-download
CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-update
CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-patch
CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-configure
CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-build
CMakeFiles/kuka-fri-complete: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'kuka-fri'"
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E make_directory /home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles/kuka-fri-complete
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-done

kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-install: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'kuka-fri'"
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && true
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && /home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-install

kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'kuka-fri'"
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E make_directory /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E make_directory /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E make_directory /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E make_directory /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/tmp
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E make_directory /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E make_directory /home/yezhao/code/kuka-dev/iiwa-driver
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-mkdir

kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-download: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'kuka-fri'"
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E echo_append
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-download

kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-update: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'kuka-fri'"
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && /home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E echo_append
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && /home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-update

kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-patch: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'kuka-fri'"
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E echo_append
	/home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-patch

kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-configure: kuka-fri-prefix/tmp/kuka-fri-cfgcmd.txt
kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-configure: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-update
kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-configure: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'kuka-fri'"
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && true
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && /home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-configure

kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-build: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'kuka-fri'"
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && make -C build/GNUMake
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri && /home/scottk/tools/cmake-3.5.2-Linux-x86_64/bin/cmake -E touch /home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-build

kuka-fri: CMakeFiles/kuka-fri
kuka-fri: CMakeFiles/kuka-fri-complete
kuka-fri: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-install
kuka-fri: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-mkdir
kuka-fri: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-download
kuka-fri: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-update
kuka-fri: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-patch
kuka-fri: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-configure
kuka-fri: kuka-fri-prefix/src/kuka-fri-stamp/kuka-fri-build
kuka-fri: CMakeFiles/kuka-fri.dir/build.make

.PHONY : kuka-fri

# Rule to build all files generated by this target.
CMakeFiles/kuka-fri.dir/build: kuka-fri

.PHONY : CMakeFiles/kuka-fri.dir/build

CMakeFiles/kuka-fri.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kuka-fri.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kuka-fri.dir/clean

CMakeFiles/kuka-fri.dir/depend:
	cd /home/yezhao/code/kuka-dev/iiwa-driver/externals && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yezhao/code/kuka-dev/iiwa-driver /home/yezhao/code/kuka-dev/iiwa-driver /home/yezhao/code/kuka-dev/iiwa-driver/externals /home/yezhao/code/kuka-dev/iiwa-driver/externals /home/yezhao/code/kuka-dev/iiwa-driver/externals/CMakeFiles/kuka-fri.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kuka-fri.dir/depend
