#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBST {
private:
    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }

        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } 
        else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } 
        else {
            cout << "⚠ El codigo ya existe.\n";
        }

        return nodo;
    }

    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }

        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }

    int altura(Nodo* nodo) {
        if (nodo == nullptr) return 0;

        int izq = altura(nodo->izquierdo);
        int der = altura(nodo->derecho);

        return 1 + (izq > der ? izq : der);
    }

    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl;
    }

public:
    ArbolBST() {
        raiz = nullptr;
    }

    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }

    void buscarEmpleado(int codigo) {
        Nodo* res = buscar(raiz, codigo);

        if (res != nullptr) {
            cout << "\n✔ Empleado encontrado:\n";
            mostrarEmpleado(res);
        } else {
            cout << "\n❌ Empleado no encontrado\n";
        }
    }

    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\n🌳 Raiz:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "Arbol vacio\n";
        }
    }

    void mostrarInorden() {
        cout << "\n📌 Inorden:\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\n📌 Preorden:\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\n📌 Postorden:\n";
        postorden(raiz);
    }

    void mostrarAltura() {
        cout << "\n📏 Altura: " << altura(raiz) << endl;
    }

    void mostrarHojas() {
        cout << "\n🍃 Hojas:\n";
        mostrarHojas(raiz);
    }
};

int main() {
    ArbolBST arbol;
    int opcion;

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

        if (opcion == 1) {
            Empleado e;
            cout << "Codigo: "; cin >> e.codigo;
            cin.ignore();
            cout << "Nombre: "; getline(cin, e.nombre);
            cout << "Cargo: "; getline(cin, e.cargo);
            arbol.insertarEmpleado(e);
        }
        else if (opcion == 2) {
            int cod;
            cout << "Codigo a buscar: ";
            cin >> cod;
            arbol.buscarEmpleado(cod);
        }
        else if (opcion == 3) arbol.mostrarRaiz();
        else if (opcion == 4) arbol.mostrarInorden();
        else if (opcion == 5) arbol.mostrarPreorden();
        else if (opcion == 6) arbol.mostrarPostorden();
        else if (opcion == 7) arbol.mostrarAltura();
        else if (opcion == 8) arbol.mostrarHojas();

    } while (opcion != 0);

    return 0;
}
