/*
 * SPI1.c
 *
 *  Created on: Jul 3, 2015
 *      Author: John
 */

#include "SPI1.h"

void SPI1_Init()
{
	P1SEL  |= SPI1CLK_PIN + SPI1SIMO_PIN;
	P1SEL2 |= SPI1CLK_PIN + SPI1SIMO_PIN;

	//P1DIR |= BIT2 + BIT4;

	UCA0CTL1 = UCSWRST;
	UCA0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC;
	//UCA0BR0 |= 8; // /2
	//UCA0BR1 = 0;
	UCA0CTL1 |= UCSSEL_2;
	UCA0CTL1 &= ~UCSWRST;
}

void SPI1_Send(uint8_t data)
{
	while (!(IFG2 & UCA0TXIFG));
	while (UCA0STAT & UCBUSY); // TODO: Is this necessary?
	UCA0TXBUF = data;
}
