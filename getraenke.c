/** @file getraenke.c
 *  @brief Software für einen Getränkeautomaten - Schritt für Schritt wird hier ein Programm erweitert, verbessert und
 *  regelmäßig einem Refactoring unterzogen.
 *  Die aktuelle Variante sieht vor alle Funktionen in functions zu abstrahieren.
 *  @version 0.5 Created functions and prototyping functions to tidy up the code and make the whole thing more readable.
 *  @author Christian Müller
 *  @bug Bisher sind keine Bugs bekannt!
 *  @details
 *
        Getraenke Automat v0.5

        Waehlen sie ihr Getraenk aus:
        1) Wasser (0,50 Euro)
        2) Limonade (1,00 Euro)
        3) Bier (2,00 Euro)

        Geben sie 1, 2 oder 3 ein: 2

        Geben sie die gewuenschte Menge ein: 1

        --- Bezahlvorgang ---

        Bezahlvorgang abbrechen mit 0

        Es fehlen noch 1.00 Euro.
        Bitte werfen sie ein Geldstueck ein: 3

        Ihr Geldstueck ist ungueltig.
        Es fehlen noch 1.00 Euro.
        Bitte werfen sie ein Geldstueck ein: 0

        Bezahlvorgang abgebrochen.
        Ausgabe von 0.00 Euro.

        Function Prototype
        x-> Ausgabe Getränkeangebot
        x-> Lese Eingabe Getränk
        x-> Ausgabe Anzahl Getränke
        x-> Lese Eingabe Anzahl
        -> Berechne Gesamtpreis
        x-> Ausgabe Betrag zu zahlen * ausgabeBetrag()
        x-> Lese Eingabe zu Münzeinwurf
        -> Berechne Betrag zu zahlen * evtl. mit Gesamtpreis kombinierbar
        -> Lese Eingabe zu Münzeinwurf
        -> Schleife bis Betrag gezahlt ist
        x-> Ausgabe Für Betrag gezahlt, zuviel bezahlt, zu wenig bezahlt * ausgabeBetrag()
        x-> Ausgabe Getränkeausgabe
*/

#include <stdio.h>

void outOffer();
void outDelivery(int);
void outToPay(float);
void outAmount();
int payment(float);

int readKey();
float readFKey();
int checkCoin(float);
float calculatePrice(int, float);
float setPrice(int);


int main(int argc, char const *argv[])
{
int auswahl, anzahl;
float preis, gesamt;

outOffer(); // Ausgabe Getränkeangebot
auswahl = readKey();

preis = setPrice(auswahl);


outAmount(); // Mengenabfrage
anzahl = readKey();

gesamt = calculatePrice(anzahl, preis); // berechnet Gesamtbetrag

outToPay(gesamt); // Ausgabe des Betrags

if(payment(gesamt)) {
    outDelivery(anzahl);
}


    return 0;
}

/** @brief Ausgabe des Getränkeangebots
 *  @param none
 *  @return none
*/
void outOffer() {
printf("Waehlen sie ihr Getraenk aus:\n\n");
printf("1) Wasser (0,50 Euro)\n");
printf("2) Limonade (1,00 Euro)\n");
printf("3) Bier (2,00 Euro)\n");
printf("\nGeben sie 1, 2 oder 3 ein:\n");
}

/** @brief Ausgabe zur Anzahl der Getränke
 *  @param none
 *  @return none
*/
void outAmount() {
    printf("\nBitte geben Sie die Anzahl der gewünschten Getränke an!\n");
}

/** @brief Ausgabe zum Betrag zu bezahlen
 *  @param float Der Betrag der ausgegeben werden soll
 *  @return none
*/
void outToPay(float f) {
    printf("\nBitte bezahlen Sie %.2f Euro ein\n", f);
}

