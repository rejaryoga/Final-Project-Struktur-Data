
// REYHAN JARSI YOGA (20081010139)

#include<iostream>
#include <algorithm>
#include <iomanip>
#include<fstream>
#include<string.h>
using namespace std;
/*
* Node Declaration
*/
ofstream outf;
class bst
{
   long long int number;
   char fname[20],lname[20],email[40];
   bst *left,*right;
   friend class tree;
};
class tree
{   public:
    bst *root;
    tree()
    {
        root=new bst();
        root=NULL;
    }
  void insert()
    {
        int k=0;
        bst *tmp,*p,*parent=NULL;
        tmp=root;
        p=new bst();
        cout<<"\nMasukkan Data Nama Mahasiswa: ";
        cin>>p->fname;
        cout<<"\nProdi Mahasiswa: ";
        cin>>p->lname;
        cout<<"\nNPM Mahasisswa: ";
        cin>>p->number;
        do{cout<<"\nEmail Mahasiswa: ";
        cin>>p->email;
        k=mailchck(p->email);
        }while(k!=1);
        p->left=NULL;
        p->right=NULL;
        if(root==NULL)
        {
            root=p;
        }
        else
        {
             while(tmp!=NULL)
             {
                 parent=tmp;
                 if(strcmp(p->fname,tmp->fname)<0)
                    tmp=tmp->left;
                 else
                    tmp=tmp->right;
             }
             if(strcmp(p->fname,parent->fname)<0)
               parent->left=p;
             else
                parent->right=p;
        }
    }
    int mailchck(char a[])
    {
        int j=0,i=0;
        while(a[i]!='\0')
        {
            if(a[i]=='@') j++;
            i++;
        }
        if(j==1) return 1;
        cout<<"Email Mahasiswa Invalid";
        return 0;
    }
    void inorder()
    {
        inordertrav(root);
    }
    void inordertrav(bst *t)
    {
        if(t!=NULL)
       {
        inordertrav(t->left);
        cout<<"========================="<<endl;
        cout<<"Nama Mahasiswa: "<<t->fname;
		cout<<"\nProdi Mahasiswa:"<<t->lname;
		cout<<"\nNPM Mahasiswa: "<<t->number;
		cout<<"\nEmail Mahasiswa:"<<t->email;
		cout<<"\n========================\n"<<endl;
        inordertrav(t->right);
       }
    }
    void preorder()
    {
        preordertrav(root);
    }
    void preordertrav(bst* t)
	{
		if (t!=NULL)
		{
	    	cout<<"========================="<<endl;
	        cout<<"Nama Mahasiswa: "<<t->fname;
			cout<<"\nProdi Mahasiswa:"<<t->lname;
			cout<<"\nNPM Mahasiswa: "<<t->number;
			cout<<"\nEmail Mahasiswa:"<<t->email;
			cout<<"\n========================\n"<<endl;
		preordertrav(t->left);
		preordertrav(t->right);
		}
	}
	void posteorder()
    {
        postordertrav(root);
    }
    void postordertrav(bst* t)
	{
		if (t!=NULL)
		{
		postordertrav(t->left);
		postordertrav(t->right);
		cout<<"========================="<<endl;
	    cout<<"Nama Mahasiswa: "<<t->fname;
		cout<<"\nProdi Mahasiswa:"<<t->lname;
		cout<<"\nNPM Mahasiswa: "<<t->number;
		cout<<"\nEmail Mahasiswa:"<<t->email;
		cout<<"\n========================\n"<<endl;
		}
	}
bst * minValueNode(struct bst* l)
{
    bst* current = l;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

bst* deleteNode(struct bst* root,char a[20])
{

    if (root == NULL) return root;

     if (strcmp(a,root->fname)<0)
        root->left = deleteNode(root->left,a);

    else if (strcmp(a,root->fname)>0)
        root->right =deleteNode(root->right,a);

    else
    {

        if (root->left == NULL)
        {
            bst *temp = root->right;
            return temp;
        }
        else if (root->right == NULL)
        {
             bst *temp = root->left;
            return temp;
        }

        bst* temp = minValueNode(root->right);
        root->number = temp->number;
        strcpy(root->lname,temp->lname);
        strcpy(root->fname,temp->fname);
        strcpy(root->email,temp->email);
        root->right = deleteNode(root->right, temp->fname);
    }
    return root;
}


bst* edit(bst* root,char a[])
{
    if (root == NULL) return root;

    if (strcmp(a,root->fname)<0)
        root->left = edit(root->left,a);

    else if (strcmp(a,root->fname)>0)
        root->right =edit(root->right,a);
    else
    {
        int x;
        cout<<" ==================================================="<<endl;
    	cout<<"=\t1. Data Nama Mahasiswa          ="<<endl;
    	cout<<"=\t2. Prodi Data Mahasiswa         ="<<endl;
    	cout<<"=\t3. NPM Data Mahasiswa           ="<<endl;
    	cout<<"=\t4. Email Data Mahasiswa         ="<<endl;
    	cout<<" ==================================================="<<endl;
        cin>>x;
        cout<<"\nEnter the new value:";
        switch(x)
        {
            case 1:cin>>root->fname; break;
            case 2:cin>>root->lname; break;
            case 3:cin>>root->number; break;
            case 4:cin>>root->email; break;
            default: cout<<"Value not modifed";
        }
    }
    return root;
}
void searc(bst* root,char a[])
{
     if (root)
   {
    if (strcmp(a,root->fname)<0)
         searc(root->left,a);
    else if (strcmp(a,root->fname)>0)
        searc(root->right,a);
    else
    {
        cout<<"\nSearch Data Mahasiswa:\n";
        cout<<"Nama Mahasiswa: "<<root->fname<<"\tProdi : "<<root->lname<<"\nNPM Mahasiswa: "<<root->number<<"\tEmail Mahasiswa: "<<root->email;
    }
     }
}
void filee(bst* t)
{
     if(t!=NULL)
       {

        filee(t->left);
        outf<<"\nData Mahasiswa :\n"<<"Nama Mahasiswa: "<<t->fname<<"\tProdi: "<<t->lname<<"\nNPM Mahasiswa: "<<t->number<<"\tEmail Mahasiswa: "<<t->email;
        filee(t->right);
       }
}
};
struct avl_node
{
	int data;
	string subject;
	string name;
	int height;
	int balance;
	struct avl_node *left;
	struct avl_node *right;
}*root;
/*
* Class Declaration
*/
class avlTree
{
public:
	int height(avl_node *);
	int diff(avl_node *);
	avl_node *rr_rotation(avl_node *);
	avl_node *ll_rotation(avl_node *);
	avl_node *lr_rotation(avl_node *);
	avl_node *rl_rotation(avl_node *);
	avl_node* balance(avl_node *);
	avl_node* insertinto(avl_node *, int num,string sub,string name);
	void display(avl_node *);
	void inorder(avl_node *);
	void preorder(avl_node *);
	void postorder(avl_node *);
	avl_node* remove(avl_node* t, int x, string sub, string nme);
	void search(avl_node* t, int x ,string sub,string nme);
	avl_node* findMin(avl_node*);
	avl_node* findMax(avl_node*);
	void displaytree(avl_node *, int);
	avlTree()
	{
		root = NULL;
	}
};

/*
* Height of AVL Tree
*/
void avlTree::displaytree(avl_node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		displaytree(ptr->right, level + 1);
		printf("\n");
		if (ptr == root){
            cout << "Root -> ";
		}
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		displaytree(ptr->left, level + 1);
	}
}

