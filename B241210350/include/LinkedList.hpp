/**       
* @file  LinkedList.hpp
* @description Agaclari birbirine baglayan ve ekranda bizden istenen bazi islemleri yapan metotlarin tanimlari. En kapsamli bagli liste
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "ListNode.hpp"

class LinkedList {
private:
    ListNode* bas;       // Listenin başı
    ListNode* simdiki;    // Seçili düğüm
    ListNode* ekranBas;       // Pencerenin başlangıç indeksi
    int toplamDugum;       // Toplam düğüm sayısı
    int sayfaSayac;     // Sayfa sayacı (hangi sayfada olduğumuzu tutar)

public:
    LinkedList();
    ~LinkedList();
    Agac* getSuankiAgac();     // Seçili ağacı döndür
    void agacEkle(Agac* agac);   // Ağacı listeye ekle
    void agacSil();       // Seçili düğümü sil
    void solaGit();            // Bir önceki düğüme git
    void sagaGit();           // Bir sonraki düğüme git
    void pencereCiz();         // 10 düğümlük pencereyi göster
    void ciziliMi();
};

#endif