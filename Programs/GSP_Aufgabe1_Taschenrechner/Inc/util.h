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
 
#ifndef UTIL_H 
#define UTIL_H 
#define INT_MIN 
#define INT_MAX

/**
 * @brief Wandelt eine Ganzzahl in einen String um.
 *
 * Konvertiert die übergebene Zahl `num` in einen nullterminierten String
 * und speichert sie im übergebenen Puffer `str`.
 *
 * @param num Die zu konvertierende Ganzzahl
 * @param str Zeiger auf den Puffer, in den der String geschrieben wird
 * @return int OK bei Erfolg
 */
int int_to_str(int num, char *str);

#endif /* UTIL_H */