int avlTree::height(avl_node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

/*
* Height Difference
*/
int avlTree::diff(avl_node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
* Right- Right Rotation
*/
avl_node *avlTree::rr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
/*
* Left- Left Rotation
*/
avl_node *avlTree::ll_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

/*
* Left - Right Rotation
*/
avl_node *avlTree::lr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

/*
* Right- Left Rotation
*/
avl_node *avlTree::rl_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
* Balancing AVL Tree
*/
avl_node* avlTree::balance(avl_node* temp) {
  int balance_factor = height(temp->left) - height(temp->right);
  if (balance_factor > 1) {
    if (height(temp->left->left) >= height(temp->left->right)) {
      temp = ll_rotation(temp);
    } else {
      temp = lr_rotation(temp);
    }
  } else if (balance_factor < -1) {
    if (height(temp->right->right) >= height(temp->right->left)) {
      temp = rr_rotation(temp);
    } else {
      temp = rl_rotation(temp);
    }
  }
  return temp;
}


/*
* Insert Element into the tree
*/
avl_node *avlTree::insertinto(avl_node *root, int value,string sub,string nme)
{
	if (root == NULL)
	{
		root = new avl_node;
		root->data = value;
		root->subject=sub;
		root->name=nme;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insertinto(root->left, value,sub,nme);
		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insertinto(root->right, value,sub,nme);
		root = balance(root);
	}
	return root;
}

/*
* Display AVL Tree
*/
void avlTree::display(avl_node *ptr)
{
    const char separator    = ' ';
	const int nameWidth     = 12;
	const int numWidth      =12;
        char result;
            if (ptr == NULL)
		return;
	display(ptr->right);
    cout << setw(nameWidth) << setfill(separator) << ptr->name;
    cout << setw(nameWidth) << setfill(separator) << ptr->subject;
    cout << setw(numWidth) << setfill(separator) <<ptr->data<<"";
    cout << setw(nameWidth) << setfill(separator) << result;
    cout << endl;
	display(ptr->left);
    }

/*
* Inorder Traversal of AVL Tree
*/
void avlTree::inorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);			
    cout <<"Nama Mahasiswa :"<<tree->name<<" | "<< "Prodi :  "<<tree->subject<<" | "<<"NPM Mahasiswa : "<<tree->data<<""<<endl;
	inorder(tree->right);
}
/*
* Preorder Traversal of AVL Tree
*/
void avlTree::preorder(avl_node *tree)
{
	if (tree == NULL)
	return;
    cout <<"Nama Mahasiswa :"<<tree->name<<" | "<< "Prodi :  "<<tree->subject<<" | "<<"NPM Mahasiswa : "<<tree->data<<""<<endl;
	preorder(tree->left);
	preorder(tree->right);
}
avl_node* avlTree::findMin(avl_node* t) {
	if (t == NULL)
    return NULL;
	else if (t->left == NULL)
    return t; // if element traverse on max left then return
	else
    return findMin(t->left); // or recursively traverse max left

}
avl_node* avlTree:: findMax(avl_node* t) {
	if (t == NULL)
	return NULL;
	else if (t->right == NULL)
    return t;
	else
    return findMax(t->right);
}
/*
* Postorder Traversal of AVL Tree
*/
void avlTree::postorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout <<"Nama Mahasiswa :"<<tree->name<<" | "<< "Prodi :  "<<tree->subject<<" | "<<"NPM Mahasiswa : "<<tree->data<<endl;
}
void avlTree::search(avl_node* t, int x ,string sub,string nme)
{
    if (t == NULL)
    {
        cout << "Key not found" << endl;
        return;
    }

    if (x < t->data)
    {
        avlTree::search(t->left, x, sub, nme);
    }
    else if (x > t->data)
    {
        avlTree::search(t->right, x, sub, nme);
    }
    else
    {
    	cout << "\nData Mahasiswa Telah Ditemukan :\n" <<endl;

        cout << "nama Mahasiswa: " << nme << endl;
        cout << "Prodi : " << sub << endl;
        cout << "NPM Mahasiswa " << x << endl;
    }
}


