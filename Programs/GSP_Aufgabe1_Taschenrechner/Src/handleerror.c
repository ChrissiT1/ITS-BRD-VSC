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
 
#include "handleerror.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "display.h"
#include "token.h"
#include "util.h"
#include "stack.h"
#include "calculate.h"
#include "main.h"


/**
 * @brief Gibt eine Fehlermeldung aus und wartet auf Benutzerbestätigung.
 *
 * Die Funktion erhält einen Fehlercode, erstellt eine passende Fehlermeldung,
 * gibt diese auf der Standardausgabe aus und wartet darauf, dass der Benutzer 'C' drückt.
 * Danach wird der Stack geleert und die Berechnung erneut gestartet.
 *
 * @param err Fehlercode, z. B. STACKOVERFLOW, DIVBYNULL, ILLEGALOP, etc.
 */
void handleError(int err) {
    char fullMessage[100];   // Gesamte Fehlermeldung: "Error: <Fehlermeldung>"
    char errorMessage[40];   // Platz für die spezifische Fehlermeldung

    // Grundprefix der Fehlermeldung setzen
    strcpy(fullMessage, "Error: ");

    // Fehlercode in verständliche Fehlermeldung übersetzen
    switch(err) {
        case STACKOVERFLOW:
            strcpy(errorMessage, "Stack overflow");  // Stack hat zu viele Elemente
            break;
        case STACKUNDERFLOW:
            strcpy(errorMessage, "Stack underflow"); // Pop auf leerem Stack
            break;
        case DIVBYNULL:
            strcpy(errorMessage, "Geteilt durch Null"); // Division durch 0
            break;
        case ILLEGALOP:
            strcpy(errorMessage, "Ungueltige Operation"); // Nicht erlaubter Operator
            break;
        case STACKNULL:
            strcpy(errorMessage, "Stack ist leer"); // Zugriff auf leeren Stack
            break;
        case SWAPTOSMALL:
            strcpy(errorMessage, "Nicht genuegend Elemente zum Tauschen"); // Swap mit zu wenig Elementen
            break;
        case ILLEGALFUNC:
            strcpy(errorMessage, "Ungueltige Funktion"); // Funktion existiert nicht
            break;
        case UNEXPECTEDINPUT:
            strcpy(errorMessage, "Unerwartete Eingabe"); // Token konnte nicht interpretiert werden
            break;
        case INPUTOVERFLOW:
            strcpy(errorMessage, "Eingabe Overflow"); // Eingabe zu lang oder zu groß
            break;
        case CALCOVERFLOW:
            strcpy(errorMessage, "Overflow"); // Ergebnis zu groß für int
            break;
    }

    // Spezifische Fehlermeldung an das Prefix anhängen
    strcat(fullMessage, errorMessage);
    strcat(fullMessage, "\n");

    // Fehlermeldung ausgeben
    printStdout(fullMessage);
    printStdout("Drueke 'C' um fortzufahren.\n");

    // Endlosschleife, bis Benutzer 'C' drückt
    T_token token;
    while (1) {
        token = nextToken();  // Nächstes Token einlesen
        if (token.tok == 'C') {
            // Benutzer hat 'C' gedrückt: Stack leeren und Berechnung erneut starten
            stackClear();  // Stack zurücksetzen
            loop();        // Berechnungsschleife neu starten
        } else {
            // Benutzer hat nicht 'C' gedrückt, Hinweis wiederholen
            printStdout("Drueke 'C' um fortzufahren.\n");
        }
    }
}