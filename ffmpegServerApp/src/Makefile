TOP=../..

include $(TOP)/configure/CONFIG

# -------------------------------
# Build an Diamond Support Module

CONFORM_CFLAGS_STRICT = 
CONFORM_CXXFLAGS_STRICT = 

LIBRARY_IOC += ffmpegServer

DBD += ffmpegServer.dbd
#INC += ffmpegServer.h

# TODO: Need to clean up this crap!
# nullHttpd module too!
# This code only builds by setting flags to old c99 std, and that
# doesn't seem to work any more under rhel6
# Shouldn't have to build our own libavcodec

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
ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
	USR_INCLUDES_WIN32 += -I$(TOP)/vendor/ffmpeg-win32-dev/include
else ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
	USR_INCLUDES_WIN32 += -I$(TOP)/vendor/ffmpeg-win64-dev/include
else ifeq (rhel6-x86_64, $(findstring rhel6-x86_64, $(T_A)))
	USR_INCLUDES_Linux += -I$(TOP)/vendor/ffmpeg-rhel6-x86_64/include	
else ifeq (linux-x86_64, $(findstring linux-x86_64, $(T_A)))
	USR_INCLUDES_Linux += -I$(TOP)/vendor/ffmpeg-linux-x86_64/include	
else ifeq (linux-x86, $(findstring linux-x86, $(T_A)))
	USR_INCLUDES_Linux += -I$(TOP)/vendor/ffmpeg-linux-x86/include
endif

USR_CXXFLAGS_WIN32 += -DWIN32
USR_CFLAGS_WIN32 += -DWIN32

# The following are compiled and added to the support library
ffmpegServer_SRCS += ffmpegCommon.cpp
ffmpegServer_SRCS += ffmpegServer.cpp cgi.c files.c format.c http.c server.c win32.c 
ffmpegServer_SRCS += ffmpegFile.cpp
PROD_SYS_LIBS += avdevice avformat avcodec avutil swscale

include $(TOP)/configure/RULES

