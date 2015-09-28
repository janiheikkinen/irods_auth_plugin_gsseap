BASEDIRS = gsseap
           

######################################################################
# Configuration should occur above this line

#include ../../iRODS/config/platform.mk
#include ../../iRODS/config/config.mk

GCC = g++ -DRODS_SERVER 

export OBJDIR = .objs
export IRODSTOPDIR = ../../iRODS
export SOTOPDIR = .

SUBS = ${BASEDIRS}

.PHONY: ${SUBS} clean

default: ${SUBS}

${SUBS}:
	@-mkdir -p $@/${OBJDIR} > /dev/null 2>&1
	${MAKE} -C $@

clean:
	@-for dir in ${SUBS}; do \
	echo "Cleaning $$dir"; \
	rm -f $$dir/${OBJDIR}/*.o > /dev/null 2>&1; \
	rm -f $$dir/*.o > /dev/null 2>&1; \
	done
	@-rm -f ${SOTOPDIR}/*.so > /dev/null 2>&1

