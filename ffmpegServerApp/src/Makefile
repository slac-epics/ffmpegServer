TOP=../..

include $(TOP)/configure/CONFIG

# -------------------------------
# Build an Diamond Support Module

CONFORM_CFLAGS_STRICT = 
CONFORM_CXXFLAGS_STRICT = 

LIBRARY_IOC += ffmpegServer

DBD += ffmpegServer.dbd
INC += ffmpegServer.h

# TODO: Need to clean up this crap!
# nullHttpd module too!
# This code only builds by setting flags to old c99 std, and that
# doesn't seem to work any more under rhel6

# ffmpeg must be built to c99 standard
USR_CFLAGS_Linux += -std=c99
#USR_CXXFLAGS += -U_BSD_SOURCE
#USR_CXXFLAGS += -U_GNU_SOURCE
#USR_CXXFLAGS += -D__USE_GNU

# Include the srcs from nullhttpd
SRC_DIRS += $(NULLHTTPD)/src

# For some reason the windows build needs stdint.h and inttypes.h
USR_INCLUDES_WIN32 += -I$(TOP)/vendor/msinttypes

# add the right include files
USR_INCLUDES += -I$(FFMPEG_INC_DIR)

USR_CXXFLAGS_WIN32 += -DWIN32
USR_CFLAGS_WIN32 += -DWIN32

# The following are compiled and added to the support library
ffmpegServer_SRCS += ffmpegCommon.cpp
ffmpegServer_SRCS += ffmpegServer.cpp cgi.c files.c format.c http.c server.c win32.c 
ffmpegServer_SRCS += ffmpegFile.cpp

LIB_INSTALLS += $(wildcard $(FFMPEG_LIB_DIR)/lib*)

#install: showme

include $(TOP)/configure/RULES

showme:
	@echo FFMPEG_TOP=$(FFMPEG_TOP)
	@echo FFMPEG_INC_DIR=$(FFMPEG_INC_DIR)
	@echo FFMPEG_LIB_DIR=$(FFMPEG_LIB_DIR)
	@echo INSTALL_LIBS=$(INSTALL_LIBS)
	@echo LIB_INSTALLS=$(LIB_INSTALLS)
