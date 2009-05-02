# Project: Ray Tracer
# Makefile

# Nicolás Hock
# Crisitan Isaza
# Alejandro Peláez

CPP  = g++
CC   = gcc
RES  = 
OBJ  = main.o math/Vector3.o math/Ray.o objects/Sphere.o objects/Object.o Util/Color.o Util/Camera.o Util/Light.o objects/Wall.o Util/Texture.o
LINKOBJ  = main.o math/Vector3.o math/Ray.o objects/Sphere.o objects/Object.o Util/Color.o Util/Camera.o Util/Light.o objects/Wall.o Util/Texture.o
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

Util/Color.o: Util/Color.cpp
	$(CPP) -c Util/Color.cpp -o Util/Color.o 

Util/Camera.o: Util/Camera.cpp
	$(CPP) -c Util/Camera.cpp -o Util/Camera.o 

Util/Light.o: Util/Light.cpp
	$(CPP) -c Util/Light.cpp -o Util/Light.o 

objects/Wall.o: objects/Wall.cpp
	$(CPP) -c objects/Wall.cpp -o objects/Wall.o

Util/Texture.o: Util/Texture.cpp
	$(CPP) -c Util/Texture.cpp -o Util/Texture.o
