SRC_DIR 		= .\src
BUILD_DIR 		= .\build
INCLUEDE_DIR 	= $(SRC_DIR)\include
LIB_DIR 		= $(SRC_DIR)\lib
SRC 			= $(SRC_DIR)\JogoDaVelha.cpp
BUILD 			= $(BUILD_DIR)\main.exe
CC				= g++
CFLAGS			= -lraylib -lgdi32 -lwinmm

compile:
	@echo "Compiling JogoDaVelha..."
	$(CC) $(SRC) -o $(BUILD)  -I $(INCLUEDE_DIR) -L $(LIB_DIR) $(CFLAGS)

clean:
	@echo "Cleaning build files..."
	del /Q $(BUILD)
