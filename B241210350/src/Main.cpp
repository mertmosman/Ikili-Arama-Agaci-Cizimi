/**       
* @file  ListNode.hpp
* @description Bizden istenen islemleri siraya koydugumuz ve dosya okudugumuz main yapisi.
* @course  1/B
* @assignment 2.Odev 
* @date  25.12.2024
* @author  Muhammed Osman MERT muhammed.mert1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include "LinkedList.hpp"
#include "Agac.hpp"

using namespace std;

int main() {
    LinkedList* list = new LinkedList(); // Bağlı liste
    string dosya = "agaclar.txt";
    ifstream ac(dosya);

    if (!ac) {
        cerr << "Dosya acilamadi: " << dosya << endl;
        return 1;
    }

    // Dosyadan ağaçları oku ve listeye ekle
    string satir;
    while (getline(ac, satir)) {
        Agac* yeniAgac = new Agac();
        for (char c : satir) {
            yeniAgac->dugumEkle(c); // Her karakteri ağaca ekle
        }
        list->agacEkle(yeniAgac); // Ağacı bağlı listeye ekle
    }
    ac.close();

    cout << "Agaclar dosyadan okundu ve liste olusturuldu.\n";

    char secim;
    while (true) {
        // Bağlı listeyi ve seçili ağacı göster
        system("cls");
        list->pencereCiz();

        Agac* simdikiAgac = list->getSuankiAgac();
        if (simdikiAgac) {
            simdikiAgac->ciz();
        } else {
            delete list;
        }

        // Kullanıcıdan komut al
        cout << "secim..: ";
        cin >> secim;

        switch (secim) {
            case 'a':
                list->solaGit();
                break;
            case 'd':
                list->sagaGit();
                break;
            case 's':
                list->agacSil();
                break;
            case 'w':
                if (simdikiAgac) {
                    simdikiAgac->aynala();
                    cout << "Agac aynalandi.\n";
                }
                break;
            case 'x':
                cout << "Programdan cikiliyor...\n";
                delete list;
                return 0;
            default:
                cout << "Gecersiz komut!\n";
                break;
        }
    }
    delete list;
}