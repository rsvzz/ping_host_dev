OBJ_DIR = ../obj
OBJGTK_DIR = ../objgtk
OBJCURL_DIR = ../objcurl
BIN_DIR = ../bin
#---------------------- folder
INC_DIR = gtkwin
MODEL = models
CURL = objlcurl
GTKWIN = gtkwin

CFLAGS = -Wall -g -I$(INC_DIR)$(MODEL)$(CURL)
EXEC = $(BIN_DIR)/app
LIBSGTK = `pkg-config --cflags --libs gtkmm-4.0`
LIBCURL = -lcurl
OBJCURL = $(OBJCURL_DIR)/HttpRequestCurl.o #-lcurl
OBJGTK = $(OBJGTK_DIR)/GtkMainWin.o #TODOS LOS MODELS QUE INCLUYAN GTK
OBJS = $(OBJ_DIR)/RequestList.o $(OBJ_DIR)/ClientRequest.o $(OBJ_DIR)/RequestStart.o  #Todos lsos modelos SIN LIBRERIAS EXTRAS
	

all : target

target: $(OBJCURL) $(OBJS) $(OBJGTK) $(OBJGTK_DIR)/main.o #porq no se puede dentro de otra carpeta.
	@mkdir $(BIN_DIR) -p
	g++ -o $(EXEC) $(OBJCURL) $(OBJS) $(OBJGTK) $(OBJGTK_DIR)/main.o $(LIBSGTK) $(LIBCURL) $(CFLAGS)

$(OBJGTK_DIR)/main.o : main.cpp
	g++ -c $? -o $@ $(LIBSGTK) $(CFLAGS)

$(OBJGTK_DIR)/%.o : $(GTKWIN)/%.cpp
	@mkdir $(OBJGTK_DIR) -p
	g++ -c $? -o $@ $(LIBSGTK)

$(OBJCURL_DIR)/%.o : $(CURL)/%.cpp
	@mkdir $(OBJCURL_DIR) -p
	g++ -c $? -o $@ $(LIBCURL) $(CFLAGS)
	
$(OBJ_DIR)/%.o : $(MODEL)/%.cpp
	@mkdir $(OBJ_DIR) -p
	g++ -c $? -o $@ 

clean :
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJGTK_DIR)/*.o
	rm -f $(OBJCURL_DIR)/*.o
	rm -r ../obj
	rm -r ../objgtk
	rm -r ../bin
	rm -r ../objcurl

exe :
	./../bin/app