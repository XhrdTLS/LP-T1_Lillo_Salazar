#include <iostream>

int funcionPotencia(){
 int example;
}
//funcion que multiplica la potencia
long exp_mult(int x, int y){
    int z = 0;
    while (y != 0)
    {
        if (y % 2){
            z += x;
        }
        x = x << 1;
        y = y >> 1;
    }
    return z;
}

int main(){
    
    return 0;
}