#include<bits/stdc++.h>
using namespace std;
class binarytree{
	public:
	int data;
	binarytree *left;
	binarytree *right;
	
	binarytree(int data ){
		this->data = data;
		left = NULL;
		right= NULL;
	}
	~binarytree(){
		delete left;
		delete right;
	}
};
void print_tree(binarytree *root){
//	if(root==NULL)return;
//	queue<binarytree*> q;
//	q.push(root);
//	while(!q.empty()){
//		binarytree *front = q.front();
//		q.pop();
//		cout<<front->data<<" ";
//		if(front->left){
//			q.push(front->left);
//		}
//		if(front->right){
//			q.push(front->right);
//		}
	if(root==NULL){
		return ;
	}
	cout<<root->data<<": ";
	//base case
	if(root->left){
		cout<<"L:"<<root->left->data<<" ";
//		printtree(root->left);
	}
	if(root->right){
		cout<<"R:"<<root->right->data<<" ";
	}
	cout<<endl;
	print_tree(root->left);
	print_tree(root->right);
	cout<<endl;
	
	}

	
//	print_tree(root->left);
//	print_tree(root->right);
binarytree* takeinput(){
	cout<<"enter root data"<<endl;
	int val;
	cin>>val;
	binarytree *root= new binarytree(val);
	queue<binarytree*> q;
	q.push(root);
	
	while(!q.empty()){
		binarytree *front = q.front();
		q.pop();
		cout<<"enter left child"<<endl;
		cin>>val;
		if(val!=-1){
			binarytree *l= new binarytree(val);			
			front->left = l;
			q.push(l);
		}
		cout<<"enter right child"<<endl;
		cin>>val;
		if(val!=-1){
			binarytree *r= new binarytree(val);
			front->right = r;
			q.push(r);
		}
	}
	return root;
}

int add_child(binarytree *node){
	if(node==NULL)return 0;
	int val = node->data;
	node->data = add_child(node->left )+ add_child(node->right);
	return node->data + val;
}

int each_node_sum_of_left_tree(binarytree * root){
	if(root==NULL){
		return 0;
	}	
	if(root->left==NULL && root->right==NULL)
	return root->data;
	int val1 = each_node_sum_of_left_tree(root->left);
	root->data = val1 + root->data;
	int val2 = each_node_sum_of_left_tree(root->right);
	return root->data+val2;
}

void mirror_tree(binarytree* node){
	if(node==NULL)return ;
	if(node->left!=NULL && node->right!=NULL)
	{
		binarytree* p;
		p = node->left;
		node->left = node->right;
		node->right = p;
	}
//	swap(node->left, node->right);
	mirror_tree(node->left);
	mirror_tree(node->right);
}

// 1 3 2 -1 -1 5 4 -1 -1 -1 -1  
int height_tree(binarytree *node){
	if(node==NULL)return 0;
	return max(height_tree(node->left), height_tree(node->right))+1;
}
//	int pre_root_id  = 0;
//	int in_root_id;
//	int data = preorder[pre_root_id];
//	for(int i=0;i<n;i++){
//		if(inorder[i]==data){
//			in_root_id = i;
//			break;
//		}
//}

binarytree * from_pre_inorder(int in[], int pre[], int in_start, int in_end, int pre_start, int pre_end, int n){
//	if(in_start<0 || pre_start<0)return NULL;
//	if(in_end>=n || pre_end>=n)return NULL;
if(in_start>in_end)return NULL;
	binarytree *node = new binarytree(pre[pre_start]);
	
	int root_id = -1;
	for(int i= in_start;i<= in_end;i++){
		if (in[i]==pre[pre_start]){
			root_id = i;
			break;
		}
	}
	int left_in_end = root_id-1;
	int left_pre_end = left_in_end - in_start + pre_start+1;
	node->left = from_pre_inorder(in, pre, in_start, left_in_end, pre_start+1, left_pre_end, n );	
	int right_pre_start = left_pre_end+1;
	node->right = from_pre_inorder(in, pre, root_id+1, in_end,right_pre_start , pre_end, n);	
	return node;
}
bool compare_trees(binarytree *node1, binarytree* node2){
	if(node1==NULL && node2==NULL)return true;
	if(node1==NULL || node2==NULL)return false;
	if(node1->data!=node2->data){
		cout<<"mismatch at "<<node1->data<<" "<<node2->data<<endl;
		return false;
	}
//	else if(node1->right->data!=node2->left->data){
//		cout<<"mismatch at "<<node1->right->data<<" "<<node2->left->data<<endl;
//		return false;
//	}
	else 
		return true;
	return compare_trees(node1->left, node2->right) &&  compare_trees(node1->right, node2->left);
//	return true;
}
//1 3 2 -1 -1 5 4 -1 -1 -1 -1
//1 2 3 4 5 -1 -1 -1 -1 -1 -1


