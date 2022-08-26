#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

// string bigSum(long a, long b){
//     string strA = to_string(a);
//     string strB = to_string(b);
    
//     string strSum = "";
//     std::string::size_type sz;  

//     if(strA.length() > strB.length()){
//         swap(strA, strB);
//     }

//     int n1 = strA.length();
//     int n2 = strB.length();
     
    
//     int carry = 0;

//     for(int i = n1-1; i>=0; i++){
//         int sum = (strA[i] - '0') + (strB[i] - '0') + carry;
//         strSum.push_back(sum%10);
//         carry = sum/10;
//     }

//     for(int i=n2-n1-1; i>0; i++){
//         int sum = (strB[i] - '0') + carry;
//         strSum.push_back(sum%10);
//         carry = sum/10;
//     }

//     if(carry)
//         strSum.push_back(carry);
    
//     reverse(strSum.begin(), strSum.end());
//     return strSum;
// }

long long aVeryBigSum(vector<long long> ar) {
    long long sum = 0;
    for (int i=0; i< ar.size(); i++){
        // string tmp = bigSum(sum, ar[i]);
        sum = sum + ar[i];
    }
    return sum;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);

    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<long long> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        long long ar_item = stol(ar_temp[i]);

        ar[i] = ar_item;
    }

    long long result;
    result = aVeryBigSum(ar);

    // fout << result << "\n";
    cout << result << endl;
    
    // fout.close;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}