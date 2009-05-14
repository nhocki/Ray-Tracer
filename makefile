# Project: Ray Tracer
# Makefile

# Nicolás Hock
# Crisitan Isaza
# Alejandro Peláez

CPP  = g++
CC   = gcc
RES  = 
OBJ  = main.o PhotonMap.o math/Vector3.o math/Ray.o objects/Sphere.o objects/Object.o objects/Cylinder.o Util/Color.o Util/Camera.o Util/Light.o objects/Wall.o Util/Texture.o Util/Timer.o
LINKOBJ  = main.o PhotonMap.o math/Vector3.o math/Ray.o objects/Sphere.o objects/Object.o objects/Cylinder.o Util/Color.o Util/Camera.o Util/Light.o objects/Wall.o Util/Texture.o Util/Timer.o
LIBS =  -lglut
BIN  = "RayTracer"
CFLAGS =  -O3
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before "RayTracer" all-after
	
clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(CFLAGS) $(LINKOBJ) -o "RayTracer" $(LIBS)

main.o: main.cpp
	$(CPP) $(CFLAGS) -c main.cpp -o main.o
PhotonMap.o: PhotonMap.cpp
	$(CPP) $(CFLAGS) -c PhotonMap.cpp -o PhotonMap.o

math/Vector3.o: math/Vector3.cpp
	$(CPP) $(CFLAGS) -c math/Vector3.cpp -o math/Vector3.o 

math/Ray.o: math/Ray.cpp
	$(CPP) $(CFLAGS) -c math/Ray.cpp -o math/Ray.o 

objects/Sphere.o: objects/Sphere.cpp
	$(CPP) $(CFLAGS) -c objects/Sphere.cpp -o objects/Sphere.o 

objects/Object.o: objects/Object.cpp
	$(CPP) $(CFLAGS) -c objects/Object.cpp -o objects/Object.o 

objects/Cylinder.o: objects/Cylinder.cpp
	$(CPP) $(CFLAGS) -c objects/Cylinder.cpp -o objects/Cylinder.o

Util/Color.o: Util/Color.cpp
	$(CPP) $(CFLAGS) -c Util/Color.cpp -o Util/Color.o 

Util/Camera.o: Util/Camera.cpp
	$(CPP) $(CFLAGS) -c Util/Camera.cpp -o Util/Camera.o 

Util/Light.o: Util/Light.cpp
	$(CPP) $(CFLAGS) -c Util/Light.cpp -o Util/Light.o 

objects/Wall.o: objects/Wall.cpp
	$(CPP) $(CFLAGS) -c objects/Wall.cpp -o objects/Wall.o

Util/Texture.o: Util/Texture.cpp
	$(CPP) $(CFLAGS) -c Util/Texture.cpp -o Util/Texture.o

Util/Timer.o: Util/Timer.cpp
	$(CPP) $(CFLAGS) -c Util/Timer.cpp -o Util/Timer.o
