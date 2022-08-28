#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    char output[8];
    s.copy(output, 8,0);
    if(s[8] == 'A' && s[0] == '1' && s[1] == '2'){
        output[0] = '0';
        output[1] = '0';
    }
    else if (s[8] == 'P'){
        char tmp[2];
        s.copy(tmp, 2,0);
        int new_tmp = (tmp[0]-'0')*10 + (tmp[1]-'0');
        new_tmp = (12 + new_tmp);
        if((new_tmp) < 24) {
            output[0] = (char) (new_tmp/10 + 48);
            output[1] = (char) (new_tmp%10 + 48);
        } else {
            output[0] = '1';
            output[1] = '2';
        }
    }

    return output;        

}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    // fout << result << "\n";
    cout << result << "\n";

    // fout.close();
    system("PAUSE");

    return 0;
}
