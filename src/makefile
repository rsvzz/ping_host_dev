OBJ_DIR = ../obj
OBJGTK_DIR = ../objgtk
OBJCURL_DIR = ../objcurl
OBJHTTP_DIR = ../objhttp
BIN_DIR = ../bin
#---------------------- folder
INC_DIR = gtkwin
MODEL = models
CURL = objlcurl
GTKWIN = gtkwin
INC_HTTP = http
#Release
#CPPXX = g++ -std=c++17 -O2
#Debug
CPPXX = g++ -std=c++17

CFLAGS = -Wall -g -I$(INC_DIR)$(MODEL)$(CURL)$(INC_HTTP)
EXEC = $(BIN_DIR)/app
LIBSGTK = `pkg-config --cflags --libs gtkmm-4.0`
LIBCURL = -lcurl
OBJCURL = $(OBJCURL_DIR)/HttpRequestCurl.o #-lcurl
OBJHTTP = $(OBJHTTP_DIR)/ClientRequest.o 
OBJGTK = $(OBJGTK_DIR)/GtkMainWin.o $(OBJGTK_DIR)/RequestStart.o #TODOS LOS MODELS QUE INCLUYAN GTK
OBJS = $(OBJ_DIR)/RequestList.o    #Todos lsos modelos SIN LIBRERIAS EXTRAS
	

all : target

target: $(OBJCURL) $(OBJS) $(OBJHTTP) $(OBJGTK) $(OBJGTK_DIR)/main.o #porq no se puede dentro de otra carpeta.
	@mkdir $(BIN_DIR) -p
	$(CPPXX) -o $(EXEC) $(OBJCURL) $(OBJS) $(OBJHTTP) $(OBJGTK) $(OBJGTK_DIR)/main.o $(LIBSGTK) $(LIBCURL) $(CFLAGS)


$(OBJGTK_DIR)/main.o : main.cpp
	$(CPPXX) -c $? -o $@ $(LIBSGTK) $(CFLAGS)

$(OBJGTK_DIR)/%.o : $(GTKWIN)/%.cpp
	@mkdir $(OBJGTK_DIR) -p
	$(CPPXX) -c $? -o $@ $(LIBSGTK) $(LIBCURL) $(CFLAGS)

$(OBJCURL_DIR)/%.o : $(CURL)/%.cpp
	@mkdir $(OBJCURL_DIR) -p
	$(CPPXX) -c $? -o $@ $(LIBCURL) 

$(OBJHTTP_DIR)/%.o : $(INC_HTTP)/%.cpp
	@mkdir $(OBJHTTP_DIR) -p
	$(CPPXX) -c $? -o $@ $(LIBCURL) $(CFLAGS)
	
$(OBJ_DIR)/%.o : $(MODEL)/%.cpp
	@mkdir $(OBJ_DIR) -p
	$(CPPXX) -c $? -o $@ 

clean :
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJGTK_DIR)/*.o
	rm -f $(OBJCURL_DIR)/*.o
	rm -f $(OBJHTTP_DIR)/*.o
	rm -r ../obj
	rm -r ../objgtk
	rm -r ../bin
	rm -r ../objcurl

exe :
	./../bin/app
