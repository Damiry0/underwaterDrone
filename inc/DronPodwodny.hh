#ifndef DRONPODWODNY_HH
#define DRONPODWODNY_HH
#include "Prostopadloscian.hh"
#include <string>

/**
 * @brief Klasa mająca za zadanie symulować reprezentacje Drona w środowisku podwwodnym
 * 
 */

class DronPodwodny :public Prostopadloscian 
{
    Prostopadloscian Dron;
    public:
   void animacja_obrotu(double kat_obrotu);
   void animacja_translacji(double kat_obrotu,double odleglosc);
};

#endif