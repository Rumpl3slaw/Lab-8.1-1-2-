#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Print(char* A)
{
	if (strlen(A) < 2)
		return 0;

	int k = 0;
	for (int i = 0;A[i + 1] != 0;i++)
		if (A[i] == ',' && A[i + 1] == '-')
			k++;
	return k;
}
char* Change(char* A)
{
	if (strlen(A) > 2)
		return A;
	char* B = new char[strlen(A) * 4 / 2 + 1];
	char* b = B;

	B[0] = '\0';
	int i = 0;
	while (A[i ] != 0)
	{
		if ( A[i + 1] == '-')
		{
			strcat(b, "*");
				b += 4;
			    i += 2;

		}
		else
		{
			*b++ = A[i++];
			*b = '\0';	
		}
	}
	*b++ = A[i++];
	*b++ = A[i++];
	*b = '\0';
	strcpy(A, B);
	return B;
}

int main()
{
	char A[101];
	cout << "Enter string:" << endl;
	cin.getline(A, 100);

	cout << "String conteined " << Print(A) << " groups of ', -' " << endl;
	Print(Change(A));
	cout << "Modified string (param):" << A << endl;
	return 0;

}