avl_node* avlTree::remove(avl_node* t, int x, string sub, string nme) {
  if (t == NULL) {
    return NULL;
  }

  if (t->data > x || (t->data == x && t->subject > sub) || (t->data == x && t->subject == sub && t->name > nme)) {
    t->left = remove(t->left, x, sub, nme);
  }
  else if (t->data < x || (t->data == x && t->subject < sub) || (t->data == x && t->subject == sub && t->name < nme)) {
    t->right = remove(t->right, x, sub, nme);
  }
  else {
    // Node has no children
    if (t->left == NULL && t->right == NULL) {
      delete t;
      return NULL;
    }
    // Node has one child
    else if (t->left == NULL) {
      avl_node* temp = t->right;
      delete t;
      return temp;
    }
    else if (t->right == NULL) {
      avl_node* temp = t->left;
      delete t;
      return temp;
    }
    // Node has two children
    else {
      avl_node* temp = findMin(t->right);
      t->data = temp->data;
      t->subject = temp->subject;
      t->name = temp->name;
      t->right = remove(t->right, temp->data, temp->subject, temp->name);
    }
  }

  // Update the height and balance of the node
  t->height = max(height(t->left), height(t->right)) + 1;
  t->balance = height(t->left) - height(t->right);

  // Rebalance the tree if necessary
  if (t->balance > 1 && t->left->balance >= 0) {
    return rr_rotation(t);
  }
  if (t->balance > 1 && t->left->balance < 0) {
    t->left = lr_rotation(t->left);
    return rr_rotation(t);
  }
  if (t->balance < -1 && t->right->balance <= 0) {
    return lr_rotation(t);
  }
  if (t->balance < -1 && t->right->balance > 0) {
    t->right = rr_rotation(t->right);
    return lr_rotation(t);
  }

  return t;
}


