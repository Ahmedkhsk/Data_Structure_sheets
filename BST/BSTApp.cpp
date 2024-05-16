#include <iostream> 
#include <iomanip>
using namespace std;

typedef int TreeElementType;
struct BSTNode
{

	TreeElementType data;
	BSTNode *left;
	BSTNode *right;
	
	BSTNode(TreeElementType x,BSTNode * l,BSTNode *r){
		data=x;
		left=l;
		right=r;
	}
	
};
typedef BSTNode* TreePosition;
class Tree{
public:
	TreePosition root;

	Tree()
	{
		root=NULL;
	}
	bool empty() {
		return root==NULL;
	}

	TreePosition Root(){
		return root;
	}


	bool isEmpty( BSTNode *tree )
	{
		return tree == NULL;
	}

	bool isLeaf( TreePosition t)
	{
		return t->left == NULL && t->right == NULL;
	}

	void insert(TreePosition &ptr, TreeElementType data )
	{
		if ( isEmpty( ptr ))
			ptr = new BSTNode(data,NULL,NULL);
	
		else
		{
			if ( data < ptr->data )
				insert(ptr->left, data );

			else 
				insert(ptr->right, data );
		} 
	}
        
	void inorder( BSTNode *tree )
	     {
		    if( tree!=NULL )
		     {
			    inorder( tree->left );
			    cout << " " << tree->data << " ";
			    inorder( tree->right );
		     }
	     }
		void preorder( BSTNode *tree )
	     {
		   if( tree!=NULL )
		    {
			    cout << " " << tree->data << " ";
			    inorder( tree->left );
			    inorder( tree->right );
		    }
	     }
		void postorder( BSTNode *tree )
	     {
		    if( tree!=NULL )
		     {
			   inorder( tree->left );
			   inorder( tree->right );
			   cout << " " << tree->data << " ";
		     }
	     }
		TreeElementType SUM(TreePosition tr)
		{
		    if(tr==NULL)
				return 0;
			return (tr->data+SUM(tr->left)+SUM(tr->right));
		}

		
	void countOccurrence(BSTNode* root, int K, int &count)
	  {
         if(root == NULL) return;
         if(root->data == K) {
			 count++;
			 countOccurrence(root->right, K, count);
		 }
		 else if(K>root->data)
			countOccurrence(root->right, K, count);
		 else
			countOccurrence(root->left, K, count);
      }
	int countOccurrence2(BSTNode* root, int K)
	  {
         if(root == NULL) return 0;
         if(root->data == K) return 1+countOccurrence2(root->right, K);
		 else if(K>root->data)
			return countOccurrence2(root->right, K);
		 else
			return countOccurrence2(root->left, K);
      }

	void remove( BSTNode *&tree, int data )
	{
		if ( isEmpty( tree )) return;

		if ( data == tree->data )
		{
			if ( !isEmpty( tree->left ) && !isEmpty( tree->right ))
			{
				BSTNode *minRight = minNode( tree->right );
				tree->data = minRight->data;
				remove( tree->right, minRight->data );
			} else
			{
				BSTNode *discard = tree;

				if ( isLeaf( tree ))
					tree = nullptr;
				else if ( !isEmpty( tree->left ))
					tree = tree->left;
				else
					tree = tree->right;

				delete discard;
			}

		} else if ( data < tree->data )
			remove( tree->left, data );
		else remove( tree->right, data );
	}
 
	BSTNode* minNode(BSTNode* node) 
	{ 
		BSTNode* current = node; 

		/* loop down to find the leftmost leaf */
		while (current->left != NULL) 
		{ 
			current = current->left; 
		} 
		return(current); 
	} 

	int maxNode(BSTNode* node) 
	{ 
		BSTNode* current = node; 

		/* loop down to find the leftmost leaf */
		while (current->right != NULL) 
		{ 
			current = current->right; 
		} 
		return(current->data); 
	} 
	

};

void main()
{
	Tree t;
	t.insert(t.root,10);
	t.insert(t.root,5);
	t.insert(t.root,110);
	t.insert(t.root,10);
	t.inorder(t.root);
	cout<<endl;
	int k,count=0;
	cin>>k;
	t.countOccurrence(t.root,10,count);
	cout<<"count of k = "<<count<<endl;

	count=t.countOccurrence2(t.root,10);
	cout<<"count of k = "<<count<<endl;


	cout<<endl<<"sum = "<<t.SUM(t.root)<<endl; 
	t.remove(t.root,10);
	t.inorder(t.root);
	cout<<endl<<"Max = "<<t.maxNode(t.root)<<endl;
	system("pause");
}