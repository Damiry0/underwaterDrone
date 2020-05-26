#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

TRGDIR=/tmp/rysowanie_3D

__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj obj/main.o obj/lacze_do_gnuplota.o obj/cuboid.o obj/DronPodwodny.o obj/Prostopadloscian.o obj/PowierzchniaDna.o obj/PowierzchniaWody.o obj/Scena.o
	g++ -std=c++17 -Wall -pedantic  -o ./rysowanie_3D obj/main.o\
                        obj/lacze_do_gnuplota.o obj/cuboid.o obj/DronPodwodny.o obj/Prostopadloscian.o obj/PowierzchniaDna.o obj/PowierzchniaWody.o obj/Scena.o


obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/cuboid.hh inc/SWektor.hh inc/SMacierz.hh inc/DronPodwodny.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/cuboid.o: inc/cuboid.hh src/cuboid.cpp
	g++ -c ${CXXFLAGS} -o obj/cuboid.o src/cuboid.cpp

obj/DronPodwodny.o: inc/DronPodwodny.hh src/DronPodwodny.cpp
	g++ -c ${CXXFLAGS} -o obj/DronPodwodny.o src/DronPodwodny.cpp

obj/Prostopadloscian.o: inc/Prostopadloscian.hh src/Prostopadloscian.cpp
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/PowierzchniaDna.o: inc/PowierzchniaDna.hh src/PowierzchniaDna.cpp
	g++ -c ${CXXFLAGS} -o obj/PowierzchniaDna.o src/PowierzchniaDna.cpp

obj/PowierzchniaWody.o: inc/PowierzchniaWody.hh src/PowierzchniaWody.cpp
	g++ -c ${CXXFLAGS} -o obj/PowierzchniaWody.o src/PowierzchniaWody.cpp

obj/Scena.o: inc/Scena.hh src/Scena.cpp
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

clean:
	rm -f obj/*.o ./rysowanie_3D