///testing
avlTree avl;
///function declaration
void insertitems();
void deleteItem();
void switchtomenu();
void init();
void itemdisplay();
void displaytree();
void inorder1();
void preorder1();
void post();
void insertitemsbst();
void search();
//void displaytree();

void init(){
int choice, item;
    system("cls");
	while (1)
	{
	cout<<" -----------------------------------------------"<<endl;
    cout<<" ==      REYHAN JARSI YOGA (20081010139)      =="<<endl;
    cout<<" -----------------------------------------------\n"<<endl;
    cout<<" ==================================================="<<endl;
    cout<<" =    PROGRAM DATA MAHASISWA BERDASARKAN AVL       ="<<endl;
    cout<<" ==================================================="<<endl;
    cout<<"=\t1. Insert Data Mahasiswa                   ="<<endl;
    cout<<"=\t2. Delete Data Mahasiswa                   ="<<endl;
    cout<<"=\t3. Display Data Mahasiswa                  ="<<endl;
    cout<<"=\t4. Search Data Mahasiswa                   ="<<endl;
    cout<<"=\t5. InOrder traversal Data Mahasiswa        ="<<endl;
    cout<<"=\t6. PreOrder traversal Data Mahasiswa       ="<<endl;
    cout<<"=\t7. PostOrder traversal Data Mahasiswa      ="<<endl;
    cout<<"=\t8. display Tree Data Mahasiswa             ="<<endl;
    cout<<"=\t9. Exit                                    ="<<endl;
    cout<<"\nPlease select any option - ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			insertitems();
			break;
		case 2:
		    if (root == NULL)
			{
				cout << "There No Records To Delete" << endl;
				continue;
			}
			deleteItem();
			break;
		case 3:
			if (root == NULL)
			{
				cout << "There No Records " << endl;
				continue;
			}
			itemdisplay();
			break;
		case 4:
			search();
			break;
		case 5:
			inorder1();
			break;
		case 6:
			preorder1();
			break;
		case 7:
			post();
			break;
		case 8:
            if (root == NULL)
			{
				cout << "Tree is Empty" << endl;
				continue;
			}
			displaytree();
			break;
        case 9:
            exit(1);
            break;
		default:
			cout << "Wrong Choice" << endl;
			 system("cls");
        init();
		}
	}
}


