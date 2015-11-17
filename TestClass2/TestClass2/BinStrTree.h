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
		++*bst.use;//�ƶ�ָ�벻�����delete ��ָ������ݣ���Ϊ����������ָ��ָ����
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