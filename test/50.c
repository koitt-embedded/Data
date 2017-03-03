#include <stdio.h>
#include <math.h>

#define RESOLUTION	1 << 24
#define MINUS_VOLT	-12
#define PLUS_VOLT	12
#define CUR_VOLT	9.7f

float get_slice(void)
{
	return (float)(PLUS_VOLT - MINUS_VOLT) / (1 << 24);
}

float dac(int bit, float slice)
{
	return CUR_VOLT / slice;
}

int main(void)
{
	float slice;
	float bit;

	slice = get_slice();
	printf("slice = %f\n", slice);

	bit = dac(bit, slice);
	printf("bit = %f\n", bit);
	printf("round(bit) = %f\n", round(bit));
	printf("round(bit) = 0x%x\n", (int)round(bit));
	
	return 0;
}
