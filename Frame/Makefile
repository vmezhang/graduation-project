#############################################################################
# Makefile for building: Frame
# Generated by qmake (2.01a) (Qt 4.8.1) on: Mon May 18 16:05:44 2015
# Project:  Frame.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Frame.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		FrameWindow.cpp \
		CodeEdit/highlight.cpp \
		CodeEdit/codeWindow.cpp \
		CodeEdit/codeEdit.cpp \
		Shell/shell.cpp \
		monitor/monitor.cpp moc_FrameWindow.cpp \
		moc_highlight.cpp \
		moc_codeWindow.cpp \
		moc_codeEdit.cpp \
		moc_shell.cpp \
		moc_monitor.cpp \
		qrc_source.cpp
OBJECTS       = main.o \
		FrameWindow.o \
		highlight.o \
		codeWindow.o \
		codeEdit.o \
		shell.o \
		monitor.o \
		moc_FrameWindow.o \
		moc_highlight.o \
		moc_codeWindow.o \
		moc_codeEdit.o \
		moc_shell.o \
		moc_monitor.o \
		qrc_source.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Frame.pro
QMAKE_TARGET  = Frame
DESTDIR       = 
TARGET        = Frame

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_codeWindow.h ui_monitor.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Frame.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Frame.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Frame.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Frame1.0.0 || $(MKDIR) .tmp/Frame1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Frame1.0.0/ && $(COPY_FILE) --parents FrameWindow.h shell.h CodeEdit/highlight.h CodeEdit/codeWindow.h CodeEdit/codeEdit.h Shell/shell.h monitor/dataclass.h monitor/monitor.h Shell/testShell.h .tmp/Frame1.0.0/ && $(COPY_FILE) --parents source.qrc .tmp/Frame1.0.0/ && $(COPY_FILE) --parents main.cpp FrameWindow.cpp CodeEdit/highlight.cpp CodeEdit/codeWindow.cpp CodeEdit/codeEdit.cpp Shell/shell.cpp monitor/monitor.cpp .tmp/Frame1.0.0/ && $(COPY_FILE) --parents CodeEdit/codeWindow.ui monitor/monitor.ui .tmp/Frame1.0.0/ && (cd `dirname .tmp/Frame1.0.0` && $(TAR) Frame1.0.0.tar Frame1.0.0 && $(COMPRESS) Frame1.0.0.tar) && $(MOVE) `dirname .tmp/Frame1.0.0`/Frame1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Frame1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_FrameWindow.cpp moc_highlight.cpp moc_codeWindow.cpp moc_codeEdit.cpp moc_shell.cpp moc_monitor.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_FrameWindow.cpp moc_highlight.cpp moc_codeWindow.cpp moc_codeEdit.cpp moc_shell.cpp moc_monitor.cpp
moc_FrameWindow.cpp: Shell/shell.h \
		CodeEdit/codeWindow.h \
		monitor/monitor.h \
		FrameWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) FrameWindow.h -o moc_FrameWindow.cpp

moc_highlight.cpp: CodeEdit/highlight.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) CodeEdit/highlight.h -o moc_highlight.cpp

moc_codeWindow.cpp: CodeEdit/codeWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) CodeEdit/codeWindow.h -o moc_codeWindow.cpp

moc_codeEdit.cpp: CodeEdit/highlight.h \
		CodeEdit/codeEdit.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) CodeEdit/codeEdit.h -o moc_codeEdit.cpp

moc_shell.cpp: Shell/shell.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Shell/shell.h -o moc_shell.cpp

moc_monitor.cpp: monitor/monitor.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) monitor/monitor.h -o moc_monitor.cpp

compiler_rcc_make_all: qrc_source.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_source.cpp
qrc_source.cpp: source.qrc \
		res/edit_image/document-open.svg \
		res/edit_image/edit-copy.svg \
		res/edit_image/edit-paste.svg \
		res/edit_image/document-save-as.svg \
		res/edit_image/document-new.svg \
		res/edit_image/document-save.svg \
		res/edit_image/edit-cut.svg \
		res/edit_image/edit-redo.svg \
		res/edit_image/edit-undo.svg \
		res/edit_image/accessories-text-editor.svg \
		res/language/qt_zh_CN.qm \
		res/images/1.png \
		res/images/2.png \
		res/images/3.png \
		res/images/terminal.png \
		res/images/4.png \
		res/images/5.png
	/usr/bin/rcc -name source source.qrc -o qrc_source.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_codeWindow.h ui_monitor.h
compiler_uic_clean:
	-$(DEL_FILE) ui_codeWindow.h ui_monitor.h
ui_codeWindow.h: CodeEdit/codeWindow.ui
	/usr/bin/uic-qt4 CodeEdit/codeWindow.ui -o ui_codeWindow.h

ui_monitor.h: monitor/monitor.ui
	/usr/bin/uic-qt4 monitor/monitor.ui -o ui_monitor.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp FrameWindow.h \
		Shell/shell.h \
		CodeEdit/codeWindow.h \
		monitor/monitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

FrameWindow.o: FrameWindow.cpp FrameWindow.h \
		Shell/shell.h \
		CodeEdit/codeWindow.h \
		monitor/monitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FrameWindow.o FrameWindow.cpp

highlight.o: CodeEdit/highlight.cpp CodeEdit/highlight.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o highlight.o CodeEdit/highlight.cpp

codeWindow.o: CodeEdit/codeWindow.cpp CodeEdit/codeWindow.h \
		CodeEdit/ui_codeWindow.h \
		CodeEdit/codeEdit.h \
		CodeEdit/highlight.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o codeWindow.o CodeEdit/codeWindow.cpp

codeEdit.o: CodeEdit/codeEdit.cpp CodeEdit/codeEdit.h \
		CodeEdit/highlight.h \
		CodeEdit/codeWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o codeEdit.o CodeEdit/codeEdit.cpp

shell.o: Shell/shell.cpp Shell/shell.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o shell.o Shell/shell.cpp

monitor.o: monitor/monitor.cpp monitor/monitor.h \
		monitor/ui_monitor.h \
		monitor/dataclass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o monitor.o monitor/monitor.cpp

moc_FrameWindow.o: moc_FrameWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_FrameWindow.o moc_FrameWindow.cpp

moc_highlight.o: moc_highlight.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_highlight.o moc_highlight.cpp

moc_codeWindow.o: moc_codeWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_codeWindow.o moc_codeWindow.cpp

moc_codeEdit.o: moc_codeEdit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_codeEdit.o moc_codeEdit.cpp

moc_shell.o: moc_shell.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_shell.o moc_shell.cpp

moc_monitor.o: moc_monitor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_monitor.o moc_monitor.cpp

qrc_source.o: qrc_source.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_source.o qrc_source.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

