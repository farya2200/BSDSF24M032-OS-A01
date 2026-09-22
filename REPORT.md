# Feature 2: Multi-file Project using Make Utility

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
