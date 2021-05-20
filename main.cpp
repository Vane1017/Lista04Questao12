#include <iostream>

using namespace std;

struct noArvore
{
    int valor;
    struct noArvore *left;
    struct noArvore *right;
};

struct noArvore *novoNo(int data) {
  struct noArvore *noArvore = (struct noArvore *)malloc(sizeof(struct noArvore));
  noArvore->valor = data;
  noArvore->left = NULL;
  noArvore->right = NULL;
  return (noArvore);
};

int height(struct noArvore *T){
    if(T == NULL){
        return -1;
    }
    else{
        return max(height(T->left),height(T->right))+1;
    }
}

void preorder(struct noArvore *T) {
    if (T != NULL) {
        cout << T->valor << endl;
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(struct noArvore *T) {
    if (T != NULL) {
        inorder(T->left);
        cout << T->valor << endl;
        inorder(T->right);
    }
}

void postorder(struct noArvore *T) {
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        cout << T->valor << endl;
    }
}

int main()
{
    struct noArvore *noRaiz = novoNo(10);
    noRaiz->left = novoNo(20);
    noRaiz->left->left = novoNo(40);
    noRaiz->left->right = novoNo(28);
    noRaiz->right = novoNo(30);
    noRaiz->right->left = novoNo(27);
    noRaiz->right->left->right = novoNo(29);
    noRaiz->right->right = novoNo(50);

    cout << "preorder" << endl;
    preorder(noRaiz);
    cout << "fim!!!" << endl;

    cout << "inorder" << endl;
    inorder(noRaiz);
    cout << "fim!!!" << endl;

    cout << "postorder" << endl;
    postorder(noRaiz);
    cout << "fim!!!" << endl;
    return 0;
}
