#OBJS specifies which files to compile as part of the project
OBJS = src/buff.cpp src/common.cpp src/main.cpp src/mirror_image.cpp src/player.cpp src/simulation.cpp src/state.cpp src/target.cpp src/unit.cpp src/water_elemental.cpp src/valkyr_protector.cpp src/valkyr_guardian.cpp

# GNU make's CreateProcess cannot launch em++.exe when Windows Application Control
# blocks it (error 4551). Call the Python driver instead. Linux/CI keep using em++.
ifeq ($(OS),Windows_NT)
  EMSDK_DIR := $(subst \,/,$(if $(EMSDK),$(EMSDK),$(USERPROFILE)/emsdk))
  ifeq ($(strip $(EMSDK_PYTHON)),)
    EMSDK_PYTHON := $(firstword $(wildcard $(EMSDK_DIR)/python/*/python.exe))
  endif
  CC = "$(subst \,/,$(EMSDK_PYTHON))" "$(EMSDK_DIR)/upstream/emscripten/em++.py"
else
  CC = em++
endif

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# ENVIRONMENT=web,worker keeps Node glue (import "node:module") out of the Vite worker bundle
COMPILER_FLAGS = --bind -sMODULARIZE=1 -sEXPORT_ES6=1 -sENVIRONMENT=web,worker -sNO_FILESYSTEM=1 -sASSERTIONS=1 -sEXPORT_NAME=MageSim -O3 -sINCOMING_MODULE_JS_API=locateFile,wasmBinary,instantiateWasm,onAbort,print,printErr

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS =

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = public/magesim.js

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
