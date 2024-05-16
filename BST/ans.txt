#include <iostream>
#include <list>
using namespace std;
typedef int etype;
struct node{
    etype ele;
    node *right,*left;
    node(){
        ele = 0;
        right = NULL;
        left = NULL;
    }
    node(etype x,node *l ,node*r){
        ele = x;
        left = l;
        right = r;
    }
    bool isExternal(){
        return right == NULL && left == NULL;
    }
    list<node*> chil(){
        list<node*> l;
        if(left!=NULL)
            l.push_back(left);
        if(right!=NULL)
            l.push_back(right);
            
        return l;    
    }
};
typedef node* tpos;
class BST{
public: 
    tpos root;
    BST(){
        root = NULL;
    }
    bool empty(){
        return root == NULL;
    }
    void insert(tpos &ptr,etype x){
        if(ptr == NULL){
            ptr = new node(x,NULL,NULL);
        }else if(ptr->ele > x){
            insert(ptr->left,x);
        }else{
            insert(ptr->right,x);
        }
    }
    bool find(tpos ptr,etype x){
        if(ptr == NULL) return false;
        if(ptr->ele == x) return true;
        else if(ptr->ele > x)
            find(ptr->left,x);
        else 
            find(ptr->right,x);
    }
    tpos minNode(tpos ptr){
        tpos curent = ptr;
        while(curent->left!=NULL){
            curent = curent->left;
        }
        return curent;
    }
    void Remove(tpos &ptr,etype x){
        if(ptr == NULL) return;
        if(ptr->ele == x){
            if(!ptr->isExternal()){
                tpos minright = minNode(ptr->right);
                ptr->ele = minright->ele;
                Remove(ptr->right,minright->ele);
        }else{  
            tpos dis = ptr;
            if(dis->isExternal()) ptr = NULL;
            else if(dis->left!=NULL) ptr = ptr->left;
            else ptr = ptr->right;
            delete dis;
        }
        }else if(ptr->ele >  x) Remove(ptr->left,x);
        else Remove(ptr->right,x);
    }
    void inorder(tpos ptr){
            if(ptr->left!=NULL) inorder(ptr->left);
            cout<<" "<<ptr->ele<<" ";
            if(ptr->right!=NULL) inorder(ptr->right);
    }
};
    int sum(tpos p){
        if(p==NULL) 
            return 0;
        else
            return (p->ele+sum(p->left)+sum(p->right));
    }
    void countocurace(tpos &ptr,int v,int &count){
       if(ptr ==NULL) return;
        if(ptr-> ele == v){
            count ++;
            //countocurace(ptr->right,v,count);
        }else if(ptr->ele < v){
            countocurace(ptr->right,v,count);
        }
        else{
            countocurace(ptr->left,v,count);
        }
    }
    
int main() {
        BST T;
        T.insert(T.root,10);
        T.insert(T.root,7);
        T.insert(T.root,9);
        T.insert(T.root,12);
        T.insert(T.root,11);
        T.insert(T.root,11);
        T.insert(T.root,11);
        T.insert(T.root,11);
        //T.Remove(T.root,11);
        T.inorder(T.root);
        
        cout<<"\nSum: "<<sum(T.root)<<endl;
        
        int count = 0;
        countocurace(T.root,11,count);
        cout<<"Count Occurrence: "<<count;
    return 0;
}