#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

// =====================================functions prototypes=====================================================

bool define_matrix(vector <vector <vector <double> > >& matrices, string m);
void display(const vector <vector <double> >& matrix); //display one matrix
void display(const vector <vector <vector <double> > >& matrices); //display an array of matrices
void list();
vector <vector <double> >  add_matrix(const vector <vector <double> >& matrixx, const vector <vector <double> >& matrixy);
vector <vector <double> >  sub_matrix(const vector <vector <double> >& matrixx, const vector <vector <double> >& matrixy);
vector<vector<double>> multiply_matrix(const vector <vector <double> >& matrixx, const vector <vector <double> >& matrixy);
double det(const vector <vector <double> >& matrix);
void trans(vector <vector <double> >& matrix);
void cofactor(vector <vector <double> >& matrix);
vector<vector<double>> inverse(const vector <vector <double> >& matrix);
void operators(vector <vector <vector <double> > >& matrices);

// =====================================functions prototypes=====================================================


int main()
{

    vector <vector <vector <double> > > matrices;

    char option{ 'e' };
    list();
    do
    {
        cout << "enter option : ";
        cin >> option;
        option = tolower(option);

        if (option == 'a')
        {
            do
            {
                int r, c;
                cout << "Please enter the order of the matrix separated by space (rows columns): ";
                cin >> r; cin >> c;

                vector <vector <double>> matrix;
                for (int i = 0; i < r; i++)
                {
                    cout << "Enter the numbers of the row number " << i + 1 << " separated by space: ";
                    vector <double> row;
                    for (int j = 0; j < c; j++)
                    {
                        double temp; cin >> temp;
                        row.push_back(temp);
                    }
                    matrix.push_back(row);
                }
                matrices.push_back(matrix);
                cout << "do you want to add another matrix (y/n): ";
                char o; cin >> o;
                o = tolower(o);
                if (o == 'n')
                    break;
            } while (true);

            list();
        }
        else if (option == 's')
        {
            display(matrices);
            list();
        }
        else if (option == 'o')
        {
            operators(matrices);
            list();
        }
    } while (option != 'e');

}

void list()
{
    cout << "please choose option from below" << endl;
    cout << "A. to define a matrix and add it to the list" << endl;
    cout << "S. to show the matrices you defined" << endl;
    cout << "O. to do an operation on two matrices" << endl;
    cout << "E or \"exit\" to close the program" << endl;
}

