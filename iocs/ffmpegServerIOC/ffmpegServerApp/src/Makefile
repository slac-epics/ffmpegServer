# 
TOP = ../..
include $(TOP)/configure/CONFIG

# Build an ioc application
PROD_NAME = example

PROD_IOC_Linux    = $(PROD_NAME)
PROD_IOC_WIN32    = $(PROD_NAME)

# $(PROD_NAME).dbd will be created and installed
DBD += $(PROD_NAME).dbd

# $(PROD_NAME).dbd will be made up from these files:
include $(ADCORE)/ADApp/commonDriverMakefile

$(PROD_NAME)_DBD += ffmpegServer.dbd
$(PROD_NAME)_DBD += simDetectorSupport.dbd

$(PROD_NAME)_SRCS += $(PROD_NAME)_registerRecordDeviceDriver.cpp
$(PROD_NAME)_SRCS += $(PROD_NAME)Main.cpp

$(PROD_NAME)_LIBS += avdevice
$(PROD_NAME)_LIBS += ffmpegServer
$(PROD_NAME)_LIBS += swscale
$(PROD_NAME)_LIBS += avformat
$(PROD_NAME)_LIBS += avcodec
$(PROD_NAME)_LIBS += avutil
$(PROD_NAME)_LIBS += swresample
$(PROD_NAME)_LIBS += bz2
$(PROD_NAME)_LIBS += lzma

$(PROD_NAME)_LIBS += simDetector

include $(TOP)/configure/RULES

