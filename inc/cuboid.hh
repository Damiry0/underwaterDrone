#ifndef CUBOID_HH
#define CUBOID_HH

#include <vector>
#include <string>
#include "SWektor.hh"

/**
 * @brief Klasa mająca za zadanie być klasą bazową dla pozostałych obiektów wyświetlanych na ekranie w środowisku wodnym.
 * 
 */
class Cuboid{
    protected:
    std::vector<Vector3D> punkty; // Trzy elementowy wektor zapisujący kolejne współrzedne 
    Vector3D wektor_translacji; // Wektor przesuniecia obiektu
    double kat_obrotu; // Kat obrotu obiektu
    public:
    Cuboid();
    void rysuj(std::string nazwa_pliku) const;
    void translacja(const Vector3D& zmiana)
    {
        wektor_translacji= wektor_translacji + zmiana;
    }
    void zmien_wartosc_kata(double kat)
    {
        kat_obrotu=kat_obrotu+kat;
    }
    inline static int licznik=0; // zmienna liczaca obiekty 
};

#endif
