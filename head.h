#include <iostream>
#include <queue>
#include <climits>
using namespace std;
////   THIS IS MY MAIN CLASS
class node
{
public:
	int data;
	node * left;
	node * right;

	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}

};
///// BUILDING TREE NORMALLY
node * buildtree()
{
	long long int v;
	cin>>v;
     
     if(v>INT_MAX)
     {
     	cout<<"Too Big Value to be stored ! "<<endl;
     	return NULL;
     }

    int d=int(v);
	if(d==-1)
	return NULL;
	
	node * root=new node(d);
	root->left=buildtree();
	root->right=buildtree();

	return root;
}
///// PREORDER PRINT
void printInPreOrder(node * root)
{
	if(root==NULL)
	return ;
	
	cout<<root->data<<", ";
	printInPreOrder(root->left);
	printInPreOrder(root->right);

}
////  POSTORDER PRINT
void printInPost(node * root)
{
	if(root==NULL)
	return ;
	
	printInPost(root->left);
	printInPost(root->right);
	cout<<root->data<<", ";

}
////  INORDER PRINT
void printinorder(node * root)
{
	if(root==NULL)
	return ;
	
	printinorder(root->left);
	cout<<root->data<<", ";
	printinorder(root->right);
	
}
//// HEIGHT OF TREE
int height(node * root)
{
	if(root==NULL)
	return 0;
	
	return max(height(root->left),height(root->right)) +1;
}
//// LEVEL ORDER PRINT IN O(N^2)
void levelOrderHeight(node * root,int k)
{
	if(root==NULL)
	return ;

	if(k==1)
	{
		cout<<root->data<<",";
		return ;
	}

	levelOrderHeight(root->left,k-1);
	levelOrderHeight(root->right,k-1);

}
//// LEVELORDER PRINT CALL
void levelordercall(node * root)
{
	for(int i=1; i<=height(root); ++i)
	{
		cout<<"LEVEL "<<i<<"       ------------------> ";
		levelOrderHeight(root,i);
		cout<<endl;
	}
}
//// LEVEL ORDER IN O(N)
void levelorderusingQueue(node * root)
{

	queue <node *> q;
	q.push(root);
	while(!q.empty())
	{
		node * frontnode=q.front();
		cout<<frontnode->data<<", ";
		q.pop();
		if(frontnode->left)
		q.push(frontnode->left);
		if(frontnode->right)
		q.push(frontnode->right);
	}
}
///// LEVEL ORDER IN O(N) WITH NEW LINE
void levelorderPerfect(node * root)
{
	queue <node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		node * frontnode=q.front();
		if(frontnode==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
			q.push(NULL);
		}
		else{
		cout<<frontnode->data<<", ";

		if(frontnode->left)
		q.push(frontnode->left);

		if(frontnode->right)
		q.push(frontnode->right);

		q.pop();
	   }
	}
}
////  COUNT NUMBER OF NODES
int countNode(node * root)
{
	if(root==NULL)
	return -1;
	
	return 2+countNode(root->left)+countNode(root->right);
}
////// SUM OF ALL NODES
int sumOfAllNodes(node * root)
{
	if(root==NULL)
	return 0;
	
	return root->data +sumOfAllNodes(root->left)+sumOfAllNodes(root->right);
}
///// CLASS PAIR FOR OPTIMISATION
class Pair
{
	public:
		int height;
		int diameter;

};
//// DIAMETER OF TREE in O(n)
Pair diameterOfTreeOpt(node * root)
{
	Pair p;
	if(root==NULL)
	{
		p.height=p.diameter=0;
		return p;
	}

	Pair Left=diameterOfTreeOpt(root->left);
	Pair Right=diameterOfTreeOpt(root->right);
	p.height=max(Left.height,Right.height)+1;
	p.diameter=max(Left.diameter,max(Right.diameter,Left.height+Right.height)) ;

	return p;
}
/// DIAMETER OF TREE IN O(N^2)
int diameterinOn2(node * root)
{
	if(root==NULL)
	return 0;
	int ownDiameter=height(root->left)+height(root->right)  ;
	return max(diameterinOn2(root->left),max(diameterinOn2(root->right),ownDiameter));
}
////// CHANGE EVERY NODE BY ITS CHILD NODE SUM
int nodeBychildNode(node * root)
{
	if(root==NULL)
	return 0; 

	if(root->left == NULL && root->right==NULL)
	return root->data;
	
	int temp=root->data;

	int leftSum=nodeBychildNode(root->left);
	int rightSum=nodeBychildNode(root->right);

	root->data=leftSum+rightSum;

	return root->data +temp;
}
///// HEIGHT BALANCE CHECK IN O(N^2)
bool isBalance(node * root)
{
	if(root==NULL)
	return true;
	
	bool myBal=false;
	int diff=abs(height(root->left)-height(root->right));
	if( diff==1 || diff==0)
	myBal=true;
	
	return myBal && isBalance(root->right) && isBalance(root->left);

}
//// CLASS FOR CHECKING BALANCE
class pairForbalance 
{
	public:
	int height;
	bool balance;
};
///// HEIGHT BALANCE CHECK IN O(N)
pairForbalance isBalanceOpt(node * root)
{
	pairForbalance p;
	if(root==NULL)
	{
		p.height=0;
		p.balance=true;
		return p;
	}

	pairForbalance Left= isBalanceOpt(root->left);
	pairForbalance Right= isBalanceOpt(root->right);

	int diff=abs(Left.height-Right.height);
	if(diff>=0 && diff <=1 && Left.balance && Right.balance)
	p.balance=true;
	else p.balance=false;
	return p;
}
//////BUILDING A HEIGHT BALANCED TREE FROM AN ARRAY
node * buildHeightBalancedaTree(int *a,int s,int e)
{
	if(s>e)
	return NULL;

	int mid=(s+e)/2;
	node * root=new node(a[mid]);
	root->left=buildHeightBalancedaTree(a,s,mid-1);
	root->right=buildHeightBalancedaTree(a,mid+1,e);

	return root;
}
////// LEFT VIEW OF TREE
void leftView(node * root)
{
	queue <node *> q;
	q.push(root);
	cout<<root->data<<" ";
	q.push(NULL);
	while(q.size()>1)
	{
		node * frontnode=q.front();

		if(frontnode==NULL)
		{
			q.pop();
			cout<<q.front()->data<<" ";
			q.push(NULL);
		}
		else{

		if(frontnode->left)
		q.push(frontnode->left);

		if(frontnode->right)
		q.push(frontnode->right);

	    q.pop();
		}
		
	}

}
//////RIGHT VIEW OF TREE
void rightView(node * root)
{

	deque <node *> q;
	q.push_back(root);
	q.push_back(NULL);

	while(q.size()>1)
	{
		node * frontnode=q.front();
		q.pop_front();
		node * nextnode=q.front();
		q.push_front(frontnode);
		if(nextnode==NULL)
		{
			cout<<frontnode->data<<" ";
		}
		if(frontnode==NULL)
		{
			q.pop_front();
			q.push_back(NULL);
		}
		else{

		if(frontnode->left)
		q.push_back(frontnode->left);

		if(frontnode->right)
		q.push_back(frontnode->right);

	    q.pop_front();
		}
	}
}
///  TOP VIEW OF TREE   (for top view we need to call both
///                  treeTopViewleft and treeTopViewRight )
void treeTopViewleft(node * root)
{

	if(root==NULL)
	return ;
	
	treeTopViewleft(root->left);
	cout<<root->data<<" ";
}
void treeTopViewRight(node * root,node * orignal)
{
	if(root==NULL)
	return;
	
	if(root!=orignal)
	cout<<root->data<<" ";
	treeTopViewRight(root->right,orignal);
	

}
////// CREATE TREE USING PREORDER AND INORDER
node * createTreeUsingOrders(int *in,int * pre,int s,int e)
{
	static int i=0;

	if(s>e)
	return NULL;

	node * root=new node(pre[i]);

	int index=-1;

	for(int j=s; s<=e; ++j)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
		
	}
    i++;
	root->left=createTreeUsingOrders(in,pre,s,index-1);
	root->right=createTreeUsingOrders(in,pre,index+1,e);

	return root;
}
//// NODES AT K DISTANCE FROM GIVEN TARGET NODE IN SUBTREE
void nodeAtKinSub(node * root,int k)
{
	if(root==NULL)
	return ;

	if(k==0)
	{
		cout<<root->data<<", ";
		return;
	}

	nodeAtKinSub(root->left,k-1);
	nodeAtKinSub(root->right,k-1);

}	
///// NODES AT K DISTANCE FROM GIVEN TARGET NODE IN WHOLE TREE
int nodeAtKDis(node * root,node * target,int k)
{
	if(root==NULL)
	return -1;
	
	if(root==target)
	{
		nodeAtKinSub(target,k);
		return 0;
	}
	
	int dl=nodeAtKDis(root->left,target,k);

	if(dl!=-1)
	{	
		if(dl+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			nodeAtKinSub(root->right,k-dl-2);
		}
		return dl+1;
	}

	int rl=nodeAtKDis(root->right,target,k);

	if(rl!=-1)
	{
		if(rl+1==k)
		cout<<root->data<<", ";
		else nodeAtKinSub(root->left,k-rl-2);
		return rl+1;
	}

	return -1;
}
// cheack for identical
bool areTreeidentical(node *a,node *b)
{
	if(a==NULL&& b==NULL)
	return true;
	if(a!=NULL and b!=NULL and a->data==b->data)
	{
		bool leftsubtree=areTreeidentical(a->left,b->left);
		bool rightsubtree=areTreeidentical(a->right,b->right);

		return leftsubtree&&rightsubtree;

	}
	return false;
}
// structurally identiacal check
bool areTreesStructurallyIdentical(node* A, node* B) 
{
	if (A == NULL && B == NULL) 
	{
		return true;
	}

	if (A != NULL && B != NULL) 
	{
		bool leftSubTree = areTreesStructurallyIdentical(A->left, B->left);
		bool rightSubTree = areTreesStructurallyIdentical(A->right, B->right);
		return leftSubTree and rightSubTree;
	}
	return false;
}
// zigzag use
void levelOrderHeight2(node * root,int k)
{
	if(root==NULL)
	return ;

	if(k==1)
	{
		cout<<root->data<<" ";
		return ;
	}

	levelOrderHeight2(root->right,k-1);
	levelOrderHeight2(root->left,k-1);

}//zigzag use
void levelOrderHeight1(node * root,int k)
{
	if(root==NULL)
	return ;

	if(k==1)
	{
		cout<<root->data<<" ";
		return ;
	}

	levelOrderHeight1(root->left,k-1);
	levelOrderHeight1(root->right,k-1);

}
// zig zag print
void printZigZag(node * root)
{
	for(int i=1; i<=height(root); ++i)
	{
		if(i&1)
		levelOrderHeight1(root,i);
		else levelOrderHeight2(root,i);
		
	}
}
/// minimum element in bst
node* FindMin(node *Node) 
{
	if(Node==NULL) 
	{
	  return NULL; 
	}
	if(Node->left) 
	return FindMin(Node->left);
	else
    return Node;
}
// max element in bst
node* FindMax(node *Node) 
{
	if(Node==NULL) 
	{
       return NULL;
	}
	if(Node->right) 
	return(FindMax(Node->right)); 
    else
	return Node; 
}
/// insertion in bst
node *Insert(node *Node,int data) 
{
	if(Node==NULL) 
	{
		node *temp;		
		temp -> data = data;
		temp -> left = temp -> right = NULL; 
		return temp;
	}
	if(data >(Node->data)) 
	{
		Node->right = Insert(Node->right,data); 
	}
	else if(data < (Node->data)) 
	{
		Node->left = Insert(Node->left,data); 
	}
		return Node; 
}
/// deletion in bst
node * Delet(node *Node, int data) 
{
	node *temp; 
	if(Node==NULL) 
	{
		cout<<"Element Not Found !"; 
	}
	else if(data < Node->data) 
	{
		Node->left = Delet(Node->left, data); 
	}
	else if(data > Node->data) 
	{
		Node->right = Delet(Node->right, data); 
	}
	else 
	{

		if(Node->right && Node->left)
			{
				temp = FindMin(Node->right);
				Node -> data = temp->data;
				Node -> right = Delet(Node->right,temp->data);
			} else 
			{
				temp = Node;
				if(Node->left == NULL)
				Node = Node->right;
				else if(Node->right == NULL)
				Node = Node->left;
		        free(temp); 
			}			
    }
return Node; 
}
/// searching in bst
node * Find(node *Node, int data) 
{
	if(Node==NULL) 
	{
		return NULL; 
	}
	if(data > Node->data) 
	{
		return Find(Node->right,data); 
	}
	else if(data < Node->data) 
	{
		return Find(Node->left,data); 
	}
	else 
	{
		return Node; 
	}
}
//// segment stl 
/// min query tree
void buildTree1(int *tree,int *arr,int index,int s,int e)
{
	//base case
	if(s>e)
	{
		return;
	}
	// base case - leaf node
	if(s==e)
	{
		tree[index]=arr[s];
		return;
	}

	int mid=(s+e)/2;
	// recursive call
	buildTree1(tree,arr,2*index,s,mid);
	buildTree1(tree,arr,2*index+1,mid+1,e); 

    int leftval=tree[2*index];
    int rightval=tree[2*index+1];

    tree[index]=min(leftval,rightval);

}
//// segment stl 
/// max query tree
void buildTree2(int *tree,int *arr,int index,int s,int e)
{
	//base case
	if(s>e)
	{
		return;
	}
	// base case - leaf node
	if(s==e)
	{
		tree[index]=arr[s];
		return;
	}

	int mid=(s+e)/2;
	// recursive call
	buildTree2(tree,arr,2*index,s,mid);
	buildTree2(tree,arr,2*index+1,mid+1,e); 

    int leftval=tree[2*index];
    int rightval=tree[2*index+1];

    tree[index]=max(leftval,rightval);

}
// return a min element in the range qs and qe
int query1(int *tree,int index,int s,int e,int qs,int qe)
{
    //3 case
    //1.no overlap
	if(qs>e || qe < s)
	{
		return INT_MAX;
	}


    //2.completer overlap
    if(qs<=s and qe>=e)
    {
    	return tree[index];
    }

    //3.partial overlap -call both sides
    int mid=(s+e)/2;
    int leftans=query1(tree,2*index,s,mid,qs,qe);
    int rightans=query1(tree,2*index+1,mid+1,e,qs,qe);

    return min(leftans,rightans);
}
// return a max element in the range qs and qe
int query2(int *tree,int index,int s,int e,int qs,int qe)
{
    //3 case
    //1.no overlap
	if(qs>e || qe < s)
	{
		return INT_MAX;
	}


    //2.completer overlap
    if(qs<=s and qe>=e)
    {
    	return tree[index];
    }

    //3.partial overlap -call both sides
    int mid=(s+e)/2;
    int leftans=query2(tree,2*index,s,mid,qs,qe);
    int rightans=query2(tree,2*index+1,mid+1,e,qs,qe);

    return max(leftans,rightans);
}
//i = index to be updated
// val= new value
void updateNode(int *tree,int index,int s,int e,int i,int val)
{
	// 1.NO overlap
	if(i<s or i>e)
	return;
	
	// reached leaf node
	if(s==e)
	{
		tree[index]=val;
		return;
	}

	// 2.Partial overlapping

	int mid=(s+e)/2;
	// lying in range i
	updateNode(tree,2*index,s,mid,i,val);
	updateNode(tree,2*index+1,mid+1,e,i,val);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}
