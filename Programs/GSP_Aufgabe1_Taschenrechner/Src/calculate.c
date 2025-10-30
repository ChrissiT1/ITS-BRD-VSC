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
 
#include "calculate.h"
#include "stack.h"
#include "display.h"
#include "terminal.h" 
#include "token.h"
#include "util.h"
#include "handleerror.h"

// Stack leeren, indem der Index der obersten Position auf -1 gesetzt wird
void stackClear() {
	top = -1;
}

/**
 * @brief Führt eine arithmetische Operation (+, -, *, /) auf den obersten zwei Stackwerten aus.
 * 
 * Poppt zwei Werte vom Stack, führt die Operation aus und pusht das Ergebnis wieder auf den Stack.
 * Bei Fehlern (z. B. Division durch 0 oder zu kleiner Stack) wird ein Fehlercode zurückgegeben.
 *
 * @param operation Das Operationszeichen (+, -, *, /)
 * @return int OK bei Erfolg, sonst Fehlercode
 */
int executeOperation(char operation) {
    int operand2;      // Zweites Operand vom Stack
    int operand1;      // Erstes Operand vom Stack
    int result = 0;    // Ergebnis der Operation

		// Operand 2 vom Stack holen
		result = pop(&operand2);
		if (result != OK) {
			return result;  // Fehler beim Pop (z. B. Stack leer)
		}
		// Operand 1 vom Stack holen
		result = pop(&operand1);
		if (result != OK) {
			return result;  // Fehler beim Pop
		}
    
    // Auswahl der Operation anhand des übergebenen Operators
    switch (operation) {
        case PLUS:
            result = operand1 + operand2;  // Addition
						printStdout("Operation: Addition\n");
            break;
        case MINUS:
            result = operand1 - operand2;  // Subtraktion
						printStdout("Operation: Subtraktion\n");
            break;
        case MULT:
            result = operand1 * operand2;  // Multiplikation
						printStdout("Operation: Multiplikation\n");
            break;
        case DIV:
            if (operand2 != 0) {
                result = operand1 / operand2;  // Division, nur wenn Operand2 != 0
								printStdout("Operation: Division\n");
            } else {
                return DIVBYNULL; // Fehler: Division durch Null
            }
            break;
        default:
            return ILLEGALOP; // Fehler: unbekannte Operation
    }
    
    // Ergebnis zurück auf den Stack legen
    push(result);
		return OK;
}


/**
 * @brief Führt Stack-Funktionen aus (p, P, C, d, r)
 * 
 * - p : oberstes Element ausgeben
 * - P : gesamten Stack ausgeben
 * - C : Stack löschen
 * - d : oberstes Element duplizieren
 * - r : die obersten zwei Elemente tauschen
 * 
 * @param function Funktionskennzeichen ('p', 'P', 'C', 'd', 'r')
 * @return int OK bei Erfolg, sonst Fehlercode
 */
int executeFunction(char function) {
    switch (function) {
				int result = 0;
        case 'p':
						if (top >= 0) {
								// oberstes Element ausgeben
								char num_str[20];  
								result = int_to_str(stack[top], num_str); // int in String konvertieren
								if (result != OK) return result;
								
								printStdout(num_str);
								printStdout(" \n");
								printStdout("Oberstes Element ausgegeben\n");
						} else {
								return STACKNULL; // Stack leer
						}
						break;
        case 'P':
            // gesamten Stack ausgeben
            printStdout("Stack: ");
            for (int i = 0; i <= top; i++) {
                char num_str[20];
                result = int_to_str(stack[i], num_str);
								if (result != OK) return result;
								
								printStdout(num_str);
								printStdout(" ");
            }
            printStdout("\n");
            break;
        case 'C':
            // Stack leeren
            stackClear();
						printStdout("Stack cleared\n");
            break;
        case 'd':
						// oberstes Element duplizieren
						if (top >= 0) {
								push(stack[top]);
								printStdout("Oberstes Element dupliziert\n");
						} else {
								return STACKNULL; // Stack leer
						}
						break;
        case 'r':
            // oberste zwei Elemente tauschen
            if (top >= 1) {
                int temp = stack[top];
                stack[top] = stack[top - 1];
                stack[top - 1] = temp;
								printStdout("Obersten zwei Elemente getauscht\n");
            } else {
                return SWAPTOSMALL; // nicht genug Elemente zum Tauschen
            }
            break;
        default:
						return ILLEGALFUNC; // unbekannte Funktion
    }
		return OK;
}


/**
 * @brief Liest Token ein und führt die passende RPN-Operation aus
 * 
 * - Token kann Zahl, Operator oder Funktion sein
 * - Ruft die entsprechenden Funktionen (push, executeOperation, executeFunction) auf
 * - Gibt Fehlercodes direkt zurück
 * 
 * @return int OK bei Erfolg oder Fehlercode bei unerwarteter Eingabe
 */
int evaluateRPN() {
    T_token token;
    
    token = nextToken();  // nächstes Token einlesen
        
    switch (token.tok) {
        case NUMBER:
            return push(token.val);  // Zahl auf Stack legen
        case PLUS:
        case MINUS:
        case MULT:
        case DIV:
            return executeOperation(token.tok);  // arithmetische Operation ausführen
        case 'p':
        case 'P':
        case 'C':
        case 'd':
        case 'r':
            return executeFunction(token.tok);  // Stack-Funktion ausführen
        case UNEXPECTED:
            return UNEXPECTEDINPUT;  // unerwartetes Token
        case OVERFLOW:
            return INPUTOVERFLOW;    // Eingabeüberlauf
        case ENTER:
        default:
            return OK;  // Ende der Eingabe oder keine Aktion
    }
}