/** @brief Ausgabe der Getränke
 *  @param int Die Anzahl an Getränken die Ausgegeben wird
 *  @return none
*/
void outDelivery(int a) {
    printf("\nVielen Dank für Ihren Einkauf, bitte entnehmen Sie ihre Getränke.");
    int i;
    for (i = 1; i <= a; i++)
    {
        printf("\nBitte entnehmen Sie Flasche %d ", i);
        printf("von %d Getränkebehältern.", a);
    }
}

/** @brief Abbezahlen des übergebenen Betrags
 *  @param float Der abzuzahlende Betrag
 *  @return int (bool) falls prozess erfolgreich ist oder nicht
*/
int payment(float p) {
    float konto = 0.0;
    float e;
    do
    {
        e = readFKey();
        if (e == 0)
        {
            printf("Abbruch des Bezahlvorgangs... \n\n");
            break;
        } else
        {
            if (checkCoin(e))
            {
                printf("Münze ist valide\n\n");
                konto += e;

                if (konto < p)
                {
                    printf("\nKaufpreis noch nicht erreicht, bitte werfen Sie noch %.2f Euro ein!\n", p - konto);

                } else if (konto == p)
                {
                    printf("Vielen Dank für Ihren Einkauf, die Getränke werden in Kürze ausgegeben");
                }
                else
                {
                    printf("\nSie haben zuviel Geld eingeworfen und erhalten %.2f Euro zurück", konto - p);
                }
            } else {
                printf("Die Münze ist nicht gültig... Such ne Richtige!!\n\n");
            }
        }
    } while (konto < p);

    // ist das zeug bezahlt?
    if (konto - p < 0.0001 && konto - p >= 0)
    {
        return(1);
    } else
    {
        return(0);
    }



}

/** @brief Gibt die Eingabe über Tastatur in int aus
 *  @param none
 *  @return int
*/
int readKey() {
    int key;
    scanf("%d", &key);
    return (key);
}

/** @brief Gibt die Eingabe über Tastatur in float aus
 *  @param none
 *  @return float
*/
float readFKey() {
    float key;
    scanf("%f", &key);
    return (key);
}

/** @brief Überprüft die Eingabe ob die Münzen entsprechend gültig sind - Interessanter Aspekt ist hier der
 *  Vergleich von float Werten. Ziehe den zu vergleichenden Wert von der Eingabe ab und überprüfe ob das
 *  Ergebnis kleiner als 0.0001 ist aber auch größer gleich 0.
 *  @param float Wert der mit den gültigen Münzen verglichen wird
 *  @return int (bool) 1 für true 0 für false
 */
int checkCoin(float coin) {
//    funktion um Münzen zu prüfen eingabe - Münze < 0.0001
    if (coin - 0.05 < 0.0001 && coin - 0.05 >= 0)
    {
        return(1);
    } else if (coin - 0.10 < 0.0001 && coin - 0.10 >= 0)
    {
        return(1);
    } else if (coin - 0.20 < 0.0001 && coin - 0.20 >= 0)
    {
        return(1);
    } else if (coin - 0.50 < 0.0001 && coin - 0.50 >= 0)
    {
        return(1);
    } else if (coin - 1.00 < 0.0001 && coin - 1.00 >= 0)
    {
        return(1);
    } else if (coin - 2.00 < 0.0001 && coin - 2.00 >= 0)
    {
        return(1);
    } else
    {
        return(0);
    }


}

/** @brief Berechnet den Preis
 *  @param int Anzahl ganze Zahlen
 *  @param float Preis des Getränks im Format %.2f
 *  @return float
*/
float calculatePrice(int a, float b) {
    return(a*b);
}

/** @brief Gibt den Preis anhand des Parameters Auswahl zurück
 *  @param int Auswahl Sorte ganze Zahlen
 *  @return float
*/
float setPrice(int i) {
    float preis;
    switch (i)
    {
    case 1:
        preis = 0.5;
        break;
    case 2:
        preis = 1;
        break;
    case 3:
        preis = 2;
        break;
    default:
        printf("Abbruch, keine gültige Eingabe\n");
        break;
    }
    return(preis);
}
