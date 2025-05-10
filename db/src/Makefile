MAKE = gmake
CC = clang++-devel

PLATFORM = $(shell file /bin/ls | cut -d' ' -f3 | cut -d'-' -f1)
BSD_VERSION = $(shell uname -v 2>&1 | cut -d' ' -f2 | cut -d'.' -f1)
DB_VERSION = $(shell cat ../../__REVISION__)
LBITS := $(shell getconf LONG_BIT)

INCDIR =
LIBDIR =
BINDIR = ..
OBJDIR = .obj
$(shell if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi)

# LIST_OF_CONSTANTS BEGIN
ENABLE_GCC_AUTODEPEND = 1
ENABLE_STATIC = 0
ENABLE_ASAN = 0
# LIST_OF_CONSTANTS END

# Depend Path File
ifneq ($(ENABLE_GCC_AUTODEPEND), 1)
DEPFILE = Depend
endif

# Project Flags
CFLAGS = -m32 -g -Wall -O2 -pipe -fno-rtti -fno-exceptions -Wno-long-long -pthread -D_THREAD_SAFE
CFLAGS += -Wno-invalid-source-encoding
CFLAGS += -Wno-tautological-pointer-compare
CXXFLAGS = -std=c++20

# for clang
ifneq '' '$(findstring clang++,$(CXX))'
CFLAGS = -m32 -g -Wall -O2 -pipe -fno-rtti -fno-exceptions -Wno-long-long -pthread -D_THREAD_SAFE
CFLAGS += -Wno-invalid-source-encoding
CFLAGS += -Wno-tautological-pointer-compare
# for gcc
else ifneq '' '$(findstring g++,$(CXX))'
# for 32bit on 64bit
ifeq ($(LBITS),64)
CFLAGS += -L/usr/local/lib32/gcc12
CFLAGS += -Wl,-rpath=/usr/local/lib32/gcc12
else
# for 32bit on 32bit
CXXFLAGS += -Wl,-rpath=/usr/local/lib/gcc12
endif
endif

ifeq ($(ENABLE_ASAN), 1)
CFLAGS += -DENABLE_ASAN
CFLAGS += -fsanitize=address -fno-omit-frame-pointer
CFLAGS += -fsanitize-recover=address
endif

# Project Library
INCDIR += -I/usr/local/include
LIBDIR += -I/usr/local/lib

# External
INCDIR += -I../../../External/include
LIBDIR += -L../../../External/library
ifeq ($(BSD_VERSION), 15)
LIBDIR += -L../../../External/library/15.0/
endif
ifeq ($(BSD_VERSION), 14)
LIBDIR += -L../../../External/library/14.0/
endif
ifeq ($(BSD_VERSION), 13)
LIBDIR += -L../../../External/library/13.0/
endif
ifeq ($(BSD_VERSION), 12)
LIBDIR += -L../../../External/library/12.0/
endif
ifeq ($(BSD_VERSION), 11)
LIBDIR += -L../../../External/library/11.0/
endif

# Boost
INCDIR += -I../../../External/include/boost

# MySQL
INCDIR += -I/usr/local/include/mysql
ifeq ($(PLATFORM), 64)
LIBS = -lmysqlclient -lz -lzstd
else
LIBS += /usr/local/lib/mysql/libmysqlclient.a /usr/lib/libz.a /usr/local/lib/libzstd.a
endif

ifeq ($(ENABLE_STATIC), 1)
CFLAGS += -static
endif

# Version defines
CFLAGS += -D__USER__=\"$(USER)\" -D__HOSTNAME__=\"$(HOSTNAME)\" -D__PWD__=\"$(PWD)\" -D__DB_VERSION__=\"$(DB_VERSION)\"

# OpenSSL
LIBS += -lssl -lcrypto

# Project Library
LIBDIR += -L../../libthecore/lib -L../../libsql -L../../libpoly -L../../libgame/lib
LIBS += -lthecore -lsql -lpoly -lgame -lm

# PROJECT_SRC_FILES BEGIN
CPPFILE = Config.cpp NetBase.cpp Peer.cpp PeerBase.cpp Main.cpp Lock.cpp DBManager.cpp \
		  Cache.cpp LoginData.cpp ClientManager.cpp ClientManagerPlayer.cpp ClientManagerLogin.cpp \
		  ClientManagerBoot.cpp ClientManagerParty.cpp ClientManagerGuild.cpp GuildManager.cpp HB.cpp \
		  PrivManager.cpp MoneyLog.cpp ItemAwardManager.cpp ClientManagerEventFlag.cpp Marriage.cpp \
		  Monarch.cpp ItemIDRangeManager.cpp ClientManagerHorseName.cpp version.cpp \
		  ProtoReader.cpp CsvReader.cpp
# PROJECT_SRC_FILES END

# PROJECT_OBJ_FILES BEGIN
CPPOBJS = $(CPPFILE:%.cpp=$(OBJDIR)/%.o)
ifeq ($(ENABLE_GCC_AUTODEPEND), 1)
CPPDEPS	= $(CPPOBJS:%.o=%.d)
endif
# PROJECT_OBJ_FILES END

# Target Paths
MAIN_TARGET = $(BINDIR)/db_r$(DB_VERSION)_$(PLATFORM)

default: $(MAIN_TARGET)

$(MAIN_TARGET): $(CPPOBJS)
	@echo linking $(MAIN_TARGET)
	@$(CXX) $(CFLAGS) $(CXXFLAGS) $(LIBDIR) $(CPPOBJS) $(LIBS) -o $(MAIN_TARGET)

$(OBJDIR)/%.o: %.cpp
	@echo compiling $<
	@$(CXX) $(CFLAGS) $(CXXFLAGS) $(INCDIR) -c $< -o $@
ifeq ($(ENABLE_GCC_AUTODEPEND), 1)
	@$(CXX) -MM -MG -MP $(CFLAGS) $(CXXFLAGS) $(INCDIR) -c $< -o $(OBJDIR)/$*.d
	@sed -i '' -e's/$*.o:/$(OBJDIR)\/$*.o:/g' $(OBJDIR)/$*.d
endif

$(OBJDIR):
	@mkdir $(OBJDIR)

symlink:
	@ln -fs db_r$(DB_VERSION) $(BINDIR)/db_symlink

strip:
	@cp $(BINDIR)/db_r$(DB_VERSION) $(BINDIR)/db_r
	@strip $(BINDIR)/db_r

clean:
	@rm -f $(CPPOBJS) $(BINDIR)/db_r*

dep:
ifeq ($(ENABLE_GCC_AUTODEPEND), 1)
	@echo "Note: gcc autodepend is autodetected, so target dep skipped"
else
	makedepend -f $(DEPFILE) $(INCDIR) -I/usr/include/c++/3.3 -I/usr/include/c++/4.2 -p$(OBJDIR)/ $(CPPFILE) 2> /dev/null > $(DEPFILE)
endif

# AUTO_DEPEND_CHECK BEGIN
ifeq ($(ENABLE_GCC_AUTODEPEND), 1)
sinclude $(CPPDEPS)
else
sinclude $(DEPFILE)
endif
# AUTO_DEPEND_CHECK END
