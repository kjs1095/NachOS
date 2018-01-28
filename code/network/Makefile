# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the network assignment
#    Defines set up assuming this assignment is done last 
#    If not, use the "bare bones"  defines below. 
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DTHREADS -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS_STUB -DNETWORK
INCPATH = -I../network -I../bin -I../filesys -I../userprog -I../threads -I../machine -I../lib
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H) $(FILESYS_H) $(NETWORK_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C) $(FILESYS_C) $(NETWORK_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O) $(FILESYS_O) $(NETWORK_O)

# bare bones version
# DEFINES =-DNETWORK
# INCPATH = -I../network -I../threads -I../machine -I../lib
# HFILES = $(THREAD_H) $(NETWORK_H)
# CFILES = $(THREAD_C) $(NETWORK_C)
# C_OFILES = $(THREAD_O) $(NETWORK_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
bitmap.o: ../lib/bitmap.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../lib/bitmap.h
debug.o: ../lib/debug.cc ../lib/copyright.h ../lib/utility.h \
 ../lib/debug.h ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h
hash.o: ../lib/hash.cc ../lib/copyright.h
libtest.o: ../lib/libtest.cc ../lib/copyright.h ../lib/libtest.h \
 ../lib/bitmap.h ../lib/utility.h ../lib/list.h ../lib/debug.h \
 ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../lib/list.cc ../lib/hash.h ../lib/hash.cc
list.o: ../lib/list.cc ../lib/copyright.h
sysdep.o: ../lib/sysdep.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 /usr/include/i386-linux-gnu/sys/time.h \
 /usr/include/i386-linux-gnu/sys/file.h /usr/include/fcntl.h \
 /usr/include/i386-linux-gnu/bits/fcntl.h \
 /usr/include/i386-linux-gnu/bits/uio.h \
 /usr/include/i386-linux-gnu/bits/stat.h \
 /usr/include/i386-linux-gnu/sys/socket.h \
 /usr/include/i386-linux-gnu/sys/uio.h \
 /usr/include/i386-linux-gnu/bits/socket.h \
 /usr/include/i386-linux-gnu/bits/sockaddr.h \
 /usr/include/i386-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h \
 /usr/include/i386-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h /usr/include/i386-linux-gnu/sys/un.h \
 /usr/include/signal.h /usr/include/i386-linux-gnu/bits/signum.h \
 /usr/include/i386-linux-gnu/bits/siginfo.h \
 /usr/include/i386-linux-gnu/bits/sigaction.h \
 /usr/include/i386-linux-gnu/bits/sigcontext.h \
 /usr/include/i386-linux-gnu/asm/sigcontext.h /usr/include/linux/types.h \
 /usr/include/i386-linux-gnu/asm/types.h /usr/include/asm-generic/types.h \
 /usr/include/asm-generic/int-ll64.h \
 /usr/include/i386-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/i386-linux-gnu/asm/posix_types.h \
 /usr/include/i386-linux-gnu/asm/posix_types_32.h \
 /usr/include/i386-linux-gnu/bits/sigstack.h \
 /usr/include/i386-linux-gnu/sys/ucontext.h \
 /usr/include/i386-linux-gnu/bits/sigthread.h
interrupt.o: ../machine/interrupt.cc ../lib/copyright.h \
 ../machine/interrupt.h ../lib/list.h ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../lib/list.cc ../machine/callback.h ../threads/main.h ../lib/debug.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../lib/utility.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h
stats.o: ../machine/stats.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/copyright.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/stats.h
timer.o: ../machine/timer.cc ../lib/copyright.h ../machine/timer.h \
 ../lib/utility.h ../lib/copyright.h ../machine/callback.h \
 ../threads/main.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/thread.h ../lib/sysdep.h ../machine/machine.h \
 ../machine/translate.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/debug.h ../lib/list.cc ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/callback.h ../machine/timer.h
alarm.o: ../threads/alarm.cc ../lib/copyright.h ../threads/alarm.h \
 ../lib/utility.h ../lib/copyright.h ../machine/callback.h \
 ../machine/timer.h ../machine/callback.h ../threads/main.h \
 ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/thread.h ../lib/sysdep.h ../machine/machine.h \
 ../machine/translate.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/debug.h ../lib/list.cc ../machine/interrupt.h ../machine/stats.h
kernel.o: ../threads/kernel.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/copyright.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../threads/main.h ../network/netkernel.h ../userprog/userkernel.h \
 ../threads/kernel.h ../lib/utility.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h ../threads/kernel.h \
 ../threads/synch.h ../threads/synchlist.h ../threads/synchlist.cc \
 ../lib/libtest.h ../machine/elevatortest.h
main.o: ../threads/main.cc ../lib/copyright.h ../threads/main.h \
 ../lib/debug.h ../lib/copyright.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../lib/utility.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h
