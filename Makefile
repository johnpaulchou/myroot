RC     := root-config
ifeq ($(findstring $(MAKECMDTARGET),clean),)
ifeq ($(shell which $(RC) 2>&1 | sed -ne "s@.*/$(RC)@$(RC)@p"),$(RC))
MKARCH := $(wildcard $(shell $(RC) --etcdir)/Makefile.arch)
RCONFIG := $(wildcard $(shell $(RC) --incdir)/RConfigure.h)
RCLIBS := $(shell $(RC) --libs)
endif
ifneq ($(MKARCH),)
include $(MKARCH)
else
ifeq ($(ROOTSYS),)
ROOTSYS = ..
endif
include $(ROOTSYS)/etc/Makefile.arch
endif
endif

#------------------------------------------------------------------------------

SRCDIR = ./src
INCDIR = ./include
LIBDIR = ./lib

IncSuf = hh
SrcSuf = cc
ObjSuf = o
DepSuf = d

CPPS = $(wildcard ${SRCDIR}/*.${SrcSuf})

INCLUDES = $(wildcard ${INCDIR}/*.${IncSuf})

OBJ = $(CPPS:%.${SrcSuf}=%.${ObjSuf})

DEP = $(OBJ:%.${ObjSuf}=%.${DepSuf})

DICT = ${SRCDIR}/Dict.cxx

LDFLAGS += -std=c++11 -fPIC

TARGET = ${LIBDIR}/libmyroot.${DllSuf}

#all: ${OBJ} ${DICT}

${TARGET}: ${OBJ} ${DICT}
ifeq ($(PLATFORM),macosx)
# We need to make both the .dylib and the .so
	$(LD) $(SOFLAGS)$@ $(LDFLAGS) -I./ -I$(ROOTSYS)/include $^ $(OutPutOpt) $@ $(EXPLLINKLIBS) $(RCLIBS)
	ifneq ($(subst $(MACOSX_MINOR),,1234),1234)
		ifeq ($(MACOSX_MINOR),4)
			ln -sf $@ $(subst .$(DllSuf),.so,$@)
		endif
	endif
else
	$(LD) $(SOFLAGS) $(LDFLAGS) -I./ -I$(ROOTSYS)/include $^ $(EXPLLINKLIBS) $(OutPutOpt)$@ $(RCLIBS)
	$(MT_DLL)
endif

-include $(DEP)



${DICT} : ${INCLUDES} ${SRCDIR}/LinkDef.h
	@echo "Generating dictionary $@..."
	$(ROOTCLING) -f $@ -I${INCDIR} -c $^

${SRCDIR}/%.${ObjSuf} : ${SRCDIR}/%.${SrcSuf}
	$(CXX) $(CXXFLAGS) -I${INCDIR} -MMD -c $< -o $@

clean:
	-rm -f ${OBJ} ${DEP} ${DICT} ${SRCDIR}/*.pcm ${TARGET}
