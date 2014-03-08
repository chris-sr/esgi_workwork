# User config
SRC=src
BOOST_PATH_HEADERS=D:/Dev/boost-1.55/include
BOOST_PATH_LIBS=D:/Dev/CPP/workwork/poc/lib
BOOST_LIB_CHRONO=boost_chrono-mgw47-mt-sd-1_55
BOOST_LIB_SYSTEM=boost_system-mgw47-mt-sd-1_55
BOOST_LIB_THREAD=boost_thread-mgw47-mt-sd-1_55

# Project config
CC=g++
FLAGS=-Wall -Wextra

poc: poc.exe

poc.exe: Utils.o Worker.o Task.o TaskCarDoor.o TaskCarEngine.o main.o
	$(CC) \
	-L$(BOOST_PATH_LIBS) \
	$^ \
	-o poc.exe \
	-l$(BOOST_LIB_CHRONO) \
	-l$(BOOST_LIB_THREAD) \
	-l$(BOOST_LIB_SYSTEM)
	del *.o
	
%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) \
	-I$(BOOST_PATH_HEADERS) \
	-c $(SRC)/$*.cpp \
	-o $*.o
	
clean:
	del *.o
	del *.exe