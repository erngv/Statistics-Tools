#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int factorial(int num)
{
    if (num == 0) return 1;
    else return num * factorial(num - 1);
}

double mean(vector<double> v, int len)
{
    double mean = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mean += v[i];
    }
    return mean/len;
}

double weighted_mean(vector<double> v, int len)
{
    double numerator = 0, denominator = 0;
    for (int i = 0; i < v.size(); i++)
    {
        numerator += v[i] * v[i+len];
        denominator += v[i+len];
    }
    return numerator/denominator;
}

double mode(vector<double> v, int len)
{
    sort(v.begin(),v.end());
    int counter = 1, largest = 0;
    double mode, tmp = v[len-1];
    for (int i = len-2; i >= 0; i--)
    {
        if (v[i] == tmp) counter++;
        else tmp = v[i];

        if (largest <= counter)
        {
            largest = counter;
            mode = v[i];
            counter = 1;
        }
    }
    return mode;
}

double median(vector<double> v, int len)
{
    sort(v.begin(),v.end());
    double median, m1, m2;
    if (len % 2 == 0) {
        m1 = v[len/2 - 1];
        m2 = v[len/2];
        median = (m1 + m2) / 2;
    } else {
        median = v[len/2];
    }
    return median;
}

double standard_dev(vector<double> v, int len)
{
    double numerator = 0, u = mean(v, len);
    for (int i = 0; i < len; i++)
    {
        numerator += pow((v[i] - u), 2);
    }
    return sqrt(numerator/len);
}

int main()
{
    int choice;
    do {
        cout << "Select computation to perform:" << endl <<

                "0. Exit\n" <<
                "1. Mean\n" <<
                "2. Weighted Mean\n" <<
                "3. Mode\n" <<
                "4. Median\n" <<
                "5. Standard Deviation\n" <<
                "6. Factorial\n" <<
                "7. Quartiles (Lower, Middle, Upper)\n" <<
                "8. Interquartile Range\n" <<
                "9. Binomial Probability Distribution\n" <<
                "10. Geometric Probability Distribution\n" <<
                "11. Poisson Probability Distribution\n" <<
                "12. Normal Probability Distribution\n" <<
                "13. Central Limit Theorem\n" <<
                "14. Pearson Correlation Coefficient\n" <<
                "15. Spearman's Rank Correlation Coefficient\n\n" <<

                "Your choice --> ";

        cin >> choice;
        cout << endl;
        
        vector<double> v;
        int len, iter;
        double tmp;
        
        switch(choice)
        {
            case 0:
                cout << "Have a nice day!" << endl << endl;
                break;
            //=========================================================================================================
            case 1:
                cout << "Enter the number of elements in the data set --> ";
                cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nMean = " << mean(v, len) << endl << endl;
                v.clear();
                break;
            //=========================================================================================================
            case 2:
                cout << "Enter the number of elements in the data set --> ";
                cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << "Now enter their respective weights (separated by spaces) --> ";
                iter = 0;
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nWeighted Mean = " << weighted_mean(v, len) << endl << endl;
                v.clear();
                break;
            //=========================================================================================================
            case 3:
                cout << "Enter the number of elements in the data set --> ";
                cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nMode = " << mode(v, len) << endl << endl;
                v.clear();
                break;
            //=========================================================================================================
            case 4:
                cout << "Enter the number of elements in the data set --> ";
                cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nMedian = " << median(v, len) << endl << endl;
                v.clear();
                break;
            //=========================================================================================================
            case 5:
                cout << "Enter the number of elements in the data set --> ";
                cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nStandard Deviation = " << standard_dev(v, len) << endl << endl;
                v.clear();
                break;
            //=========================================================================================================
            case 6:
                cout << "Enter the number whose factorial you wish to compute --> ";
                cin >> len;
                cout << endl << len << "! = " << factorial(len) << endl << endl;
                break;
            //=========================================================================================================
            case 7:
                break;
            //=========================================================================================================
            case 8:
                break;
            //=========================================================================================================
            case 9:
                break;
            //=========================================================================================================
            case 10:
                break;
            //=========================================================================================================
            case 11:
                break;
            //=========================================================================================================
            case 12:
                break;
            //=========================================================================================================
            case 13:
                break;
            //=========================================================================================================
            case 14:
                break;
            //=========================================================================================================
            case 15:
                break;
            //=========================================================================================================
            default:
                cout << "Invalid input. Try again!" << endl << endl;
                break;
        }
    } while(choice != 0);
    return 0;
}