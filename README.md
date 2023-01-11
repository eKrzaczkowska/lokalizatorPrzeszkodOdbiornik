# Projekt bezprzewodowego lokalizatora dla osób głucho-niewidomych
## Ewa Krzaczkowska

Biała laska ułatwia wykrywanie obiektów występującyc poniżej linii kolan. Zbudowany prototyp lokalizatora przeszkód będzie narzędziem wspomagającym. Jego zadaniem jest analiza otoczenia powyżej poziomu biodra. W skonstruowanym urządzeniu skupiono się na wykrywaniu obiektów w odległości 60 cm. Od tej odległości silnik zacznie wibrować zwiększając swoją szybkość co 10 cm.  

Ostateczna wersja urządzenia będzie składała się z dwóch osobnych podzespołów: nadajnika i odbiornika. Komunikacja między nimi będzie odbywać się przy pomocy modułów radiowych nrf24L01. Część nadawcza będzie wyposażona w czujnik ultradźwiękowych i przy pomocy mikroprocesora będzie wykonywała pomiary odległości w odstępie 10 ms. Jeżeli dystans od obiektu będzie się zmniejszał to przy określonej granicznej wartości, będzie wysyłana o tym informacja do odbiornika. W urządzeniu odbiorczym należy sprawdzić czy została odebrana wiadomość. Jeżeli tak, to zgodnie z jej treścią będzie można przy pomocy modulacja PWM zmieniać szybkość wibrowania silnika.  

W celu realizacji tego urządzenia należy zaopatrzyć się w odpowiednie elementy elektroniczne. Tabela zawiera spis wszystkich wymaganych podzespołów.  

|ELEMENT|NAZWA|
|-------|-----|
|Mikroprocesor x2|Atmega8A|
|Moduł radiowy x2|nRF24L01|
|Stabilizator napięcia x2|LF33CV|
|Czujnik ultradźwiękowy|Grove 2.0|
|Silnik wibracyjny|C1030B015F|
|Programator x2|USBasp v 2.0|
|Tranzystor NPN|CT2N3904|
|RLC| 4x 100nF;  2x 10nF;  4x 2.2uF;  2x 22uF;  2x 10kΩ;  3x 0 kΩ;  2x 100uH|  

## Schematy płytek
![image](https://user-images.githubusercontent.com/112576532/211834005-406f2f0f-1e85-4e70-a67d-7f5becad4251.png)
![image](https://user-images.githubusercontent.com/112576532/211834048-b014fc7e-a113-47f4-8403-d6b049ea180a.png)

