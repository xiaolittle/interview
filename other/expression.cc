#include <stdio.h>
#include <string>
#include <string.h>
#include <cctype>
#include <iostream>
using namespace std;

double readNum( char * &str){

    double num;
    sscanf( str, "%lf", &num );
    
    str++;
    while( isdigit(*str) || *str == '.' )
        str++;
    return num;

}

double evaluate( char *str){

    if( *str == '\0' )
        return 0.0;
    
    double res = 1.0;
    char op = '*';
    
    while( op == '*' || op == '/' ){
    
        if( op == '*' )
            res *= readNum(str);
        else
            res /= readNum(str);
        
        op = *str++;
    }
    
    return res + evaluate( --str);
}

int main(){
    
    cout << evaluate("-3-4.3+5.05*2/4-4.10/5+3") <<endl;
    
    
}
int main() {

}
