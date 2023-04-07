/*
In the illion function, I tried to replace the less-readable if-then-switch-case way of adding an
interfix(?) with the array way, to improve the program's performance, but it showed mixed results
when I tested it. Sometimes the array way was faster, sometimes slower. I think the array way is
slower by a fraction, so I scrapped it by commenting it out.
*/
#include<boost/multiprecision/gmp.hpp>
#include<iostream>
#include<string>
using namespace std;
namespace bmp = boost::multiprecision ;
string illion(bmp::mpz_int F){
    string s="";
    bmp::mpz_int f,i,I=((((bmp::mpz_int)(F.str().size()))-1)/3)*3;
    short sf;
    char f1,f2,f3;//,sm;
    for(;I>=0;I-=3){
        f=F;
        if(I<=INT_MAX){
            f/=bmp::pow((bmp::mpz_int)10,(int)I);}
        else{
            for(i=0;i<I;i++){
                f/=1000;}}
        sf=(short)(f%1000);
        switch(sf){
            case 1:{s+='m';break;}
            case 2:{s+='b';break;}
            case 3:{s+="tr";break;}
            case 4:{s+="quadr";break;}
            case 5:{s+="quint";break;}
            case 6:{s+="sext";break;}
            case 7:{s+="sept";break;}
            case 8:{s+="oct";break;}
            case 9:{s+="non";break;}
            case 0:{s+="n";break;}
            default:{
                f1=sf%10;
                f2=(sf/10)%10;
                f3=(sf/100)%10;
                //sm=0;
                switch(f1){
                    case 1:{s+="un";break;}
                    case 2:{s+="duo";break;}
                    case 3:{/*sm=1;*/s+="tre";break;}
                    case 4:{s+="quattuor";break;}
                    case 5:{
                        if((f2>0)&&(f2<4))
                            s+="quin";
                        else
                            s+="quinqua";
                        break;}
                    case 6:{/*sm=1;*/s+="se";break;}
                    case 7:{/*sm=2;*/s+="septe";break;}
                    case 8:{s+="octo";break;}
                    case 9:{/*sm=2;*/s+="nove";break;}}
                /*if((sm>0)&&((f2+f3)>0)){
                    const char sxnm[2][2][9]={{
                        { 0 ,'s','s','s','s', 0 , 0 ,'x', 0 },  //ten before sx
                        {'n','m','n','n','n','n','n','m', 0 }},{//tens before nm
                        {'x', 0 ,'s','s','s', 0 , 0 ,'x', 0 },  //hundreds before sx
                        {'n','n','n','n','n','n','n','m', 0 }}};//hundreds before nm
                    sm=sxnm[(f2==0)?1:0][sm-1][((f2==0)?f3:f2)-1];
                    if(sm!=0){
                        s+=sm;}}*/
                switch(f1){
                    case 3:
                    case 6:
                        if(f2>0)
                            switch(f2){
                                case 2 ... 5:
                                    s+="s";
                                    break;
                                case 8:
                                    s+="x";}
                        else
                            switch(f3){
                                case 3 ... 5:
                                    s+="s";
                                    break;
                                case 1:
                                case 8:
                                    s+="x";}
                        break;
                    case 7:
                    case 9:
                        if(f2>0)
                            switch(f2){
                                case 1:
                                case 3 ... 7:
                                    s+="n";
                                    break;
                                case 2:
                                case 8:
                                    s+="m";}
                        else
                            switch(f3){
                                case 1 ... 7:
                                    s+="n";
                                    break;
                                case 8:
                                    s+="m";}}
                switch(f2){
                    case 1:{s+="deci";break;}
                    case 2:{s+="viginti";break;}
                    case 3:{s+="triginta";break;}
                    case 4:{s+="quadraginta";break;}
                    case 5:{s+="quinquaginta";break;}
                    case 6:{s+="sexaginta";break;}
                    case 7:{s+="septuaginta";break;}
                    case 8:{s+="octoginta";break;}
                    case 9:{s+="nonaginta";break;}}
                switch(f3){
                    case 1:{s+="centi";break;}
                    case 2:{s+="ducenti";break;}
                    case 3:{s+="trecenti";break;}
                    case 4:{s+="quadringenti";break;}
                    case 5:{s+="quingenti";break;}
                    case 6:{s+="sescenti";break;}
                    case 7:{s+="septingenti";break;}
                    case 8:{s+="octingenti";break;}
                    case 9:{s+="nongenti";break;}}
                break;}}
        switch(*prev(s.end())){
            case 'a':
            case 'i':
                s.pop_back();}
        s+="illi";}
    return s+"on";}
void NumbersToWords(string n){
    if(n[0]=='-'){
        cout<<"minus ";
        n.erase(n.begin());}
    if((n=="")||(n=="0")){
        cout<<"zero\n";
        return;}
    string s="";
    bmp::mpz_int l=n.size();
    string::iterator i=n.begin(),ie=n.end();
    char o,e=3-(char)((l-1)%3);
    bool t;
    for(bmp::mpz_int ff=(l-1)/3;i!=ie;e=1,ff--){
        t=false;
        for(;e<4;e++,i=next(i)){
            o=*i;
            if(o=='0'){
                continue;}
            else{
                t=true;}
            if(e==2){
                switch(o){
                    case '1':{
                        e++;
                        i=next(i);
                        switch(*i){
                            case '0':{s+="ten";break;}
                            case '1':{s+="eleven";break;}
                            case '2':{s+="twelve";break;}
                            case '3':{s+="thirteen";break;}
                            case '4':{s+="fourteen";break;}
                            case '5':{s+="fifteen";break;}
                            case '6':{s+="sixteen";break;}
                            case '7':{s+="seventeen";break;}
                            case '8':{s+="eighteen";break;}
                            case '9':{s+="nineteen";break;}}
                        break;}
                    case '2':{s+="twenty";break;}
                    case '3':{s+="thirty";break;}
                    case '4':{s+="fourty";break;}
                    case '5':{s+="fifty";break;}
                    case '6':{s+="sixty";break;}
                    case '7':{s+="seventy";break;}
                    case '8':{s+="eighty";break;}
                    case '9':{s+="ninety";break;}}}
            else{
                switch(o){
                    case '1':{s+="one";break;}
                    case '2':{s+="two";break;}
                    case '3':{s+="three";break;}
                    case '4':{s+="four";break;}
                    case '5':{s+="five";break;}
                    case '6':{s+="six";break;}
                    case '7':{s+="seven";break;}
                    case '8':{s+="eight";break;}
                    case '9':{s+="nine";break;}}
                if((e==1)&&(o!='0')){
                    s+=" hundred";}}
            s+=' ';}
        if(t){
            if(ff==0)
                continue;
            else if(ff==1)
                s+="thousand";
            else s+=illion((bmp::mpz_int)(ff-1));
            s+=' ';}}
    s.pop_back();
    cout<<s<<'\n';}
int main(int argc,char** argv){
    bool I=false;
    string s;
    long long int i=1;
    if(argc>1){
        s=argv[1];
        if(s=="-i"){
            i=2;
            I=true;}}
    if(i<argc){
        for(;i<argc;i++){
            s=argv[i];
            if(I)
                cout<<illion((bmp::mpz_int)s)<<'\n';
            else
                NumbersToWords(s);}}
    else{
        if(I){
            bmp::mpz_int ii;
            while(cin>>ii)
                cout<<illion(ii)<<'\n';}
        else{
            string nn;
            while(cin>>nn)
                NumbersToWords(nn);}}}