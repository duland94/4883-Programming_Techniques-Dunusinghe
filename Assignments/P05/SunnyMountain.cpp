#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
//first creata a struct to store the x and y coordinates of each point and cols
struct Point
{
    int x; //for x coordinates
    int y; //for y coordinates
};

bool comparison(const Point &a, const Point &b)
{
    return b.x < a.x;
}

//to calculate the euclidean line length
double calLength(Point a, Point b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{

    //to hold the Coordinates
    int C;
              //for number of cases
    int N;                //for number of points and cols
    int count = 0;        //to store the values in the array
    cin >>C;
    //scanf("%d", &C);
    const int size=C;  
    double lengthForCase[size];


    

    while (C--)
    {
        // to get and put those points to vector
        cin >> N; //get the number of points and cols
         vector<Point> points;
        for (int a = 0; a < N; a++)
        {
            Point point;
            cin >> point.x >> point.y;
            points.push_back(point);
        }
        //now we got the array of pointer vector
        //need to sort that vector based on X coordinates in descending order
        sort(points.begin(), points.end(), comparison);

        //now we have a sorted vector and we can start the calculation
        //we need to track the Y values and go  with the X values

        int Yval = 0;      //start from the most right side
        double length = 0; //to store the final length

        for (int a = 1; a < points.size(); ++a)
        {
            if (points[a].y > Yval)
            {
                length += calLength(points[a], points[a - 1]) * (points[a].y - Yval) / (points[a].y - points[a - 1].y);
                Yval = points[a].y;
            }
        }


        
       
        lengthForCase[count] = length;
        count++;
    }

    //to display the values
    for (int a = 0; a < sizeof(lengthForCase) / sizeof(lengthForCase[0]); a++)
    {
        cout << setprecision(2) <<setiosflags(ios::fixed)<< lengthForCase[a] << endl;
    }

    return 0;
}

