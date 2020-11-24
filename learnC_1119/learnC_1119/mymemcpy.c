#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void* mymemcpy(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* pDest = (char*)dest;
	char* pSrc = (char*)src;
	for (size_t i = 0; i < num; i++) {
		*(pDest + i) = *(pSrc + i);
	}
	return dest;
}

void* mymemmmove(void* dest, const void* src, size_t num){
	assert(dest != NULL && src != NULL);
	char* pDest = (char*)dest;
	char* pSrc = (char*)src;
	if (pSrc <= pDest && pDest <= pSrc + num) {
		for (size_t i = num - 1; i >= 0; i--) {
			*(pDest + i) = *(pSrc + i);
			return dest;
		}
	}
	else {
		return mymemcpy(dest, src, num);
	}
}

int main() {
	system("pause");
	return 0;

}