/// Range update
// u r given rs and re ,u hv to incriment every value in range by value v
void updateRange(int *tree,int index,int s,int e,int rs,int re,int val)
{
	//NO Overlap
	if(re<s or rs>e)
	return;

	//leaf node 
	if(re==rs)
	{
		tree[index]+=val;
		return;
	}
	int mid=(s+e)/2;
	updateRange(tree,2*index,s,mid,rs,re,val);
	updateRange(tree,2*index+1,mid+1,e,rs,re,val);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}

void Beauty(string prefix,  node* root, bool isLeft)
{
    if( root !=     NULL )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << root->data <<endl;

        // enter the next tree level - left and right branch
        Beauty( prefix + (isLeft ? "│   " : "    "), root->left, true);
        Beauty( prefix + (isLeft ? "│   " : "    "), root->right, false);
    }
}

void Beautify( node * root)
{
    if(root==NULL)
    {
    	cout<<"Your tree is null "<<endl;
    	return;
    }
    cout<<endl<<endl;
    Beauty("", root, false);    
}

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

class chart
{
public:
	string name;
	chart * left;
	chart * right;

	chart(string s)
	{
		name=s;
		left=NULL;
		right=NULL;
	}
};
chart * buildorganchart()
{
	string s;
    cin>>s;
    
	if(s=="-1")
	return NULL;
	
	chart * root=new chart(s);
	root->left=buildorganchart();
	root->right=buildorganchart();

	return root;
}
chart * sear(string val,chart * root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->name==val)
	return root;
	
	chart * leftsearch= sear(val,root->left);
	chart * rightsearch= sear(val,root->right);

	if(leftsearch)
	return leftsearch;
	
	if(rightsearch)
	return rightsearch;

	return NULL;
}
int heightboard(chart * root)
{
	if(root==NULL)
	return 0;
	
	return max(heightboard(root->left),heightboard(root->right)) +1;
}
void Beautyy(string prefix,  chart* root, bool isLeft)
{
    if( root !=     NULL )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << root->name <<endl;

        // enter the next tree level - left and right branch
        Beautyy( prefix + (isLeft ? "│   " : "    "), root->left, true);
        Beautyy( prefix + (isLeft ? "│   " : "    "), root->right, false);
    }
}

