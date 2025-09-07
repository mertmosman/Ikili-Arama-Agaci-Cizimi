/**       
* @file  ListNode.hpp
* @description Dugumler uzerindeki bagli liste.
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include "Agac.hpp"

class ListNode {
public:
    Agac* agac;       // Ağacı tutan işaretçi
    ListNode* sonraki;   // Bir sonraki bağlı liste düğümü
    ListNode();       // Kurucu fonksiyon
    ~ListNode();      // Yıkıcı fonksiyon (Bellek yönetimi için)
};

#endif