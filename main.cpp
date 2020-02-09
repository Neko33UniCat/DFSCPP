
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Node{
public:
	int value;
	int parent;
	int branch;
	int seen;
	vector<int> children;
	Node();
};
Node::Node(){
	value = 0;
	parent = 0;
	branch = 0;
}
vector<Node> tree;
int n;//頂点の数
void inputtree(){
	cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++)
	{
		// cout<<"now node id : "<<i<<endl;
		if(i==0){
			tree[i].parent = -1;
			cin >> tree.at(i).branch;
			if(tree.at(i).branch == 0){
				cin >> tree.at(i).value;
			}else{
				tree.at(i).children.resize(tree.at(i).branch);
				for (int j = 0; j < tree.at(i).branch; j++)
				{
					cin >> tree.at(i).children.at(j);
				}
				tree.at(i).value = -1;
			}
		}else{
			cin >> tree.at(i).parent >> tree.at(i).branch;
			if(tree.at(i).branch == 0){
				cin >> tree.at(i).value;
			}else{
				tree.at(i).children.resize(tree.at(i).branch);
				for (int j = 0; j < tree.at(i).branch; j++)
				{
					cin >> tree.at(i).children.at(j);
				}
				tree.at(i).value = -1;
			}
		}
		tree.at(i).seen = -1;
	} 
}
int DFS(Node node){
	int r = node.value;
	for(int i = 0;i<node.branch;i++){
		if(r<DFS(tree[node.children[i]])){
			r = DFS(tree[node.children[i]]);
		}
	}
	return r;
}
int main(){
	inputtree();
	cout<<DFS(tree[0])<<endl;;
	// for_each(tree.begin(), tree.end(), [](int x){cout<<DFS(x);});
	return 0;
} 

