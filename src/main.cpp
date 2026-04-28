#include <iostream>   // Librería para entrada y salida (cout, cin)
#include <string>     // Librería para usar strings
using namespace std;  // Evita escribir std:: en todo momento

// Estructura que representa un empleado
struct Empleado {
    int codigo;      // Clave única del empleado
    string nombre;   // Nombre del empleado
    string cargo;    // Cargo dentro de la empresa
};

// Estructura del nodo del árbol
struct Nodo {
    Empleado dato;     // Información del empleado
    Nodo* izquierdo;   // Puntero al hijo izquierdo
    Nodo* derecho;     // Puntero al hijo derecho

    // Constructor del nodo
    Nodo(Empleado emp) {
        dato = emp;              // Guarda los datos del empleado
        izquierdo = nullptr;     // Inicializa sin hijo izquierdo
        derecho = nullptr;       // Inicializa sin hijo derecho
    }
};

// Clase del Árbol Binario de Búsqueda
class ArbolBST {
private:
    Nodo* raiz;  // Puntero a la raíz del árbol

    // Método recursivo para insertar un empleado
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        // Si el nodo está vacío, se crea uno nuevo
        if (nodo == nullptr) {
            return new Nodo(emp);
        }

        // Si el código es menor, va a la izquierda
        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } 
        // Si es mayor, va a la derecha
        else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } 
        // Si el código ya existe
        else {
            cout << "⚠ El codigo ya existe.\n";
        }

        return nodo; // Retorna el nodo actualizado
    }

    // Método recursivo para buscar un empleado
    Nodo* buscar(Nodo* nodo, int codigo) {
        // Si es nulo o se encuentra el código, retorna el nodo
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }

        // Buscar en subárbol izquierdo
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } 
        // Buscar en subárbol derecho
        else {
            return buscar(nodo->derecho, codigo);
        }
    }

    // Recorrido Inorden: izquierda - raíz - derecha
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);     // Recorre izquierda
            mostrarEmpleado(nodo);        // Muestra nodo
            inorden(nodo->derecho);       // Recorre derecha
        }
    }

    // Recorrido Preorden: raíz - izquierda - derecha
    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);        // Muestra nodo
            preorden(nodo->izquierdo);    // Izquierda
            preorden(nodo->derecho);      // Derecha
        }
    }

    // Recorrido Postorden: izquierda - derecha - raíz
    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);   // Izquierda
            postorden(nodo->derecho);     // Derecha
            mostrarEmpleado(nodo);        // Muestra nodo
        }
    }

    // Calcula la altura del árbol
    int altura(Nodo* nodo) {
        if (nodo == nullptr) return 0; // Caso base

        // Calcula altura izquierda y derecha
        int izq = altura(nodo->izquierdo);
        int der = altura(nodo->derecho);

        // Retorna la mayor + 1
        return 1 + (izq > der ? izq : der);
    }

    // Muestra los nodos hoja
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            // Si no tiene hijos, es hoja
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            // Recorre ambos lados
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    // Muestra los datos de un empleado
    void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl;
    }

public:
    // Constructor del árbol
    ArbolBST() {
        raiz = nullptr; // Inicialmente vacío
    }

    // Inserta un empleado (interfaz pública)
    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }

    // Busca un empleado
    void buscarEmpleado(int codigo) {
        Nodo* res = buscar(raiz, codigo);

        if (res != nullptr) {
            cout << "\n✔ Empleado encontrado:\n";
            mostrarEmpleado(res);
        } else {
            cout << "\n❌ Empleado no encontrado\n";
        }
    }

    // Muestra la raíz del árbol
    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\n🌳 Raiz:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "Arbol vacio\n";
        }
    }

    // Muestra recorrido inorden
    void mostrarInorden() {
        cout << "\n📌 Inorden:\n";
        inorden(raiz);
    }

    // Muestra recorrido preorden
    void mostrarPreorden() {
        cout << "\n📌 Preorden:\n";
        preorden(raiz);
    }

    // Muestra recorrido postorden
    void mostrarPostorden() {
        cout << "\n📌 Postorden:\n";
        postorden(raiz);
    }

    // Muestra altura del árbol
    void mostrarAltura() {
        cout << "\n📏 Altura: " << altura(raiz) << endl;
    }

    // Muestra nodos hoja
    void mostrarHojas() {
        cout << "\n🍃 Hojas:\n";
        mostrarHojas(raiz);
    }
};

int main() {
    ArbolBST arbol;  // Se crea el árbol
    int opcion;      // Variable para el menú

    // Menú interactivo
    do {
        cout << "\n===== MENU BST EMPRESA =====\n";
        cout << "1. Insertar\n";
        cout << "2. Buscar\n";
        cout << "3. Raiz\n";
        cout << "4. Inorden\n";
        cout << "5. Preorden\n";
        cout << "6. Postorden\n";
        cout << "7. Altura\n";
        cout << "8. Hojas\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        // Insertar empleado
        if (opcion == 1) {
            Empleado e;
            cout << "Codigo: "; cin >> e.codigo;
            cin.ignore(); // Limpia buffer
            cout << "Nombre: "; getline(cin, e.nombre);
            cout << "Cargo: "; getline(cin, e.cargo);
            arbol.insertarEmpleado(e);
        }
        // Buscar empleado
        else if (opcion == 2) {
            int cod;
            cout << "Codigo a buscar: ";
            cin >> cod;
            arbol.buscarEmpleado(cod);
        }
        // Otras opciones
        else if (opcion == 3) arbol.mostrarRaiz();
        else if (opcion == 4) arbol.mostrarInorden();
        else if (opcion == 5) arbol.mostrarPreorden();
        else if (opcion == 6) arbol.mostrarPostorden();
        else if (opcion == 7) arbol.mostrarAltura();
        else if (opcion == 8) arbol.mostrarHojas();

    } while (opcion != 0); // Se repite hasta salir

    return 0; // Fin del programa
}