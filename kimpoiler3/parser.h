#ifndef PARSER_H
#define PARSER_H
void parser(string kalimat[]){
    _aturan aturan;

    lexer(inputLine);

    aturan.stm(kalimat);
    aturan.parse_check(kalimat);
    if(!errorFlag){
        cout << inputLine << endl << endl;
        cout << "Kalimat diatas Valid" << endl;
    }
}

#endif // PARSER_H
