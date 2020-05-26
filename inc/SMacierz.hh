#ifndef SMACIERZ_HH
#define SMACIERZ_HH
#include <iostream>
#include "SWektor.hh"
#include "rozmiar.h"
#include <cmath>
#include <iomanip>




template <typename STyp, int SWymiar>
class SMacierz {

    SWektor<STyp,SWymiar>  kolumna[SWymiar];
  public:
    SMacierz();
    SWektor<STyp,SWymiar>  operator [] (unsigned int Ind) const { return kolumna[Ind]; }
    SWektor<STyp,SWymiar> &operator [] (unsigned int Ind)       { return kolumna[Ind]; }
    SWektor<STyp,SWymiar> operator - (const SMacierz<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator*(SWektor<STyp,SWymiar> B)const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SMacierz<STyp,SWymiar> PodstawKolumne(SWektor <STyp,SWymiar> B, int n)const;
    STyp wyznacznik () const;
    SMacierz<STyp,SWymiar> Macierz_Rotacji(double kat);
    SMacierz<STyp,SWymiar> Macierz_RotacjiX(double kat);
    SMacierz<STyp,SWymiar> transpozycja();
};
/*
* Konstruktor klasy Macierz
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
* -Ukryty obiekt klasy typu Macierz  
* Zwraca:
*   Obiekt klasy Macierz wczytany samymi zerami.
*/
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar>::SMacierz()
{
    SWektor<STyp,SWymiar> z[ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j=0;j<ROZMIAR;j++)
        {
            z[i][j]=0;
        }
        kolumna[i]=z[i];
    }
}
/*
* Metoda realizuje podstawienie kolumny przez Wektor B w kolumnie numer n
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   Ukryty obiekt klasy typu Macierz  
*   B - obiekt klasy Wektor
*   n - numer kolumny
* Zwraca:
*   Kopie macierzy po wykonaniu operacji podstawienia kolumny
*/
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::PodstawKolumne (SWektor<STyp,SWymiar> B, int n) const
{
    SMacierz<STyp,SWymiar> C;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
           C[i][j]=this->kolumna[i][j];
        }
    }
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
           if(i==n)
           {
               C[i][j]=B[j]; 
           }
        }
    }
    return C;
}
/*
* Metoda realizuje obliczanie wyznacznik
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   Ukryty obiekt klasy typu Wektor  
*   A - obiekt klasy macierz
* Zwraca:
*   Wyznacznik macierzy A
*/
template <typename STyp, int SWymiar>
  STyp SMacierz<STyp,SWymiar>::wyznacznik () const
  {
    STyp det;
    SMacierz A;
    for (int i = 0; i < ROZMIAR ; i++)

        for (int j = 0; j < ROZMIAR; j++)
        {
            A[i][j]=this->kolumna[i][j];
        }
    for (int i = 0; i < ROZMIAR - 1; i++)

        for (int j = i + 1; j < ROZMIAR; j++)

            for (int k = i + 1; k < ROZMIAR; k++)
                A[j][k] = A[j][i] / A[i][i] * A[i][k] -A[j][k];
                
    det=A[0][0];
    for (int i = 0; i < ROZMIAR-1; ++i)
    {
        det = A[i+1][i+1]* det;
    }
    if (det ==0)
    {
    std::cerr<<"Wyznacznik macierzy równy 0. Brak rozwiązań rzeczywistych.";
       exit(0);
    }
    return det; 
  }
/*
* Metoda realizuje operacji transpozycji macierzy
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   Ukryty obiekt klasy typu Macierz  
* Zwraca:
*   Kopie macierzy po wykonaniu operacji transpozycji
*/
  
template <typename STyp, int SWymiar>

SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::transpozycja() 
{
    SMacierz<STyp,SWymiar> B;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            B[i][j]=this->kolumna[j][i];

        }
    }
    return B;
}
/*
* Metoda realizuje mnożenie macierzy przez wektor
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   Ukryty obiekt klasy typu Macierz  
*   B - obiekt klasy Wektor
* Zwraca:
*   Kopie macierzy po wykonaniu operacji mnozenia
*/
template <typename STyp, int SWymiar>

 SWektor<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator*(SWektor<STyp,SWymiar> B) const
{
    SWektor<STyp,SWymiar> C;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
           C[i]=C[i]+B[j]*this->kolumna[i][j];
        }
    }
    return C;
}
 /*
* Przeciążenie operatora wejscia dla Macierzy
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   StrWe- strumien wejscia
*   Mac - obiekt klasy Macierz
* Zwraca:
*   Strumien wejscia
*/
template <typename STyp, int SWymiar>
std::istream &operator>>(std::istream &StrWe, SMacierz<STyp,SWymiar> &A)
{
    SWektor<STyp,SWymiar> z;
    for (int i = 0; i < SWymiar; ++i)
    {
            StrWe>>z;
            A[i]=z;

    }
    return StrWe;
}
  /*
* Przeciążenie operatora wyjscia dla Macierzy
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   StrWy- strumien wyjscia
*   Mac - obiekt klasy Macierz
* Zwraca:
*   Strumien wyjscia
*/
template <typename STyp, int SWymiar>
std::ostream &operator<<(std::ostream &StrWy, const SMacierz<STyp,SWymiar> &Mac)
{
     for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            StrWy << Mac[i][j]<< " ";
        }
        StrWy << std::endl;
    }
    StrWy << std::endl;
    return StrWy;
}
/**
 * @brief Metoda tworząca macierz obrotu względem osi OZ
 * Parametry:
 * @tparam STyp - Typ macierzy
 * @tparam SWymiar- Wymier macierzy, dopuszczalne wyłącznie kwadratowe
 * @param kat - kąt obrotu macierzy
 * @return Zwraca SMacierz<STyp,SWymiar>, będącą macierzą obrotu dla wybranego kątu
 */
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::Macierz_Rotacji (double kat) 
{
   SMacierz<double,3> B;
    B[0][0]=cos(kat*M_PI/180);
    B[0][1]=-sin(kat*M_PI/180);
    B[0][2]=0;
    B[1][0]=sin(kat*M_PI/180);
    B[1][1]=cos(kat*M_PI/180);
    B[1][2]=0;
    B[2][0]=0;
    B[2][1]=0;
    B[2][2]=1;
    return B;

}






#endif
