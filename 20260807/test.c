#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

const char* my_strstr(const char* str2, const char* str1) {
	assert(str1 && str2);
	while (*str2 != '\0') 
	{
		const char* tmp1 = str1;
		const char* tmp2 = str2;
		if (*tmp1 == *tmp2) 
		{
			while (*tmp1 != '\0'&&* tmp2 != '\0')
			{
				if (*tmp1 == *tmp2) 
				{
					tmp1++;
					tmp2++;
				}
				else {
					str2++;
					break;
				}

			}
			if (*tmp1 == '\0')
				return str2;
			else
				return NULL;
		}
		else 
		{
			str2++;
		}
	}
	return NULL;
}

void my_strcpy(char* dest,const char* source) {
	assert(dest != NULL && source != NULL);
	while (*source != '\0') {
		*dest++ = *source++;
		//dest++;
		//source++;
	}
	*dest = *source;
}

//ตÝน้
size_t my_strlen(const char* str) {
	assert(str != NULL);
	if (*str == '\0') {
		return 0;
	}
	else {
		return 1 + my_strlen(str + 1);
	}
}

void main() {

}