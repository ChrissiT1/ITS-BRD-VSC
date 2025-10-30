/**
 ******************************************************************************
 * @file    main.c
 * @author  Christoph Tank, 2713845
 *			Hendrik Tank, 2744601	
 *
 * @version 1.0
 *
 * @date    25. Oktober 2025
 * @brief   Aufgabe 1: Reverse Polish Notation Taschenrechner auf dem ITS-Board
 *
 ******************************************************************************
 */
 
#include "util.h"
#include "handleerror.h"
#include "limits.h"

/**
 * @brief Wandelt eine Ganzzahl in einen String um.
 *
 * Konvertiert die übergebene Zahl `num` in einen nullterminierten String und speichert
 * ihn im übergebenen Puffer `str`. Berücksichtigt auch negative Zahlen und INT_MIN.
 *
 * @param num Die zu konvertierende Ganzzahl
 * @param str Zeiger auf den Puffer, in den der String geschrieben wird
 * @return int OK bei Erfolg
 */
int int_to_str(int num, char *str) {
    // Spezialfall: Zahl ist 0
    if (num == 0) {
        str[0] = '0';    // Einzelne Ziffer '0' speichern
        str[1] = '\0';   // String terminieren
        return OK;
    }

    // Sonderfall: INT_MIN prüfen, bevor num negiert wird
    // Grund: -INT_MIN würde einen Overflow erzeugen (zu groß für int)
    if (num == INT_MIN) {
        char min[] = "-2147483648";
        for (int i = 0; min[i] != '\0'; i++) {
            str[i] = min[i];  // Zeichen für Zeichen kopieren
        }
        str[11] = '\0';  // String terminieren (optional, da min bereits nullterminiert ist)
        return OK;
    }

    int index = 0;       // Zähler für die Position im String
    int is_negative = 0; // Flag, ob die Zahl negativ ist

    // Prüfen, ob die Zahl negativ ist
    if (num < 0) {
        is_negative = 1;  // Flag setzen
        num = -num;       // Betrag bilden
    }

    // Anzahl der Ziffern ermitteln
    int temp = num;
    while (temp != 0) {
        temp /= 10; // Letzte Ziffer entfernen
        index++;    // Anzahl der Ziffern erhöhen
    }

    // Platz für '-' reservieren, falls negativ
    if (is_negative) {
        index++;
    }

    str[index] = '\0';   // String am Ende terminieren
    index--;             // Index auf die letzte Stelle setzen

    // Ziffern von hinten nach vorne eintragen
    while (num != 0) {
        str[index] = (num % 10) + '0'; // Letzte Ziffer in ASCII umwandeln
        num /= 10;                     // Ziffer entfernen
        index--;                       // Zum nächsten Platz nach links gehen
    }

    // Falls negativ: '-' an erster Stelle einfügen
    if (is_negative) {
        str[0] = '-';
    }

    return OK; // Erfolgreiche Konvertierung
}