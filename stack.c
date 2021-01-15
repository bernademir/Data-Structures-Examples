#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKSIZE 100

struct stack {
	int items[STACKSIZE];
	int top;
} stack;

void push(int newdata) {
	stack.top++;
	stack.items[stack.top] = newdata;
}

int pop() {
	int deldata;
	deldata = stack.items[stack.top];
	stack.top--;
	return (deldata);
}

void display() {
	for (int i = stack.top; i >= 0; i--) {
		printf("\n%d", stack.items[i]);
	}
}

int main() {
	int data;
	int cikis;
	do{
		printf("\nMenu \n1= Ekle \n2= Sil \n3= Listele \n0= Cikis");
		scanf_s("%d", &cikis);
		switch (cikis) {
		case 1:
			printf("\nEklemek istediginiz sayiyi giriniz..");
			scanf_s("%d", &data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		}
	} while (cikis != 0);
	return 0;
}