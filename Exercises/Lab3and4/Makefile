CC = g++                         # Compiler
FLAGS = -std=c++20 -w            # Compiler flags
TARGET = TestFiniteFunctions     # Executable name

OBJECTS = TestFiniteFunctions.o FiniteFunctions.o MyFunctions.o

LIBS = -I ../../GNUplot/ -lboost_iostreams

# ---------------------------------------------------------
# Default target: build executable
# ---------------------------------------------------------
${TARGET}: ${OBJECTS}
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

# ---------------------------------------------------------
# Compile main program
# ---------------------------------------------------------
TestFiniteFunctions.o: TestFiniteFunctions.cxx FiniteFunctions.h MyFunctions.h
	${CC} ${FLAGS} ${LIBS} -c TestFiniteFunctions.cxx

# ---------------------------------------------------------
# Compile FiniteFunctions base class
# ---------------------------------------------------------
FiniteFunctions.o: FiniteFunctions.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c FiniteFunctions.cxx

# ---------------------------------------------------------
# Compile MyFunctions derived class
# ---------------------------------------------------------
MyFunctions.o: MyFunctions.cxx MyFunctions.h FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c MyFunctions.cxx

# ---------------------------------------------------------
# Clean object files
# ---------------------------------------------------------
clean:
	@rm -f *.o *~

# ---------------------------------------------------------
# Clean the final executable
# ---------------------------------------------------------
cleantarget:
	@rm -f ${TARGET}