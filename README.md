# Egzaminas
Šiame darbe buvo panaudoti asociatyvi konteineriai, nes šitam uždaviniui
jie yra efektyvesni ir labiau tinkami lyginant su sekos konteineriais.
Darbo tikslas yra sukurti tokia funkcijas, kurie gali dirbti su tekstais,
straipsniais. Funkcijos turi galimybe ieškot žodžius tekste, skaičiuot
kiek kartu jie atsiranda tekste, rodyt kurioje eilutėje iš teksto tie
žodžiai yra ir dar ieškot URL adresus, jei tokie yra.

# Panaudotas tekstas
Šiam užduočiui naudojau teksta iš vikipedijos apie Europos Sąjunga:
https://lt.wikipedia.org/wiki/Europos_S%C4%85junga
Iš šito puslapio tik nebuvo įkeltas į teksto dalį skyrius "Istorija ir plėtra",
nes ten mažai žodžių ir tekstas yra su integruotais paveiksleliais.
Be to skyrio teksto žodžių skaičius yra: 1665.

# Panaudoti domenai
Kadangi URL suradimui naudojau domenus, kad surast tinkamus URL adresus
net jeigu nera adreso protokolo, naudojau domenus iš šito puslapio:
https://www.iana.org/domains/root/files Ten yra atskiras failas su visais
surašytais domenais, kuris yra dažnai atnaujinamas, jei atsiranda nauji
domenai.

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

# Naudojimosi instrukcija
Iš pradžių bus klausimas, ar mes norim išvest rezultatą dar į ekraną, jei
ivest T, tai kai programa atliks veiksmus mes matysim rezultatus ne tik
atskirame faile, bet ir iškart ekrane.
Paleidžiant programą, yra 3 pasirinkimai:
1. Jei norite surast žodžius iš teksto, kurie kartojasi daugiau nei vieną kartą,
iveskite K. Šiuo atvėju reikės ivest failo su teksta pavadinima ir failo pavadinima,
į kuri norite išvest rezultatus.
2. Jei norite surast eilučių numerius žodžių, kurie kartojasi daugiau nei vieną kartą,
iveskite E. Šiuo atvėju irgi reikės ivest failo su teksta pavadinima ir failo pavadinima,
į kuri norite išvest rezultatus.
3. Jei norite surast URL adresus iš teksto, iveskite L. Šiuo atvėju dar reikės pateikt
domenų failo pavadinima, kuriame bus tie domenai, kuriu adresus jus norite surast. Kaip
ir kitais atvejais po to ivedamas teksto failo pavadinimas ir išvedimo failo pavadinimas.


# Kaip atrodo rezultatai
Tokius rezultatus išveda funkcijos countWords, findWordLocations ir findURL:

![image](https://github.com/RatmirSemionov/Egzaminas/assets/144428344/2f15f767-e457-4201-b8df-99d74ba2648a)
