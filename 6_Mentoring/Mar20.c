#include<stdio.h>
#include<stdlib.h>
void *my_malloc(int num_bytes) {
	void *p = malloc(num_bytes + 3);
	unsigned int x = (unsigned int)p;

	while (x <= (x + (num_bytes + 3))){
		if((x & 3) == 0) {
			unsigned int next_align_addr = x;
			int pad = next_align_addr - x;		
			void *ret = (void*) x + pad;
			return ret;		// --> ret will be 4 byte aligned
		}
		x++;
	}
}


int main (void) {
	void *p = my_malloc(10);		// p = aligned to 4byte boundry and points to 10 byte block
	printf("%x", p);
	free(p);
}
