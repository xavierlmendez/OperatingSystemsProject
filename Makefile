CC = g++
CCFLAGS = -g -std=c++11
# LIBRARIES = -lboost_system -lboost_thread
LIBRARIES = -lpthread
EXECUTABLES = n-threads

# Command for creating an executable file
.cpp:
	$(CC) $(CCFLAGS) $(INCLUDES) -o $@ $@.cpp $(LIBRARIES)

# Command for creating an executable file
.o:
	$(CC) -o $@ $@.o $(LIBRARIES)

# Rule for generating .o file from .cpp file
%.o: %.cpp 
	$(CC) $(CCFLAGS) $(INCLUDES) -c $^ 

# All files to be generated
all: $(EXECUTABLES) 
#	$(CC) $(CCFLAGS) threads.cpp -o threads $(CCLIBRARIES)

# Clean the directory
clean: 
	rm -f $(EXECUTABLES)  *.o
		

