# Game of Live 


Projekt "gry w życie" przygotowany na zajęcia programowania obiektowego

realizuje program klasycznej automaty z zasadami opracowanymi przez Johna Conwaya


## zasady automaty
<li>martwa komórka, która ma dokładnie 3 żywych sąsiadów, staje się żywa w następnej jednostce czasu (rodzi się)

<li>żywa komórka z 2 albo 3 żywymi sąsiadami pozostaje nadal żywa

<li>przy innej liczbie sąsiadów umiera (z „samotności” albo „zatłoczenia”)


<br>więcej pod adresem 
 [gra w życie ](https://pl.wikipedia.org/wiki/Gra_w_%C5%BCycie)

## wymagania sprzętowe 
<li> System wondows 10



## sorce
całość projeku dostępna jest pod adresem 
[game of life](https://github.com/piotr233/gol)

<li>projekt napisany jest w standardzie c++ 17 
<li>skompilowane przy uzyciu Microsoft Visual c++
<br>

## sposób użycia 
1. należy zadeklarować obiekt silnika gry <br>
  ```  
   int x, y;

    x = 7; // gra będzie miała wyokość 7 komórek 
    y = 7; // szerokość 7 komórek
    game_engine life(x, y);
```
2. następnie należy nadać planszy startowe wartości <br>
```   
    life.get_cell(2,3) = true;
    life.get_cell(3,4) = true;
    life.get_cell(4,4) = true;
    life.get_cell(4,3) = true;
    life.get_cell(4,2) = true;
   
```
3. stwożyć silnik graficzny
```
    console_win game(&life); // przekazujemy mu wskaźnik na grę 
```
4. uruchomić grę 
```     
    game.play(1000); // gra będzie wyświetlała klatę co 1s 
```

działający przykład załączony jest w pliki main.cpp 
