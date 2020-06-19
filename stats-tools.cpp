#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int factorial(int num)
{
    if (num == 0) return 1;
    else return num * factorial(num - 1);
}

double nchoosek(int n, int k)
{
    return (double)(factorial(n)/(factorial(n-k) * factorial(k)));
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

double median(vector<double> v)
{
    int len = v.size();
    double median, m1, m2;
    sort(v.begin(), v.end());
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

void quartiles(vector<double> v, int len)
{
    double med;
    sort(v.begin(), v.end());
    vector<double> lower, upper;
    if (len % 2 != 0) // odd length
    {
        med = v[len/2];
        for (int i = 0; i < len/2; i++) lower.push_back(v[i]);
        for (int i = (len/2)+1; i < len; i++) upper.push_back(v[i]);
    }
    else // even length
    {
        med = (v[len/2 - 1] + v[len/2]) / 2;
        for (int i = 0; i < len/2; i++) lower.push_back(v[i]);
        for (int i = (len/2); i < len; i++) upper.push_back(v[i]);
    }

    cout << "Lower Quartile: " << median(lower) << endl;
    cout << "Middle Quartile: " << med << endl;
    cout << "Upper Quartile: " << median(upper) << endl << endl;
}

double binomial(int n, int k, double prob)
{
    return nchoosek(n, k) * pow(prob, k) * pow(1 - prob, n - k);
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
                "8. Binomial Probability Distribution\n" <<
                "9. Geometric Probability Distribution\n" <<
                "10. Poisson Probability Distribution\n" <<
                "11. Normal Probability Distribution\n" <<
                "12. Central Limit Theorem\n" <<
                "13. Pearson Correlation Coefficient\n" <<
                "14. Spearman's Rank Correlation Coefficient\n\n" <<

                "Your choice --> ";

        cin >> choice;
        cout << endl;
        
        vector<double> v;
        int len, iter, n, k;
        double tmp, prob, answer = 0;
        string pick;
        
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
                cout << "==============================" << endl;
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
                cout << "==============================" << endl;
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
                cout << "==============================" << endl;
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
                cout << fixed << setprecision(3) << "\nMedian = " << median(v) << endl << endl;
                v.clear();
                cout << "==============================" << endl;
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
                cout << "==============================" << endl;
                break;
            //=========================================================================================================
            case 6:
                cout << "Enter the number whose factorial you wish to compute --> ";
                cin >> len;
                cout << endl << len << "! = " << factorial(len) << endl << endl;
                cout << "==============================" << endl;
                break;
            //=========================================================================================================
            case 7:
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
                cout << endl;
                quartiles(v, len);
                v.clear();
                cout << endl << "==============================" << endl;
                break;
            //=========================================================================================================
            case 8:
                cout << "Enter the number of trials --> "; cin >> n;
                cout << "Enter the number of successes --> "; cin >> k;
                cout << "Enter the probability --> "; cin >> prob;
                
                answer = binomial(n, k, prob);
                cout << endl << fixed << setprecision(3) << "P(X = " << k << ") = " << answer << endl;

                answer = 0;
                for (int i = 0; i <= k; i++) answer += binomial(n, i, prob);
                cout << fixed << setprecision(3) << "P(X <= " << k << ") = " << answer << endl;
                answer = 1 - answer;
                cout << fixed << setprecision(3) << "P(X > " << k << ") = " << answer << endl;
                
                answer = 0;
                for (int i = 0; i < k; i++) answer += binomial(n, i, prob);
                cout << fixed << setprecision(3) << "P(X < " << k << ") = " << answer << endl;
                answer = 1 - answer;
                cout << fixed << setprecision(3) << "P(X >= " << k << ") = " << answer << endl << endl;
                
                cout << "E[X] = " << n*prob << endl;
                cout << "Var[X] = " << n*prob*(1-prob) << endl << endl;

                cout << "Standard Deviation = " << sqrt(n*prob*(1-prob)) << endl << endl;
                cout << "==============================" << endl;
                answer = 0;
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
            default:
                cout << "Invalid input. Try again!" << endl;
                cout << "==============================" << endl;
                break;
        }
    } while(choice != 0);
    return 0;
}
