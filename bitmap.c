/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */
#include <stdio.h>
#include <limits.h>

#define BT_OK (1)
#define BT_ERROR (0)

#define GETBIT(__byte_, __n_) ((__byte_ & (((unsigned char) 1) << (CHAR_BIT - __n_))) ? 1 : 0)

int bitmapProc(unsigned char *bitmap, size_t bitmapsize)
{
	unsigned int bi = 1;
	unsigned int c  = 0;
	unsigned int i  = 0;

	for(i = 0, bi = 1, c = 0; i < bitmapsize; i++, bi++){

		if(bi == CHAR_BIT + 1){
			bi = 1;
			c++;
		}

		if(GETBIT(bitmap[c], bi) == 1){
			printf("%03d ON\n", i);
		}

	}

	return(BT_OK);
}


int main(int argc, char *argv[])
{
#define BITMAPSIZE (16)
	size_t bitmapsize = 40;
	unsigned char bitmap[BITMAPSIZE] = {"\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA"};

	if(bitmapProc(bitmap, bitmapsize) == BT_ERROR){
		return(-1);
	}

	return(0);
}
