#ifndef LEXER_H
#define LEXER_H
string kalimat[999];
int kolomKalimat[999];

void lexer(string input){
    _token token;
    int kolom;
    int inputLength = input.length();
    string space;

    if(debugMode)cout << "Loop\t\tInput\tKalimat\t\tToken" << endl;


    for(int i=0;i<inputLength;i++){
        int tes = 0;
        kolom = i;
        if(debugMode)cout << "loop : " << i << "\t" << input[i] << "\t";

        string oneInput = "";
        string operator_temp = "";
        string keyword_temp = "";
        oneInput += input[i];

        //keyword
        for(int j=0;j<token.keywordLength;j++){
            tes = 0;
            keyword_temp = "";
            if(oneInput[0] == token.KEYWORD[j][0]){
                bool check_keyword = true;
                while(check_keyword){
                    keyword_temp += oneInput;
                    if(token.KEYWORD[j].find(keyword_temp) != string::npos){
                        if(token.KEYWORD[j] == keyword_temp){
                            check_keyword = false;
                        }
                        tes++;
                        oneInput = input[i+tes];
                    }
                    else {
                        oneInput = input[i];
                        check_keyword = false;
                    }
                }
                if(keyword_temp == token.KEYWORD[j]){
                    if(debugMode)cout << token.KEYWORD[j] << "\t\t : Keyword (Panjang : " << token.KEYWORD[j].length() << ")" << endl;
                    kalimat[banyakKalimat] = token.KEYWORD[j];
                    kolomKalimat[banyakKalimat] = i;
                    banyakKalimat++;
                    i += keyword_temp.length()-1;
                    tes = 0;
                    goto done;
                }
            }
        }

        //operator
        for(int j=0;j<token.operatorLength;j++){
            string oneChar = "";
            oneChar += token.OPERATOR[j][0];
            if(oneChar.find(oneInput) != string::npos){
                if(j==0){
                    oneInput = input[i+1];
                    operator_temp = oneInput;

                    if(token.OPERATOR[0].find(oneInput) != string::npos){
                        if(debugMode)cout << token.OPERATOR[0] << "\t\t : := (Panjang : " << token.OPERATOR[0].length() << ")" << endl;
                        kalimat[banyakKalimat] = ":=";
                        kolomKalimat[banyakKalimat] = i;
                        banyakKalimat++;
                        i++;
                        goto done;
                    }
                    else{
                        oneInput = input[i];
                    }
                }
                else {
                    if(oneInput == token.OPERATOR[j]){
                        if(debugMode)cout << token.OPERATOR[j] << "\t\t : Binop" << endl;
                        kalimat[banyakKalimat] = "Binop";
                        kolomKalimat[banyakKalimat] = i;
                        banyakKalimat++;
                        goto done;
                    }
                }
            }
        }

        //identifier
        if(token.KARAKTER().find(oneInput) != string::npos){
            string identifier = "";
            tes = 0;
            bool identifierCheck = true;
            identifier += oneInput;
            while(identifierCheck){
                tes++;
                oneInput = input[i+tes];
                if(token.KARAKTER().find(oneInput) != string::npos){
                    identifier += oneInput;
                }
                else if(token.NUMERIK().find(oneInput) != string::npos){
                    identifier += oneInput;
                }
                else {
                    if(debugMode)cout << identifier << "\t\t : id (Panjang : " << identifier.length() << ")" << endl;
                    kalimat[banyakKalimat] = "id";
                    kolomKalimat[banyakKalimat] = i;
                    banyakKalimat++;
                    i += identifier.length()-1;
                    identifierCheck = false;
                    goto done;
                }
            }
        }

        //numeric
        if(token.NUMERIK().find(oneInput) != string::npos){
            string numerik = "";
            tes = 0;
            bool numerikCheck = true;
            numerik += oneInput;
            while(numerikCheck){
                tes++;
                oneInput = input[i+tes];
                if(token.NUMERIK().find(oneInput) != string::npos){
                    numerik += oneInput;
                }
                else {
                    if(debugMode)cout << numerik << "\t\t : num (Panjang : " << numerik.length() << ")" << endl;
                    kalimat[banyakKalimat] = "num";
                    kolomKalimat[banyakKalimat] = i;
                    banyakKalimat++;
                    i += numerik.length()-1;
                    numerikCheck = false;
                    goto done;
                }
            }
        }

        //symbol
        if(token.SYMBOL().find(oneInput) != string::npos){
            if(debugMode)cout << oneInput << "\t\t : Symbol" << endl;
            kalimat[banyakKalimat] = oneInput;
            kolomKalimat[banyakKalimat] = i;
            banyakKalimat++;
            goto done;
        }

        //end mark
        if(token.END.find(oneInput) != string::npos){
            if(debugMode)cout << oneInput << "\t\t : End Mark" << endl;
            kalimat[banyakKalimat] = oneInput;
            kolomKalimat[banyakKalimat] = i;
            banyakKalimat++;
            goto done;
        }

        if(debugMode)cout << "???\t\t???" << endl;

        for(int i=0;i<kolom;i++){
            space += " ";
        }
        cout << inputLine << endl;
        cout << space << "^" << endl;
        cout << space << "^" << endl;
        cout << endl << endl << "Error! Karakter '" << input[i] << "' pada kolom " << i << " tidak dikenali." <<endl;
        exit(0);

        done :
            cout << "";
    }
    if(debugMode)cout << endl << "Banyak kalimat : " << banyakKalimat << endl;
    if(debugMode)cout << "Kalimat : ";

    for(int k=0;k<banyakKalimat;k++){
       if(k!=0){
        if(debugMode)cout << ", " << kalimat[k];
       }
       else {
        if(debugMode)cout << kalimat[k];
       }
    }

    cout << endl << endl;
}
#endif // LEXER_H
