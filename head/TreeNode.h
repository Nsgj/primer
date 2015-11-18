#include <string>
class	TreeNode{
public:
	TreeNode() :value(std::string()), count(1), left(nullptr), right(nullptr){}

	TreeNode(const TreeNode&rhs) :value(rhs.value), count(rhs.count){
		right = new TreeNode(*rhs.left);
		left = new TreeNode(*rhs.right); 
	}
	TreeNode& operator=(const TreeNode&rhs){
		value = rhs.value;
		count = rhs.count;
		auto tempLeft = *rhs.left;
		auto tempRight = *rhs.right;
		delete left;
		delete right;
		left = &tempLeft;
		right = &tempRight;
	}

	~TreeNode(){
		delete left;
		delete right;
	}
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};