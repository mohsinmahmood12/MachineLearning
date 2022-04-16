// Linear Regression
#include<iostream>
#include<vector>
using namespace std;

// Linear Regression C++ algorithm

class LinearRegression
{
    int n;
    vector<double> x;
    vector<double> y;
    double x_mean;
    double y_mean;
    double x_var;
    double y_var;
    double x_y_cov;
    double b1;
    double b0;
    double r_sq;
    double y_pred;
    double y_err;
    double y_err_sq;
    double y_err_sum;
    
    void compute_mean();
    void compute_variance();
    void compute_covariance();
    void compute_coefficients();
    void compute_r_sq();
    void compute_y_pred();
    void compute_y_err();
    void compute_y_err_sq();
    void compute_y_err_sum();
public:
    LinearRegression(int n);
    void add_data(double x_val, double y_val);
    void compute_regression();
    void print_regression();
};


LinearRegression::LinearRegression(int n)
{
    this->n = n;
    x.resize(n);
    y.resize(n);
}


void LinearRegression::add_data(double x_val, double y_val)
{
    x[n-1] = x_val;
    y[n-1] = y_val;
}


void LinearRegression::compute_mean()
{
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
    }
    x_mean = sum_x/n;
    y_mean = sum_y/n;
}


void LinearRegression::compute_variance()
{
    double sum_x_sq = 0;
    double sum_y_sq = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x_sq += x[i]*x[i];
        sum_y_sq += y[i]*y[i];
    }
    x_var = sum_x_sq/n - x_mean*x_mean;
    y_var = sum_y_sq/n - y_mean*y_mean;
}


void LinearRegression::compute_covariance()
{
    double sum_xy = 0;
    for (int i = 0; i < n; i++)
        sum_xy += x[i]*y[i];
    x_y_cov = sum_xy/n - x_mean*y_mean;
}


void LinearRegression::compute_coefficients()
{
    b1 = x_y_cov/x_var;
    b0 = y_mean - b1*x_mean;
}


void LinearRegression::compute_r_sq()
{
    r_sq = x_y_cov*x_y_cov/(x_var*y_var);
}


void LinearRegression::compute_y_pred()
{
    y_pred = b0 + b1*x_mean;
}


void LinearRegression::compute_y_err()
{
    y_err = y_mean - y_pred;
}


void LinearRegression::compute_y_err_sq()
{
    y_err_sq = y_err*y_err;
}


void LinearRegression::compute_y_err_sum()
{
    y_err_sum = 0;
    for (int i = 0; i < n; i++)
        y_err_sum += y_err_sq;
}

void LinearRegression::compute_regression()
{
    compute_mean();
    compute_variance();
    compute_covariance();
    compute_coefficients();
    compute_r_sq();
    compute_y_pred();
    compute_y_err();
    compute_y_err_sq();
    compute_y_err_sum();
}


void LinearRegression::print_regression()
{
    cout << "y = " << b0 << " + " << b1 << "x" << endl;
    cout << "r^2 = " << r_sq << endl;
    cout << "y_pred = " << y_pred << endl;
    cout << "y_err = " << y_err << endl;
    cout << "y_err_sq = " << y_err_sq << endl;
    cout << "y_err_sum = " << y_err_sum << endl;
}
// Create and generate dataset

void generate_dataset(int n, vector<double> &x, vector<double> &y)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = i;
        y[i] = i*i-2*i;
    }
}
void menu()
{
    cout << "1. Add data" << endl;
    cout << "2. Compute regression" << endl;
    cout << "3. Print regression" << endl;
    cout << "4. Exit" << endl;
}


int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    LinearRegression lr(n);
    vector<double> x(n);
    vector<double> y(n);
    generate_dataset(n, x, y);
    for (int i = 0; i < n; i++)
        lr.add_data(x[i], y[i]);
    int choice;
    do
    {
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                {
                    int x_val, y_val;
                    cout << "Enter x value: ";
                    cin >> x_val;
                    cout << "Enter y value: ";
                    cin >> y_val;
                    lr.add_data(x_val, y_val);
                    break;
                }
            case 2:
                lr.compute_regression();
                break;
            case 3:
                lr.print_regression();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}
