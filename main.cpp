#include <iostream>
using namespace std;
//función que permite mostrar por pantalla el numero binario de un numero
void printBinary(unsigned int number){
  cout << "BIN = ";
  for (int i = 31; i >=0; --i) {
    cout << (((number >> i)%2)? '1' : '0');
  }
  cout << " : DEC = " << number << endl;
}
//funcion que multiplica por potencias mayores de 2
long pow_mult(int a, int b){
    long pow = 0;
    //se le quita un numero, para que cuando llegue a la multiplicacion, no haga una extra.
    if (b%2==1) {
      b = b-1;
      //cout << "es impar\n" << b << endl;
    }
    while (b != 0)
    {
      if (b%2){
          a *= b;
          pow += a;
        }
        a = a << 1;
        b = b >> 1;
    }
    return pow;
}
//funcion que divide por potencias mayores de 2
int pow_div(int a, int b){
  int pow = 0;
  if (b%2==1) {
    b = b-1;
    //cout << "es impar\n" << b << endl;
  }
  while (b != 0)
  {
    if (b % 2){
      a /= b;
      pow += a;
      }
      a = a >> 1;
      b = b >> 1;
  }
  return pow;
}
void func_one(){
    //valores de prueba
    cout << "Se comenzara con los numeros de prueba\nEn la multiplicacion seran 15 y 20\n"
         << "el resultado es: " << pow_mult(15,20)
         << "\n\nEn la division se tomaran los valores 350 y 15\n"
         << "el resultado es: " << pow_div(350,15)
         << "\n\n Ahora se podra experimentar con cualquier valor\n";
    int a, b;
    cout << "\n > Ingrese un numero para comenzar a multiplicar: ";
    cin >> a;
    cout << "\n > Ingrese el segundo numero: ";
    cin >> b;

}

int main(){
    cout    << "=========================================\n"
            << " - - - - - B I E N V E N I D O - - - - - \n"
            << "\n1. Multiplicacion y division utilizando shift\n";
    func_one();

    return 0;
}
