# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/teotoivo/Projects/ttsh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teotoivo/Projects/ttsh/build

# Include any dependencies generated for this target.
include CMakeFiles/ttsh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ttsh.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ttsh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ttsh.dir/flags.make

CMakeFiles/ttsh.dir/codegen:
.PHONY : CMakeFiles/ttsh.dir/codegen

CMakeFiles/ttsh.dir/src/main.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/main.c.o: /home/teotoivo/Projects/ttsh/src/main.c
CMakeFiles/ttsh.dir/src/main.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ttsh.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/main.c.o -MF CMakeFiles/ttsh.dir/src/main.c.o.d -o CMakeFiles/ttsh.dir/src/main.c.o -c /home/teotoivo/Projects/ttsh/src/main.c

CMakeFiles/ttsh.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/main.c > CMakeFiles/ttsh.dir/src/main.c.i

CMakeFiles/ttsh.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/main.c -o CMakeFiles/ttsh.dir/src/main.c.s

CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_builtins.c
CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_builtins.c

CMakeFiles/ttsh.dir/src/ttsh_builtins.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_builtins.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_builtins.c > CMakeFiles/ttsh.dir/src/ttsh_builtins.c.i

CMakeFiles/ttsh.dir/src/ttsh_builtins.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_builtins.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_builtins.c -o CMakeFiles/ttsh.dir/src/ttsh_builtins.c.s

CMakeFiles/ttsh.dir/src/ttsh_config.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_config.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_config.c
CMakeFiles/ttsh.dir/src/ttsh_config.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ttsh.dir/src/ttsh_config.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_config.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_config.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_config.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_config.c

CMakeFiles/ttsh.dir/src/ttsh_config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_config.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_config.c > CMakeFiles/ttsh.dir/src/ttsh_config.c.i

CMakeFiles/ttsh.dir/src/ttsh_config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_config.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_config.c -o CMakeFiles/ttsh.dir/src/ttsh_config.c.s

CMakeFiles/ttsh.dir/src/ttsh_core.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_core.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_core.c
CMakeFiles/ttsh.dir/src/ttsh_core.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ttsh.dir/src/ttsh_core.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_core.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_core.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_core.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_core.c

CMakeFiles/ttsh.dir/src/ttsh_core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_core.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_core.c > CMakeFiles/ttsh.dir/src/ttsh_core.c.i

CMakeFiles/ttsh.dir/src/ttsh_core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_core.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_core.c -o CMakeFiles/ttsh.dir/src/ttsh_core.c.s

CMakeFiles/ttsh.dir/src/ttsh_execution.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_execution.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_execution.c
CMakeFiles/ttsh.dir/src/ttsh_execution.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ttsh.dir/src/ttsh_execution.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_execution.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_execution.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_execution.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_execution.c

CMakeFiles/ttsh.dir/src/ttsh_execution.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_execution.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_execution.c > CMakeFiles/ttsh.dir/src/ttsh_execution.c.i

CMakeFiles/ttsh.dir/src/ttsh_execution.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_execution.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_execution.c -o CMakeFiles/ttsh.dir/src/ttsh_execution.c.s

CMakeFiles/ttsh.dir/src/ttsh_input.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_input.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_input.c
CMakeFiles/ttsh.dir/src/ttsh_input.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ttsh.dir/src/ttsh_input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_input.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_input.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_input.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_input.c

CMakeFiles/ttsh.dir/src/ttsh_input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_input.c > CMakeFiles/ttsh.dir/src/ttsh_input.c.i

CMakeFiles/ttsh.dir/src/ttsh_input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_input.c -o CMakeFiles/ttsh.dir/src/ttsh_input.c.s

CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_prompt.c
CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_prompt.c

CMakeFiles/ttsh.dir/src/ttsh_prompt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_prompt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_prompt.c > CMakeFiles/ttsh.dir/src/ttsh_prompt.c.i

CMakeFiles/ttsh.dir/src/ttsh_prompt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_prompt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_prompt.c -o CMakeFiles/ttsh.dir/src/ttsh_prompt.c.s

CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_tokenizer.c
CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_tokenizer.c

CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_tokenizer.c > CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.i

CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_tokenizer.c -o CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.s

CMakeFiles/ttsh.dir/src/ttsh_utils.c.o: CMakeFiles/ttsh.dir/flags.make
CMakeFiles/ttsh.dir/src/ttsh_utils.c.o: /home/teotoivo/Projects/ttsh/src/ttsh_utils.c
CMakeFiles/ttsh.dir/src/ttsh_utils.c.o: CMakeFiles/ttsh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/ttsh.dir/src/ttsh_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ttsh.dir/src/ttsh_utils.c.o -MF CMakeFiles/ttsh.dir/src/ttsh_utils.c.o.d -o CMakeFiles/ttsh.dir/src/ttsh_utils.c.o -c /home/teotoivo/Projects/ttsh/src/ttsh_utils.c

CMakeFiles/ttsh.dir/src/ttsh_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ttsh.dir/src/ttsh_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/teotoivo/Projects/ttsh/src/ttsh_utils.c > CMakeFiles/ttsh.dir/src/ttsh_utils.c.i

CMakeFiles/ttsh.dir/src/ttsh_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ttsh.dir/src/ttsh_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/teotoivo/Projects/ttsh/src/ttsh_utils.c -o CMakeFiles/ttsh.dir/src/ttsh_utils.c.s

# Object files for target ttsh
ttsh_OBJECTS = \
"CMakeFiles/ttsh.dir/src/main.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_config.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_core.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_execution.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_input.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o" \
"CMakeFiles/ttsh.dir/src/ttsh_utils.c.o"

# External object files for target ttsh
ttsh_EXTERNAL_OBJECTS =

/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/main.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_builtins.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_config.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_core.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_execution.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_input.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_prompt.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_tokenizer.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/src/ttsh_utils.c.o
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/build.make
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/compiler_depend.ts
/home/teotoivo/Projects/ttsh/bin/ttsh: CMakeFiles/ttsh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/teotoivo/Projects/ttsh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable /home/teotoivo/Projects/ttsh/bin/ttsh"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ttsh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ttsh.dir/build: /home/teotoivo/Projects/ttsh/bin/ttsh
.PHONY : CMakeFiles/ttsh.dir/build

CMakeFiles/ttsh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ttsh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ttsh.dir/clean

CMakeFiles/ttsh.dir/depend:
	cd /home/teotoivo/Projects/ttsh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teotoivo/Projects/ttsh /home/teotoivo/Projects/ttsh /home/teotoivo/Projects/ttsh/build /home/teotoivo/Projects/ttsh/build /home/teotoivo/Projects/ttsh/build/CMakeFiles/ttsh.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ttsh.dir/depend

