/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "machikania.h"

int add_values(int a, int b){
	return a+b;
}

int main() {
	int a=0,b=0;
	stdio_init_all();
	machikania_init();
	while (true) {
		printf("%d + %d = %d\n", a, b, add_values(a,b));
		a+=1;
		b+=2;
		sleep_ms(1000);
	}
	return 0;
}
