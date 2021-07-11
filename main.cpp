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
    /*long new_pot(int a,int b){ // calcular potencia.
    int c=3;
    int i;
    int pot = c;
    for (i = c; i <= b, i++){
        pot = pot * b;
    }
    return pot;
} V.1*/
//[1.1]funcion que multiplica por potencias mayores de 2
long pow_mult(int a, int b)
{
  long pow = 0, temp = 0;
  //cuando 'a' es mayor que 'b', el binario no coincide con el resultado, por lo que si es mayor, se invierte.
  if (b < a)
  {
    temp = b;
    b = a;
    a = temp;
  }
  //se le quita un numero, para que cuando llegue a la multiplicacion, no haga una extra.
  if (b % 2 == 1)
  {
    b = b - 1;
    //cout << "es impar\n" << b << endl;
  }
  while (b != 0)
  {
    if (b % 2)
    {
      //a *= b;
      pow += a;
    }
    a = a << 1;
    b = b >> 1;
  }
  return pow;
}
//[1.2]funcion que divide por potencias mayores de 2
int pow_div(int a, int b)
{
  int pow = 0;
  //cout << b << endl;
  if (b % 2 == 1)
  {
    b = b - 1;
  }
  while (b != 0)
  {
    if (b % 2)
    {
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
void new_matriz(int n, int m, matriz matrizWL)
{ //matriz without loop
  int i = 0, j;

/*El loop recorre todo j antes de seguir con i ejemplo: i1,j1 > i1,j2 > i1,j3
  de manera que avanza por filas, antes de continuar con las columnas
  de este modo se puede usar mxn                                               */
loop_i: //inicio de loop en i
  if (i < n)
  {
    j = 0;
  loop_j: //inicio de loop en j
    if (j < m)
    {
      cout << " > ingrese el numero que corresponde a " << i + 1 << "-" << j + 1 << ": ";
      cin >> matrizWL[i][j];
      j++;
      goto loop_j;
    } //salida del loop en j
    i++;
    goto loop_i;
  } //salida del loop en i
}
// [2.2]funcion que genera una matriz como resultado de la suma de dos matrices
void suma_matriz(matriz matrizA, matriz matrizB, int col, int fil)
{
  int i = 0, j;
  new_matriz(col, fil, matrizB);
loop_i: //inicio de loop en i
  if (i < col)
  {
    j = 0;
  loop_j: //inicio de loop en j
    if (j < fil)
    {
      matrizB[i][j] = matrizA[i][j] + matrizB[i][j];
      //cout << matrizB[i][j] << endl;
      j++;
      goto loop_j;
    } //salida del loop en j
    i++;
    goto loop_i;
  } //salida del loop en i
}

// [2.3]funcion que despliega una matriz de nxm
void show_matriz(matriz matrizWL, int n, int m){
  int i = 0, j;
loop_i: //inicio de loop en i
  if (i < n)
  {
    j = 0;
  loop_j: //inicio de loop en j
    if (j < m)
    {
      cout << "  " << matrizWL[i][j];
      j++;
      goto loop_j;
    } //salida del loop en j
    cout << endl;
    i++;
    goto loop_i;
  } //salida del loop en i

}
//arreglos definidos de manera global
int *arrDinamico, arreglo=0;
// [3.1]funcion que crea un arreglo dinamico
void dyArray(){
  cout << "\n Se crea el arreglo de enteros\n";
  arrDinamico = new int[arreglo];
}

// [3.2]funcion que inserta elementos al arreglo
void insert_dyArray(int posicion){
  int numero;
  cout << " > Ingrese un numero para agregar al arreglo en la posicion " << posicion <<": ";
  cin >> numero;
  arrDinamico[posicion] = numero;
}

// [3.3]funcion que verifica la longitud del arreglo
int length_dyArray(){
  arreglo++;
  return arreglo;
}

// [3.4]funcion que despliega el contenido del arreglo
void show_dyArray(){
  cout << "\n Arreglo ingresado:\n  A[ ";
  for (int i = 1; i <= arreglo; i++){
    cout << arrDinamico[i] << " ";
  }
  cout << "]\n";
}

/* ------- Seccion uno ------------------------------------------------------------- */
void func_one(){
  cout << "\n1. Multiplicacion y division utilizando shift.\n";
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

/* ------- Seccion dos ------------------------------------------------------------ */
void func_two(matriz matrizWL){
  cout << "\n2. Creacion de matrices.\n";
  int value_n, value_m;
  matriz matrizWL2;
  cout << "Para crear una Matriz de n x m se necesita:\n"
       << "\n > Ingresar n: ";
  cin >> value_n;
  cout << "\n > Ingresar m: ";
  cin >> value_m;
  new_matriz(value_n, value_m, matrizWL);
  cout << "\nPara sumar matrices se utilizaran los datos de la matriz anteriormente creada\n"
       << "y se solicitaran nuevos datos para la matriz nueva\n";
  suma_matriz(matrizWL, matrizWL2, value_m, value_n);
  system ("pause");
  cout << "\nDespliege de Matrices: \n\n Matriz ingresada manualmente" << endl;
  show_matriz(matrizWL, value_n, value_m);
  cout << "\n Matriz calculada por la suma de dos matrices" << endl;
  show_matriz(matrizWL2, value_n, value_m);
}

/* ------- Seccion tres ----------------------------------------------------------- */
void func_three(){
  cout << "\n3. Simulacion de estrategia dinamica.\n";
  int verif, num_ingresado;
  dyArray();
  do
  {
    insert_dyArray(length_dyArray());
    cout << " > Ingrese 1 si desea ingresar otro numero,\n   0 en caso contrario\n   > ";
    cin >> verif;
    if (verif !=1){ //para evitar el loop infinito
      verif = 0;
    }
    
  } while (verif != 0);
  cout << "\n Se ha finalizado la simulacion, en total se han indexado " << arreglo << " numeros"
       << "\n Por lo que el valor del dominio en R es de " << arreglo << endl;
  show_dyArray();
  delete[] arrDinamico;
}

/*--------- MAIN ------------------------------------------------------------------------ */
int main(){
  matriz matriz_global;
  cout << "=========================================\n"
       << " - - - - - B I E N V E N I D O - - - - - \n"
       << "=========================================\n";
  system("pause"); //solo funciona en windows
  func_one();
  system("pause"); //solo funciona en windows
  func_two(matriz_global);
  system("pause");
  func_three();
  
  return 0;
}

/* ------- Seccion cuatro ------- */
   // https://www.youtube.com/watch?v=9FKV4lhXTU0&ab_channel=MateFacil (conjunto potencia)
   // base T = {x / 0 ≤ x ≤ 9} es decir P(T).

/*void func_four(){
    int i, y, lim;
}*/
