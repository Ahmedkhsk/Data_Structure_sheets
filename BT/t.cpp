#include <iostream>
#include <list>
using namespace std;
typedef char etype;
struct node{
    etype element;
    node *parent,*left,*right;
    node(){
        element = 0;
        parent=left=right=NULL;
    }
    node(etype x,node*p,node*lft,node*rgt){
        element=x;
        parent=p;
        left=lft;
        right=rgt;
    }
    bool isExternal(){
        return left == NULL && right == NULL;
    }
    list<node*>children(){
        list<node*> l;
        if(left!=NULL)
            l.push_back(left);
        if(right!=NULL)
            l.push_back(right);
        return l;
    }
    bool isRoot(){
        return parent == NULL;
    }
};
class linkedBinaryTree{
    public:
    node *root;//pointer to the root
    int count;
    linkedBinaryTree(){
        root=NULL;
        count = 0;
    }
    int size(){
        return count;
    }
    bool empty(){
        return root == NULL;
    }
    node* getRoot(){
        return root;
    }
    node* addRoot(etype e){
        if(!empty()){
            cout<<"Tree not empty\n";
        }else{
            root = new node(e,NULL,NULL,NULL);
            count++;
        }
        return root;
    }
    node* addLeft(node*p , etype e){
        if(p->left!=NULL){
            cout<<"P already has a left child\n";
            return NULL;
        }else{
            node* child =new node(e,p,NULL,NULL);
            p->left = child;
            count ++;
            return child;
        }
    }
    node* addRight(node*p , etype e){
        if(p->right!=NULL){
            cout<<"P already has a right child\n";
            return NULL;
        }else{
            node* child =new node(e,p,NULL,NULL);
            p->right = child;
            count ++;
            return child;
        }
    }
    void attach(node*p,linkedBinaryTree t1,linkedBinaryTree t2){
        if(!p->isExternal())
            cout<<"p must be an External or Leaf\n";
        else{
            p->left = t1.root;
            p->right =t2.root;
            if(t1.root!=NULL) t1.root->parent = p;
            if(t2.root!=NULL) t2.root->parent = p;
            count+=(t1.size()+t2.size());
        }
    }
    void preorder(node* v){
        cout<<" "<<v->element<<" ";
        if(v->left != NULL) preorder(v->left);
        if(v->right != NULL) preorder(v->right);
    }
    void inorder(node* v){
        if(v->left != NULL) inorder(v->left);
         cout<<" "<<v->element<<" ";
        if(v->right != NULL) inorder(v->right);
    }
    void postorder(node* v){
        if(v->left != NULL) inorder(v->left);
        if(v->right != NULL) inorder(v->right);
         cout<<" "<<v->element<<" ";
    }
    

};
int evaluateExprssion(linkedBinaryTree t,node* p){
        if(!p->isExternal()){
            int x = evaluateExprssion(t,p->left);
            int y = evaluateExprssion(t,p->right);
            switch(p->element){
                case '+':return x+y;
                break;
                case '-':return x-y;
                break;
                case '*':return x*y;
                break;
                case '/':return x/y;
                break;
                default:
                return 0;
                }
            }else
                return int(p->element-'0');
    }
        void printExpression(linkedBinaryTree t,node* p){
        if(p->isExternal())
            cout<<p->element;
        else{
            cout<<"(";
            printExpression(t,p->left);
            cout<<p->element;
            printExpression(t,p->right);
            cout<<")";
        }
    }
int main() {
    linkedBinaryTree t1;t1.addRoot('-');
    linkedBinaryTree t2;t2.addRoot('/');
    linkedBinaryTree t3;t3.addRoot('+');
    linkedBinaryTree t4;t4.addRoot('*');
    linkedBinaryTree t5;t5.addRoot('+');
    linkedBinaryTree t6;t6.addRoot('*');
    linkedBinaryTree t7;t7.addRoot('6');
    linkedBinaryTree t8;t8.addRoot('+');
    linkedBinaryTree t9;t9.addRoot('3');
    linkedBinaryTree t10;t10.addRoot('-');
    linkedBinaryTree t11;t11.addRoot('2');
    linkedBinaryTree t12;t12.addRoot('3');
    linkedBinaryTree t13;t13.addRoot('-');
    linkedBinaryTree t16;t16.addRoot('3');
    linkedBinaryTree t17;t17.addRoot('1');
    linkedBinaryTree t20;t20.addRoot('9');
    linkedBinaryTree t21;t21.addRoot('5');
    linkedBinaryTree t26;t26.addRoot('7');
    linkedBinaryTree t27;t27.addRoot('4');
    t8.attach(t8.root,t16,t17);
    t10.attach(t10.root,t21,t21);
    t13.attach(t13.root,t26,t27);
    t4.attach(t4.root,t8,t9);
    t5.attach(t5.root,t10,t11);
    t6.attach(t6.root,t12,t13);
    t2.attach(t2.root,t4,t5);
    t3.attach(t3.root,t6,t7);
    t1.attach(t1.root,t2,t3);
    
    t1.preorder(t1.root);
    cout<<endl;
    t1.inorder(t1.root);
    cout<<endl;
    t1.postorder(t1.root);
    cout<<endl;
    cout<<"EvaluateExprssion: "<<evaluateExprssion(t1,t1.getRoot())<<endl;
    cout<<"Size of Tree: "<<t1.size()<<endl;
    cout<<"print Expression: ";
    printExpression(t1,t1.getRoot());
    cout<<endl;
    system("pause");
    return 0;
}