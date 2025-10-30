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
 
#ifndef STACK_H
#define STACK_H

// Maximale Größe des Stacks
#define STACK_SIZE 100

// Externe Deklarationen, damit andere Module auf den Stack zugreifen können
extern int stack[STACK_SIZE]; // Array für die Stack-Werte
extern int top;               // Index des obersten Elements (-1 = Stack leer)

/**
 * @brief Legt einen Wert auf den Stack.
 *
 * Prüft, ob noch Platz im Stack ist. Falls ja, wird der Wert oben abgelegt.
 *
 * @param value Zu speichernder Wert
 * @return int OK bei Erfolg, STACKOVERFLOW bei vollem Stack
 */
int push(int value);

/**
 * @brief Entfernt das oberste Element vom Stack und gibt es zurück.
 *
 * Liest das oberste Element aus dem Stack aus und dekrementiert den Stackzeiger.
 *
 * @param[out] value Zeiger, wo das gelesene Element gespeichert wird
 * @return int OK bei Erfolg, STACKUNDERFLOW bei leerem Stack
 */
int pop(int *value);

#endif /* STACK_H */
// EOF

