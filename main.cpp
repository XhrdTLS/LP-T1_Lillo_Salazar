#include <iostream>
using namespace std;
#define int matriz[100][100];

//función que permite mostrar por pantalla el numero binario de un numero (32 bits)
void printBinary(unsigned int number){
  cout << "BIN = ";
  for (int i = 31; i >=0; --i) {
    cout << (((number >> i)%2)? '1' : '0');
  }
  cout << " : DEC = " << number << endl;
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
    while (b != 0){
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
      //cout << "\n a: ";
      //printBinary(a);
      //cout << endl << " b:";
      //printBinary(b);
      }
      a = a >> 1;
      b = b >> 1;
  }
  return pow;
}
//funcion que crea una matriz
void new_matriz(int n, int m){
  int i = 0, j = 0; 
  matriz matrizWL[n][m]; //nombre referencia a Without Loop
  loop_llenar:
    cout << " > ingrese el numero que corresponde a A" << i+1;
    cin >> matrixWL[i][j];
    i++;
    if(i < n){
      goto loop_llenar;
    }
  
}

void func_one(){
  int value_one, value_two, option=0;
  //valores de prueba
  cout << "Se comenzara con los numeros de prueba\nEn la multiplicacion seran 20 y 15\n"
       << "el resultado es: " << pow_mult(20, 15) << endl;
  printBinary(pow_mult(20, 15));
  cout << "\n\nEn la division se tomaran los valores 350 y 15\n"
       << "el resultado es: " << pow_div(350, 50) << endl;
  printBinary(pow_div(350, 50));
  cout << "\n\n Desea ingresar datos?\nIngrese '1' si es afirmativo, en caso contrario '0'\n > ";
  cin >> option;
  if (option == 1){
    cout << "\n > Ingrese un numero para comenzar a multiplicar: ";
    cin >> value_one;
    cout << "\n > Ingrese el segundo numero: ";
    cin >> value_two;
    cout << "el resultado es: " << pow_mult(value_one, value_two) << endl;
    printBinary(pow_mult(value_one, value_two));
  }
  else if (option != 0)
  {
    cout << " El numero ingresado no corresponde a ninguna de las opciones." << endl;
  }
  
}
void func_two(){
  cout << "Se comienza a crear la matriz de prueba con los datos:\n"
       << "Matriz de 3 x 2 (para ejemplo), con datos ingresados, \nluego se podra ingresar datos manuales.(m x n)\n";
  new_matriz(3,2);
}
int main(){
    cout    << "=========================================\n"
            << " - - - - - B I E N V E N I D O - - - - - \n"
            << "\n1. Multiplicacion y division utilizando shift.\n";
    func_one();
    //solo funciona en windows
    system("pause");
    cout    << "\n\n2. Creacion de matrices.\n";
    func_two();
    return 0;
}
