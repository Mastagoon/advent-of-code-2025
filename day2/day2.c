#include <math.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long pow_of_ten(long pow){
	long out = 1;
	for(long i = 0; i < pow; i++) out *= 10;
	return out;
}

long digit_count(long i){
	return (long)floor(log10(labs(i))) + 1;
}

long digits_diff(long num1, long num2) {
	return digit_count(num1) - digit_count(num2);
}

long left_half(long num) {
	return num / pow_of_ten(digit_count(num)/2);
}

long right_half(long num) {
	return num % pow_of_ten(digit_count(num)/2);
}

long repeat(long num) {
	return num * pow_of_ten(digit_count(num)) + num;
}

long part1(){
	FILE *fptr;
	fptr = fopen("input.txt", "r");
	char input[5000];
	fgets(input, sizeof(input), fptr);
	char del = '-';
	long sum = 0;

	char *set = strtok(input, "-");
	while(set != NULL) {
		char *left = set;
		set = strtok(NULL, ",");
		char *right = set;
		long leftN = atol(left);
		long rightN = atol(right);
		int diff = digits_diff(rightN, leftN);
		do {
			// ignore odd
			if(digit_count(leftN) %2 != 0) {
				leftN = pow_of_ten(digit_count(leftN));
				diff--;
				continue;
			}


			int ll = left_half(leftN);
			int lr = right_half(leftN);

			int rl = left_half(rightN);
			int rr = right_half(rightN);

			if(ll == lr) {
				sum += leftN;
			}

			if(ll > lr) {
				sum += repeat(ll);
			}

			for(int i = ll+1; i <= rl; i++){
				long num = repeat(i);
				if(num >= rightN) break;
				sum += num;
			}

			leftN = pow_of_ten(digit_count(leftN));
			diff--;
			
		} while(diff >= 0);

		set = strtok(NULL, "-");
	}


	return sum;
}


int main(){
	printf("part1: %lu\n", part1());
	return 0;
}
