#include <iostream>
using namespace std; 

struct node{
 int coeficiente;
 int grado;
 node *next=NULL;

};
struct polinomio{
    node *head=NULL;
    void insertar(int coef,int grad){
        node *new_node = new node();
        new_node->coeficiente=coef;
        new_node->grado=grad;
        
        if(this->head!=nullptr){
            new_node->next=this->head;
        }
        else{
            new_node->next= nullptr;
        }
        this->head=new_node;
    }
    void insertar_Atras(int coef,int grad){
        node *new_node = new node();
        new_node->coeficiente=coef;
        new_node->grado=grad;
        
        if(this->head!=nullptr){
            new_node->next=this->head;
        }
        else{
            new_node= nullptr;
        }
        this->head=new_node->next;
    }
    
    void imprimir(){
        node *x=this->head;
        
        while(x!= NULL){
            cout<<"x->coeficiente "<<x->coeficiente<<"x->grado "<<x->grado<<endl;
            x=x->next;
        }
        cout << endl;
    }
    
    void add(int cof,int gra){
        node *new_node = new node();
        new_node->coeficiente=cof;
        new_node->grado=gra;
        node *x=this->head;
        if(x==nullptr){
            cout<<"no hay datos en la lista"<<endl;
        }
        else{
            if(x<=cof){
                insertar(cof,gra);//inserta al inicio
            } else {
                insertar_Atras(cof,gra);//inserta al final
            }
        }
    }
    
};

int main(){

    struct polinomio Pa;
    Pa.insertar(1,2);
    Pa.imprimir();
    Pa.add(3,4);
    Pa.imprimir();
    
}