scheduler.o: ../threads/scheduler.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/copyright.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../threads/scheduler.h ../lib/list.h ../lib/debug.h ../lib/list.cc \
 ../threads/thread.h ../lib/utility.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/main.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../machine/interrupt.h ../machine/callback.h ../machine/stats.h \
 ../threads/alarm.h ../machine/callback.h ../machine/timer.h
synch.o: ../threads/synch.cc ../lib/copyright.h ../threads/synch.h \
 ../threads/thread.h ../lib/utility.h ../lib/copyright.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../lib/list.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h ../lib/list.cc ../threads/main.h \
 ../lib/debug.h ../network/netkernel.h ../userprog/userkernel.h \
 ../threads/kernel.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h
synchlist.o: ../threads/synchlist.cc ../lib/copyright.h \
 ../threads/synchlist.h ../lib/list.h ../lib/copyright.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../lib/list.cc ../threads/synch.h ../threads/thread.h ../lib/utility.h \
 ../lib/sysdep.h ../machine/machine.h ../machine/translate.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/main.h ../lib/debug.h ../network/netkernel.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/callback.h ../machine/stats.h \
 ../threads/alarm.h ../machine/callback.h ../machine/timer.h \
 ../threads/synchlist.cc
thread.o: ../threads/thread.cc ../lib/copyright.h ../threads/thread.h \
 ../lib/utility.h ../lib/copyright.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/switch.h \
 ../threads/synch.h ../lib/list.h ../lib/debug.h ../lib/utility.h \
 ../lib/sysdep.h ../lib/list.cc ../threads/main.h ../lib/debug.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/callback.h \
 ../machine/stats.h ../threads/alarm.h ../machine/callback.h \
 ../machine/timer.h
elevatortest.o: ../machine/elevatortest.cc ../lib/copyright.h \
 ../machine/elevatortest.h ../machine/elevator.h ../lib/utility.h \
 ../lib/copyright.h ../machine/callback.h ../lib/list.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../lib/list.cc ../threads/synch.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/main.h \
 ../lib/debug.h ../network/netkernel.h ../userprog/userkernel.h \
 ../threads/kernel.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/callback.h \
 ../machine/timer.h ../threads/thread.h
elevator.o: ../machine/elevator.cc ../lib/copyright.h \
 ../machine/elevator.h ../lib/utility.h ../lib/copyright.h \
 ../machine/callback.h ../lib/list.h ../lib/debug.h ../lib/utility.h \
 ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../lib/list.cc ../threads/kernel.h ../lib/debug.h ../threads/thread.h \
 ../lib/sysdep.h ../machine/machine.h ../machine/translate.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/callback.h ../machine/timer.h \
 ../threads/main.h ../network/netkernel.h ../userprog/userkernel.h
addrspace.o: ../userprog/addrspace.cc ../lib/copyright.h \
 ../threads/main.h ../lib/debug.h ../lib/copyright.h ../lib/utility.h \
 ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../lib/utility.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h ../userprog/addrspace.h \
 ../bin/noff.h
exception.o: ../userprog/exception.cc ../lib/copyright.h \
 ../threads/main.h ../lib/debug.h ../lib/copyright.h ../lib/utility.h \
 ../lib/sysdep.h /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../lib/utility.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h ../userprog/syscall.h
synchconsole.o: ../userprog/synchconsole.cc ../lib/copyright.h \
 ../userprog/synchconsole.h ../lib/utility.h ../lib/copyright.h \
 ../machine/callback.h ../machine/console.h ../machine/callback.h \
 ../threads/synch.h ../threads/thread.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../lib/list.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h ../lib/list.cc ../threads/main.h \
 ../lib/debug.h ../network/netkernel.h ../userprog/userkernel.h \
 ../threads/kernel.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/timer.h
userkernel.o: ../userprog/userkernel.cc ../lib/copyright.h \
 ../userprog/synchconsole.h ../lib/utility.h ../lib/copyright.h \
 ../machine/callback.h ../machine/console.h ../machine/callback.h \
 ../threads/synch.h ../threads/thread.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../lib/list.h ../lib/debug.h \
 ../lib/utility.h ../lib/sysdep.h ../lib/list.cc ../threads/main.h \
 ../lib/debug.h ../network/netkernel.h ../userprog/userkernel.h \
 ../threads/kernel.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/timer.h \
 ../userprog/userkernel.h
console.o: ../machine/console.cc ../lib/copyright.h ../machine/console.h \
 ../lib/utility.h ../lib/copyright.h ../machine/callback.h \
 ../threads/main.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/thread.h ../lib/sysdep.h ../machine/machine.h \
 ../machine/translate.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/debug.h ../lib/list.cc ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/callback.h ../machine/timer.h
