#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "type.h"
#include <stdbool.h>

#define _tz1_use_if_

double Задание1( const double x, const double y )
{
#ifdef _tz1_use_if_
	// Формулировка с использованием инструкции if
	if ( x < 0 )
		{
			return y - x;
		} else if ( x >= 0 && y < 0 )
		{
			return ( y * y ) - x;
		} else
		{
			return sin( y );
		}
#else
	// Формулировка с использованием условной операции ?:
	return (x < 0) ? (y - x) :
		       ((x >= 0 && y < 0) ? ((y * y) - x) : sin(y));
#endif
}

#undef _tz1_use_if_

void Задание2( int32 *k, int32 *m, int32 *n )
{
	// Подсчет количества четных чисел
	int8 even_count = 0;
	even_count += ( *k & 1 ) ? 0 : 1;
	even_count += ( *m & 1 ) ? 0 : 1;
	even_count += ( *n & 1 ) ? 0 : 1;
	
	// Определение действий в зависимости от количества четных чисел
	if ( even_count == 0 )
		{
			*k *= *k;
			*m *= *m;
			*n *= *n;
		} else if ( even_count == 1 )
		{
			if ( ! ( *k & 1 ) ) *k += 1;
			if ( ! ( *m & 1 ) ) *m += 1;
			if ( ! ( *n & 1 ) ) *n += 1;
		} else if ( even_count == 2 )
		{
			if ( *k & 1 ) *k *= 2;
			if ( *m & 1 ) *m *= 2;
			if ( *n & 1 ) *n *= 2;
		}
}

double Задание3( const uint32 k )
{
	double       result = 0;
	for ( uint32 i      = 0; i < k; i ++ )
		{
			result = sqrt( 2 + result );
		}
	return result;
}

uint32 Задание4( int32 number )
{
	uint32 count = 0;
	number = abs( number );
	do
		{
			if ( number % 10 == 2 )
				count ++;
			number /= 10;
		} while ( number != 0 );
	
	return count;
}

double Задание5( const double x, const double epsilon )
{
	double term      = x; // первый член ряда
	double sum       = term; // сумма ряда (пока только первый член)
	double x_squared = -x * x / 2;
	int    i;

	for ( i = 1; abs( term ) > epsilon; i ++ )
		{
			term *=  x_squared / ( i * ( 2 * i + 1 ) );
			sum += term;
		}

	return 2 * sum;
}

// Для проверки результата
double Задание5_validate_result( const double x )
{
	return 2 * sin( 2 * x );
}

void Задание6( uint32 m, uint32 n )
{
	for ( uint32 number = m; number <= n; number ++ )
		{
			uint32 temp          = number;
			uint32 sum_of_digits = 0;
			
			// Рассчитываем сумму цифр числа
			while ( temp > 0 )
				{
					sum_of_digits += temp % 10;
					temp /= 10;
				}
			
			// Проверяем, является ли разность числа и суммы его цифр кратной 9
			if ( ( number - sum_of_digits ) % 9 != 0 )
				{
					printf( "The statement is false for number: %u\n", number );
					return;
				}
		}
	
	printf( "The statement is true for all numbers between %u and %u\n", m, n );
}

bool Задание7( int A[], int size )
{
	for ( int i = 0; i < size - 1; ++ i )
		{
			if ( A[ i ] < A[ i + 1 ] )
				{
					return false;
				}
		}
	return true;
}


int main( int argc, char **argv )
{
	
	double x       = 0.5; // значение x, которое вы хотите проверить
	double epsilon = 0.000001; // заданная точность ε
	
	printf( "Series result: %f\n", Задание5( x, epsilon ) );
	printf( "Validation result: %f\n", Задание5_validate_result( x ) );
	
	
	
	/* Задание 2 */
	
	return 0;
}
