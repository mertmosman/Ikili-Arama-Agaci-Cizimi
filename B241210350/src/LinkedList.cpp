/**       
* @file  LinkedList.cpp
* @description Agaclari birbirine baglayan ve ekranda bizden istenen bazi islemleri yapan metotlarin tanimlari. En kapsamli bagli liste
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#include "LinkedList.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

// Kurucu fonksiyon
LinkedList::LinkedList() {
    bas = nullptr;
    simdiki = nullptr;
    ekranBas = nullptr;
    sayfaSayac = 0;
    toplamDugum = 0;
}

// Yıkıcı fonksiyon
LinkedList::~LinkedList() {
    while (bas != nullptr) {
        ListNode* gecici = bas;
        bas = bas->sonraki;
        delete gecici;
    }
}

//Ağaç ekleme
void LinkedList::agacEkle(Agac* agac) {
    ListNode* yeniDugum = new ListNode();
    yeniDugum->agac = agac;
    yeniDugum->sonraki = nullptr;

    if (bas == nullptr) {
        bas = yeniDugum;
        simdiki = bas;
        ekranBas = bas; // İlk düğüm eklendiğinde başlangıç düğümü ayarlanır
    } else {
        ListNode* gecici = bas;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
    }
    toplamDugum++;
}

Agac* LinkedList::getSuankiAgac() {
    return simdiki ? simdiki->agac : nullptr;
}

//Seçili ağacı sil
void LinkedList::agacSil() {
    if (simdiki == nullptr) return;

    // Eğer silinen düğüm listenin başıysa
    if (simdiki == bas) {
        bas = bas->sonraki;

        // Eğer silinen düğüm aynı zamanda ekranBas ise
        if (simdiki == ekranBas) {
            ekranBas = bas; // Yeni başlangıç düğümünü ayarla
        }

        delete simdiki;
        simdiki = bas; // Yeni seçili düğümü ayarla
    } else {
        ListNode* gecici = bas;
        while (gecici->sonraki != simdiki) {
            gecici = gecici->sonraki;
        }

        // Bağlantıyı atla ve düğümü sil
        gecici->sonraki = simdiki->sonraki;

        // Eğer silinen düğüm ekranBas ise
        if (simdiki == ekranBas) {
            ekranBas = gecici->sonraki ? gecici->sonraki : bas; // Yeni sayfa başlangıcını belirle
        }

        delete simdiki;
        simdiki = gecici; // Yeni seçili düğümü ayarla
    }

    // Eğer liste tamamen boşsa
    if (bas == nullptr) {
        simdiki = nullptr;
        ekranBas = nullptr;
        return;
    }

    // Seçili düğümün mutlaka görünmesini sağla
    ciziliMi();
}

//Ağaç çizilmiş mi kontrol et
void LinkedList::ciziliMi() {
    if (simdiki == nullptr) return;

    ListNode* gecici = bas;
    int sayac = 0;

    // Seçili düğümün hangi sayfada olduğunu bul
    while (gecici != nullptr) {
        if (gecici == simdiki) break;
        gecici = gecici->sonraki;
        sayac++;
    }

    // Sayfa başlangıç düğümünü hesapla
    int sayfaBaslangic = (sayac / 10) * 10; // Her 10 düğüm bir sayfa
    gecici = bas;
    for (int i = 0; i < sayfaBaslangic && gecici != nullptr; i++) {
        gecici = gecici->sonraki;
    }

    ekranBas = gecici; // Yeni sayfa başlangıcını güncelle
}

//Sola gidiş
void LinkedList::solaGit() {
    // Eğer başa dönüldüyse sola hareket edilemez
    if (simdiki == nullptr || simdiki == bas) {
        cout << "Sola hareket edilemiyor. Ilk dugumdesiniz.\n";
        return;
    }

    // Eğer simdiki, sayfanın ilk düğümündeyse eski sayfanın ilk düğümüne git
    if (simdiki == ekranBas) {
        // Eğer pageCounter 0 ise, yani henüz bir sayfa geçişi yapılmadıysa, başa gitme işlemi yok
        if (sayfaSayac == 0) {
            // Sayfa sayacını bir artırıyoruz (ilk sayfa)
            sayfaSayac++;
            return;
        }

        // Eski sayfaya geçmek için, sayaç geriye gidiyor ve sayfanın başını buluyor
        ListNode* gecici = bas;
        int adim = 0;

        // Sayfa sayacına göre, o kadar adım ileri gitmek
        while (gecici != nullptr && adim < 10 * (sayfaSayac - 1)) {
            gecici = gecici->sonraki;
            adim++;
        }

        ekranBas = gecici;  // Eski sayfanın başı
        simdiki = ekranBas;  // Eski sayfada son düğüme gitmek için başlangıç

        // Eski sayfanın son düğümüne gitmek için, 9 düğüm daha ilerle
        int kalanAdim = 9;  // 9 adım ilerle, çünkü ilk düğümdeyiz
        while (simdiki->sonraki != nullptr && kalanAdim > 0) {
            simdiki = simdiki->sonraki;
            kalanAdim--;
        }

        sayfaSayac--;  // Sayfa sayacını azaltıyoruz
        return;
    }

    // Normalde tek tek geri gitme işlemi
    ListNode* gecici = bas;
    while (gecici->sonraki != simdiki) {
        gecici = gecici->sonraki;
    }
    simdiki = gecici;
}

//Sağa gidiş
void LinkedList::sagaGit() {
    if (simdiki != nullptr && simdiki->sonraki != nullptr) {
        simdiki = simdiki->sonraki;

        // Sayfa başında 10 düğümü geçtikten sonra, yeni sayfaya geçiş
        int adim = 0;
        ListNode* gecici = ekranBas;
        while (gecici != nullptr && adim < 10) {
            gecici = gecici->sonraki;
            adim++;
        }

        if (simdiki == gecici && simdiki != nullptr) {
            ekranBas = simdiki;  // Yeni sayfaya geçiş
            sayfaSayac++;  // Sayfa sayacını arttırıyoruz
        }
    } else {
        cout << "Saga hareket edilemiyor. Son dugumdesiniz.\n";
    }
}

//Ekranda pencere cizimi
void LinkedList::pencereCiz() {
    ListNode* gecici = ekranBas;
    int ekrandakiDugum = 0;

    // Başlangıç düğümünden itibaren, 10 düğüm yazdırıyoruz
    while (gecici != nullptr && ekrandakiDugum < 10) {
        cout << setw(15) << gecici << " |";  // Veriler arasında '|' işareti
        gecici = gecici->sonraki;
        ekrandakiDugum++;
    }
    cout << endl;

    // Yatay çizgi ekleyerek ayırma
    cout <<"      "<< string(15 * 11-1, '-') << endl;

    // Toplam değeri yazdır
    gecici = ekranBas;
    ekrandakiDugum = 0;
    while (gecici != nullptr && ekrandakiDugum < 10) {
        cout << setw(15) << gecici->agac->toplamHesapla() << " |";  // Veriler arasında '|' işareti
        gecici = gecici->sonraki;
        ekrandakiDugum++;
    }
    cout << endl;

    // Yatay çizgi ekleyerek ayırma
    cout <<"      "<< string(15 * 11-1, '-') << endl;

    // Sonraki düğümün adresini yazdır
    gecici = ekranBas;
    ekrandakiDugum = 0;
    while (gecici != nullptr && ekrandakiDugum < 10) {
        cout << setw(15) << gecici->sonraki << " |";  // Veriler arasında '|' işareti
        gecici = gecici->sonraki;
        ekrandakiDugum++;
    }
    cout << endl;

    // Yatay çizgi ekleyerek ayırma
    cout <<"      "<< string(15 * 11-1, '-') << endl;

    gecici = ekranBas;
    ekrandakiDugum = 0;
    while (gecici != nullptr && ekrandakiDugum < 10) {
        if (gecici == simdiki) {
            cout << setw(17 * (ekrandakiDugum + 1)) << "^^^^^^^^" << " ";  // Seçili düğüm işareti
        }
        gecici = gecici->sonraki;
        ekrandakiDugum++;
    }
    cout << endl;
}