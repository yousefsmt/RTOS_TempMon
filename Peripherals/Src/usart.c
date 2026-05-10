#include "usart.h"

void USART_Init( const uint32_t baud_rate )
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	/* Clear MODE and CNF for USART2 (printf) */
	GPIOA->CRL &= ~( GPIO_CRL_CNF2 | GPIO_CRL_MODE2 |
					 GPIO_CRL_CNF3 | GPIO_CRL_MODE3  );



	GPIOA->CRL |= ( GPIO_CRL_MODE2_0 | GPIO_CRL_CNF2_1 |
				  ( 0x00 << GPIO_CRL_MODE3_Pos ) | GPIO_CRL_CNF3_0 );

	uint32_t uartdiv = SystemCoreClock / baud_rate; /* Mantissa ~4, Fraction ~.340277778 */
	USART2->BRR = ( ( ( uartdiv / 16 ) << USART_BRR_DIV_Mantissa_Pos ) |
				    ( ( uartdiv % 16 ) << USART_BRR_DIV_Fraction_Pos ) );

	USART2->CR1 |= ( USART_CR1_RE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE );
}