pair<int, int> min_max(binarytree *node, int min_v, int max_v){
	if(node == NULL){
		pair<int, int> p;
		p.first = min_v;
		p.second = max_v;
		return p;
	}
//	cout<<"data is: "<<node->data<<" max val is: "<<max_v<<endl;
	if(node->data>max_v){
		max_v = node->data;
	}
	if(node->data<min_v){
		min_v = node->data;
	}
	pair<int, int>p1 = min_max(node->left, min_v, max_v);
	pair<int, int>p2 = min_max(node->right, min_v, max_v);
	if(p1.first<p2.first){
		min_v = p1.first;
	}
	else{
		min_v = p2.first;
	}
	if(p1.second>p2.second){
		max_v = p1.second;
	}else{
		max_v = p2.second;
	}
	return {min_v, max_v};
	//1 2 3 4 5  6 -1 7 -1   -1 -1 -1 -1 -1 -1 
}
bool balanced_tree(binarytree *node){
	if(node==NULL)return true;
	int h1 = height_tree(node->left);
	int h2 = height_tree(node->right);
	if(abs(h1-h2)<=1){
		balanced_tree(node->left);
		balanced_tree(node->right);
		return true;
	}
	return false;
}
// 1 2 -1 3 -1 4 -1 5 -1

void zigzag(binarytree* root){
	stack<binarytree*>s1;
	stack<binarytree*>s2;
	int level =1;
	queue<binarytree *>q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			binarytree*	 f = q.front();
			q.pop();
			s1.push(f);
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
		if(level==1){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			while(!s2.empty()){
				cout<<s2.top()->data<<" ";
				s2.pop();
			}
			cout<<endl;
			level =0;
		}else{
			while(!s1.empty()){
				cout<<s1.top()->data<<" ";
				s1.pop();
			}
			cout<<endl;
			level =1;
		}
	}	
}

class Node{
	public:
	Node *next;
	int data;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};
void levelwise_LL(binarytree *root){
	
	// gather all nodes of a level->make a LL and return that
	queue<binarytree *>q;
	q.push(root);
	vector<int>v;
	Node *head;
	Node* tail;
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			binarytree*	 f = q.front();
			q.pop();
			Node *temp = new Node(f->data);
			if(i==0){
				head = temp;
				tail =temp;
				v.push_back(head->data);
			}else{
				tail->next = temp;
				tail = temp;		
			}
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
	}
	vector<int>::iterator i;
	for( i = v.begin(); i  != v.end(); i++){
        cout << *i << endl;
    }
}
//time: 0 1 1 5
//direc:1 0 1 0
//i:     0
//d:     1
//ans = 1
//1 2 2 3
vector<int> getTimes(int num, vector<int> time, vector<int> direc){
	vector<int>ans;
	vector<int> v(num);
	for(int i=0;i<num;i++){
		v[i]=i;
	}
	int d = 1;//exit
	for(int i=0;i<num;i++){
		if(direc[i]==d){
			ans.push_back(v[i]);
		}else{
			if(time[i+1]!= i){
				ans.push_back(v[i]);
				d =0;
			}
			else if(direc[i+1]==d){
				ans.push_back(v[i+1]);
				direc[i+1] = direc[i];
				time[i+1] = time[i]+1;
				v[i+1] = v[i];
			}
		}
		vector<int>::iterator it;
	for( it = ans.begin(); it  != ans.end(); it++){
        cout << *it << " ";
    }
    cout<<endl;
	}
	return ans;
}
class A{
	public:
		~A(){
			cout<<"Killed"<<endl;
		}
		virtual int func(){
			return 0;
		}
};

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
//	binarytree *root = new binarytree(1);
//	binarytree *l = new binarytree(2);
//	root->left = l;
	A a;
	cout<<a.func()<<endl;
	return 0;
	
//int arr[] =  {0,0,1,5};
//	vector<int>time(arr,arr+4);
//	int a[] = {0,1,1,0};
//	vector<int>direc(a,a+4);
//	int num = 4;
//	vector<int> v = getTimes(num, time, direc);
//	vector<int>::iterator i;
//	for( i = v.begin(); i  != v.end(); i++){
//        cout << *i << endl;
//    }

//	binarytree* root = takeinput();
//	print_tree(root);
//	
//	zigzag(root);
//	levelwise_LL(root);
//	cout<<balanced_tree(root);
//	pair<int, int> p = min_max(root, INT_MAX, INT_MIN);
//	cout<<"min value is "<<p.first<<" max valu is "<<p.second<<endl;
//	int sum =0;
	//	int v = add_child(root);
	//    int x = each_node_sum_of_left_tree(root);
//	mirror_tree(root);
//	cout<<height_tree(root);
//	int n =  9;
//	int inorder[] = {4, 2, 5, 1, 8,6,9,3,7};
//	int preorder[] = {1,2,4,5,3,6,8,9,7};

//	int pre_end = in_root_id - 0 - pre_root_id;
//	binarytree* root = from_pre_inorder(inorder, preorder, 0, n-1, 0, n-1, n );
//	binarytree* root1 = takeinput();
//	print_tree(root1);
//	binarytree* root2 = takeinput();
//	print_tree(root2);
//	cout<<compare_trees(root1, root2);
//	cout<<endl;
//	print_tree(root);
//	delete root;
}

//-1 -1
// + each_node_sum_of_left_tree(root->left->right)












//day 0: 5000 5000*2  5000*3   5000*4   5000*5
//day 1: 5000+5000+1  5000*3 + 5000 + 1
//n = 10 25003=> 
//
//10
