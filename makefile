# Project: Ray Tracer
# Makefile created by Dev-C++ 4.9.9.2

CPP  = g++
CC   = gcc
#WINDRES = windres.exe
RES  = 
OBJ  = main.o math/Vector3.o math/Ray.o objects/Sphere.o objects/Object.o Util/color.o Util/camera.o Util/light.o objects/Wall.o 
LINKOBJ  = main.o math/Vector3.o math/Ray.o objects/Sphere.o objects/Object.o Util/color.o Util/camera.o Util/light.o objects/Wall.o 
LIBS =  -lglut
BIN  = "RayTracer"
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before "RayTracer" all-after
	
clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "RayTracer" $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o

math/Vector3.o: math/Vector3.cpp
	$(CPP) -c math/Vector3.cpp -o math/Vector3.o 

math/Ray.o: math/Ray.cpp
	$(CPP) -c math/Ray.cpp -o math/Ray.o 

objects/Sphere.o: objects/Sphere.cpp
	$(CPP) -c objects/Sphere.cpp -o objects/Sphere.o 

objects/Object.o: objects/Object.cpp
	$(CPP) -c objects/Object.cpp -o objects/Object.o 

Util/color.o: Util/color.cpp
	$(CPP) -c Util/color.cpp -o Util/color.o 

Util/camera.o: Util/camera.cpp
	$(CPP) -c Util/camera.cpp -o Util/camera.o 

Util/light.o: Util/light.cpp
	$(CPP) -c Util/light.cpp -o Util/light.o 

objects/Wall.o: objects/Wall.cpp
	$(CPP) -c objects/Wall.cpp -o objects/Wall.o 
