#include<iostream>

using namespace std;

int MyStrlen(const char* p)
{
	int count = 0;
	while (*p != '\0')
	{
		count++; 
		p++;
	}
	return count;
}

class Mstr
{
public:

	Mstr()
	{
		mstr = nullptr;
		length = 0;
	}

	Mstr(const char* str)
	{
		length = MyStrlen(str);

		this->mstr = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->mstr[i] = str[i];
		}

		this->mstr[length] = '\0';
	}

	~Mstr()
	{
		delete[] this->mstr;
	}

	int lenght()
	{
		return length;
	}

	Mstr& operator =(const Mstr& scnd)
	{
		if (this->mstr != nullptr)
		{
			delete[] mstr;
		}
		length = MyStrlen(scnd.mstr);
		this->mstr = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->mstr[i] = scnd.mstr[i];
		}
		this->mstr[length] = '\0';
		return *this;
	}
	
	char& operator [](int index)
	{
		return this->mstr[index];
	}
	
	void clear() {
		delete[] mstr;
		mstr = nullptr;
		length = 0;

	}
	bool empty() {
		return !length;
	}
	void push_back(char s) {
		char* tmp = new char[length + 2];
		for (int i = 0; i < length; i++) {
			tmp[i] = mstr[i];
		}
		tmp[length] = s;
		tmp[length + 1] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length++;
	}
	void erase(int pos) {
		char* tmp = new char[pos + 1];
		for (int i = 0; i < pos; i++) {
			tmp[i] = mstr[i];
		}
		tmp[pos] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length = pos;
	}
	void erase(int pos, int num) {
		if (pos + num >= length) {
			this->erase(pos);
		}
		else {
			char* tmp = new char[length - num + 1];
			for (int i = 0; i < pos; i++) {
				tmp[i] = mstr[i];
			}
			int j = pos;
			for (int i = pos + num; i < length; i++) {
				tmp[j] = mstr[i];
				j++;
			}
			tmp[length - num] = '\0';
			delete[] mstr;
			mstr = tmp;
			tmp = nullptr;
			length = length - num;
		}
	}
	void resize(int n) {
		if (n > length) {
			char* tmp = new char[n + 1];
			for (int i = 0; i < length; i++) {
				tmp[i] = mstr[i];
			}
			tmp[n] = '\0';
			delete[] mstr;
			mstr = tmp;
			tmp = nullptr;
			length = n;
		}
		else if (n < length) {
			char* tmp = new char[n + 1];
			for (int i = 0; i < n; i++) {
				tmp[i] = mstr[i];
			}
			tmp[n] = '\0';
			delete[] mstr;
			mstr = tmp;
			tmp = nullptr;
			length = n;
		}
	}
	void resize(int n, char c) {
		if (n > length) {
			char* tmp = new char[n + 1];
			for (int i = 0; i < length; i++) {
				tmp[i] = mstr[i];
			}
			for (int i = length; i < n; i++) {
				tmp[i] = c;
			}
			tmp[n] = '\0';
			delete[] mstr;
			mstr = tmp;
			tmp = nullptr;
			length = n;
		}
		else if (n < length) {
			char* tmp = new char[n + 1];
			for (int i = 0; i < n; i++) {
				tmp[i] = mstr[i];
			}
			tmp[n] = '\0';
			delete[] mstr;
			mstr = tmp;
			tmp = nullptr;
			length = n;
		}
	}
	void append(int n, char c) {
		char* tmp = new char[length + n + 1];
		for (int i = 0; i < length; i++) {
			tmp[i] = mstr[i];
		}
		for (int i = length; i < n + length; i++) {
			tmp[i] = c;
		}
		tmp[length + n] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length = length + n;
	}
	void append(const Mstr& other, int pos, int num) {
		char* tmp = new char[length + num + 1];
		for (int i = 0; i < length; i++) {
			tmp[i] = mstr[i];
		}
		int j = pos;
		for (int i = length; i < num + length; i++) {
			tmp[i] = other.mstr[j];
			j++;
		}
		tmp[length + num] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length = length + num;
	}
	void insert(int i, int n, char c) {
		char* tmp = new char[length + n + 1];
		for (int j = 0; j < i; j++) {
			tmp[j] = mstr[j];
		}
		for (int j = i; j < i + n; j++) {
			tmp[j] = c;
		}
		int k = i;
		for (int j = i + n; j < length + n; j++) {
			tmp[j] = mstr[k];
			k++;
		}
		tmp[length + n] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length = length + n;
	}
	void insert(int i, const Mstr& other, int pos, int num) {
		char* tmp = new char[length + num + 1];
		for (int j = 0; j < i; j++) {
			tmp[j] = mstr[j];
		}
		int k = pos;
		for (int j = i; j < i + num; j++) {
			tmp[j] = other.mstr[k];
			k++;
		}
		k = i;
		for (int j = i + num; j < length + num; j++) {
			tmp[j] = mstr[k];
			k++;
		}
		tmp[length + num] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length = length + num;
	}
	void replace(int pos, int num, int n, char c) {
		char* tmp = new char[length - num + n + 1];
		for (int i = 0; i < pos; i++) {
			tmp[i] = mstr[i];
		}
		for (int i = pos; i < pos + n; i++) {
			tmp[i] = c;
		}
		int j = pos + num;
		for (int i = pos + n; i < length - num + n; i++) {
			tmp[i] = mstr[j];
			j++;
		}
		tmp[length - num + n] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length = length - num + n;
	}
	void replace(int pos, int num, const Mstr& other) {
		char* tmp = new char[length - num + other.length + 1];
		for (int i = 0; i < pos; i++) {
			tmp[i] = mstr[i];
		}
		int j = 0;
		for (int i = pos; i < pos + other.length; i++) {
			tmp[i] = other.mstr[j];
			j++;
		}
		j = pos + num;
		for (int i = pos + other.length; i < length - num + other.length; i++) {
			tmp[i] = mstr[j];
			j++;
		}
		tmp[length - num + other.length] = '\0';
		delete[] mstr;
		mstr = tmp;
		tmp = nullptr;
		length = length - num + other.length;
	}


	friend istream& operator>>(istream& stream, Mstr& input_string);
	friend ostream& operator<<(ostream& out, const Mstr&);
	friend bool operator>(const Mstr& lhs, const Mstr& rhs);
	friend bool operator<(const Mstr& lhs, const Mstr& rhs);
	friend bool operator>=(const Mstr& lhs, const Mstr& rhs);
	friend bool operator<=(const Mstr& lhs, const Mstr& rhs);

