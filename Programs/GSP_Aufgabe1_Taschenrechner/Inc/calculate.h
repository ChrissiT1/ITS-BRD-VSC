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
 
#ifndef EVALUATION_H
#define EVALUATION_H


#include "token.h"  // Enthält Definitionen für Token-Strukturen und Token-Typen

// Funktionsprototypen für den RPN-Rechner

/**
 * @brief Leert den Stack.
 *
 * Setzt den Stack-Zeiger 'top' auf -1, damit der Stack als leer gilt.
 */
void stackClear();

/**
 * @brief Führt eine arithmetische Operation (+, -, *, /) auf den obersten Stackwerten aus.
 *
 * @param operation Der Operator als Zeichen
 * @return int OK bei Erfolg, sonst Fehlercode
 */
int executeOperation(char operation);

/**
 * @brief Führt eine Stack-Funktion aus (p, P, C, d, r).
 *
 * @param function Funktionszeichen
 * @return int OK bei Erfolg, sonst Fehlercode
 */
int executeFunction(char function);

/**
 * @brief Liest Tokens ein und wertet sie als RPN aus.
 *
 * Unterscheidet Zahlen, Operatoren und Funktionen und ruft die passenden Funktionen auf.
 *
 * @return int OK bei Erfolg, sonst Fehlercode
 */
int evaluateRPN();

/**
 * @brief Liest das nächste Token ein.
 *
 * @return T_token Struktur mit Token-Typ und Wert
 */
T_token nextToken();

#endif /* EVALUATION_H */

// EOF

