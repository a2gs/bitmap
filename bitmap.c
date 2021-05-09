/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */
#include <stdio.h>
#include <limits.h>

#define BT_OK    (1)
#define BT_ERROR (0)

/* https://github.com/a2gs/bitwiseByteGetSetBits */
#define GETBIT(__byte_, __n_) ((__byte_ & (((unsigned char) 1) << (CHAR_BIT - __n_))) ? 1 : 0)
#define SETBIT(__byte_, __n_) (__byte_ |= ((unsigned char) 1) << (CHAR_BIT - __n_))

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

int bitmapSet(unsigned char *bitmap, size_t bitmapsize, unsigned int bit)
{
	unsigned int offset = 0;

	if(bit >= (unsigned int)bitmapsize)
		return(BT_ERROR);

	offset = (unsigned int)(bit / CHAR_BIT);

	/* newBit = (CHAR_BIT - (((offset + 1) * CHAR_BIT) - bit )) + 1; */

	SETBIT(bitmap[offset], ((CHAR_BIT + 1) - (offset * CHAR_BIT + CHAR_BIT - bit)));

	return(BT_OK);
}


int main(int argc, char *argv[])
{
#define BITMAPSIZE (16)
	size_t bitmapsize = 40;
	unsigned char bitmap[BITMAPSIZE] = {0};

	bitmapSet(bitmap, bitmapsize, 1);
	bitmapSet(bitmap, bitmapsize, 40);
	bitmapSet(bitmap, bitmapsize, 7);
	bitmapSet(bitmap, bitmapsize, 26);
	bitmapSet(bitmap, bitmapsize, 8);
	bitmapSet(bitmap, bitmapsize, 13);
	bitmapSet(bitmap, bitmapsize, 3);
	bitmapSet(bitmap, bitmapsize, 14);
	bitmapSet(bitmap, bitmapsize, 0);
	bitmapSet(bitmap, bitmapsize, 31);

	if(bitmapProc(bitmap, bitmapsize) == BT_ERROR){
		return(-1);
	}

	return(0);
}
