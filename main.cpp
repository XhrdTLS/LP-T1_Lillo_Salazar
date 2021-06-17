#include <iostream>

int funcionPotencia(){
 int example;
}
//funcion que multiplica la potencia
long pow_multiply(int a, int b){
    long pow = 0;
    while (b != 0)
    {
        if (b % 2){
            pow += a;
        }
        a = a << 1;
        b = b >> 1;
    }
    return pow;
}

int main(){
    
    return 0;
}