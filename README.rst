Makefile Templates
==================

This contains a number of makefile templates. These Makefile
templates are as follows:

one.mk
------

Builds a single target from multiple input object files. It supports the
following variables as targets:

BIN
	The name of a binary. This binary is not installed. This is
	primarily useful for code generation.

LIB
	The name of a static library to build. This static library
        is not installed. This is primarily convenient for breaking
        your code up into smaller modules, which are linked together.

SUB
	A list of subdirectories to recurse into when building a well
	known target (eg, `clean`, `install`, and so on).

INSTBIN
	The name of a binary which is installed to `$prefix/bin`. This
        is the most common target which I use. 

INSTLIB
	The name of a static library which is installed to `$prefix/lib`.
        This makefile fragment expects the name to be in the form of
        `lib$LIBNAME.a`.

INSTHDR
	A list of headers to install. The headers are copied to
	`$prefix/include`.

INSTPKG
	This lists a set of pkg-config files, which are installed
	to `$prefix/lib/pkgconfig`. If you are building a library
	that others use, it is *highly* recommended to include a
	pkg-config file for ease of use.

INSTMAN
	Installs a manpage. The manpage is expected to be named in
	the form of `docname.SECT`, eg, `mycmd.1`, ad will be installed
	into the appropriate directory.

The inputs to all of the targets which are built are listed in the
`OBJ` variable, making it the central part of the makefiles.

OBJ
	This is the list of all the .o files that go into either the
	library or the binary that is being constructed.


There are also a number of other variables that can be used to control
the way that this makefile include works:

EXTRA
	This is a list of extra targets to build when running
	`make all`. These targets should be provided by you.

PCPKGS
	This contains a list of pkg-config packages that this program
	depends on. The libraries and include paths will be added to the
	build for the target being compiled.

DEPS
	This contains a list of local libraries that the current target
	depends on, in the form `../module/libmodule.a`. These dependencies
	will be built before the module that defines the dependencies.

EXTRADEP
	This is a list of extra dependencies to be added to the BIN, INSTBIN,
	LIB, or INSTLIB targets.

EXTRACLEAN
	This is a list of extra files to be removed on `make clean`

LDFLAGS
	This contains the linker flags. This should only be appended to,
	and not overridden.

CFLAGS
	This contains the C compiler flags. This should only be appended to,
	and not overridden.

CXXFLAGS
	This contains the C++ compiler flags. This should only be appended to,
	and not overridden.

INST_ROOT
	This defines the directory to install into. In this example, it
	is set by ./configure

lexyacc.mk
------

Augments one.mk and many.mk rules with lex and yacc rules. These
rules will take a yacc file named `input.y`, and produce `input.c` and
`input.h` from it.

Configure
=========

This also ships with a single, trivial script named configure. It
only supports setting the prefix, which for many of the programs I need
is enough.

There are some examples of libraries -- for example, clang -- which do not
ship with pkg-config files, and are typically not installed to /usr/lib. For
those, code is added to the ./configure script.

This script will automatically be run when running `make`.

An Example
==========

Pulled from my Myrddin code::

	INSTBIN=6m
	OBJ= \
		blob.o \
		gen.o \
		gengas.o \
		genp9.o \
		isel.o \
		locs.o \
		main.o \
		ra.o \
		peep.o \
		simp.o \
		typeinfo.o \

	DEPS=../parse/libparse.a ../mi/libmi.a

	include ../config.mk
	include ../mk/c.mk
