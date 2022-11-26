#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
struct Node
{
    T m_data;
    Node *m_right;
    Node *m_left;

    Node(T data):m_data(data), m_right(nullptr), m_left(nullptr){}

    friend std::ostream &operator<<(std::ostream &os, Node<T> const &n) { 
        // completar
        return os << n.m_data;
    }
};

template<class T>
struct BST
{
    Node<T> *m_root;
    BST():m_root(nullptr){}

    Node<T>* insert(Node<T>* current, T data){
        if(current==nullptr) return new Node<T>(data);
        else{
            // completar
            if(data < current->m_data){
                current->m_left = insert(current->m_left, data);
            }else if(data > current->m_data){
                current->m_right = insert(current->m_right, data);
            }
        }
        return current;
    }

    void insert(T data){
        m_root = insert(m_root, data);
    }

    Node<T>* find(T key){
        // Implementar Buscar SIN RECURSION 
        Node<T> *current = m_root;
        if(current==nullptr || m_root->m_data == key) return current;
        else {
            while(m_root != nullptr && key != m_root->m_data){
                if(key < current->m_data){
                    current = current->m_left;
                } else{
                    current = current->m_right;
                }
            }
            return current;
        }
    }
    

    
    Node<T>* find(T key){
        return find(key);
    }


    void LevelTraverse(){
        // Implementar
        if(m_root == nullptr){
            return;
        }
        list<Node<T>*> q;
        q.push_back(m_root);
        Node<T>*curr = nullptr;
        while(q.size())
        {
            curr = q.front();
            q.pop_front();
            cout<< curr->m_data <<" ";
            if(curr->m_left){
                q.push_back(curr->m_left);
            }
            if(curr->m_right){
                q.push_back(curr->m_right);
            }
        }
    }

    Node<T>* minNode(Node<T>* current){
        // completar
        if(current==nullptr || current->m_left==nullptr) return current;
        return maxNode(current->m_left);
    }


    Node<T>* deleteNode(Node<T>* current, T key){
        if(current==nullptr) return current;

        if(key < current->m_data){
            current->m_left = deleteNode(current->m_left, key);
        }else if(key > current->m_data){
            current->m_right = deleteNode(current->m_right, key);
        } else {
            // completar usando minNode
            if (current->m_left == nullptr){
                Node<T>* temp = current->m_right;
                free(current);
                return temp;
            }else if(current->m_right == nullptr){
                Node<T>* temp = current->m_left;
                free(current);
                return temp;
            }

            Node<T>* temp = maxNode(current->m_right);

            current->m_data = temp->m_data;
            current->m_left = deleteNode(current->m_left, temp->m_data);
            
        }

        return current;
    }

    void deleteNode(T key){
        deleteNode(m_root, key);
    }

    int sizeTree(){
        // Retornar el tamaño del àrbol SUN RECURSION
        Node<T> *current = m_root;
        int cont = 0;
        if(m_root == nullptr) {
            return 0;
        } else {
            /*
            while(m_root != nullptr){
                if(current->m_left){
                    current = current->m_left;
                } else{
                    current = current->m_right;
                }
            }
            */

        }
        return cont;
       
    }

    void removeLeaf(){
        // implemnetar una funcion que elimine las hojas del arbol
        if(m_root == nullptr) {
            return nullptr;
        } 
        if (m_root->m_left == nullptr && m_root->m_right == nullptr) {
            free(m_root);
            return nullptr;
        }

    }

/
    
    bool isAVL(){
        // Función que verifica si un arbol cumple con las caracteŕisticas de un AVL
    }

    
};



int main() {

    

    return 0;
}
