/**       
* @file  Agac.hpp
* @description Dugumleri agaclara eklememizi ve bunlar uzerinde cesitli islemler yapmamizi saglayan metot tanimlari.
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#ifndef AGAC_HPP
#define AGAC_HPP

#include "Dugum.hpp"

class Agac {
private:
    Dugum* kok; // Ağacın kök düğümü
    void dugumEkle(Dugum*& simdiki, char veri); // Özel düğüm ekleme (recursive)
    int toplamHesapla(Dugum* simdiki, bool isLeft); // Toplam hesaplama (recursive)
    void aynala(Dugum* simdiki); // Aynalama işlemi (recursive)
    void konumaYerlestir(Dugum* Dugum, char konum[][1024], int derinlik, int index); // Ağacın seviyelerini doldur
    int yukseklikAl(Dugum* Dugum); // Ağacın yüksekliğini hesapla
public:
    Agac();
    ~Agac();
    void agacSil(Dugum*& dugum);
    void dugumEkle(char veri); // Ağaca düğüm ekleme
    void ciz(); // Ağacı çizme
    int toplamHesapla(); // Toplam değeri hesaplama
    void aynala(); // Ağacı aynalama
};

#endif