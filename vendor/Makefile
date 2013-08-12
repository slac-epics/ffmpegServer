TOP = ..
include $(TOP)/configure/CONFIG

# config options for linux builds
CONFIGOPTIONS += --prefix=$(shell cd $(TOP)/vendor && pwd)/ffmpeg-$(T_A)
CONFIGOPTIONS += --enable-shared --disable-static --enable-debug --disable-stripping
CONFIGOPTIONS += --disable-ffmpeg --disable-ffplay --disable-ffprobe --disable-ffserver
CONFIGOPTIONS += --disable-indevs --disable-outdevs

# install libs
# Update these version numbers if you updte the ffmpeg vendor library
FFMPEG_LINUX_LIBS += libavcodec/libavcodec.so
FFMPEG_LINUX_LIBS += libavcodec/libavcodec.so.54
FFMPEG_LINUX_LIBS += libavdevice/libavdevice.so
FFMPEG_LINUX_LIBS += libavdevice/libavdevice.so.54
FFMPEG_LINUX_LIBS += libavfilter/libavfilter.so
FFMPEG_LINUX_LIBS += libavfilter/libavfilter.so.3
FFMPEG_LINUX_LIBS += libavformat/libavformat.so
FFMPEG_LINUX_LIBS += libavformat/libavformat.so.54
FFMPEG_LINUX_LIBS += libavutil/libavutil.so
FFMPEG_LINUX_LIBS += libavutil/libavutil.so.52
FFMPEG_LINUX_LIBS += libswscale/libswscale.so
FFMPEG_LINUX_LIBS += libswscale/libswscale.so.2

ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
	BIN_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win32-shared/bin/*.*)
	LIB_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win32-dev/lib/*.*)	
else ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
	BIN_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win64-shared/bin/*.*)
	LIB_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win64-dev/lib/*.*)	
else ifeq (rhel6-x86_64, $(findstring rhel6-x86_64, $(T_A)))
	LIB_INSTALLS_Linux  += $(addprefix ../ffmpeg-rhel6-x86_64/, $(FFMPEG_LINUX_LIBS))
	FFMPEGMAK = $(TOP)/vendor/ffmpeg-rhel6-x86_64/config.mak	
	YASM = $(TOP)/vendor/yasm-rhel6-x86_64/yasm
else ifeq (linux-x86_64, $(findstring linux-x86_64, $(T_A)))
	LIB_INSTALLS_Linux  += $(addprefix ../ffmpeg-linux-x86_64/, $(FFMPEG_LINUX_LIBS))
	FFMPEGMAK = $(TOP)/vendor/ffmpeg-linux-x86_64/config.mak	
	YASM = $(TOP)/vendor/yasm-linux-x86_64/yasm
else ifeq (linux-x86, $(findstring linux-x86, $(T_A)))
	LIB_INSTALLS_Linux  += $(addprefix ../ffmpeg-linux-x86/, $(FFMPEG_LINUX_LIBS))
	FFMPEGMAK = $(TOP)/vendor/ffmpeg-linux-x86/config.mak
	YASM = $(TOP)/vendor/yasm-linux-x86/yasm
endif

include $(TOP)/configure/RULES

# Local build rules

install: showme

showme:
	@echo T_A=$(T_A)
	@echo FFMPEGMAK=$(FFMPEGMAK)
	@echo YASM=$(YASM)
	@echo LIB_INSTALLS=$(LIB_INSTALLS)
	@echo LIB_INSTALLS_Linux=$(LIB_INSTALLS_Linux)
	@echo INSTALL_LIB=$(INSTALL_LIB)

install: install_ffmpeg

build: build_ffmpeg

$(LIB_INSTALLS_Linux): build_ffmpeg

build_ffmpeg: $(FFMPEGMAK) $(YASM)
	@echo Building ffmpeg for $(T_A) target architecture
	ls -l $(FFMPEGMAK)
	ls -l $(YASM)
	@echo LIB_INSTALLS=$(LIB_INSTALLS)
	@echo LIB_INSTALLS_Linux=$(LIB_INSTALLS_Linux)
	@echo INSTALL_LIB=$(INSTALL_LIB)
ifneq ("", "$(T_A)")
	PATH=${PATH}:../yasm-$(T_A) make -C $(TOP)/vendor/ffmpeg-$(T_A)
endif

install_ffmpeg: build_ffmpeg
	@echo Installing ffmpeg for $(T_A) target architecture
ifneq ("", "$(T_A)")
	PATH=${PATH}:../yasm-$(T_A) make -C $(TOP)/vendor/ffmpeg-$(T_A) install
endif

# $(YASM):	build_yasm
# 
# build_yasm:

realclean archclean archs_common_clean:	local_realclean

local_realclean:
	$(RMDIR) $(TOP)/vendor/ffmpeg-*
	$(RMDIR) $(TOP)/vendor/yasm-*

$(TOP)/vendor/ffmpeg-%/config.mak: $(YASM)
	@echo Configuring ffmpeg for $(*F) target architecture
	@ls -l $(YASM)
	(mkdir -p $(TOP)/vendor/ffmpeg-$(*F); cd $(TOP)/vendor/ffmpeg-$(*F); export PATH=${PATH}:../yasm-$(*F); sh ../ffmpeg/configure $(CONFIGOPTIONS))

$(TOP)/vendor/yasm-%/yasm:
	@echo Configuring yasm for $(*F) target architecture
	(mkdir -p $(TOP)/vendor/yasm-$(*F); cd $(TOP)/vendor/yasm-$(*F); sh ../yasm/configure && make && touch $@)
	ls -l $@

