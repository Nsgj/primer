#include "TreeNode.h"
class BinStrTree{
public:
	BinStrTree():root(nullptr),use(new size_t(1)){

	}
	BinStrTree(const BinStrTree&bst):root(bst.root){
		++*bst.use;
		use = bst.use;
	}
	BinStrTree& operator=(const BinStrTree&bst){
		++*bst.use;//移动指针不能随便delete 它指向的内容，因为可能有其他指针指向着
		if (--*use == 0){
			delete root;
			delete use;
		}
		root = bst.root;
		return *this;
	}
	~BinStrTree(){
		if (--*use){
			delete root;
			delete use;
		}
	}
private:
	TreeNode *root;
	std::size_t *use;
};