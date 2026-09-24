# Feature 4: Creating and Using Dynamic Library

## 1. Position-Independent Code (-fPIC)

Position-Independent Code (PIC) is code that can run correctly regardless of where it is loaded into memory.

The `-fPIC` option tells GCC to generate position-independent code.

It is important for shared libraries because a dynamic library can be loaded at different memory addresses by different programs. The code must therefore be able to work correctly without depending on a fixed memory address.

In this project, `-fPIC` was used when compiling the object files for `libmyutils.so`.

## 2. Difference Between Static and Dynamic Client File Sizes

The static client `client_static` and dynamic client `client_dynamic` have different file sizes.

The static executable is generally larger because the required code from `libmyutils.a` is copied into the executable during linking.

The dynamic executable is generally smaller because the code from `libmyutils.so` remains in the shared library instead of being copied into the executable.

When `client_dynamic` runs, the operating system's dynamic loader loads the required shared library separately.

Therefore, the difference in size occurs because static linking includes library code inside the executable, while dynamic linking keeps the library code in a separate `.so` file.

## 3. LD_LIBRARY_PATH

`LD_LIBRARY_PATH` is an environment variable that tells the Linux dynamic loader which directories to search for shared libraries.

When `./bin/client_dynamic` was first executed, the loader could not find `libmyutils.so` because the project's `lib/` directory was not one of its default library search locations.

The error was:

`cannot open shared object file: No such file or directory`

We fixed this by using:

`export LD_LIBRARY_PATH=$PWD/lib:$LD_LIBRARY_PATH`

After setting this variable, the loader was able to find `libmyutils.so` in the project's `lib/` directory and the program executed successfully.

This shows that the dynamic loader is responsible for finding and loading shared libraries when a dynamically linked program starts. The library must be located in a directory known to the loader.# Feature 3: Creating and Using Static Library

## 1. Comparison of Makefiles

In Part 2, the Makefile compiled the source files into object files and then directly linked all the object files to create the executable.

In Part 3, the Makefile was modified to first create a static library called `libmyutils.a`. The utility object files `mystrfunctions.o` and `myfilefunctions.o` are placed inside this library.

The important differences are:

- Part 2 directly links all object files.
- Part 3 creates a static library using `ar`.
- Part 3 uses `LIB = lib/libmyutils.a`.
- The final executable is linked using `-Llib -lmyutils`.
- The final executable is named `client_static`.

Therefore, Part 3 separates the utility functions into a reusable static library.

## 2. Purpose of the ar Command

The `ar` command is used to create and modify archive files.

In this project, `ar` combines the object files into the static library:

`lib/libmyutils.a`

The command used was:

`ar rcs lib/libmyutils.a obj/mystrfunctions.o obj/myfilefunctions.o`

The options mean:

- `r` — insert or replace files in the archive.
- `c` — create the archive if it does not exist.
- `s` — create or update the symbol index.

`ranlib` is often used after `ar` to create or update the symbol index of a static library. This index helps the linker quickly find the required symbols. When the `s` option is used with `ar`, the symbol index is created automatically, so a separate `ranlib` command is not necessary.

## 3. nm and Static Linking

When `nm` is run on the `client_static` executable, symbols for functions such as `mystrlen` are present.

For example:

`nm bin/client_static | grep mystrlen`

shows the `mystrlen` symbol in the executable.

This demonstrates that the required function code from the static library has been included in the final executable during static linking.

In static linking, the linker takes the required object code from the `.a` library and places it into the executable. Therefore, functions such as `mystrlen` become part of `client_static`.# Feature 2: Multi-file Project using Make Utility

## 1. Linking Rule in Makefile

The rule `$(TARGET): $(OBJECTS)` means that the final executable depends on all the object files.

For example:

$(TARGET): $(OBJECTS)

This tells Make that `client` must be created or updated using `main.o`, `mystrfunctions.o`, and `myfilefunctions.o`.

The object files are then linked together to create the final executable.

If a Makefile links against a library, the library is also included as a dependency and is specified in the linking command. For example, a library can be linked using `-L` to specify the library location and `-l` to specify the library name.

Therefore, direct multi-file linking combines the object files directly, while library linking uses functions provided by a separate library.

## 2. Git Tags

A Git tag is a name given to a specific commit in a Git repository.

Tags are useful for marking important versions or milestones of a project, such as Version 1.0 or Version 2.0.

There are two common types of tags:

- Lightweight tag: A simple pointer to a specific commit.
- Annotated tag: A complete Git object containing information such as the tag name, message, tagger, and date.

Annotated tags are useful for official releases because they contain additional information about the version.

For this project, the annotated tag `v0.1.1-multifile` was created to mark the multi-file build version.

## 3. GitHub Releases

A GitHub Release is a published version of a project based on a Git tag.

It provides users with a convenient way to access a specific version of the project.

Attaching the compiled binary is useful because users can download and use the executable directly without installing the compiler or compiling the source code themselves.

For this project, the `client` executable was attached to the GitHub Release.
