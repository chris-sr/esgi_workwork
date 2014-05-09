
# Variables to set

PROJECT_NAME            =factory
PATH_SRC                =src
PATH_BUILD_DEB          =build.deb
PATH_BUILD_REL          =build.rel
EXT_SRC                 =cpp
EXT_O_DEB               =deb.o
EXT_O_REL               =rel.o
EXT_EXE_DEB             =deb.exe
EXT_EXE_REL             =exe
CMD_MKDIR               =mkdir
CMD_ECHO                =echo
CMD_RMDIR_FORCE         =rmdir /Q /S
CMD_RM                  =del /Q /F
CMD_DEVNULL             =nul
CMD_SEP                 =---------------------------------

WIN_FIND_PWD            =echo %cd%
WIN_FIND_DIRS           =dir /s /b /a:d /o:gn .\$(subst /,\,$(PATH_SRC))

DEB_CC                  =g++
DEB_FLAGS               =-g -Wall -Wextra -fno-diagnostics-show-caret -ftrack-macro-expansion=0 -DWW_DEBUG
DEB_LINKS               =-lboost_thread-mgw47-mt-sd-1_55 -lboost_system-mgw47-mt-sd-1_55 -lboost_chrono-mgw47-mt-sd-1_55 -lOgreMain_d -lOgreMain_d.dll -lOIS_d.dll
REL_CC                  =g++
REL_FLAGS               =-w -Os
REL_LINKS               =-lboost_thread-mgw47-mt-s-1_55 -lboost_system-mgw47-mt-s-1_55 -lboost_chrono-mgw47-mt-s-1_55 -lOgreMain -lOgreMain.dll -lOIS.dll

OGRE_PATH               =D:/Dev/ogre-1.8/sdk
BOOST_PATH              =D:/Dev/boost-1.55
SDL_PATH                =D:/Dev/SDL2

# Computed variables

