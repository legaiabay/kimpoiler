#ifndef ATURAN_H
#define ATURAN_H
class _aturan {
private :
    int kata_ke = 0;

public :

    void stm(string kata[]){
        if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
        if(kata[kata_ke] == "id"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            if(kata[kata_ke] == ":="){
                kata_ke++;
                if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
                exp(kata);
                stm_(kata);
            }
            else {
                parse_error(kata);
            }
       }
       else if(kata[kata_ke] == "print"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            if(kata[kata_ke] == "("){
                kata_ke++;
                if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
                expList(kata);
                if(kata[kata_ke] == ")"){
                    kata_ke++;
                    if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
                    stm_(kata);
                }
                else{
                    parse_error(kata);
                }
            }
            else {
                parse_error(kata);
            }
       }
       else {
           parse_error(kata);
       }
    }

    void stm_(string kata[]){
        if(kata[kata_ke] == ";"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            stm(kata);
            stm_(kata);
        }
    }

    void exp(string kata[]){
        if(kata[kata_ke] == "id"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            exp_(kata);
        }
        else if(kata[kata_ke] == "num"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            exp_(kata);
        }
        else if(kata[kata_ke] == "("){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            stm(kata);
            if(kata[kata_ke] == ","){
                kata_ke++;
                if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
                exp(kata);
                if(kata[kata_ke] == ")"){
                    kata_ke++;
                    if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
                    exp_(kata);
                }
                else {
                    parse_error(kata);
                }
            }
            else{
                parse_error(kata);
            }
        }
        else {
            parse_error(kata);
        }
    }

    void exp_(string kata[]){
        if(kata[kata_ke] == "Binop"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            exp(kata);
            exp_(kata);
        }
    }

    void expList(string kata[]){
        if(kata[kata_ke] == "id"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            exp_(kata);
            expList_(kata);
        }
        else if(kata[kata_ke] == "num"){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            exp_(kata);
            expList_(kata);
        }
        else if(kata[kata_ke] == "("){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            stm(kata);
            if(kata[kata_ke] == ","){
                kata_ke++;
                if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
                exp(kata);
                if(kata[kata_ke] == ")"){
                    kata_ke++;
                    if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
                    exp_(kata);
                    expList_(kata);
                }
                else {
                    parse_error(kata);
                }
            }
            else {
                parse_error(kata);
            }
        }
        else {
            parse_error(kata);
        }
    }

    void expList_(string kata[]){
        if(kata[kata_ke] == ","){
            kata_ke++;
            if(debugMode)cout << kata_ke << "\t" << kata[kata_ke] << endl;
            expList(kata);
        }
    }

    void parse_error(string kata[]){

        string space;

        for(int i=0;i<kolomKalimat[kata_ke];i++){
            space += " ";
        }

        cout << inputLine << endl;
        cout << space << "^" << endl;
        cout << space << "^" << endl;

        cout << "Error! '" << kata[kata_ke] << "' pada kolom " << kolomKalimat[kata_ke]<< " salah urutan.";
        errorFlag = true;
        exit(0);
    }

    void parse_check(string kata[]){
        if(kata_ke < banyakKalimat){
            parse_error(kata);
        }
    }

};
#endif // ATURAN_H
