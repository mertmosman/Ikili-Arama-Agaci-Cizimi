/**       
* @file  ListNode.hpp
* @description Dugumler uzerindeki bagli liste.
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#include "ListNode.hpp"
#include <iostream>
// Kurucu fonksiyon
ListNode::ListNode() {
    agac = new Agac();
    sonraki = nullptr;
}

// Yıkıcı fonksiyon
ListNode::~ListNode() {
    delete agac;
}