private:
	char* mstr;
	int length;
};

char* strcopy(char* dst, const char* src) {
	if (*dst = *src)
		strcopy(dst + 1, src + 1);
	return dst;
}

istream& operator>>(istream& stream, Mstr& string) {
	char* input_data = nullptr;
	int counter = 0;
	char symbol;
	while (true) 
	{
		if ((symbol = stream.get()) != '\n') {
			input_data = (char*)realloc(input_data, ++counter);
			input_data[counter - 1] = symbol;
		}
		else {
			input_data = (char*)realloc(input_data, ++counter);
			input_data[counter - 1] = '\0';
			break;
		}
	}
	string.mstr = new char[counter];
	strcopy(string.mstr, input_data);
	string.length = string.lenght();
	return stream;
}

ostream& operator<<(ostream& out, const Mstr& string)
{
	out << string.mstr;
	return out;
}

bool operator>(const Mstr& lhs, const Mstr& rhs)
{
	return (MyStrlen(lhs.mstr) > MyStrlen(rhs.mstr)) ? true : false;
}

bool operator>=(const Mstr& lhs, const Mstr& rhs)
{
	return (MyStrlen(lhs.mstr) >= MyStrlen(rhs.mstr)) ? true : false;
}
bool operator<(const Mstr& lhs, const Mstr& rhs)
{
	return (MyStrlen(lhs.mstr) < MyStrlen(rhs.mstr)) ? true : false;
}
bool operator<=(const Mstr& lhs, const Mstr& rhs)
{
	return (MyStrlen(lhs.mstr) <= MyStrlen(rhs.mstr)) ? true : false;
}


template<class S>

void Swap(S* x, int i, int j)
{
	S temp;
	temp = x[i]; 
	x[i] = x[j]; 
	x[j] = temp;
}

template<class S>

void ChoiceSort(S* x, int n)
{
	int last = n - 1;

	int left = 1, right = n - 1;

	do {
		for (int j = right; j > 0; j--)
		{

			if (x[j - 1][0] > x[j][0])
			{
				Swap(x, j - 1, j);
				last = j;
			}
		}

		left = last + 1;

		for (int j = 1; j <= right; j++)
		{
			if (x[j - 1][0] > x[j][0])
			{
				Swap(x, j - 1, j);

				last = j;


			}
		}
		right = last - 1;
	} while (left < right);

}

/*template<class S>

void AlphabeticalSort(S* x, int n)
{
	bool HasChanged;
	do
	{
		HasChanged = false;
		for (int i = n - 1; i > 0; i--)
		{
			int ii = i - 1;
			if (x[i][0] == x[ii][0])
			{
				for (int j = 0; j < x[i].lenght() && j < x[ii].lenght(); ++j)
				{
					if (x[ii][j] < x[i][j])
					{
						break;
					}
					else if (x[i][j] < x[ii][j])
					{
						Swap(x, i, ii);
						HasChanged = true;
						break;
					}
					else
					{
						if (x[i].lenght() == j + 1 && x[ii].lenght() != j + 1)
						{
							Swap(x, i, ii);
							HasChanged = true;
							break;
						}
						else if (x[ii].lenght() == j && x[i].lenght() != j)
						{
							break;
						}
					}


				}
			}
		}
	} while (HasChanged == true);
}
*/

template<typename S>

void arrout(S* arr, int n)

{
	for (int i = 0; i < n; i++)

		cout << i + 1 << ". " << arr[i] << endl;

	cout << endl;
}


int main()
{
	int n;
	cout << "Enter the amount of strings: ";
	cin >> n;
	while (n < 2)
	{
		cout << "Input error. Number should be more than 1!" << endl;
		cin >> n;
	}
	long int count = 0;
	Mstr* arr = new Mstr[n];
	cout << "Enter strings: " << endl;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << endl << "Unsorted array:\n";

	arrout(arr, n);

	ChoiceSort(arr, n);

	Mstr TS;
	
	int i, j, F, m;
	for (i = 0; i < n - 1; ++i) 
	{
		F = i + 1;
		TS = arr[F];
		for (j = i + 1; j > 0; j--) 
		{
			if (TS[0] == arr[j - 1][0])
			{
				if (TS.lenght() == 1) 
				{
					arr[j] = arr[j - 1];
					F = j - 1;
				}
				else 
				{
					m = 1;
					while (m < TS.lenght() && m < arr[j - 1].lenght()) 
					{
						if (TS[m] == arr[j - 1][m]) 
						{
							m++;
							if (TS.lenght() == m) 
							{
								arr[j] = arr[j - 1];
								F = j - 1;
							}
						}
						else if (TS[m] < arr[j - 1][m]) 
						{
							arr[j] = arr[j - 1];
							F = j - 1;
							m = TS.lenght();
						}
						else 
						{
							m = TS.lenght();
						}
					}
				}
			}
		}
		arr[F] = TS;
	}
	cout << "Sorted array: " << endl;
	arrout(arr, n);
	delete[]arr;
}
