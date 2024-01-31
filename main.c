/** @file main.c
 *  @brief Projektdatei für allerlei Spielerei im Kontext meines C Kurses.
 *  Struktur eines Programms
 *  - Eingabe der zu multiplizierenden Zahlen
 *  - Zahlen Verarbeiten
 *  - Ergebnis auf dem Terminal ausgeben
 *  @author Christian Müller
 *  @bug Bisher sind keine Bugs bekannt!
*/

#include <stdio.h>

/** @brief Funktionsdeklaration
*/
float eingabeZahl();
float multipliziereZahlen(float, float);
void ausgabe(float);

int main()
{
    ausgabe(multipliziereZahlen(eingabeZahl(), eingabeZahl() ) );
    return 0;
}



/** @brief Funktion die die Parameter addiert
 *  @param int
 *  @param int
 *  @return int
*/
int addiere(int a, int b) {
    return (a + b);
}

/** @brief Funktion Zur Eingabe von Zahlen
 *  @return float, die Eingabe direkt als float.
*/
float eingabeZahl() {
    float eingabe;
    printf("Bitte geben Sie eine Zahl ein\n");
    scanf("%f", &eingabe);
    return eingabe;
}

/** @brief Multipliziere zwei Zahlen
 *  @param float
 *  @param float
 *  @return float
*/
float multipliziereZahlen(float a, float b) {
    return (a*b);
}

/** @brief Ausgabefunktion
 *  @param float
 *  @return void, kein Rückgabewert der Funktion
*/
void ausgabe(float a) {
    printf("\nDas Ergebnis lautet %f\n", a);
}
