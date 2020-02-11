#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ME 0 
#define COMPUTER 1
using namespace std;
class Node
{
public:
	int parent;
	int branch;
	int value;
	int player;
	bool seen;
	vector<int> leaf;
	Node();
};
Node::Node(){
	value = 0;
	parent = 0;
	branch = 0;
}
vector<Node> tree;
int n;
void Inputtree(){
	cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++)
	{
		// cout<<"now node id : "<<i<<endl;
		cin >> tree.at(i).player >> tree.at(i).branch;
		tree.at(i).leaf.resize(tree.at(i).branch);
		for (int j = 0; j < tree.at(i).branch; j++){
			cin >> tree.at(i).leaf.at(j);
		}
		if(tree.at(i).branch==0){
			cin >> tree.at(i).value;
		}else{
			if(tree.at(i).player == ME){
				tree.at(i).value = -100000;
			}else if(tree.at(i).player == COMPUTER){
				tree.at(i).value = 10000;
			}
		}
	} 
}
int MiniMax(Node node){
	int r = node.value;
	if(node.branch>0){
		if(tree[node.leaf[0]].player == COMPUTER){//次の手がComputer -> 最大値を取る
			for (int i = 0; i < node.branch; ++i)
			{
				if(r<MiniMax(tree[node.leaf[i]])){
					r = MiniMax(tree[node.leaf[i]]);
				}
			}
		}else if(tree[node.leaf[0]].player == ME){//次の手が自分　-> 最小値を取る
			for (int i = 0; i < node.branch; ++i)
			{
				if(r>MiniMax(tree[node.leaf[i]])){
					r = MiniMax(tree[node.leaf[i]]);
				}
			}
		}
	}
	return  r;
};
int main(){
	Inputtree();
	cout<<MiniMax(tree[0])<<endl;
	return 0;
}