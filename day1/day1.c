#include <stdio.h>
#include <stdlib.h>

int part1() {
	FILE *fptr;
	fptr = fopen("input.txt", "r");
	char instruction[10];
	int n = 50;
	int result = 0;
	while(fgets(instruction, sizeof(instruction), fptr)) {
		char dir = instruction[0];
		int turns = atoi(instruction+1);
		if(dir == 'R') {
			n = ((n + turns) % 100);
		} else {
			n = ((n - turns) % 100);
		}
		if(n == 0) result++;
	};
	return result;
}

int part2(){
	FILE *fptr;
	fptr = fopen("input.txt", "r");
	char instruction[100];
	int n = 50;
	int result = 0;
	while(fgets(instruction, sizeof(instruction), fptr)) {
		char dir = instruction[0];
		int turns = atoi(instruction+1);

		if(dir == 'R') {
			int tmp = n + turns;
			if(tmp > 99) {
				result += tmp / 100;
			}
			n = tmp % 100;
		} else {
			int tmp = n - turns;
			if(tmp <= 0) {
				result += (tmp / -100);
				if(n != 0) result++;
			}
			n = tmp % 100;
			if(n < 0) n += 100;
		}
	}

	return result;
}

int main(){
	printf("part1: %d, part2: %d\n", part1(), part2());
	return 0;
}
