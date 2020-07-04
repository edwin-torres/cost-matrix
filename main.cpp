#include <iostream>
#include <vector>

using namespace std;



int maxValue (int x, int y)
{
    return x>y?x:y;
}

int payingMatrix(int m,int n)
{

    int matrix[m][n];
    int price[m][n];

    /*
        example:

            4 5 6
            7 4 2
            2 3 9

            It costs 4 to step on [0][0] and on [1][1].  It costs 5 to step on [0][1]. etc.
    */


    cout << "Enter the matrix ("<<m<<"x"<<n<<") cost values: " << endl;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {

            cin>>price[i][j];

        }

    }

    /*
     Calculates the total cost (Most Expensive) to arrive at a particular cell.

      example:

         4 5 6
         7 4 2
         2 3 9

     it costs a total of 4 to arrive at [0][0].
     it costs a total of 9 to arrive at [0][1].
     it costs a total of 15 to arrive at [1][1].
     it costs a total of 13 to arrive at [2][0]. etc.
    */


    for(int i = 0; i < m; i++)
    {

        for(int j = 0; j < n; j++)
        {

            if(i>0 && j>0)
            {
                matrix[i][j] = maxValue(matrix[i][j-1], matrix[i-1][j]) + price[i][j];
            }
            else
            {
                if(i > 0)
                {
                    matrix[i][j] = matrix[i-1][j] + price[i][j];
                }
                else
                {
                    if(j > 0)
                    {
                        matrix[i][j] = matrix[i][j-1] + price[i][j];
                    }
                    else
                    {
                        if(i==0 && j==0)
                        {
                            matrix[i][j] = price[i][j];
                        }
                    }

                }

            }

        }
    }


    cout << endl;

    //Prints the Price matrix
    cout << "PRICE: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {

            cout << price[i][j] << " ";

        }
        cout << endl;
    }




    cout << endl;


    //Prints the Highest Cost Matrix
    cout << "MATRIX: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {

            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }


    return matrix[m-1][n-1];
}






int main()
{

    int m, n;
    cout << "Enter the Matrix Dimensions." << endl;

    cout << "Number of Rows: " << endl;
    cin>>m;
    cout << "Number of Columns: " << endl;
    cin>>n;



    payingMatrix(m,n);


}


