# 
TOP = ../../../..
include $(TOP)/configure/CONFIG

SCRIPTS += ../stexample.sh
SCRIPTS += stexample.boot

include $(TOP)/configure/RULES

%.boot: ../%.src
	$(CP) $< $@
