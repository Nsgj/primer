#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "StrVec.h"
#include "structX.h"
#include "HasPtr.h"
#include <algorithm>
int main(int argc, char** argv){
	/*StrBlob sb1({ "a", "b" });
	auto i = sb1.count();
	printf("%d\n", i);

	StrBlob sb2(sb1);
     i = sb2.count();
	printf("%d\n", i);

	StrBlobPtr sbp1(sb1);
	i = sbp1.count();
	printf("%d\n", i);

	StrBlobPtr sbp2(sbp1);
	i = sbp1.count();
	printf("%d", i);*/
	/*X x1;
	X X2(x1);*/
	std::vector<HasPtr> v1={ HasPtr("Asf", 1), HasPtr("bsfd", 32), HasPtr("csfsd", 124), HasPtr("dfsdf", 2) };
	std::sort(v1.begin(), v1.end());

}