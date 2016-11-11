#ifndef TOKEN_H
#define TOKEN_H
class _token {

public :
    string WHITESPACE = " ";

    string END = ";";

    string KARAKTER(){
        string KARAKTER = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
        return KARAKTER;
    }

    string NUMERIK(){
        string NUMERIK = "0123456789";
        return NUMERIK;
    }

    string SYMBOL() {
        string SYMBOL = ":,()=";
        return SYMBOL;
    }

    string OPERATOR[5] = {
        ":=",
        "+",
        "-",
        "*",
        "/"
    };

    string KEYWORD[1] = {
        "print"
    };

    int operatorLength = (sizeof(OPERATOR)/sizeof(*OPERATOR));

    int keywordLength = (sizeof(KEYWORD)/sizeof(*KEYWORD));
};

#endif // TOKEN_H

