#include "Polynomial.h"
int main()
{
	Polynomial A = nullptr, sum1 = nullptr, sum2 = nullptr, A_c = nullptr;
	CreatePolyn(A, 4);
	Traverse(A);

	CopyPolyn(A, A_c);

	Reverse(A);
	Traverse(A);

	Add(A_c, A_c, sum1);
	Traverse(sum1);

	Sub(A_c, A_c, sum2);
	Traverse(sum2);

	double x;
	cin >> x;
	double value = Evaluate(A_c, x);
	cout << "多项式在 x = " << x
		<< " 时的值为：" << value << endl;

	DestroyPolyn(A);
	DestroyPolyn(A_c);
	DestroyPolyn(sum1);
	DestroyPolyn(sum2);
	return 0;
}