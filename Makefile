SRC_DIR 		= .\src
BUILD_DIR 		= .\build
INCLUEDE_DIR 	= $(SRC_DIR)\include
LIB_DIR 		= $(SRC_DIR)\lib
SRC 			= $(SRC_DIR)\JogoDaVelha.cpp
DOMAIN_SRC 		= $(SRC_DIR)\domain\grid.cpp
DOMAIN_SRC 		+= $(SRC_DIR)\domain\player.cpp
INCLUDE_FILES 	= $(SRC_DIR)\domain\grid.h

BUILD 			= $(BUILD_DIR)\main.exe
CC				= g++
CFLAGS			= -lraylib -lgdi32 -lwinmm

compile:
	@echo "Compiling JogoDaVelha..."
	$(CC) $(SRC) $(DOMAIN_SRC) -o $(BUILD)  -I $(INCLUEDE_DIR) -L $(LIB_DIR) $(CFLAGS)

clean:
	@echo "Cleaning build files..."
	del /Q $(BUILD)
