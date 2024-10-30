PHONY: all, clean

#==============design-time parameters==============
OUTPUT_EXE = 
OUTPUT_DL = libheat
EXTRA_ARGS = 
STATIC_MINGW = false

#==============platform & toolchains===============
CXX = g++
CC = gcc
AR = ar
RANLIB = ranlib
CPP_VERSION = c++11
SHELL = bash

# The following variables are set by Makefile.
# Do not edit manually.
DLEXT =
DLPREFIX =
SLEXT =
SLPREFIX =
FOUND_WIN32 =

TARGET_OS = $(shell uname -s)
TARGET_ARCH = $(shell uname -m)

ifeq ($(CXX),g++)
CXXFLAGS_USER = -std=$(CPP_VERSION) -O2 -Wno-unused-variable -Wno-unused-value
CFLAGS_DEPS = -w -O2
else
CXXFLAGS_USER = -std=$(CPP_VERSION) -O2 -Wno-unused-variable -Wno-unused-value -fno-sanitize=undefined
CFLAGS_DEPS = -w -O2 -fno-sanitize=undefined
endif

DL_FLAGS = -Wl,--as-needed -Wl,-rpath,'$$ORIGIN/lib:$$ORIGIN:.'
EXE_FLAGS = -Wl,--as-needed -Wl,-rpath,'$$ORIGIN/lib:$$ORIGIN:.'

ifeq ($(CXX),g++)
ifeq ($(findstring _NT,$(TARGET_OS)), _NT)
DL_FLAGS += -Wl,--out-implib bin/$(OUTPUT_DL).lib
endif
endif

ifeq ($(findstring _NT,$(TARGET_OS)), _NT)
	DLEXT = .dll
	FOUND_WIN32 = true
	ifeq ($(findstring zig,$(CXX)),zig)
		SLEXT = .lib
		EXE_FLAGS += -fno-lto
	else
		SLEXT = .a
		SLPREFIX = lib
	endif
	DL_FLAGS += -DWIN32_LEAN_AND_MEAN
	EXE_FLAGS += -DWIN32_LEAN_AND_MEAN
	ifeq ($(STATIC_MINGW),true)
		DL_FLAGS += -static-libgcc -static-libstdc++
		EXE_FLAGS += -static-libgcc -static-libstdc++

		ifeq ($(findstring zig,$(CXX)),zig)
		else
			DL_FLAGS += -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
			EXE_FLAGS += -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
		endif
	endif
endif

ifeq ($(TARGET_OS),Linux)
	DLEXT = .so
	DLPREFIX = lib
	SLPREFIX = lib
	SLEXT = .a
	CFLAGS_DEPS += -D_GNU_SOURCE
	EXE_FLAGS += -ldl -lpthread
	DL_FLAGS += -ldl -lpthread
endif

ifeq ($(TARGET_OS),Darwin)
	DLEXT = .dylib
	DLPREFIX = lib
	SLPREFIX = lib
	SLEXT = .a
	CFLAGS_DEPS += -D_DARWIN_C_SOURCE
endif

ifeq ($(DLEXT),)
$(error "DLEXT is not set and could not be guessed for the current OS: $(OS)")
endif

OUTPUT_SEQ = bin/$(DLPREFIX)bdwgc$(DLEXT)
ifneq ($(OUTPUT_EXE),)
OUTPUT_SEQ += bin/$(OUTPUT_EXE)
endif
ifneq ($(OUTPUT_DL),)
OUTPUT_SEQ += bin/$(OUTPUT_DL)$(DLEXT)
endif

#===========compilation specific logics============
## IORT
HEDAER_IORT = $(shell find syslabcrt-io/include -name "*.h")
SRCS_IORT = $(shell find syslabcrt-io/src -name "*.c")
OBJS_IORT = $(patsubst %.c,%.o,$(SRCS_IORT))

## DYLIB
SRCS_DYLIB = syslabcrt-dylib/syslabcrt_dylib.c
OBJS_DYLIB = syslabcrt-dylib/syslabcrt_dylib.o

## INTRINSICS
HEDAER_INTRINSICS = $(shell find syslabcrt-intrinsics -name "*.hpp")

