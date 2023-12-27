# Egzaminas
Šiame darbe buvo panaudoti asociatyvi konteineriai, nes šitam uždaviniui
jie yra efektyvesni ir labiau tinkami lyginant su sekos konteineriais.
Darbo tikslas yra sukurti tokia funkcijas, kurie gali dirbti su tekstais,
straipsniais. Funkcijos turi galimybe ieškot žodžius tekste, skaičiuot
kiek kartu jie atsiranda tekste, rodyt kurioje eilutėje iš teksto tie
žodžiai yra ir dar ieškot URL adresus, jei tokie yra.

# Sukurtos funkcijos
Darbui buvo sukurtos 9 funkcijos.
1. Funkcija isNumber, kuri padeda funkcijai countWords ištrint numerius,
nes ieškom žodžius.
2. Funkcija isCustomPunct, kuri ištrina iš teksto punktuacijos simbolius.
3. Funkcija toLowerLT, kuri leidžia programai veikt su lietuviškomis raidėmis
ir taip pat pakeičia teksto raides į mažasias tam, kad tiksliau ieškot vienodus
žodžius tekste.
4. Funkcija UTF8, kuri padeda rezultatų išvedimui. Dėl Lietuviškų raidžių
išvedimas nelygiai išvedė rezultatus, su šita funkcija tos problemos nera.
5. Pati funkcija countWords, kuri surado žodžius tekste, kurie atsiranda
tekste daugiau nei vieną kartą.
6. Funkcija findWordLocations, kuri suranda žodžiams jų eilučių numerius ir
taip pat išveda rezultatus.
7. Funkcija Domains, kuri naudoja faila su domenais tam, kad irašyt visus
domenus į set tolesniu panaudojimui.
8. Funkcija isValidDomain, kuri užtikrina ar rastas URL adresas tekste turi
tinkama domeni.
9. Funkcija findURL, kuri suranda URL adresus tekste ir išveda rezultatus.
