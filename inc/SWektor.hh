#ifndef SWEKTOR_HH
#define SWEKTOR_HH
#include <iostream>
#include <iomanip>
#include <limits>

template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> &A) const;
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Dodatnik) const;
    SWektor<STyp,SWymiar> operator / (double Dzielnik) const;
};
using Vector3D= SWektor<double,3>;

/*
* Realizuje odejmowanie liczby zmiennno przecinkowej od wektora
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWymiar - Wymiar operowanej macierzy typu liczba całkowita
* Argumenty:
*   Ukryty obiekt klasy typu Wektor
*   Odejmnik - liczba zmienno przecinkowa typu double
* Zwraca:
*   Różnice dwóch wektorów
*/
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}

/*
* Realizuje mnożenia wektora przez liczbe zmienno przecinkowa
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWymiar - Wymiar operowanej macierzy typu liczba całkowita
* Argumenty:
*   Ukryty obiekt klasy typu Wektor
*   Mnoznik - liczba zmiennoprzecinkowa typu double 
* Zwraca:
*   Liczbe zmienno przecinkową typu double 
*/
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

/*
* Realizuje dodawanie dwóch wektorów
* Argumenty:
*   Ukryty obiekt klasy typu Wektor
*   Arg2 - wektor o wielkosci ROZMIAR
* Zwraca:
*   Sume dwóch wektorów
*/

template <typename STyp, int SWymiar>
 SWektor<STyp,SWymiar>  SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Dodatnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Dodatnik[Ind];
  return Wynik;
}
/* Przeciążenie operatora wyjścia dla wektora
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWymiar - Wymiar operowanej macierzy typu liczba całkowita
* Argumenty:
*   StrWy- strumien wyjscia
*   Arg1 - wektor o wielkosci ROZMIAR -> patrz rozmiar.h
* Zwraca:
*   Kolejne elementy składowe wektora
*/
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << W[Ind]<<" ";
  }  
  StrmWyj << std::endl;
  return StrmWyj;
}
/*
* Przeciążenie operatora wejscia dla wektora
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWymiar - Wymiar operowanej macierzy typu liczba całkowita
* Argumenty:
*   StrWe- strumien wejscia
*   Arg1 - wektor o wielkosci ROZMIAR -> patrz rozmiar.h
* Zwraca:
*   Strumien wejscia
*/
template <typename STyp, int SWymiar>
std::istream &operator>>(std::istream &StrWe, SWektor<STyp,SWymiar> &Arg1)
{
    for (int i = 0; i < SWymiar; i++)
    {
        StrWe >> Arg1[i];
       
    }
    
    return StrWe;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (double Dzielnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]/Dzielnik;
  return Wynik;  
}
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &A) const
{
  SWektor<STyp,SWymiar> Wynik;
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind]= (*this)[Ind] * A[Ind];
  return Wynik;
}



#endif
