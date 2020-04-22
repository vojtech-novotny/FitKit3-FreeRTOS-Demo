# Demo aplikace nad FreeRTOS pro platformu FITKit3

### Funkcionalita
 - Každému ze 4 hlavních tlačítek je přiřazena jedna dioda.
 - Každým stisknutím tlačítka se příslušná dioda rozsvítí a svítí právě jednu sekundu.
 - Opakovaným stisknutím se čas prodlouží o jednu sekundu za každé stisknutí.

Toto demonstruje použití základních funkcí RT OS.
 - Task (úkoly) - jsou využity k obsluze led diod.
 - Přerušení - jsou využity k obsluze tlačítek.
 - Semafory - jsou využity ke spouštění úkolů.
 - Časovače - jsou využity k načasování 1 sekundy.