void bst(){
	system("cls");
   tree q;
   char c,a[20];
    int x;
    do{
    	cout<<" -----------------------------------------------"<<endl;
    	cout<<" ==      REYHAN JARSI YOGA (20081010139)      =="<<endl;
    	cout<<" ----------------------------------------------\n"<<endl;
    	cout<<" =============================================="<<endl;
    	cout<<" =    PROGRAM DATA MAHASISWA BERDASARKAN BST  ="<<endl;
    	cout<<" =============================================="<<endl;
        cout<<" = 	1.Insert Data Mahasiswa BST           ="<<endl;
        cout<<" =	2.Delete Data BST                     ="<<endl;
        cout<<" =	3.Edit Data Mahasiswa BST             ="<<endl;
        cout<<" = 	4.Search Data Mahasiswa BST           ="<<endl;
        cout<<" = 	5.View BST Secara inorder             ="<<endl;
        cout<<" = 	6.View Bst Secara preorder            ="<<endl;
        cout<<" = 	7.View Bst Secara postorder           ="<<endl;
        cout<<" = 	8.exit                                ="<<endl;
        cout<<" =============================================="<<endl;
        cout<< "\n\n>> Pilih Metode Yang Digunakan : "; cin >> x;
    switch(x)
    {
    case 1:
		q.insert(); 
		cout<<"\nContact Insertion successful"; 
		break;
    case 2:
        cout<<"\nMasukkan Nama Mahasiswa:";
	    cin>>a;
	    q.root=q.deleteNode(q.root,a);
	    cout<<"\n Delete Data Mahasiswa Berhasil";
	    cout<<"\n=============================================="<<endl;
	    cout<<"\n Data Mahasiswa Setelah Dihapus\n";
	    q.inorder();
	    break;
    case 3:
	    cout<<"\nMasukkan Nama Mahasiswa:";
	    cin>>a;
	    q.root=q.edit(q.root,a);
	    cout<<"\nData Mahasiswa Telah Diupdate";
	    cout<<"\n=============================================="<<endl;
	    cout<<"\n Data Mahasiswa Setelah Diupdates\n";
	    q.inorder();
	    break;
    case 4:
        cout<<"\nMasukkan Nama Mahasiswa:";
	    cin>>a;
	    cout<<"\n=============================================="<<endl;
	    cout<<"\n Data Mahasiswa Pencarian\n";
	    q.searc(q.root,a); break;
	    
	case 5:
		cout<<"\nDisplay Data Mahasiswa\n";
		q.inorder();
		break;
	case 6:
		cout<<"\nDisplay Data Mahasiswa preorder\n";
		q.preorder();
		break;
	case 7:
		cout<<"\nDisplay Data Mahasiswa preorder\n";
		q.posteorder();
		break;
	case 8:
            exit(1);
            break;
     default:cout<<"\nOption Invalid";
    }
    cout<<"\nContinue?\n";
    cin>>c;
    }while(c=='m'); 
}


void menuawal()
{
    int choose;
    system("cls");
    do {
    	cout<<" -----------------------------------------------"<<endl;
    	cout<<" ==      REYHAN JARSI YOGA (20081010139)      =="<<endl;
    	cout<<" ----------------------------------------------\n"<<endl;
    	cout<<" ================================="<<endl;
    	cout<<" =   PROGRAM UAS DATA MAHASISWA  ="<<endl;
    	cout<<" ================================="<<endl;	
        cout<<" =          1.Secara Avl         ="<<endl;
        cout<<" =          2.Secara Bst         ="<<endl;
        cout<<" ================================="<<endl;
        cout<< "\n\n>> Pilih Metode Yang Digunakan : "; cin >> choose;
        switch (choose){
            case 1:
            	init();
                break;
            case 2:
				bst();
                break;
            default:
                cout << "Pilihan tidak ada\nMasukan pilihan sesuai dengan daftar" << endl;
                break;
        }
        system("cls");
    }while(choose !=2);
}

