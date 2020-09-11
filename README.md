# LRUCache

Implementación de un LRU (Least Recently Used) Cache, basado en las técnicas de programación estudiadas hasta ahora, en adición al paper: *How to teach data structure design: an incremental approach*. 

Instrucciones Implementadas:

* InsertValueKeyPair
* GetValueFromKey
* GetMostRecentKey

Estas 3 instrucciones tienen un tiempo de ejecución de O(1), como veremos a continuación.

## Implementacion

### Estructuras Auxiliares

Una **struct** *Node* que almacena las entradas de llave y data, en adicion a punteros *prev, next* a otros nodos, necesario para la implementación de la siguiente estructura.

Una **clase** *DLList* que representa una lista doblemente enlazada con punteros a su *head, tail*. Esta tiene los metodos de: *insert* (equivalente a un *push_back*), *popFront* y *erase* (de forma que se pueda eliminar un elemento a traves de su puntero en tiempo constante)

Una **clase abstracta** *Cache* que tiene los metodos basicos a implementar, pero con funciones virtuales para implementar diferentes criterios de insercion y de *Cache* (en este caso un LRU y un FIFO).

### LRUCache

Consiste en un *HashMap* a punteros a Nodos que se encuentran en una DLList *queue* en donde se mantiene el orden de uso de cada una de las llaves en cuestion.

## Complejidad 

### InsertValueKeyPair O(1)

El metodo consiste en lo siguiente:

* Crear un nuevo nodo con la clave y data provistas.
* Si este nodo ya existe en el *hashMap* (buscar en esta estructura es *O(1)*), se saca de su posicion en el *queue* (O(1) a traves de su puntero), y se inserta el nuevo nodo al final de esta, con el valor cambiado. 
* Caso contrario, se inserta el nuevo nodo de forma normal.
* En caso se supere el *maxSize* del queue, se elimina el *head* ya que este corresponde a la clave mas antigua.

### GetValueFromKey O(1)

El metodo consiste en lo siguiente:

* Obtiene el puntero al nodo buscando a traves de la llave en el *hashMap* (O(1))
* Su valor se almacena
* Se realiza el proceso anteriormente mencionado para sacar al Nodo a traves de su puntero y llevarlo al final del *queue* en O(1).

### GetMostRecentKey O(1)

El metodo consiste en lo siguiente:

* Retorna el tail del *queue* que corresponde a la ultimo Nodo utilizado O(1), a partir del cual se obtiene su llave.