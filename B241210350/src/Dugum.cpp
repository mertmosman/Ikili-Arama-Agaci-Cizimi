/**       
* @file  Dugum.cpp
* @description Dugum olusturmamizi saglayan sinif ve kurucu govdesi
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

// Node kurucu fonksiyonu
Dugum::Dugum(char veri) {
    this->veri = veri;
    this->sol = nullptr;
    this->sag = nullptr;
}