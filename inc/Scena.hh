#ifndef SCENA_HH
#define SCENA_HH

#include "cuboid.hh"
#include "DronPodwodny.hh"
#include "PowierzchniaDna.hh"
#include "PowierzchniaWody.hh"

/**
 * @brief Klasa Scena łącząca w sobie funkcjonalność Klasy DronPodwodny,PowierzchniaDna oraz Powierzchnia Wody
 * 
 */
class Scena:public  DronPodwodny,PowierzchniaDna,PowierzchniaWody
{
    PowierzchniaDna PowDna;
    PowierzchniaWody PowWody;
    DronPodwodny Dron;
    public:
    DronPodwodny Get_DronPodwodny()const{
        return Dron;
    }
    DronPodwodny &Get_DronPodwodny(){
        return Dron;
    }
    PowierzchniaWody Get_PowierzchniaWody()const{
        return PowWody;
    }
    PowierzchniaWody &Get_PowierzchniaWody(){
        return PowWody;
    }
    PowierzchniaDna Get_PowierzchniaDna()const{
        return PowDna;
    }
    PowierzchniaDna &Get_PowierzchniaDna(){
        return PowDna;
    }
};





#endif 