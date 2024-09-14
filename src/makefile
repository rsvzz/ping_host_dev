OBJ_DIR = ../obj
BIN_DIR = ../bin
INC_DIR = ../inc
CFLAGS = -Wall -g -I$(INC_DIR)
EXEC = $(BIN_DIR)/app
MODEL = models
LIBS = `pkg-config --cflags --libs gtkmm-4.0`
OBJS = $(OBJ_DIR)/GtkMainWin.o #Todos lsos modelos

all : $(OBJS) $(OBJ_DIR)/main.o #porq no se puede dentro de otra carpeta.
	@mkdir $(BIN_DIR) -p
	g++ -o $(EXEC) $(OBJS) $(OBJ_DIR)/main.o $(LIBS) $(CFLAGS)

$(OBJ_DIR)/main.o : main.cpp
	g++ -c main.cpp -o $(OBJ_DIR)/main.o $(LIBS) $(CFLAGS)
	
$(OBJ_DIR)/%.o : $(MODEL)/*.cpp
	g++ -c $< -o $@ $(LIBS)

clean :
	rm -f $(OBJ_DIR)/*.o