machine.o: ../machine/machine.cc ../lib/copyright.h ../machine/machine.h \
 ../lib/utility.h ../lib/copyright.h ../machine/translate.h \
 ../threads/main.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/thread.h ../lib/sysdep.h ../machine/machine.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../lib/list.h ../lib/debug.h ../lib/list.cc \
 ../machine/interrupt.h ../machine/callback.h ../machine/stats.h \
 ../threads/alarm.h ../machine/callback.h ../machine/timer.h
mipssim.o: ../machine/mipssim.cc ../lib/copyright.h ../lib/debug.h \
 ../lib/copyright.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/machine.h ../lib/utility.h ../machine/translate.h \
 ../machine/mipssim.h ../threads/main.h ../network/netkernel.h \
 ../userprog/userkernel.h ../threads/kernel.h ../threads/thread.h \
 ../lib/sysdep.h ../machine/machine.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h
translate.o: ../machine/translate.cc ../lib/copyright.h ../threads/main.h \
 ../lib/debug.h ../lib/copyright.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../lib/utility.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h
netkernel.o: ../network/netkernel.cc /usr/include/errno.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/i386-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/i386-linux-gnu/asm/errno.h /usr/include/asm-generic/errno.h \
 /usr/include/asm-generic/errno-base.h ../lib/copyright.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../lib/debug.h ../lib/copyright.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../lib/utility.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../lib/list.h ../lib/debug.h ../lib/list.cc ../machine/interrupt.h \
 ../machine/callback.h ../machine/stats.h ../threads/alarm.h \
 ../machine/callback.h ../machine/timer.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h \
 ../threads/main.h ../network/netkernel.h ../threads/synchlist.cc \
 ../threads/synchlist.h ../threads/synch.h
post.o: ../network/post.cc ../lib/copyright.h ../network/post.h \
 ../lib/utility.h ../lib/copyright.h ../machine/callback.h \
 ../machine/network.h ../machine/callback.h ../threads/synchlist.h \
 ../lib/list.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../lib/list.cc ../threads/synch.h ../threads/thread.h ../lib/sysdep.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/main.h \
 ../lib/debug.h ../network/netkernel.h ../userprog/userkernel.h \
 ../threads/kernel.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../threads/alarm.h ../machine/timer.h \
 ../threads/synchlist.cc ../threads/synchlist.h ../threads/synch.h
network.o: ../machine/network.cc ../lib/copyright.h ../machine/network.h \
 ../lib/utility.h ../lib/copyright.h ../machine/callback.h \
 ../threads/main.h ../lib/debug.h ../lib/utility.h ../lib/sysdep.h \
 /usr/include/c++/4.6/iostream \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/ostream /usr/include/c++/4.6/ios \
 /usr/include/c++/4.6/iosfwd /usr/include/c++/4.6/bits/stringfwd.h \
 /usr/include/c++/4.6/bits/postypes.h /usr/include/c++/4.6/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/char_traits.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/localefwd.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++locale.h \
 /usr/include/c++/4.6/clocale /usr/include/locale.h \
 /usr/include/i386-linux-gnu/bits/locale.h /usr/include/c++/4.6/cctype \
 /usr/include/ctype.h /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/c++/4.6/bits/ios_base.h \
 /usr/include/c++/4.6/ext/atomicity.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/sched.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/bits/timex.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/setjmp.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/atomic_word.h \
 /usr/include/c++/4.6/bits/locale_classes.h /usr/include/c++/4.6/string \
 /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/bits/ostream_insert.h \
 /usr/include/c++/4.6/bits/cxxabi_forced.h \
 /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/range_access.h \
 /usr/include/c++/4.6/bits/basic_string.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/basic_string.tcc \
 /usr/include/c++/4.6/bits/locale_classes.tcc \
 /usr/include/c++/4.6/streambuf /usr/include/c++/4.6/bits/streambuf.tcc \
 /usr/include/c++/4.6/bits/basic_ios.h \
 /usr/include/c++/4.6/bits/locale_facets.h /usr/include/c++/4.6/cwctype \
 /usr/include/wctype.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_base.h \
 /usr/include/c++/4.6/bits/streambuf_iterator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/ctype_inline.h \
 /usr/include/c++/4.6/bits/locale_facets.tcc \
 /usr/include/c++/4.6/bits/basic_ios.tcc \
 /usr/include/c++/4.6/bits/ostream.tcc /usr/include/c++/4.6/istream \
 /usr/include/c++/4.6/bits/istream.tcc /usr/include/stdlib.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/errno.h /usr/include/i386-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/i386-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../network/netkernel.h ../userprog/userkernel.h ../threads/kernel.h \
 ../threads/thread.h ../lib/sysdep.h ../machine/machine.h \
 ../machine/translate.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../lib/list.h \
 ../lib/debug.h ../lib/list.cc ../machine/interrupt.h ../machine/stats.h \
 ../threads/alarm.h ../machine/callback.h ../machine/timer.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
