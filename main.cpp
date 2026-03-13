// main.cpp
#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
	if(argc == 1) {
		printf("this program needs more than 1 file\n");
		return 1;
	}
	uint32_t num;
	uint32_t sum = 0;
	for(int i=1; i<argc; i++){
		//binary 파일을 읽기 때문에 rb 사용
		FILE* fp = fopen(argv[i], "rb");
		if(fp == NULL){
			printf("file opening error\n");
			return 1;
		}
		if(fread(&num, sizeof(uint32_t), 1, fp) != 1){
			printf("file reading error\n");
			fclose(fp);
			return 1;
		}
 		num = ntohl(num);

		sum += num;
		printf("%u(0x%08x)",num, num);
		if(i == argc-1) printf(" = ");
		else printf(" + ");
		fclose(fp);
	}
	printf("%u(0x%08x)\n", sum, sum);
	return 0;
}
