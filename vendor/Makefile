TOP = ..
include $(TOP)/configure/CONFIG

# config options for linux builds
CONFIGOPTIONS += --prefix=$(shell cd $(TOP)/vendor && pwd)/ffmpeg-$(T_A)
CONFIGOPTIONS += --enable-shared --disable-static --enable-debug --disable-stripping
CONFIGOPTIONS += --disable-ffmpeg --disable-ffplay --disable-ffprobe --disable-ffserver
CONFIGOPTIONS += --disable-indevs --disable-outdevs

# install libs
# Update these version numbers if you updte the ffmpeg vendor library
FFMPEG_LINUX_LIBS += libavcodec.so	libavcodec.so.54	libavcodec.so.54.92.100
FFMPEG_LINUX_LIBS += libavdevice.so	libavdevice.so.54	libavdevice.so.54.3.103
FFMPEG_LINUX_LIBS += libavfilter.so	libavfilter.so.3	libavfilter.so.3.42.103
FFMPEG_LINUX_LIBS += libavformat.so	libavformat.so.54	libavformat.so.54.63.104
FFMPEG_LINUX_LIBS += libavutil.so	libavutil.so.52		libavutil.so.52.18.100
FFMPEG_LINUX_LIBS += libswscale.so	libswscale.so.2		libswscale.so.2.2.100

ifeq (win32-x86, $(findstring win32-x86, $(T_A)))
	BIN_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win32-shared/bin/*.*)
	LIB_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win32-dev/lib/*.*)	
else ifeq (windows-x64, $(findstring windows-x64, $(T_A)))
	BIN_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win64-shared/bin/*.*)
	LIB_INSTALLS_WIN32  += $(wildcard ../ffmpeg-win64-dev/lib/*.*)	
else ifeq (rhel6-x86_64, $(findstring rhel6-x86_64, $(T_A)))
	LIB_INSTALLS_Linux  += $(addprefix ../ffmpeg-rhel6-x86_64/lib/, $(FFMPEG_LINUX_LIBS))
	FFMPEGMAK = $(TOP)/vendor/ffmpeg-rhel6-x86_64/config.mak	
	YASM = $(TOP)/vendor/yasm-rhel6-x86_64/yasm
else ifeq (linux-x86_64, $(findstring linux-x86_64, $(T_A)))
	LIB_INSTALLS_Linux  += $(addprefix ../ffmpeg-linux-x86_64/lib/, $(FFMPEG_LINUX_LIBS))
	FFMPEGMAK = $(TOP)/vendor/ffmpeg-linux-x86_64/config.mak	
	YASM = $(TOP)/vendor/yasm-linux-x86_64/yasm
else ifeq (linux-x86, $(findstring linux-x86, $(T_A)))
	LIB_INSTALLS_Linux  += $(addprefix ../ffmpeg-linux-x86/lib/, $(FFMPEG_LINUX_LIBS))
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

install: install_ffmpeg

build: build_ffmpeg

$(LIB_INSTALLS_Linux): build_ffmpeg

build_ffmpeg: $(FFMPEGMAK) $(YASM)
	@echo Building ffmpeg for $(T_A) target architecture
	ls -l $(FFMPEGMAK)
	ls -l $(YASM)
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

