#ifndef SCANNER_H
#define SCANNER_H
void scanner(string input){
    _token token;
    int inputLength = input.length();

    cout << "Kolom\tKarakter" << endl;
    for(int i=0;i<inputLength;i++){
        if(input[i] == token.WHITESPACE[0]){
            cout << i << "\tWhitespace" << endl;
        }
        else {
            cout << i << "\t" << input[i] << endl;
        }
    }
}
#endif // SCANNER_H
