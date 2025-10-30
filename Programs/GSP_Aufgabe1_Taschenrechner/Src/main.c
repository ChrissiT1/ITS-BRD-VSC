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

#include <stdio.h> 
#include "stm32f4xx_hal.h" 
#include "init.h" 
#include "lcd.h" 
#include "errno.h" 
#include "keypad.h" 
#include "scanner.h" 
#include "display.h" 
#include "terminal.h" 
#include "token.h"
#include "stack.h"
#include "calculate.h"
#include "handleerror.h"

void loop();

/**
 * @brief Hauptschleife des RPN-Taschenrechners.
 *
 * Startet die Eingabe-/Auswerteschleife, liest Token ein und wertet diese mit evaluateRPN() aus.
 * Bei Fehlern wird handleError() aufgerufen, um die Fehlermeldung auszugeben.
 */
int main(void) {
    initITSboard(); // Initialisierung des ITSBoards
    initDisplay(); // Initialisierung des Displays
    
		loop();
}


/**
 * @brief Einstiegspunkt des Programms.
 *
 * Initialisiert das ITS-Board und das Display, startet anschließend die Hauptschleife.
 *
 * @return int Rückgabewert für das Betriebssystem (normalerweise 0).
 */
void loop(){
		printStdout("RPN Taschnrechner\n");
	int err = 0;
		while (1) { // Endlosschleife für wiederholtes Aufrufen von evaluateRPN()
        err = evaluateRPN();
				if(err != OK) {
					handleError(err);
				}
    }
}

// EOF
