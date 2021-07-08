#include <iostream>
using namespace std;
//función que permite mostrar por pantalla el numero binario de un numero (32 bits)
void printBinary(unsigned int number){
  cout << "BIN = ";
  for (int i = 31; i >=0; --i) {
    cout << (((number >> i)%2)? '1' : '0');
  }
  cout << " : DEC = " << number;
}
//funcion que multiplica por potencias mayores de 2
long pow_mult(int a, int b){
    long pow = 0, temp = 0;
    //cuando 'a' es mayor que 'b', el binario no coincide con el resultado, por lo que si es mayor, se invierte.
    if (b < a)
    {
      temp = b;
      b = a;
      a = temp;
    }
    //se le quita un numero, para que cuando llegue a la multiplicacion, no haga una extra.
    if (b%2==1) {
      b = b-1;
      //cout << "es impar\n" << b << endl;
    }
    while (b != 0)
    {
      if (b%2){
          //a *= b;
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
  cout << b << endl;
  if (b%2==1) {
    b = b-1;
  }
  while (b != 0)
  {
    if (b % 2){
      pow += a;
      cout << "\n a: "
      printBinary(a);
      cout << endl << " b:";
      printBinary(b);
      }
      a = a << 1;
      b = b >> 1;
  }
  return pow;
}
void func_one(){
    //valores de prueba
    cout << "Se comenzara con los numeros de prueba\nEn la multiplicacion seran 20 y 15\n"
         << "el resultado es: " << pow_mult(20, 15) << endl;
    printBinary(pow_mult(20,15));
    cout << "\n\nEn la division se tomaran los valores 350 y 15\n"
         << "el resultado es: " << pow_div(350, 50) << endl;
    printBinary(pow_div(350,50));
    cout << "\n\n Ahora se podra experimentar con cualquier valor\n";
    int a, b;
    cout << "\n > Ingrese un numero para comenzar a multiplicar: ";
    cin >> a;
    cout << "\n > Ingrese el segundo numero: ";
    cin >> b;
    cout << "el resultado es: " << pow_mult(a,b) << endl;
    printBinary(pow_mult(a,b));

}

int main(){
    cout    << "=========================================\n"
            << " - - - - - B I E N V E N I D O - - - - - \n"
            << "\n1. Multiplicacion y division utilizando shift\n";
    func_one();

    return 0;
}
