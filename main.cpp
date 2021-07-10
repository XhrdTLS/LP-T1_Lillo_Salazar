#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int matriz[100][100];

//función que permite mostrar por pantalla el numero binario de un numero (32 bits)
void printBinary(unsigned int number){
  cout << "BIN = ";
  for (int i = 31; i >=0; --i) {
    cout << (((number >> i)%2)? '1' : '0');
  }
  cout << " : DEC = " << number << endl;
}
//[1.1]funcion que multiplica por potencias mayores de 2
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
//[1.2]funcion que divide por potencias mayores de 2
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
//[2.1]funcion que crea una matriz
void new_matriz(int n, int m, matriz matrizWL){ //matriz without loop
  int i = 0, j; 

  /*El loop recorre todo j antes de seguir con i ejemplo: i1,j1 > i1,j2 > i1,j3
  de manera que avanza por filas, antes de continuar con las columnas
  de este modo se puede usar mxn                                               */
  loop_i: //inicio de loop en i
    if (i < n){
      j = 0;
      loop_j: //inicio de loop en j
        if (j < m){
          cout << " > ingrese el numero que corresponde a " << i + 1 << "-" << j + 1 << ": ";
          cin >> matrizWL[i][j];
          j++;
          goto loop_j;
        }//salida del loop en j
        i++;
        goto loop_i;
    }//salida del loop en i

  }
// [2.2]func

// [2.3]func

// [4.1]func 
/*long new_pot(int a,int b){ // calcular potencia.
    int c=3;
    int i;
    int pot = c;
    for (i = c; i <= b, i++){
        pot = pot * b;
    }
    return pot;
} V.1*/


/* ------- Seccion uno ------- */
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
  else if (option != 0){
    cout << " El numero ingresado no corresponde a ninguna de las opciones." << endl;
  }
}
/* ------- Seccion dos ------- */
void func_two(matriz matrizWL){
  int value_n, value_m;
  cout << "Para crear una Matriz de n x m se necesita:\n"
       << "\n > Ingresar n: ";
  cin >> value_n;
  cout << "\n > Ingresar m: ";
  cin >> value_m;
  new_matriz(value_n, value_m, matrizWL);
}
/* ------- Seccion tres ------- */


int main(){
  matriz matriz_global;
  cout << "=========================================\n"
       << " - - - - - B I E N V E N I D O - - - - - \n"
       << "=========================================\n";
  system("pause"); //solo funciona en windows
  cout << "\n1. Multiplicacion y division utilizando shift.\n";
  func_one();
  system("pause"); //solo funciona en windows
  cout << "\n2. Creacion de matrices.\n";
  func_two(matriz_global);
  return 0;
}

/* ------- Seccion cuatro ------- */
   // https://www.youtube.com/watch?v=9FKV4lhXTU0&ab_channel=MateFacil (conjunto potencia)
   // base T = {x / 0 ≤ x ≤ 9} es decir P(T).

void func_four(){
    int i, y, lim;
}
