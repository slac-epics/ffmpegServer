TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
# In a Diamond Support Module, install
# templates like this
#
DB += ffmpegStream.template
DB += ffmpegFile.template

ARCHIVE += ffmpegStream.tpl-arch
ARCHIVE += ffmpegFile.tpl-arch

REQ += ffmpegStream.tpl-req
REQ += ffmpegFile.tpl-req

# Build and install ADStream compatible pluginFileMJPEG and pluginMJPG files
DB          += pluginFileMPEG.db
ARCHIVE     += pluginFileMPEG.archive
REQ         += pluginFileMPEG.req
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginFileMPEG.cmd
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginFileMPEG.substitutions
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginFileMPEG.sub-arch
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginFileMPEG.sub-req
DB          += pluginMJPG.db
ARCHIVE     += pluginMJPG.archive
REQ         += pluginMJPG.req
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginMJPG.cmd
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginMJPG.substitutions
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginMJPG.sub-arch
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginMJPG.sub-req

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
