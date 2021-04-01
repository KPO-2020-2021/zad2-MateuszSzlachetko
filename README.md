# Projekt 2 - Arytmetyka liczb zespolonych

## Budowanie programu i testów

W celu zbudowania programu należy zainstalować program cmake,przejść do folderu build

```bash
			cd build
```

użyć komendy

```bash
			cmake ..
```

która wygeneruje Makefile'e dla folderu z testami i plikami źródłowymi programu.Jeżeli proces się powiódł wystarczy użyć z poziomu folderu komendy

```bash
			make
```

Która wykona kompilację dla całego programu i dołączonych testów

## Uruchamianie programu

Aby uruchomić program z poziomu folderu build należy użyć następującej komendy

```bash
			./complex latwe/trudne
```

Gdzie latwe i trudne oznaczają poziomy trudności zadawanych przez program pytań.Gdyby użytkownik zapomniał wybrać jedną z dwóch opcji,program automatycznie przyjmie poziom na **latwe**,to samo stanie się w przypadku podania flagi błędnie.Gdyby brakowało potrzebnego pliku z wyrażeniami,program poinformuje o błędzie.

## Uruchamianie testów

Do uruchomienia testów z poziomu build należy przejść do folderu tst

```bash
			cd tst
```

i wywołać testy komendą

```bash
			./complex_tst
```

Jeżeli testy przebiegną pomyślnie program powinien zwrócić nastepujący komunikat.

```js
[----------] Global test environment tear-down
[==========] 34 tests from 16 test suites ran. (x ms total)
[  PASSED  ] 34 tests.
```

Powyższy ciąg komend można wywołać jednorazowo wklejając poniższą komendę do terminala

```bash
			cd build && cmake .. && make && cd tst && ./complex_tst && cd .. && ./complex latwe
```

W razie problemów proszę o kontakt <259370@student.pwr.edu.pl>

# Rozszerzenia

W programie zastosowałem oba rozszerzenia,skrócona notacja liczby zespolonej i wczytywanie wyrażeń z pliku.
Założyłem dodatkowo,że warunkiem poprawnego wczytania liczby zespolonej jest wpisanie jej (x+yi) i zatwierdzenia końcowo enterem,zapobiega to wpisywaniu nadmiarowych znaków po zamykającym nawiasie.Jednak w takim wypadku w celu poprawnego wczytywania wyrażeń z pliku po ostatnim wyrażeniu musi znajdować się pusta linia.

# Struktura repozytorium

&nbsp;&nbsp; [src](src/) - folder z plikami źródłowymi\
&nbsp;&nbsp; ├── [main.cpp](src/main.cpp) - główny plik main programu\
&nbsp;&nbsp; ├── [complex.cpp](src/Complex.cpp) - plik źródłowy dla klasy reprezentującej liczbę zespoloną\
&nbsp;&nbsp; ├── [complex_equation.cpp](src/complex_equation.cpp) - plik źródłowy dla klasy wyrażenia zespolonego\
&nbsp;&nbsp; ├── [exam.cpp](src/exam.cpp) - plik źródłowy dla funkcji wczytujących bazę pytań i przeprowadzającej sprawdzian\
&nbsp;&nbsp; └── [statistics.cpp](src/statistics.cpp) - plik źródłowy dla klasy statystki\
&nbsp;&nbsp; [inc](inc/) - folder z plikami nagłówkowymi\
&nbsp;&nbsp; ├── [complex.h](inc/complex.h) - plik nagłówkowy klasy complex\
&nbsp;&nbsp; ├── [complex_equation.h](inc/complex_equation.h) - plik nagłówkowy klasy complex_equation\
&nbsp;&nbsp; ├── [exam.h](inc/exam.h) - plik nagłówkowy dla funkcji sprawdzianu\
&nbsp;&nbsp; └── [statistics.h](inc/statistics.h) - plik nagłówkowy klasy statistics\
&nbsp;&nbsp; [tst](tst/) - zawiera pliki źródłowe testów\
&nbsp;&nbsp; ├── [CMakeLists.txt](tst/CMakeLists.txt) - cmake generujący makefile dla programu complex_tst\
&nbsp;&nbsp; ├── [test1.cpp](tst/test1.cpp) - plik zawierający testy **SUBTRACTION | ADDITION | MULTIPLICATION | DIVISION**\
&nbsp;&nbsp; ├── [test2.cpp](tst/test2.cpp) - plik zawierający testy **EQUALITY | COMPLEX CONJUGATE | SQUARE OF COMPLEX ABS**\
&nbsp;&nbsp; ├── [test3.cpp](tst/test3.cpp) - plik zawierający testy **STATISTICS | EQUATION SOLVER**\
&nbsp;&nbsp; ├── [test4.cpp](tst/test4.cpp) - plik zawierający testy **READ/SHOW COMPLEX | READ/SHOW EQUATION**\
&nbsp;&nbsp; ├── [test5.cpp](tst/test5.cpp) - plik zawierający testy **MODIFICATIONS**\
&nbsp;&nbsp; └── [main.cpp](tst/main.cpp) - plik main dla programu complex_tst\
&nbsp;&nbsp; [lib](lib/) - zawiera biblioteke googletest\
&nbsp;&nbsp; └── [googletest](lib/googletest) - folder z biblioteką googletest\
&nbsp;&nbsp; [build](build/) - zawiera pliki z wyrażeniami do testu\
&nbsp;&nbsp; ├── [latwe.dat](dtb/latwe.dat) - plik z łatwymi wyrażeniami\
&nbsp;&nbsp; └── [trudne.dat](dtb/trude.dat) - plik z trudnymi wyrażeniami\
&nbsp;&nbsp; [man](man/) - instrukcje do zadania oraz inne pomoce naukowe\
&nbsp;&nbsp; [CMakeLists.txt](CMakeLists.txt) - cmake generujący makefile dla programu complex\
&nbsp;&nbsp; [.gitignore](.gitignore) - plik określający, które pliki mają być ignorowane przez Gita\
