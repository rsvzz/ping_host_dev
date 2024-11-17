# Path exe
BIN = bin
TARGET = $(BIN)/troping

# path folder .o
MODEL_DIR = $(BIN)/model
JCPP_DIR = $(BIN)/jcpp
CURL_MODEL_DIR = $(BIN)/curlmodel
GTKWIN_DIR = $(BIN)/win

# Compile name
CXX = g++ -std=c++17

# Path .hpp
INC = inc
INC_MODEL_DIR = $(INC)/model
INC_CURLMODEL_DIR = $(INC)/curl
INC_GTK_MODEL_DIR = $(INC)/win
INC_GTKWIN_MODEL_DIR = $(INC_GTKWIN_DIR)/model
INC_JCPP_DIR = $(INC)/jcpp

# Path .cpp
SRC_CPP = src
MODEL_SRC = $(SRC_CPP)/models
MODEL_CURL_SRC = $(SRC_CPP)/curl_model
JCPP_SRC = $(SRC_CPP)/jcpp
GTK_MODEL_SRC = $(SRC_CPP)/gtk_model

CFLAGS = -Wall -g -I$(INC_MODEL_DIR)$(INC_CURLMODEL_DIR)$(INC_GTKWIN_DIR)$(INC_GTKWIN_MODEL_DIR)$(INC_JCPP_DIR)

#libs
LIB_GTK = `pkg-config --cflags --libs gtkmm-4.0`
LIB_CURL = -lcurl
LIB_JSONCPP =  `pkg-config --cflags --libs jsoncpp`

#path .o files

OBJS_MODEL = $(MODEL_DIR)/RequestList.o
OBJS_CURL_MODEL = $(CURL_MODEL_DIR)/HttpRequestCurl.o $(CURL_MODEL_DIR)/ClientRequest.o
OBJS_JCPP = $(JCPP_DIR)/SaveInfo.o
OBJS_GTK_MODEL = $(GTKWIN_DIR)/RequestStart.o $(GTKWIN_DIR)/GtkMainWin.o $(GTKWIN_DIR)/main.o
#exe : $(MODEL_SRC)/RequestList.cpp
#@mkdir $(BIN) -p
#@mkdir $(MODEL_DIR) -p
#$(CXX) $(MODEL_SRC)/RequestList.cpp -c -o bin/model/RequestList.o

all : $(OBJS_MODEL) $(OBJS_CURL_MODEL) $(OBJS_JCPP) $(OBJS_GTK_MODEL)
	$(CXX) -o $(TARGET) $? $(LIBSGTK) $(LIB_CURL) $(LIB_JSONCPP) $(LIB_GTK)


#model build first call

	
$(MODEL_DIR)/%.o : $(MODEL_SRC)/%.cpp
	@mkdir $(BIN) -p
	@mkdir $(MODEL_DIR) -p
	$(CXX) -c $? -o $@

#curl build

$(CURL_MODEL_DIR)/%.o : $(MODEL_CURL_SRC)/%.cpp
	@mkdir $(CURL_MODEL_DIR) -p
	$(CXX) -c $? -o $@ $(LIB_CURL)

#jcpp build
$(JCPP_DIR)/%.o : $(JCPP_SRC)/%.cpp
	@mkdir $(JCPP_DIR) -p
	$(CXX) -c $? -o $@ $(LIB_JSONCPP)

#gtkwin model build
$(GTKWIN_DIR)/%.o : $(GTK_MODEL_SRC)/%.cpp
	@mkdir -p $(GTKWIN_DIR)
	$(CXX) -c $? -o $@ $(LIB_GTK) $(LIB_CURL)

#gtkwin build
$(GTKWIN_DIR)/%.o : $(SRC_CPP)/%.cpp
	@mkdir -p $(GTKWIN_DIR)
	$(CXX) -c $? -o $@ $(LIB_GTK) $(LIB_CURL) $(LIB_JSONCPP)

exe :
	@./bin/troping

clean : 
	rm -r $(BIN)
