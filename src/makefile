OBJ_DIR = ../obj
OBJGTK_DIR = ../objgtk
BIN_DIR = ../bin
INC_DIR = gtkwin
CFLAGS = -Wall -g -I$(INC_DIR)
EXEC = $(BIN_DIR)/app
MODEL = models
GTKWIN = gtkwin
LIBS = `pkg-config --cflags --libs gtkmm-4.0`
OBJGTK = $(OBJGTK_DIR)/GtkMainWin.o #TODOS LOS MODELS QUE INCLUYAN GTK
OBJS = $(OBJ_DIR)/RequestList.o #Todos lsos modelos SIN LIBRERIAS EXTRAS

all : target

target: $(OBJS) $(OBJGTK) $(OBJGTK_DIR)/main.o #porq no se puede dentro de otra carpeta.
	@mkdir $(BIN_DIR) -p
	g++ -o $(EXEC) $(OBJS) $(OBJGTK) $(OBJGTK_DIR)/main.o $(LIBS) $(CFLAGS)

$(OBJGTK_DIR)/main.o : main.cpp
	g++ -c main.cpp -o $(OBJGTK_DIR)/main.o $(LIBS) $(CFLAGS)

$(OBJGTK_DIR)/%.o : $(GTKWIN)/*.cpp
	@mkdir $(OBJGTK_DIR) -p
	g++ -c $< -o $@ $(LIBS)
	
$(OBJ_DIR)/%.o : $(MODEL)/*.cpp
	@mkdir $(OBJ_DIR) -p
	g++ -c $< -o $@ 



clean :
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJGTK_DIR)/*.o
	rm -r ../obj
	rm -r ../objgtk
	rm -r ../bin