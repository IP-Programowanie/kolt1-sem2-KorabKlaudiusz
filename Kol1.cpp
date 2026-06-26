#include "Wybor.h"
#include "PK1_kolA(1).h"


using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczać pomiędzy #ifdef a #endif. 
*/

#ifdef Kol_1

uint32_t Kompresuj(const Dane& d) {

	uint32_t wynik = 0;

	wynik |= (static_cast<uint32_t>(static_cast<unsigned char>(d.symbol) &0xFF) << 23;
	wynik |= (static_cast<uint32_t>(static_cast<uint16_t>(d.liczba) &0xFFFF) << 8;
	wynik |= (static_cast<uint32_t>(d.obliczona) &0x01) << 5;
	wynik |= (static_cast<uint32_t>(d.aktywna) &0x01) << 4;
	wynik |= (static_cast<uint32_t>(d.estymowana) &0x01) << 3;
	wynik |= (static_cast<uint32_t>(d.wczytana) &0x01) << 1;

	return wynik;
}

Dane Dekompresuj(uint32_t skompresowane) {
	Dane d;
	std::memset(&d, 0, sizeof(Dane));
	
	d.symbol = static_cast<unsigned char>((skompresowane) &0xFF >> 23);
	d.liczba = static_cast<short>((skompresowane) &0xFFFF >> 8);
	d.obliczona = static_cast<bool>((skompresowane) &0x01 >> 5);
	d.aktywna = static_cast<bool>((skompresowane) &0x01) >> 4);
	d.estymowana = static_cast<bool>((skompresowane) &0x01 >> 3);
	d.wczytana = static_cast<bool>((skompresowane) &0x01 >> 1);
}

int main()
{
	 
	Dane test;

	wypelnij(test, 51, "X", 0, 1, 0, 1);
	
	uint32_t skompresowane = kompresuj(test);
	Dekompresuj(skompresowane);

	operator==(skompresowane, test);


	

}

#endif
