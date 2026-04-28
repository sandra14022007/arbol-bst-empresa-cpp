# arbol-bst-empresa-cpp
## Integrantes: 
Morocho Buñay Sandra Paola 
## Objetivo 
Implementar un Árbol Binario de Búsqueda (BST) en C++ para organizar empleados dentro de una empresa utilizando un código numérico como clave, permitiendo realizar operaciones eficientes de inserción, búsqueda y recorrido.
## Funcionalidades:
- Insertar empleados
- Buscar empleados
- Mostrar raíz
- Recorridos inorden, preorden y postorden
- Calcular altura
- Mostrar nodos hoja
## Capturas:
1. Menú principal

![image_copy](capturas/image_copy.png)

2. Inserción de empleados

Los datos a ingresar son: 

![image-ej](capturas/image-ej.png)

![image-1](capturas/image-1.png)

![imagen](capturas/image.png)

![imagen-8](capturas/image-8.png)

![imagen-9](capturas/image-9.png)

![imagen-10](capturas/image-10.png)

![imagen-11](capturas/image-11.png)

![imagen-12](capturas/image-12.png)

3. Raiz 

![image-raiz](capturas/image-raiz.png)

4. Búsqueda

![image-2](capturas/image-2.png)

5. Recorridos

- Inorden 

![image-3](capturas/image-3.png)

- Preorden

![image-4](capturas/image-4.png)

- Postorden

![image-5](capturas/image-5.png)

6. Altura y hojas

- Altura

![image-6](capturas/image-6.png) 

- Hojas

![image-7](capturas/image-7.png)

## Explicacion 
- Raiz

Es el primer nodo del árbol, desde donde se origina toda la estructura, en nuestro caso es la EmpresaUTA

- Nodo Interno 

Nodo que tiene al menos un hijo, son los gerentes ingresados 

- Hoja 

Nodo que no tiene hijos, son los empleados que ingresamos 

- Nivel 

Indica la posición de un nodo en el árbol:

Nivel 1 → Raíz

Nivel 2 → Hijos de la raíz

Nivel 3 → Nietos, etc.

En nuestro caso tenemos 3 niveles: 

Nivel 1 → EmpresaUTA

Nivel 2 → Gerentes

Nivel 3 → Empleados

- Altura

Es la longitud del camino más largo desde la raíz hasta una hoja.
Representa cuántos niveles tiene el árbol. 

## Ejemplo de funcionamiento 
Al insertar los datos sugeridos, el árbol se organiza automáticamente:
![image-ejemplo](capturas/image-ejemplo.png)

## Conclusión
* El Árbol Binario de Búsqueda permite organizar datos de forma jerárquica y eficiente, facilitando búsquedas rápidas y recorridos ordenados.

* Es una estructura fundamental en informática y muy utilizada en sistemas reales como bases de datos y sistemas de archivos.
