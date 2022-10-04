#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ( (*head_ref) != NULL)(*head_ref)->prev =new_node;

    (*head_ref) = new_node;
}
void printList(Node** head_ref){
    Node* aux = new Node();
    aux = *head_ref;
    if(head_ref!=NULL){
            do{
                cout << aux->data << " -> ";
                aux =  aux->next;
           }while(aux!=NULL);
    } else {
        cout << "la lista esta vacia.";
    } 

}

void eliminarInicio(Node** head_ref)
{
    Node* aux = new Node();
    aux = *head_ref;
    if(head_ref==NULL){
        cout << "NO HAY ELEMENTOS.";
    } else { 
        *head_ref = aux->next;
        (*head_ref)->prev = NULL;
        aux->prev = NULL;
        delete(aux);
    }

}

void eliminarFinal(Node** head_ref)
{
    Node* aux = new Node();
    Node* aux2 = new Node();
    aux = *head_ref;
    aux2 = *head_ref;
    if(head_ref==NULL){
        cout << "NO HAY ELEMENTOS.";
    } else { 
        while(aux->next!=NULL){
            aux=aux->next;
           
        }
        aux2 = aux->prev;
        aux2->next = NULL;
        aux->prev = NULL;
        delete(aux);
    }
}

void eliminarMiddle(Node** head_ref, int posicion)
{
    Node* aux = new Node();
    Node* aux2 = new Node();
     Node* aux3 = new Node();
    aux = *head_ref;
    aux2 = *head_ref;
    aux3 = *head_ref;
    if(head_ref==NULL){
        cout << "NO HAY ELEMENTOS.";
    } else { 
        for(int i=0; i<posicion-1; ++i){
            aux=aux->next; 
        }
        aux2 = aux->prev;
        aux3 = aux->next;
        aux2->next = aux3;
        aux3->prev = aux2;
        aux->next = NULL;
        aux->prev = NULL;    
        delete(aux);
    }
}

int contar(Node** head_ref){
    Node* aux = new Node();
    aux = *head_ref;
    int cont=1;
    while(aux!=NULL){
        aux=aux->next;
        cont++;
           
    }
    return cont;
}

void DLLDelete(Node** head_ref, int posicion){
    Node* aux = new Node();
    Node* aux2 = new Node();
    Node* aux3 = new Node();
    aux = *head_ref;
    aux2 = *head_ref;
    aux3 = *head_ref;
    

    int k=1;

    if(*head_ref==NULL){
        cout << "NO HAY ELEMENTOS.";
        return;
    }
    if(posicion == 1){
        eliminarInicio(head_ref);
        return;
    }else if(posicion == contar(head_ref)-1){
        eliminarFinal(head_ref);
    }else if(posicion <= contar(head_ref)-1 && posicion >= 1 ){
        eliminarMiddle(head_ref, posicion);
    }else {
        cout << "NO existe la posicion\n";
        
    }
}





int main(){
    Node **pri;
    push(pri,2);
    push(pri,3);
    push(pri,4);
    push(pri,5);
    push(pri,6);
    push(pri,7);
    push(pri,8);
    push(pri,9);
    push(pri,10);
    push(pri,11);
    push(pri,12);

    //eliminarInicio(pri);
    //eliminarInicio(pri);
    //eliminarFinal(pri);
    //eliminarFinal(pri);
    //eliminarMiddle(pri, 3);
   // DLLDelete(pri, 3);
    //DLLDelete(pri, 1);
    //DLLDelete(pri, 7);
    DLLDelete(pri, 12);
    printList(pri);
}
