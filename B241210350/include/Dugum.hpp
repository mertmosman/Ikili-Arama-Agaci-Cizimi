/**       
* @file  Dugum.hpp
* @description Dugum olusturmamizi saglayan sinif
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    char veri;      // Düğümün verisi
    Dugum* sol;     // Sol çocuk
    Dugum* sag;    // Sağ çocuk
    Dugum(char veri); // Kurucu fonksiyon
};

#endif