## BDWGC
HEADER_ATOMIC_OPS = $(shell find atomic_ops/src -name "*.h")
HEADERS_BDWGC = $(shell find bdwgc/include -name "*.h")
SRCS_BDWGC = $(wildcard bdwgc/*.c)
OBJS_BDWGC = $(patsubst %.c,%.o,$(SRCS_BDWGC))
DEFINE_BDWGC = -DENABLE_DISCLAIM \
	-DGC_ATOMIC_UNCOLLECTABLE \
	-DGC_GCJ_SUPPORT \
	-DJAVA_FINALIZATION \
	-DNO_EXECUTE_PERMISSION \
	-DUSE_MMAP \
	-DUSE_MUNMAP \
	-DGC_THREADS \
	-DPARALLEL_MARK \
	-DTHREAD_LOCAL_ALLOC

ifeq ($(FOUND_WIN32),true)
	DEFINE_BDWGC += -DWIN32_THREADS
endif


#=====================targets======================
bin/$(DLPREFIX)bdwgc$(DLEXT): $(OBJS_BDWGC)
	mkdir -p bin
	$(CC) -shared $(CFLAGS_DEPS) -o $@ win32-implib/bdwgc.c -Ibdwgc/include -Iatomic_ops/src $^ $(DLFLAGS_BDWGC)

bdwgc/%.o: bdwgc/%.c $(HEADERS_BDWGC) $(HEADER_ATOMIC_OPS)
	$(CC) -fPIC -c $(CFLAGS_DEPS) -Ibdwgc/include -Iatomic_ops/src -o $@ $< $(DEFINE_BDWGC)

bin/$(SLPREFIX)syslabcrt-io$(SLEXT): $(OBJS_IORT)
	mkdir -p bin
	$(AR) rcs $@ $^
	$(RANLIB) $@

syslabcrt-io/%.o: syslabcrt-io/%.c $(HEDAER_IORT)
	$(CC) -fPIC -c $(CFLAGS_DEPS) -Isyslabcrt-io/include -o $@ $<

bin/$(SLPREFIX)syslabcrt-dylib$(SLEXT): $(OBJS_DYLIB)
	mkdir -p bin
	echo $(SRCS_DYLIB)
	$(AR) rcs $@ $^
	$(RANLIB) $@

syslabcrt-dylib/%.o: syslabcrt-dylib/%.c
	$(CC) -fPIC -c $(CFLAGS_DEPS) -o $@ $<

bin/$(OUTPUT_EXE): $(HEDAER_INTRINSICS) bin/$(SLPREFIX)syslabcrt-io$(SLEXT) bin/$(SLPREFIX)syslabcrt-dylib$(SLEXT) bin/$(DLPREFIX)bdwgc$(DLEXT) $(OUTPUT_EXE).cpp
	mkdir -p bin
	mkdir -p lib
	$(CXX) $(CXXFLAGS_USER) -o $@ $(OUTPUT_EXE).cpp -Isyslabcrt-intrinsics -Isyslabcrt-io/include -Ighc-filesystem -Lbin -lsyslabcrt-dylib -lsyslabcrt-io -lbdwgc $(EXE_FLAGS) $(EXTRA_ARGS)

bin/$(OUTPUT_DL)$(DLEXT): $(HEDAER_INTRINSICS) bin/$(SLPREFIX)syslabcrt-io$(SLEXT) bin/$(SLPREFIX)syslabcrt-dylib$(SLEXT) bin/$(DLPREFIX)bdwgc$(DLEXT) $(OUTPUT_DL).cpp
	mkdir -p bin
	mkdir -p lib
	touch bin/$(OUTPUT_DL).lib
	$(CXX) $(CXXFLAGS_USER) -fPIC -shared -o $@ $(OUTPUT_DL).cpp -Isyslabcrt-intrinsics -Isyslabcrt-io/include -Ighc-filesystem -Lbin -lsyslabcrt-dylib -lsyslabcrt-io -lbdwgc $(DL_FLAGS) $(EXTRA_ARGS)

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.a" -type f -delete
	find . -name "*.lib" -type f -delete
	rm -rf bin/*
	rm -rf .zig-cache/

all: $(OUTPUT_SEQ)
	rm -rf bin/lib
	cp -rf lib bin/
	@echo -e "\x1b[1m\x1b[32m[Info]:\x1b[0m\x1b[0m Build succeeded."


