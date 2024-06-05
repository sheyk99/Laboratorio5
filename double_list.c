#include <stdio.h>
#include <stdlib.h>

//implementacion de las funciones

// Definición de la estructura de un nodo
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Función para crear un nuevo nodo
struct Node* nuevonodo(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //reserva la memoria y hace cast con la memoria dinamica
    newNode->data = data; 
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Función para insertar un nodo al inicio de la lista
void nodo_inicio(struct Node** head, int data) {
    struct Node* newNode = nuevonodo(data);
    newNode->next = *head;
    if (*head != NULL) //revisa si el nodo fue creado correctamente
        (*head)->prev = newNode;
    *head = newNode; 
}

// Función para insertar un nodo al final de la lista
void nodo_final(struct Node** head, int data) {
    struct Node* newNode = nuevonodo(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

// Función para insertar un nodo en una posición específica
void nodo_indice(struct Node** head, int data, int index) {
    //si el indice es 0 lo pone al inicio de la lista
    if (index == 0) {
        nodo_inicio(head, data);
        return;
    }

    //sino, crea el nuevo nodo
    struct Node* newNode = nuevonodo(data);
    struct Node* current = *head;
    int i = 0;
    //recorre la lista hasta encontrar el nodo que actualmente tiene ese index
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    //si no encuentra ese valor, es porque la lista es mas pequena
    if (current == NULL) {
        printf("Indice no encontrado\n");
        return;
    }
    //si lo encuentra apunta el nuevo nodo a los valores prev y next del nodo que antes tenia esa posicion
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
}

// Función para eliminar un nodo basado en el contenido del data
void nodo_borrar(struct Node** head, int data) {
    struct Node* current = *head;
    //revisa si la data buscada existe en la lista 
    while (current != NULL && current->data != data)
        current = current->next;
    if (current == NULL) {
        printf("El data no existe en la lista\n");
        return;
    }
    //si existe, localiza el nodo, revisa que no sea el primero o el ultimo y cambia los apuntadores
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    //apunta la cabeza al siguiente nodo
    if (current == *head)
        *head = current->next;
    free(current);
}

// Función para buscar un elemento a partir de su data
struct Node* nodo_buscar(struct Node* head, int data) {
    struct Node* current = head;
    //apunta al siguiente nodo mientras no encuentre el dato buscado
    while (current != NULL && current->data != data)
        current = current->next;
    return current;
}

// Función para imprimir la lista
void imprime_lista(struct Node* head) {
  //pasa por el head de cada nodo e imprime el apuntador a su data
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Función para recorrer la lista hacia adelante e imprimir los elementos
void imprime_lista_adelante(struct Node* head) {
    printf("Lista hacia adelante: ");
    //recorre desde el head de cada nodo el data y lo apunta al siguiente nodo
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Función para recorrer la lista hacia atrás e imprimir los elementos
void imprime_lista_atras(struct Node* tail) {
    printf("Lista hacia atrás: ");
    //recorre desde el tail de cada nodo el data y lo apunta al anterior
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}