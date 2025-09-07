/**       
* @file  Agac.cpp
* @description Dugumleri agaclara eklememizi ve bunlar uzerinde cesitli islemler yapmamizi saglayan metot tanimlarinin govdeleri.
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#include "Agac.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Kurucu fonksiyon
Agac::Agac() {
    kok = nullptr;
}

//Yıkıcı fonksiyon
Agac::~Agac() {
    agacSil(kok);
}

//Bellekteki ağaçları sil
void Agac::agacSil(Dugum*& Dugum) {
    if (Dugum == nullptr) return;

    // Alt düğümleri sil
    agacSil(Dugum->sol);
    agacSil(Dugum->sag);

    // Mevcut düğümü serbest bırak
    delete Dugum;
}

// Ağaca düğüm ekleme (recursive)
void Agac::dugumEkle(Dugum*& simdiki, char veri) {
    if (simdiki == nullptr) {
        simdiki = new Dugum(veri);
    } else if (veri < simdiki->veri) { // Sol tarafa ekle
        dugumEkle(simdiki->sol, veri);
    } else { // Sağ tarafa ekle
        dugumEkle(simdiki->sag, veri);
    }
}

void Agac::dugumEkle(char veri) {
    dugumEkle(kok, veri);
}

//Yukseklik hesaplama
int Agac::yukseklikAl(Dugum* dugum) {
    if (dugum == nullptr) return -1;
    return 1 + std::max(yukseklikAl(dugum->sol), yukseklikAl(dugum->sag));
}

//Dizideki ilgili yerlere verileri koy
void Agac::konumaYerlestir(Dugum* Dugum, char konum[][1024], int derinlik, int index) {
    if (Dugum == nullptr || derinlik >= 10) return;

    // Mevcut düğümü seviyelere ekle
    konum[derinlik][index] = Dugum->veri;

    // Sol ve sağ çocukları doldur
    konumaYerlestir(Dugum->sol, konum, derinlik + 1, 2 * index);
    konumaYerlestir(Dugum->sag, konum, derinlik + 1, 2 * index + 1);
}

//Ağaç çizme işlemi (boşluk, nokta, veri)
void Agac::ciz() {
    if (kok == nullptr) {
        std::cout << "Agac bos!" << std::endl;
        return;
    }

    // Seviyeleri saklayacak dizi
    char konum[10][1024];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 1024; ++j) {
            konum[i][j] = ' '; // Boşlukla başlat
        }
    }

    // Seviyeleri doldur
    konumaYerlestir(kok, konum, 0, 0);

    // Ağacın yüksekliğini hesapla
    int yukseklik = yukseklikAl(kok);

    // Ağacı seviyeler halinde yazdır
    for (int derinlik = 0; derinlik <= yukseklik; ++derinlik) {
        // Düğüm boşlukları: Her seviyede düğümler arasındaki mesafe
        int dugumBosluk = pow(2, yukseklik - derinlik + 1) - 1;

        // Ek sağa kayma boşluğu (sadece yapraklar için)
        int sagKayma = (derinlik == yukseklik) ? dugumBosluk / 2 : 0;

        // Düğümleri yazdır
        for (int i = 0; i < pow(2, derinlik); ++i) {
            // Sol boşluk
            if (i == 0) for (int j = 0; j < dugumBosluk + sagKayma; ++j) std::cout << " ";

             // Düğümü yazdır
            if (derinlik == yukseklik) {
                std::cout<<" " << konum[derinlik][i];
            }
            else {
                std::cout << konum[derinlik][i];
            }

            // Sağ boşluk
            for (int j = 0; j < dugumBosluk * 2; ++j) std::cout << " ";
        }
        std::cout << std::endl;

        // Eğer bir alt seviyeye bağlantı gerekiyorsa, noktaları çiz
        if (derinlik < yukseklik) {
            for (int i = 0; i < pow(2, derinlik); ++i) {
                // Sol bağlantı
                if (konum[derinlik][i] != ' ' && konum[derinlik + 1][2 * i] != ' ') {
                    for (int j = 0; j < dugumBosluk / 2; ++j) std::cout << " ";
                    std::cout << ".";
                    for (int j = 0; j < dugumBosluk / 2; ++j) std::cout << ".";
                } else {
                    for (int j = 0; j < dugumBosluk+1; ++j) std::cout << " ";
                }

                // Sağ bağlantı
                if (konum[derinlik][i] != ' ' && konum[derinlik + 1][2 * i + 1] != ' ') {
                    for (int j = 0; j < dugumBosluk / 2; ++j) std::cout << ".";
                    std::cout << ".";
                    for (int j = 0; j < dugumBosluk/2 ; ++j) std::cout << " ";
                } else {
                    for (int j = 0; j < dugumBosluk; ++j) std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}

// Toplam değer hesaplama (recursive)
int Agac::toplamHesapla(Dugum* simdiki, bool isLeft) {
    if (simdiki == nullptr) return 0;

    int toplam = 0;
    if (isLeft) {
        toplam += (simdiki->veri * 2);
    } else {
        toplam += simdiki->veri;
    }
    toplam += toplamHesapla(simdiki->sol, true);
    toplam += toplamHesapla(simdiki->sag, false);

    return toplam;
}

int Agac::toplamHesapla() {
    return toplamHesapla(kok, false);
}

// Aynalama (recursive)
void Agac::aynala(Dugum* simdiki) {
    if (simdiki == nullptr) return;

    // Sol ve sağ düğümleri yer değiştir
    Dugum* gecici = simdiki->sol;
    simdiki->sol = simdiki->sag;
    simdiki->sag = gecici;

    aynala(simdiki->sol);
    aynala(simdiki->sag);
}

void Agac::aynala() {
    aynala(kok);
}