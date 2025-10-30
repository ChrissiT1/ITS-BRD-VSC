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
 
#ifndef HANDLEERROR_H
#define HANDLEERROR_H
#define OK 0
#define STACKOVERFLOW 1
#define STACKUNDERFLOW 2
#define DIVBYNULL 3
#define ILLEGALOP 4
#define STACKNULL 5
#define SWAPTOSMALL 6
#define ILLEGALFUNC 7
#define UNEXPECTEDINPUT 8
#define INPUTOVERFLOW 9
#define CALCOVERFLOW 10



#include <errno.h>  // Für Standard-Fehlercodes (optional, je nach Implementierung)

/**
 * @brief Gibt eine Fehlermeldung aus und wartet auf Benutzerbestätigung.
 *
 * Die Funktion empfängt einen Fehlercode, erzeugt eine passende Fehlermeldung,
 * gibt diese auf der Standardausgabe aus und wartet darauf, dass der Benutzer 'C' drückt,
 * bevor der Stack geleert und die Berechnung erneut gestartet wird.
 *
 * @param err Fehlercode, z. B. STACKOVERFLOW, DIVBYNULL, ILLEGALOP, etc.
 */
void handleError(int err);

#endif /* HANDLEERROR_H */

