#ifndef double_list
#define double_list

// Definición de la estructura de un nodo
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Función para crear un nuevo nodo
struct Node* nuevonodo(int data);

// Función para insertar un nodo al inicio de la lista
void nodo_inicio(struct Node** head, int data);

// Función para insertar un nodo al final de la lista
void nodo_final(struct Node** head, int data);

// Función para insertar un nodo en una posición específica
void nodo_indice(struct Node** head, int data, int index);

// Función para eliminar un nodo basado en el contenido del data
void nodo_borrar(struct Node** head, int data);

// Función para buscar un elemento a partir de su data
struct Node* nodo_buscar(struct Node* head, int data);

// Función para imprimir la lista
void imprime_lista(struct Node* head);

// Función para recorrer la lista hacia adelante e imprimir los elementos
void imprime_lista_adelante(struct Node* head);

// Función para recorrer la lista hacia atrás e imprimir los elementos
void imprime_lista_atras(struct Node* tail);

// Función para liberar memoria alocada
void freelist(struct Node* head);


#endif
