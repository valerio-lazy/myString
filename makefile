SrcFiles=$(wildcard *.cpp)
ObjFiles=$(patsubst %.cpp, %.o, $(SrcFiles))
AppFile=a.out

all:$(AppFile)


$(AppFile):$(ObjFiles) MIterator.hpp MString.h
	g++ $^ -o $@ *.hpp -std=c++11 -fno-elide-constructors

%.o:%.cpp
	g++ -c $^ -std=c++11 

clean:
	rm -f $(ObjFiles) a.out