void insertitems(){
              system("cls");
 cout<<"\t\t---------- Insert Data Mahasiswa ----------"<<endl;
    string subject,nme;
    int marks;
    char status;
    cin.ignore();
      while(true){
        cout<<"Masukkan Nama Mahasiswa ="<<endl;getline(cin, nme);
        cout<<"Prodi Mahasiswa ="<<endl;cin>>subject;
        cout<<"NPM Mahasiswa"<<endl;cin>>marks;
  //cout<<marks <<endl;
        root=avl.insertinto(root,marks,subject,nme);
 		cout<<"Data Mahasiswa Telah Dmasukkan" <<endl;
        cout<<"Klik 'n/N'untuk Lanjut Menu Lainnya "<<endl;
 //cout<<root <<endl;
        cin>>status;
        if(status == 'n' || status == 'N'){
            menuawal();
            break;
      }
        cin.ignore();
        system("cls");
    }
}

void deleteItem() {
  system("cls");
  cout << "\t\t---------- Delete Data Mahasiswa ----------" << endl;
  cout << "Masukkan Nama Mahasiswa yang Ingin Dihapus=" << endl;
  string name, sub;
  int marks;
  cin >> name;
  cout << "Masukkan Prodi Mahasiswa yag Ingin Dihapus=" << endl;
  cin >> sub;
  cout << "Masukkan NPM Mahasiswa Yang Akan Dihapus" << endl;
  cin >> marks;
  if (name,sub,root,marks) {
    root = avl.remove(root, marks, sub, name);
    cout << name << "  " << "item deleted " << endl;
  }
  else {
    cout << "Theres no records for given item " << name << endl;
  }
  switchtomenu();
}
void inorder1(){
system("cls");
cout<<"\t\t---------- Display Data Mahasiswa Secara Inorder Traversal ----------"<<endl;
cout<<endl;
avl.inorder(root);
switchtomenu();
}

void search()
{
    system("cls");
    cout<<"\t\t---------- Search Data Mahasiswa ----------"<<endl;
    cout<<"Masukkan Nama Mahasiswa yang Ingin dicari="<<endl;
    string name,sub;
    int marks;
    cin>>name;
    cout<<"Masukkan Prodi Mahasiswa yag Ingin dicari="<<endl;
    cin>>sub;
    cout<<"Masukkan NPM Mahasiswa Yang Akan dicari"<<endl;
    cin>>marks;

    // Perform search in AVL tree using search function
    avl.search(root, marks, sub, name);
}

void preorder1(){
system("cls");
cout<<"\t\t---------- Display Data Mahasiswa Secara preorder Traversal ----------"<<endl;
cout<<endl;
avl.preorder(root);
switchtomenu();
}

void post(){
system("cls");
cout<<"\t\t---------- Display Data Mahasiswa Secara postrder Traversal ----------"<<endl;
cout<<endl;
avl.postorder(root);
switchtomenu();
}


void switchtomenu(){
	    char status;
	    cout<<"Back to main menu (Y) ";
	    cin>>status;
	    if(status=='Y' || status=='y'){
	         menuawal();
	        return;
	    }
	}

void itemdisplay(){
	    system("cls");
	    cout<<"\t\t---------- Display items ----------"<<endl;
	    cout<<endl;
	    avl.display(root);
	    switchtomenu();
	    //cin.ignore();
	}
void displaytree(){
               system("cls");
    cout<<"\t\t---------- Display items ----------"<<endl;
    cout<<endl;
	    avl.displaytree(root, 1);
	    cout<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<endl;
	    switchtomenu();
}
int main()
{
menuawal();
}


