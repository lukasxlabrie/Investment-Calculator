# This is a simple Makefile for building the Investment Calculator program.
# We use '#' to start a comment.

# Compiler settings - Can change 'g++' to 'clang++' if using Clang.
CXX = g++

# Compiler flags:
# -g adds debugging information to the executable file
# -Wall turns on most compiler warnings
CXXFLAGS = -std=c++14 -Wall -g

# The build target executable:
TARGET = investmentCalculator

# This default 'all' target will be built when you run 'make' without arguments.
all: $(TARGET)

# Link the object files into the executable
$(TARGET): main.o BankAccount.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o BankAccount.o

# Compile the main.cpp file into main.o
main.o: main.cpp BankAccount.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile the BankAccount.cpp file into BankAccount.o
BankAccount.o: BankAccount.cpp BankAccount.h
	$(CXX) $(CXXFLAGS) -c BankAccount.cpp

# The 'clean' target for cleaning up (removing) all compiled files
clean:
	rm -f *.o $(TARGET)
# This is a simple Makefile for building the Investment Calculator program.
# We use '#' to start a comment.

# Compiler settings - Can change 'g++' to 'clang++' if using Clang.
CXX = g++

# Compiler flags:
# -g adds debugging information to the executable file
# -Wall turns on most compiler warnings
CXXFLAGS = -std=c++14 -Wall -g

# The build target executable:
TARGET = investmentCalculator

# This default 'all' target will be built when you run 'make' without arguments.
all: $(TARGET)

# Link the object files into the executable
$(TARGET): main.o BankAccount.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o BankAccount.o

# Compile the main.cpp file into main.o
main.o: main.cpp BankAccount.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile the BankAccount.cpp file into BankAccount.o
BankAccount.o: BankAccount.cpp BankAccount.h
	$(CXX) $(CXXFLAGS) -c BankAccount.cpp

# The 'clean' target for cleaning up (removing) all compiled files
clean:
	rm -f *.o $(TARGET)
