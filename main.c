#include "double_list.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    //Se declara el puntero de head para ingresarlo en las funciones
    struct Node* head = NULL;

    //Ingresa un elemento al principio de la lista
    nodo_inicio(&head, 2);
    nodo_inicio(&head, 1);
    //Ingresa un elemento al final de la lista
    nodo_final(&head, 4);
    nodo_final(&head, 5);
    printf("Lista actual con inserciones al inicio y final: ");
    imprime_lista(head);


    //Inserta un elemento en el indice 3 de la lista
    nodo_indice(&head, 3, 2);
    printf("Lista actual con insercion por indice: ");
    imprime_lista(head);

    //elimina un nodo segun su data
    nodo_borrar(&head, 2);
    printf("Lista después de eliminar el nodo con data 2: ");
    imprime_lista(head);

    //busca un elemento por su data
    int data = 5;
    //asigna el retorno de la funcion de busqueda a un puntero con el resultado y revisa si existe
    struct Node* busca_data = nodo_buscar(head, busca_data);
    if (busca_data != NULL)
        printf("Elemento %d encontrado en la lista\n", busca_data);
    else
        printf("Elemento %d no encontrado en la lista\n", busca_data);

    // Imprime la lista hacia adelante
    imprime_lista_adelante(head); 

    // Crear un puntero al final de la lista para recorrerla hacia atrás
    //tail es el final de la lista
    struct Node* tail = head;
    //revisa que la lista no este vacia y que pase al siguiente (que en la funcion es el previo)
    while (tail != NULL && tail->next != NULL)
        tail = tail->next;

    imprime_lista_atras(tail); // Imprime la lista hacia atrás

    return 0;
}