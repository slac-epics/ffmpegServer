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

REQ += ffmpegStream.tpl-req
REQ += ffmpegFile.tpl-req

# Build and install ADStream compatible pluginFileMJPEG and pluginMJPG files
DB          += pluginFileMPEG.db
REQ         += pluginFileMPEG.req
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginFileMPEG.cmd
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginFileMPEG.substitutions
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginFileMPEG.sub-req
DB          += pluginMJPG.db
REQ         += pluginMJPG.req
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginMJPG.cmd
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginMJPG.substitutions
DB_INSTALLS += $(TOP)/ffmpegServerApp/Db/pluginMJPG.sub-req

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
