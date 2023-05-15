#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int findGCD(int a, int b){
int i;
for(i=1;i<=a&& 1<=b; ++i){
if(a%i ==0 && b%i ==0)
return i;
}
return -1;
}

int powMod(int a, int b, int n) {
long long x = 1, y = a;
while (b > 0) {
if (b % 2 == 1)
x = (x * y) % n;
y = (y * y) % n;
b /= 2;
}
return x%n;
}

int checkPrime(int n) {
int i;
int m = n / 2;

for (i = 2; i <= m; i++) {
if (n % i == 0) {
return 0;
}
}
return 1; // Prime
}


int main(){
int p,q,n,phi_n;
int data, cipher, decrypt;

while(1){
printf("Enter any 2 prime numbers: ");
scanf("%d%d",&p,&q);
if(checkPrime(p)&&checkPrime(q))
break;
else
printf("\nThe entered numbers are not prime\n");
}
printf("P=%d\tQ=%d\n",p,q);

n=p*q;
printf("n=%d\n",n);

phi_n=(p-1)*(q-1);
printf("phi(n)=%d\n",phi_n);

int e;
for(e=5;e< 100;e++){
if(findGCD(phi_n,e)==1)
break;
}

int d=0;
for (d = e + 1; d <= 100; d++) {
if ( ((d * e) % phi_n) == 1)
break;
}

printf("e=%d\nd=%d\n", e, d);

printf("Enter numerical data: ");
scanf("%d", &data);

cipher = powMod(data, e, n);
printf("The cipher text is: %d\n", cipher);

decrypt = powMod(cipher, d, n);
printf("The decrypted text is: %d\n", decrypt);
return 0;
}
