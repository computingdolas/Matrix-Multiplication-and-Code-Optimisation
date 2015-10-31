/*
#include <iostream>

using namespace std;

template <class T>
class  sagar{
	T first, second 
	public :
		sagar(T a, T b){
		first = a;
		second = b;
		}
		
		T bigger();
		
		
};

template <class T>
T sagar<T>::bigger()
*/
using std::cout;
using std::cin;
using std::endl;
class Matrix 
{
	private :
	int row;
	int col;
	int row1;
	int col1;
	double *ptr;
	
	
	public:
	
	Matrix(int nrow , int ncol ,double ini);//Constructor 
	~Matrix();//Destructor
	Matrix(const Matrix &obj);// Copy constructor 
	Matrix& operator = (const Matrix& obj);//Assignment Operator 
 	void display();// Dislplay Function 
 	//Matrix& operator+=(const Matrix& obj);
 	//Matrix& Operator-=(const Matrix& obj);
 	friend Matrix operator+(const Matrix& obj,const Matrix& obj1);
 	//Matrix operator-(const Matrix& obj,const Matrix& obj1) 

};

Matrix::Matrix(int nrow, int ncol ,double ini)
{
	cout<<" constructor created "<<endl;
	
	row= nrow ;
	col= ncol ;
	ptr = new double [row*col];
	for (int i =0;i < row*col ;++i)
		*(ptr+ i)= ini ;
}

Matrix::~Matrix()
{

	cout<<" Destructor called"<<endl;
	delete [] ptr;
			
}
Matrix& Matrix :: operator = (const Matrix& obj)
{
	cout<<"The Assignment copy constructor is created"<<endl;
	if (this != &obj)
	{
		row= obj.row;
		col = obj.col;
		//ptr = new double [row * col]
		for (int i =0;i < row * col; ++i)
			*(ptr+i)= *(obj.ptr + i);
		
	}

	return *this ;
}
Matrix::Matrix(const Matrix &obj)

{
	cout<<" The copy constructor is created "<<endl;
	row= obj.row ;
	col = obj.col ;
	ptr = new double [row*col];
	//cout<< nrow<<"    "<<ncol;
	for (int j =0;j<row*col ;++j)
		*(ptr+j)= *(obj.ptr +j);
	
	
	//cout << " The elements of "<<j<< " is "<<*(this.ptr +j)<<endl;
		
}

Matrix operator+ (const Matrix& obj,const Matrix& obj1)
{
	cout<<" the addition operator is called "<<endl;
		
	this.row = obj.row;
	this.row1 =obj1.row;
	this.col  =obj.col;
	this.col1 = obj1.col;
	if (obj.row == obj.row1 && obj.col == obj.col1)
		cout<<" The addition is not possible ";
	else 
	{
		for(int i= 0;i< this.row * this.col ;++i )	
		{
			*(this.ptr + i)= *(obj.ptr +i) + *(obj1.ptr + i);
		}
	}

	return temp ;
	


}
void Matrix::display()
{
	cout<<" the display is called cheacking the program"<<endl;
	/*
	int i= 0 ;
	
	for (i=0;i<row;++i
	{	
		for(int j=0;j<col;++j)
		
		//cout<<"The elements of"<<i<<"the matrix are "<<*(ptr + i)<<endl;
		
	}
	*/
}