bool define_matrix(vector <vector <vector <double> > >& matrices, string m)
{
    vector<vector<double>> matrix;
    string mat{ m };
    istringstream sin{ m };
    istringstream min{ mat };

    char c;
    double d;

    //determine the number of the columns
    int columns{ 0 };
    sin >> c;
    while (sin >> d)
        columns++;

    //pushing the matrix to the list

    while (c != ']')
    {
        vector<double> temp;
        for (int i{ 0 }; i < columns; i++) {
            min >> d;
            temp.push_back(d);
        }

        matrix.push_back(temp);
        min >> c;
    }
    matrices.push_back(matrix);

    //checking for the last matrix
    min >> c;

    if (c != '.')
        return true;

    return false;



}
void display(const vector <vector <double> >& matrix)// to display a single matrix
{
    for (auto I : matrix)
    {
        for (auto II : I)
            cout << setprecision(2) << fixed << " " << II << " ";
        cout << endl;
    }

}
void display(const vector <vector <vector <double> > >& matrices)
{
    cout << "=======================================================" << endl;
    for (size_t i{ 0 }; i < matrices.size(); i++)
    {
        cout << "matrix no. (" << i + 1 << ")\n" << endl;
        display(matrices.at(i));
    }
    cout << "=======================================================" << endl;

}
void operators(vector <vector <vector <double> > >& matrices)
{
    display(matrices);
    cout << "you can do the following operations :" << endl;
    cout << "1. [1 + 2] (to add matrix no.1 and no.2)" << endl;
    cout << "1. [1 - 2] (to subtract matrix no.2 from no.1)" << endl;
    cout << "2. [1 * 2] (to multiply matrix no.1 with no.2)" << endl;
    cout << "3. [1 / 2] (to divide matrix no.1 by no.2)" << endl;
    cout << "4. [1'] (to calculate the transpose of a matrix)" << endl;

    int x, y;
    char operation;
    cin >> x >> operation;
    if (operation == '+')
    {
        cin >> y;
        cout << "***************************************************" << endl;
        display(add_matrix(matrices.at(x - 1), matrices.at(y - 1)));
        cout << "***************************************************" << endl;

    }
    else if (operation == '-')
    {
        cin >> y;
        cout << "***************************************************" << endl;
        display(sub_matrix(matrices.at(x - 1), matrices.at(y - 1)));
        cout << "***************************************************" << endl;

    }
    else if (operation == '*')
    {
        cin >> y;
        cout << "***************************************************" << endl;
        display(multiply_matrix(matrices.at(x - 1), matrices.at(y - 1)));
        cout << "***************************************************" << endl;

    }
    else if (operation == '/')
    {
        cin >> y;
        cout << "***************************************************" << endl;
        display(multiply_matrix(matrices.at(x - 1), inverse(matrices.at(y - 1))));
        cout << "***************************************************" << endl;

    }
    else if (operation == '\'')
    {
        vector <vector<double> > temp = matrices.at(x - 1);
        trans(temp);
        cout << "***************************************************" << endl;
        display(temp);
        cout << "***************************************************" << endl;
    }

}
vector <vector <double> >  add_matrix(const vector <vector <double> >& matrixx, const vector <vector <double> >& matrixy)
{
    if (matrixx.size() != matrixy.size() || matrixx.at(0).size() != matrixy.at(0).size())
    {
        cout << "the operation can not be done because the order of the two matrices is not the same " << endl;
        return vector<vector<double>> { {0.00} };
    }

    size_t rows = matrixx.size();
    size_t columns = matrixy.at(0).size();

    //defining a matrix that has the same size of the matrices to be added
    vector <vector <double> > temp(rows, vector<double>(columns));

    //adding the corresponding elemnts of the two arrays and storing the result in temp
    for (size_t i{ 0 }; i < rows; i++)
        for (size_t j{ 0 }; j < columns; j++)
            temp.at(i).at(j) = matrixx.at(i).at(j) + matrixy.at(i).at(j);

    return temp;

}
vector <vector <double> >  sub_matrix(const vector <vector <double> >& matrixx, const vector <vector <double> >& matrixy)
{
    if (matrixx.size() != matrixy.size() || matrixx.at(0).size() != matrixy.at(0).size())
    {
        cout << "the operation can not be done because the order of the two matrices is not the same " << endl;
        return vector<vector<double>> { {0.00} };
    }

    size_t rows = matrixx.size();
    size_t columns = matrixy.at(0).size();

    //defining a matrix that has the same size of the matrices to be subtracted
    vector <vector <double> > temp(rows, vector<double>(columns));

    //subtracting the corresponding elemnts of the two arrays and storing the result in temp
    for (size_t i{ 0 }; i < rows; i++)
        for (size_t j{ 0 }; j < columns; j++)
            temp.at(i).at(j) = matrixx.at(i).at(j) - matrixy.at(i).at(j);

    return temp;

}
vector<vector<double>> multiply_matrix(const vector <vector <double> >& matrixx, const vector <vector <double> >& matrixy)
{
    size_t ry{ matrixy.size() };
    size_t cy{ matrixy.at(0).size() };
    size_t rx{ matrixx.size() };
    size_t cx{ matrixx.at(0).size() };

    if (ry != cx)
    {
        cout << "the operation can not be done" << endl;
        return vector<vector<double>> { {0} };
    }

    vector <vector <double> > temp(rx, vector<double>(cy));
    for (size_t i{ 0 }; i < rx; i++)
        for (size_t j{ 0 }; j < cy; j++)
            for (size_t k{ 0 }; k < ry; k++)
                temp.at(i).at(j) += (matrixx.at(i).at(k) * matrixy.at(k).at(j));

    return temp;
}
double det(const vector <vector <double> >& matrix)
{
    size_t rows{ matrix.size() };
    size_t columns{ matrix.at(0).size() };

    if (rows == columns)
    {

        if (rows == 1)
            return matrix.at(0).at(0);

        double determinant{ 0 };

        for (size_t j{ 0 }; j < columns; j++)
        {
            vector <vector<double> > temp;

            for (size_t m{ 1 }; m < rows; m++)
            {
                vector <double> temp0;

                for (size_t n{ 0 }; n < columns; n++)
                {
                    if (n != j)
                        temp0.push_back(matrix.at(m).at(n));
                }

                temp.push_back(temp0);
            }

            determinant += pow(-1, j) * matrix.at(0).at(j) * det(temp);
        }
        return determinant;
    }
    else
    {
        cout << "the determinant can be only calculated for square matrices" << endl;
        return 9999999999.999999;
    }
}
void trans(vector <vector <double> >& matrix)
{
    size_t rows{ matrix.size() };
    size_t columns{ matrix.at(0).size() };

    vector <vector <double> > temp(rows, vector<double>(columns));

    for (size_t i{ 0 }; i < rows; i++)
        for (size_t j{ 0 }; j < rows; j++)
            temp.at(j).at(i) = matrix.at(i).at(j);

    matrix = temp;
}
void cofactor(vector <vector <double> >& matrix)
{
    size_t rows{ matrix.size() };
    size_t columns{ matrix.at(0).size() };

    vector <vector <double> > cofactor(rows, vector<double>(columns));

    for (size_t i{ 0 }; i < rows; i++)
    {
        for (size_t j{ 0 }; j < columns; j++)
        {
            vector <vector<double> > temp;

            for (size_t m{ 0 }; m < rows; m++)
            {
                vector <double> temp0;

                for (size_t n{ 0 }; n < columns; n++)
                {
                    if (m != i && n != j)
                        temp0.push_back(matrix.at(m).at(n));
                }
                if (m != i)
                    temp.push_back(temp0);
            }

            cofactor.at(i).at(j) = pow(-1, j) * pow(-1, i) * det(temp);
        }

    }

    matrix = cofactor;

}
vector<vector <double> > inverse(const vector <vector <double> >& matrix)
{

    if (det(matrix) == 0)
    {
        cout << "the matrix does not have an inverse" << endl;
        return vector<vector<double> > { {0} };
    }
    size_t rows{ matrix.size() };
    size_t columns{ matrix.at(0).size() };

    vector <vector <double> > temp(rows, vector<double>(columns));
    temp = matrix;
    cofactor(temp);
    trans(temp);
    double determinant{ det(matrix) };


    for (size_t i{ 0 }; i < rows; i++)
        for (size_t j{ 0 }; j < columns; j++)
        {
            temp.at(i).at(j) = (1 / determinant) * temp.at(i).at(j);
        }

    return temp;
}


