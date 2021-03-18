#include <iostream>
#include <vector>
#include <array>

#include <map>
#include <set>

int main(){
  /*Vector jest to tak zwany kontener na dane(pojemnik), inaczej dynamiczna tablica.
  W owej tablicy mamy dostęp do każdego jej elementu oraz możemy w każdym momencie zwiększać jej wielkość.
  https://en.cppreference.com/w/cpp/container/vector
  Funkcja erase() z podanym jednym parametrem, czyli adresem określonego elementu, usuwa go. 
  Pamiętajmy że begin()+3 nie oznacza 3 elementu, a 4 ponieważ sama funkcja begin zwraca iterator do 1 elementu. Funkcji erase() można też używać podając dwa parametry. Zostaje wtedy usunięty
ciąg elementów pomiędzy podanymi adresami wraz z podanymi adresami. */
  std::vector<int> vec(3,100);
  auto it = vec.begin();
  it = vec.insert(it+1, 200); //na drugie miejsce
  vec.push_back(13);
  for (auto x: vec) std::cout << ' ' << x;
  vec.pop_back(); 
  it = vec.erase(it);
  
  std::vector < int > tab; //lub {1,2,3,2,5,6,9}
  tab.push_back( 0 );
  srand( time( NULL ) ); //#include <ctime>
  for( int i = 0; i < 10; i++ )
    {
        int gdzie = rand() % tab.size();
        tab.insert( tab.begin() + gdzie, i );
    }
  for( int i = 0; i < tab.size(); i++ ) std::cout << tab[ i ] << std::endl;
  sort( tab.begin()+5, tab.end() );//#include <algorithm> 
  //---ARRAY---------------------------------------------------------------------------------------------------------------------------------------
  /*std::array is a container that encapsulates fixed size arrays. 
  array with the benefits of a standard container, such as knowing its own size, supporting assignment, random access iterators, etc. 
  */
  // construction uses aggregate initialization
    std::array<int, 3> a1{ {1, 2, 3} }; // double-braces required in C++11 prior to
                                        // the CWG 1270 revision (not needed in C++11
                                        // after the revision and in C++14 and beyond)
 
    std::array<int, 3> a2 = {1, 2, 3};  // double braces never required after =
 
    std::array<std::string, 2> a3 = { std::string("a"), "b" };
 
    // container operations are supported
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), 
                      std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
  
    std::cout << "Second element: " << a1[1] << '\n';
    data.at(1) = 88;
    for (int elem : data)
          std::cout << " " << elem;
    std::cout << '\n';
  
    // ranged for loop is supported
    for(const auto& s: a3)
        std::cout << s << ' ';
 
   //KOLEJKA--------------------------------------------------------------------------------------------------------------------
  /*std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end. 
  In addition, insertion and deletion at either end of a deque never invalidates pointers or references to the rest of the elements.
*/
  std::deque<int> d = {7, 5, 16, 8};
  d.push_front(13);
  d.push_back(25);
  for(int n : d) std::cout << n << '\n';
  
     
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