void Beautifyy( chart * root)
{
    if(root==NULL)
    {
    	cout<<"Your tree is null "<<endl;
    	return;
    }
    cout<<endl<<endl;
    Beautyy("", root, false);    
}
chart * lca(chart * root,chart * n1,chart *n2)
{
	if(root==NULL)
	return NULL;

	if(root==n1 or root==n2)
	return root;

	chart *leftlca=lca(root->left,n1,n2);
	chart *rightlca=lca(root->right,n1,n2);

	if(leftlca!=NULL and rightlca!=NULL)
	return root;

	if(leftlca==NULL and rightlca==NULL)
	return NULL;

	return leftlca !=NULL ? leftlca : rightlca;
}
bool hasPath(chart *root, vector<string> & arr, string x) 
{ 
    if (!root) 
        return false; 
      
    arr.push_back(root->name);     
      
    if (root->name == x)     
        return true; 
      
    if (hasPath(root->left, arr, x) || 
        hasPath(root->right, arr, x)) 
        return true; 
          
    arr.pop_back(); 
    return false;             
} 
void printPath(chart *root, string x) 
{ 
    vector<string> arr; 
   
    if (hasPath(root, arr, x)) 
    { 
        for (int i=0; i<arr.size()-1; i++)     
        cout << arr[i] << " -> "; 
        cout << arr[arr.size() - 1];     
    } 
    else
        cout << "No Path"; 
} 
bool getPath(chart * root, vector<string>& arr, string x) 
{ 
    if (!root) 
        return false; 
   
    arr.push_back(root->name); 
  
    if (root->name == x) 
        return true; 
  
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) 
        return true; 
  
    arr.pop_back(); 
    return false; 
} 
  
void printPathBetweenNodes(chart * root, string  n1, string n2) 
{ 
	vector<string> path1; 
    
    vector<string> path2; 
  
    getPath(root, path1, n1); 
    getPath(root, path2, n2); 
  
    int intersection = -1; 
  
    int i = 0, j = 0; 

    while (i != path1.size() || j != path2.size()) 
    { 
  
        if (i == j && path1[i] == path2[j]) { 
            i++; 
            j++; 
        } 
        else { 
            intersection = j - 1; 
            break; 
        } 
    } 

    if(path1[path1.size()-2]==path2[path2.size()-2])
    {

    	cout<<"Data from your own department is already accessible to you ! "<<endl;
    	return;
    }
    cout<<"Follow the following procedure to request data from "<<n2<<" Deptartment "<<endl;
  	cout<<path1[path1.size()-1];
    for (int i = path1.size() - 2; i > intersection; i--) 
        cout << " -> "<<path1[i] ; 
  
    for (int i = intersection; i < path2.size(); i++) 
        {
        	cout << " -> "<< path2[i] ;
    	} 

} 