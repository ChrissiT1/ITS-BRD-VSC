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
 
#include "stack.h"
#include "display.h"
#include "handleerror.h"

// Definition des Stacks als statisches Array
int stack[STACK_SIZE]; // Stack-Array mit maximaler Größe STACK_SIZE
int top = -1;          // Index des obersten Elements (-1 = Stack leer)

/**
 * @brief Legt einen Wert auf den Stack.
 *
 * Prüft, ob noch Platz im Stack ist. Wenn ja, wird der Wert oben auf den Stack gelegt.
 * Wenn der Stack bereits voll ist, wird ein Fehlercode zurückgegeben.
 *
 * @param value Zu speichernder Wert
 * @return int OK bei Erfolg, STACKOVERFLOW bei vollem Stack
 */
int push(int value) {
    if (top < STACK_SIZE - 1) { // Prüfen, ob noch Platz ist
        stack[++top] = value;   // Top erhöhen und Wert speichern
        return OK;              // Erfolg zurückgeben
    } else {
        return STACKOVERFLOW;   // Fehler: Stack ist voll
    }
}

/**
 * @brief Entfernt das oberste Element vom Stack und gibt es zurück.
 *
 * Liest das oberste Element aus dem Stack aus und verringert den Stackzeiger.
 * Wenn der Stack leer ist, wird ein Fehlercode zurückgegeben.
 *
 * @param[out] value Pointer auf Speicher, wo das gelesene Element abgelegt wird
 * @return int OK bei Erfolg, STACKUNDERFLOW bei leerem Stack
 */
int pop(int *value) {
    if (top >= 0) {            // Prüfen, ob Stack nicht leer ist
        *value = stack[top--];  // Wert auslesen und Top dekrementieren
        return OK;              // Erfolg
    } else {
        return STACKUNDERFLOW;  // Fehler: Stack ist leer
    }
}
// EOF
