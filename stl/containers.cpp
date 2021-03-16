#include <iostream>
#include <vector>
#include <array>

#include <map>
#include <set>

int main(){
  
  // MAP -----------------------------------------------------------------------------------------------------
  /*std::map<K, V> mapuje klucz typu K na jakąś dowolną wartość typu V,
  która nie bierze udziału w porządkowaniu kontenera, ani wyszukiwaniu. 
  Tutaj też klucze są unikalne, oraz dostępne są wszystkie operacje omówione wcześniej dla zbioru,
  z tą różnicą, że teraz iterator nie wskazuje na klucz, lecz na parę std::pair<K, V>.
  Mozliwością map jest użycie operatora indeksowania [], 
  który jako indeks przyjmuje klucz (więc niekoniecznie liczbę) i zwraca referencję na przechowywaną wartość.
  Takie zachowanie może być niepożądane w niektórych przypadkach, wtedy należy użyć find(), 
  sprawdzić czy element istnieje i dostać się do niego przez iterator.
  Inną opcją jest użycie metody at(), która działa tak samo jak operator [], 
  ale gdy element nie istnieje, wywołuje błąd, zamiast go dodawać.
  */
  
  //SET - unique keys---------------------------------------------------
  /*Podstawowe operacje size(), empty(), clear(), erase() działają analogicznie jak w przypadku std::vector<>. 
  Ze względu na drzewiastą strukturę, nie ma tu aspektu rezerwacji pamięci, ani dodawania elementów w określone miejsce 
  (porządkowanie elementów w kontenerze jest poza naszą kontrolą). 
  Dodawanie elementów odbywa się przy użyciu metody insert(), do której po prostu podajemy klucz do dodania. 
  Jeśli klucz już istnieje w zbiorze, operacja dodawania nie zmienia w żaden sposób zawartości kontenera.
  */
  
  int dane[ 10 ] = { 1, 9, 2, 3, 1, 4, 6, 5, 5, 8 };
    std::set < int > zbior;
   
    // pojedynczo
    for( int i = 0; i < 10; ++i )
         zbior.insert( dane[ i ] );
   
    // lub wszystkie naraz (para iteratorów)
    zbior.insert( dane, dane + 10 );
   
    // 'std::set<int>::iterator' zamiast 'auto', przed C++11
    for( auto iter = zbior.begin(); iter != zbior.end(); ++iter )
         std::cout << * iter << ' ';
   
  
  
  
}