CURRENT_DIR             =$(subst \,/,$(shell $(WIN_FIND_PWD)))
LIST_DIRS               =$(sort $(subst $(CURRENT_DIR)/,,$(subst \,/,$(shell $(WIN_FIND_DIRS)))))
LIST_DIRS               +=$(PATH_SRC)
LIST_DIRS_BUILD_DEB     =$(LIST_DIRS:$(PATH_SRC)%=$(PATH_BUILD_DEB)%)
LIST_DIRS_BUILD_REL     =$(LIST_DIRS:$(PATH_SRC)%=$(PATH_BUILD_REL)%)
LIST_FILES_SRC_TMP      =$(wildcard $(addsuffix /*.$(EXT_SRC),$(LIST_DIRS)))
LIST_FILES_SRC          =$(LIST_FILES_SRC_TMP:$(PATH_SRC)/%=%)
LIST_FILES_O_DEB        =$(LIST_FILES_SRC:%.$(EXT_SRC)=%.$(EXT_O_DEB))
LIST_FILES_O_REL        =$(LIST_FILES_SRC:%.$(EXT_SRC)=%.$(EXT_O_REL))
LIST_FILES_FULL_O_DEB   =$(LIST_FILES_O_DEB:%=$(PATH_BUILD_DEB)/%)
LIST_FILES_FULL_O_REL   =$(LIST_FILES_O_REL:%=$(PATH_BUILD_REL)/%)

OIS_PATH_INCLUDE        =$(OGRE_PATH)/include/OIS
OGRE_PATH_INCLUDE       =$(OGRE_PATH)/include/OGRE
OGRE_PATH_LIB_DEBUG     =$(OGRE_PATH)/lib/debug
OGRE_PATH_LIB_RELEASE   =$(OGRE_PATH)/lib/release
BOOST_PATH_INCLUDE      =$(BOOST_PATH)/include
BOOST_PATH_LIB_DEBUG    =$(BOOST_PATH)/lib/
BOOST_PATH_LIB_RELEASE  =$(BOOST_PATH)/lib/
SDL_PATH_INCLUDE        =$(SDL_PATH)/include
SDL_PATH_LIB            =$(SDL_PATH)/lib

# Targets

debug: $(LIST_DIRS_BUILD_DEB) $(PATH_BUILD_DEB)/$(PROJECT_NAME).$(EXT_EXE_DEB)

# debug: create the build directories
$(LIST_DIRS_BUILD_DEB):
	$(CMD_MKDIR) $(subst /,\,$@) > $(CMD_DEVNULL) 2>&1

# debug: link the executable
$(PATH_BUILD_DEB)/$(PROJECT_NAME).$(EXT_EXE_DEB): $(LIST_FILES_FULL_O_DEB)
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) Linking executable $@
	@$(DEB_CC) \
    -o $@ \
	$(LIST_FILES_FULL_O_DEB) \
	$(DEB_LINKS) \
	-L$(OGRE_PATH_LIB_DEBUG) \
	-L$(BOOST_PATH_LIB_DEBUG) \
	-L$(SDL_PATH_LIB)

# debug: compile a single cpp
$(PATH_BUILD_DEB)/%.$(EXT_O_DEB): $(PATH_SRC)/%.$(EXT_SRC)
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) Building $@ from $^
	@$(DEB_CC) \
	$(DEB_FLAGS) \
	-o $@ \
	-c $^ \
	-isystem $(OGRE_PATH_INCLUDE) \
	-isystem $(OIS_PATH_INCLUDE) \
	-isystem $(BOOST_PATH_INCLUDE) \
	-isystem $(SDL_PATH_INCLUDE)
    
release: $(LIST_DIRS_BUILD_REL) $(PATH_BUILD_REL)/$(PROJECT_NAME).$(EXT_EXE_REL)

# release: create the build directories
$(LIST_DIRS_BUILD_REL):
	$(CMD_MKDIR) $(subst /,\,$@) > $(CMD_DEVNULL) 2>&1

# release: link the executable
$(PATH_BUILD_REL)/$(PROJECT_NAME).$(EXT_EXE_REL): $(LIST_FILES_FULL_O_REL)
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) Linking executable $@
	@$(REL_CC) \
	-o $@ \
	$(LIST_FILES_FULL_O_REL) \
	$(REL_LINKS) \
	-L$(OGRE_PATH_LIB_RELEASE) \
	-L$(BOOST_PATH_LIB_RELEASE) \
	-L$(SDL_PATH_LIB)

# release: compile a single cpp
$(PATH_BUILD_REL)/%.$(EXT_O_REL): $(PATH_SRC)/%.$(EXT_SRC)
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) Building $@ from $^
	@$(REL_CC) \
	$(REL_FLAGS) \
	-o $@ \
	-c $^ \
	-isystem $(OGRE_PATH_INCLUDE) \
	-isystem $(OIS_PATH_INCLUDE) \
	-isystem $(BOOST_PATH_INCLUDE) \
	-isystem $(SDL_PATH_INCLUDE)
    
clear:
	@ $(CMD_ECHO) $(CMD_SEP)
	@ $(CMD_ECHO) Cleaning previous builds and binaries
ifneq ($(wildcard $(PATH_BUILD_DEB)),)
	$(CMD_RMDIR_FORCE) $(PATH_BUILD_DEB)
endif
ifneq ($(wildcard $(PATH_BUILD_REL)),)
	$(CMD_RMDIR_FORCE) $(PATH_BUILD_REL)
endif

showvars:
	@$(CMD_ECHO) PROJECT_NAME           =$(PROJECT_NAME)
	@$(CMD_ECHO) PATH_SRC               =$(PATH_SRC)
	@$(CMD_ECHO) PATH_BUILD_DEB         =$(PATH_BUILD_DEB)
	@$(CMD_ECHO) PATH_BUILD_REL         =$(PATH_BUILD_REL)
	@$(CMD_ECHO) EXT_SRC                =$(EXT_SRC)
	@$(CMD_ECHO) EXT_O_DEB              =$(EXT_O_DEB)
	@$(CMD_ECHO) EXT_O_REL              =$(EXT_O_REL)
	@$(CMD_ECHO) EXT_EXE_DEB            =$(EXT_EXE_DEB)
	@$(CMD_ECHO) EXT_EXE_REL            =$(EXT_EXE_REL)
	@$(CMD_ECHO) CMD_ECHO               =$(CMD_ECHO)
	@$(CMD_ECHO) CMD_RMDIR_FORCE        =$(CMD_RMDIR_FORCE)
	@$(CMD_ECHO) CMD_RM                 =$(CMD_RM)
	@$(CMD_ECHO) CMD_DEVNULL            =$(CMD_DEVNULL)
	@$(CMD_ECHO) CMD_SEP                =$(CMD_SEP)
	@$(CMD_ECHO) WIN_FIND_PWD           =$(WIN_FIND_PWD)
	@$(CMD_ECHO) WIN_FIND_DIRS          =$(WIN_FIND_DIRS)
	@$(CMD_ECHO) DEB_CC                 =$(DEB_CC)
	@$(CMD_ECHO) DEB_FLAGS              =$(DEB_FLAGS)
	@$(CMD_ECHO) DEB_LINKS              =$(DEB_LINKS)
	@$(CMD_ECHO) REL_CC                 =$(REL_CC)
	@$(CMD_ECHO) REL_FLAGS              =$(REL_FLAGS)
	@$(CMD_ECHO) REL_LINKS              =$(REL_LINKS)
	
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) LIST_DIRS
	@$(CMD_ECHO) $(LIST_DIRS)
	
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) LIST_DIRS_BUILD_DEB
	@$(CMD_ECHO) $(LIST_DIRS_BUILD_DEB)
	
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) LIST_DIRS_BUILD_REL
	@$(CMD_ECHO) $(LIST_DIRS_BUILD_REL)
	
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) CURRENT_DIR
	@$(CMD_ECHO) $(CURRENT_DIR)
	
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) LIST_FILES_SRC
	@$(CMD_ECHO) $(LIST_FILES_SRC)
	
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) LIST_FILES_O_DEB
	@$(CMD_ECHO) $(LIST_FILES_O_DEB)
	
	@$(CMD_ECHO) $(CMD_SEP)
	@$(CMD_ECHO) LIST_FILES_FULL_O_DEB
	@$(CMD_ECHO) $(LIST_FILES_FULL_O_DEB)



