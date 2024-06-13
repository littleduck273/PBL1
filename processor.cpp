#include <cstring>

#include "process.h"

void trimcpy (char const in[], char out[]){
	const size_t len{strlen(in)};
	size_t start{0};
	while (start<len) {
		if (in[start]!=32) break;
        start++;
	}
	size_t end{len-1};
	while (end>0) {
		if (in[end]!=32) break;
        end--;
	}
	size_t j{0};
	for (size_t i{start}; i<=end; i++) {
		if ((in[i]!=32)||(in[i+1]!=32)){
			out[j]=in[i];
			j++;
		}
	}
	out[j]='\0';
}